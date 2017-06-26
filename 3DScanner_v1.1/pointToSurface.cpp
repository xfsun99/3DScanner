#include "pointToSurface.h"
#include <vtkSmartPointer.h>
#include <vtkDelaunay2D.h>
#include <vtkSmoothPolyDataFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include "actorManagerClass.h"
#include "UiStateManager.h"

#include <QtCore/qglobal.h>
#include <QCursor>
pointToSurface::pointToSurface(QMainWindow& mainWindow,Ui::pointCloudEditToolBar *toolbar)
{
	PointToSurfaceDocWidget = new QDockWidget(&mainWindow);
	PointToSurfaceDocWidget_ui.setupUi(PointToSurfaceDocWidget);
	mainWindow.addDockWidget(static_cast<Qt::DockWidgetArea>(2), PointToSurfaceDocWidget);
	PointToSurfaceDocWidget->hide();

	//on ok button clicked
	QObject::connect(PointToSurfaceDocWidget_ui.okButton,SIGNAL(clicked()),this,SLOT(pointtosurface()));
	//on cancel button clicked
	QObject::connect(PointToSurfaceDocWidget_ui.cancelButton,SIGNAL(clicked()),this,SLOT(onCancelClickedSlot()));
	QObject::connect(this,SIGNAL(setPointToSurfaceChecked(bool)),toolbar->actionPointToSurface,SLOT(setChecked(bool)));
	//
	QObject::connect(toolbar->actionPointToSurface,SIGNAL(triggered()),this,SLOT(pointToSurfaceSlot()));

	QObject::connect(PointToSurfaceDocWidget_ui.doubleSpinBoxAlpha,SIGNAL(valueChanged(double)),this,SLOT(AlphasliderMoveSlot(double)));
	QObject::connect(PointToSurfaceDocWidget_ui.horizontalSliderAlpha,SIGNAL(valueChanged(int)),this,SLOT(AlphaboxValueChangeSlot(int)));

	//enable undo button on main toolbar
	UiStateManager*uimanager=UiStateManager::getInstance();
	QObject::connect(this,SIGNAL(setUndoEnabled(bool)),uimanager,SLOT(setUndoEnabledSlot(bool)));


}
pointToSurface::~pointToSurface()
{

}
void pointToSurface::AlphasliderMoveSlot(double v)
{
	PointToSurfaceDocWidget_ui.horizontalSliderAlpha->setValue(v*10);
}
void pointToSurface::AlphaboxValueChangeSlot(int v)
{
	PointToSurfaceDocWidget_ui.doubleSpinBoxAlpha->setValue(v/10.0);
}
void pointToSurface::pointToSurfaceSlot()
{
	PointToSurfaceDocWidget->show();
	emit setPointToSurfaceChecked(true);
}
void pointToSurface::pointtosurface()
{
	PointToSurfaceDocWidget->setDisabled(true);
	//change cursor shape
	vtkDisplayClass*displayinstance=vtkDisplayClass::getInstance();
	displayinstance->Qwindow->setCursor(Qt::WaitCursor);
	double Alpha=PointToSurfaceDocWidget_ui.doubleSpinBoxAlpha->value();
	int Iterations=PointToSurfaceDocWidget_ui.spinBoxItera->value();
	// Triangulate the grid points
	vtkSmartPointer<vtkDelaunay2D> delaunay = vtkSmartPointer<vtkDelaunay2D>::New();

	actorManagerClass* currentActorStruct=actorManagerClass::getInstance();
	//get the selected polyData
	vtkPolyData*inputData= currentActorStruct->getCurrentActor()->getPolyData();

	std::vector<vtkPolyData*>*vector=currentActorStruct->getCurrentActor()->getDataStateVector();
	if(vector->size()==0)
	{
		vtkPolyData*inputDataTemp=vtkPolyData::New();
		inputDataTemp->ShallowCopy(inputData);
		currentActorStruct->getCurrentActor()->addSate(inputDataTemp);
	}


#if VTK_MAJOR_VERSION <= 5
  delaunay->SetInput(inputData);
#else
 delaunay->SetInputData(inputData);
#endif

	delaunay->SetAlpha(Alpha);
	delaunay->Update();

	vtkSmartPointer<vtkSmoothPolyDataFilter> smoothFilter =
	vtkSmartPointer<vtkSmoothPolyDataFilter>::New();
	smoothFilter->SetInputConnection(delaunay->GetOutputPort());
	smoothFilter->SetNumberOfIterations(Iterations);
	smoothFilter->SetFeatureEdgeSmoothing(0);
	smoothFilter->Update();
	//update data
	inputData->ShallowCopy(smoothFilter->GetOutput());
	//new a polydata 
	vtkPolyData*PolyData=vtkPolyData::New();
	PolyData->ShallowCopy(smoothFilter->GetOutput());
	currentActorStruct->getCurrentActor()->addSate(PolyData);
	//update the display window
	currentActorStruct->display();
	//enable Undo action
	emit setUndoEnabled(true);
	PointToSurfaceDocWidget->setDisabled(false);
	displayinstance->Qwindow->setCursor(Qt::ArrowCursor);
}
void pointToSurface::onCancelClickedSlot()
{
	PointToSurfaceDocWidget->hide();
	emit setPointToSurfaceChecked(false);
}
