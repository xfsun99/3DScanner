#include "pointCloudFilter.h"
#include "actorManagerClass.h"
#include "UiStateManager.h"

#include "vtkSimplePointsWriter.h"
#include "vtkPolyData.h"
#include "vtkSTLWriter.h"
#include <vtkSmartPointer.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkOctreePointLocator.h>
#include <vtkDelaunay2D.h>
#include <vtkSmoothPolyDataFilter.h>
#include "vtkDisplayClass.h"
#include <vtkElevationFilter.h>
#include <vtkPointData.h>
#include <vtkCellArray.h>
#include <vtkUnsignedCharArray.h>

pointCloudFilter::pointCloudFilter(QMainWindow& mainWindow,Ui::pointCloudEditToolBar *toolbar)
{
	//create pointCloudFilterDockWidget
	pointCloudFilterDockWidget = new QDockWidget(&mainWindow);
	PointCloudFilterDocWidget_ui.setupUi(pointCloudFilterDockWidget);
	mainWindow.addDockWidget(static_cast<Qt::DockWidgetArea>(2), pointCloudFilterDockWidget);
	pointCloudFilterDockWidget->hide();

	//on ok button clicked
	QObject::connect(PointCloudFilterDocWidget_ui.okButton,SIGNAL(clicked()),this,SLOT(pointcloudFilter()));
	//on cancel button clicked
	QObject::connect(PointCloudFilterDocWidget_ui.cancelButton,SIGNAL(clicked()),this,SLOT(onCancelClickedSlot()));
	QObject::connect(this,SIGNAL(setPointCloudFilterChecked(bool)),toolbar->actionPointCloudFilter,SLOT(setChecked(bool)));
	//spin box and slider
	QObject::connect(PointCloudFilterDocWidget_ui.doubleSpinBox_Rad,SIGNAL(valueChanged(double)),this,SLOT(RadsliderMoveSlot(double)));
	QObject::connect(PointCloudFilterDocWidget_ui.horizontalSliderRad,SIGNAL(valueChanged(int)),this,SLOT(RadboxValueChangeSlot(int)));

	QObject::connect(PointCloudFilterDocWidget_ui.doubleSpinBox_Sigma,SIGNAL(valueChanged(double)),this,SLOT(SigmasliderMoveSlot(double)));
	QObject::connect(PointCloudFilterDocWidget_ui.horizontalSliderSigma,SIGNAL(valueChanged(int)),this,SLOT(SigmaboxValueChangeSlot(int)));

	QObject::connect(PointCloudFilterDocWidget_ui.doubleSpinBox_Thrd,SIGNAL(valueChanged(double)),this,SLOT(ThrdsliderMoveSlot(double)));
	QObject::connect(PointCloudFilterDocWidget_ui.horizontalSliderThrd,SIGNAL(valueChanged(int)),this,SLOT(ThrdboxValueChangeSlot(int)));

	//on button clicked
	QObject::connect(toolbar->actionPointCloudFilter,SIGNAL(triggered()),this,SLOT(pointClouFilterSlot()));

	//enable the point cloud edit toolbar
	actorManagerClass*actorStruct=actorManagerClass::getInstance();
	QObject::connect(actorStruct,SIGNAL(actorIsValid(bool)),toolbar->actionPointCloudFilter,SLOT(setEnabled(bool)));
	QObject::connect(actorStruct,SIGNAL(actorIsValid(bool)),toolbar->actionPointToSurface,SLOT(setEnabled(bool)));
	//enable undo button on main toolbar
	UiStateManager*uimanager=UiStateManager::getInstance();
	QObject::connect(this,SIGNAL(setUndoEnabled(bool)),uimanager,SLOT(setUndoEnabledSlot(bool)));


}
pointCloudFilter::~pointCloudFilter()
{
}
//on cancel button clicked
void pointCloudFilter::onCancelClickedSlot()
{
	pointCloudFilterDockWidget->hide();
	emit setPointCloudFilterChecked(false);
}
//box and silder connect
void pointCloudFilter::RadsliderMoveSlot(double v)
{
	PointCloudFilterDocWidget_ui.horizontalSliderRad->setValue(v*10);
}
void pointCloudFilter::RadboxValueChangeSlot(int v)
{
	PointCloudFilterDocWidget_ui.doubleSpinBox_Rad->setValue(v/10.0);
}
//box and silder connect
void pointCloudFilter::SigmasliderMoveSlot(double v)
{
	PointCloudFilterDocWidget_ui.horizontalSliderSigma->setValue(v*10);
}
void pointCloudFilter::SigmaboxValueChangeSlot(int v)
{
	PointCloudFilterDocWidget_ui.doubleSpinBox_Sigma->setValue(v/10.0);
}
//box and silder connect
void pointCloudFilter::ThrdsliderMoveSlot(double v)
{
	PointCloudFilterDocWidget_ui.horizontalSliderThrd->setValue(v*10);
}
void pointCloudFilter::ThrdboxValueChangeSlot(int v)
{
	PointCloudFilterDocWidget_ui.doubleSpinBox_Thrd->setValue(v/10.0);
}
//point cloud filter slot,on pointcloudfilter button clicked
void pointCloudFilter::pointClouFilterSlot()
{
	pointCloudFilterDockWidget->show();
	emit setPointCloudFilterChecked(true);
}
void pointCloudFilter::pointcloudFilter()
{
	//get partarm in ui
	double rad=PointCloudFilterDocWidget_ui.doubleSpinBox_Rad->value();
	double sigema=PointCloudFilterDocWidget_ui.doubleSpinBox_Sigma->value();
	double threslod=PointCloudFilterDocWidget_ui.doubleSpinBox_Thrd->value();
	//build a OCTree
	vtkSmartPointer<vtkOctreePointLocator> pointTree =vtkSmartPointer<vtkOctreePointLocator>::New();
	actorManagerClass* currentActorStruct=actorManagerClass::getInstance();
	//get the selected polyData
	vtkPolyData*inputData= currentActorStruct->getCurrentActor()->getPolyData();
	pointTree->SetDataSet(inputData);  
	pointTree->BuildLocator(); 
	//get state vector in actor struct
	std::vector<vtkPolyData*>*vector=currentActorStruct->getCurrentActor()->getDataStateVector();
	if(vector->size()==0)
	{
		vtkPolyData*inputDataTemp=vtkPolyData::New();
		inputDataTemp->ShallowCopy(inputData);
		currentActorStruct->getCurrentActor()->addSate(inputDataTemp);
	}
	vtkIdType k=inputData->GetNumberOfPoints();
	double testPoint[3] = {0.0, 0.0, 0.0};  
	vtkSmartPointer<vtkIdList> result =  vtkSmartPointer<vtkIdList>::New();
	vtkSmartPointer<vtkPoints> outlinepoints=vtkSmartPointer<vtkPoints>::New();
	vtkSmartPointer<vtkPoints> inlinepoints=vtkSmartPointer<vtkPoints>::New();
	//KNN method
	for(vtkIdType i = 0; i < k; i++)
	{
		inputData->GetPoint(i, testPoint);	  
		pointTree->FindPointsWithinRadius(rad, testPoint, result);
		if(result->GetNumberOfIds()<10)
		{
			outlinepoints->InsertNextPoint(testPoint);
		}
		else 
		{
			double inlinepoint[3];
			double diskernel=0;
			double dist=0;
			if(sigema>0)
			{
				for(int j=0;j<result->GetNumberOfIds();j++)
				{
					inputData->GetPoint(result->GetId(j),inlinepoint);
					dist=(testPoint[0]-inlinepoint[0])*(testPoint[0]-inlinepoint[0])+
						(testPoint[1]-inlinepoint[1])*(testPoint[1]-inlinepoint[1])+
						(testPoint[2]-inlinepoint[2])*(testPoint[2]-inlinepoint[2]);
					dist=dist/sigema;
					diskernel+=exp(-dist);
					dist=0;
				}
			}
			else
			{
				for(int j=0;j<result->GetNumberOfIds();j++)
				{
					inputData->GetPoint(result->GetId(j),inlinepoint);
					dist=(testPoint[0]-inlinepoint[0])*(testPoint[0]-inlinepoint[0])+
						(testPoint[1]-inlinepoint[1])*(testPoint[1]-inlinepoint[1])+
						(testPoint[2]-inlinepoint[2])*(testPoint[2]-inlinepoint[2]);
					diskernel+=dist;
					dist=0;
				}
			}
			if(diskernel>threslod)
				inlinepoints->InsertNextPoint(testPoint);
		}
	}
	vtkSmartPointer<vtkPolyData> temp = vtkSmartPointer<vtkPolyData>::New();
	temp->SetPoints(inlinepoints);
	vtkSmartPointer<vtkVertexGlyphFilter> vertexFilter = vtkSmartPointer<vtkVertexGlyphFilter>::New();
	vertexFilter->SetInputData(temp);
	vertexFilter->Update();

	vtkPolyData*PolyData=vtkPolyData::New();
	PolyData->ShallowCopy(vertexFilter->GetOutput());

	currentActorStruct->getCurrentActor()->addSate(PolyData);

	inputData->ShallowCopy(vertexFilter->GetOutput());
	//update the display window
	currentActorStruct->display();
	//enable Undo action
	emit setUndoEnabled(true);
}