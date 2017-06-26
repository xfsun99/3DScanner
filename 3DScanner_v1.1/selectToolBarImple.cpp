#include "selectToolBarImple.h"
#include "actorManagerClass.h"
#include "selectSurfacePointUsePoly.h"
#include "vtkDisplayClass.h"
#include <vtkSimplePointsReader.h>
#include <vtkPolyDataMapper.h> 
#include <vtkSimplePointsWriter.h>
#include <vtkSTLWriter.h>
#include"normalInteractorStyle.h"

#include "UiStateManager.h"
selectToolBarImple::selectToolBarImple(Ui::selectToolbar* selecttoolbar)
{
	//PolySelectSurfacePointSlot
	connect(selecttoolbar->actionPolySelectSurfacePoint,SIGNAL(triggered()),this,SLOT(PolySelectSurfacePointSlot()));
	//PolySelectSurfaceCellSlot
	connect(selecttoolbar->actionPolySelectSurfaceCell,SIGNAL(triggered()),this,SLOT(PolySelectSurfaceCellSlot()));
	//SelectPointOnSlot
	connect(selecttoolbar->actionSelectPointOn,SIGNAL(triggered()),this,SLOT(SelectPointOnSlot()));
	//SelectCellOnSlot
	connect(selecttoolbar->actionSelectCellOn,SIGNAL(triggered()),this,SLOT(SelectCellOnSlot()));
	//SelectPointThrougSlot
	connect(selecttoolbar->actionSelectPointThroug,SIGNAL(triggered()),this,SLOT(SelectPointThrougSlot()));
	//SelectCellThrougSlot
	connect(selecttoolbar->actionSelectCellThroug,SIGNAL(triggered()),this,SLOT(SelectCellThrougSlot()));
	//save selected part
	connect(selecttoolbar->actionSaveSelectedPart,SIGNAL(triggered()),this,SLOT(SaveSelectedPartSlot()));
	//delete selected part
	connect(selecttoolbar->actionDeleleSelectedPart,SIGNAL(triggered()),this,SLOT(deleteSlectedPartSlot()));
	//signal from actorMangaerClass,change selectToolBar state
	actorManagerClass*instance=actorManagerClass::getInstance();
	connect(instance,SIGNAL(actorIsValid(bool)),selecttoolbar->actionPolySelectSurfaceCell,SLOT(setEnabled(bool)));
	connect(instance,SIGNAL(actorIsValid(bool)),selecttoolbar->actionPolySelectSurfacePoint,SLOT(setEnabled(bool)));
	connect(instance,SIGNAL(actorIsValid(bool)),selecttoolbar->actionSelectCellOn,SLOT(setEnabled(bool)));
	connect(instance,SIGNAL(actorIsValid(bool)),selecttoolbar->actionSelectCellThroug,SLOT(setEnabled(bool)));
	connect(instance,SIGNAL(actorIsValid(bool)),selecttoolbar->actionSelectPointOn,SLOT(setEnabled(bool)));
	connect(instance,SIGNAL(actorIsValid(bool)),selecttoolbar->actionSelectPointThroug,SLOT(setEnabled(bool)));
	connect(instance,SIGNAL(actorIsValid(bool)),selecttoolbar->actionSaveSelectedPart,SLOT(setEnabled(bool)));
	connect(instance,SIGNAL(actorIsValid(bool)),selecttoolbar->actionDeleleSelectedPart,SLOT(setEnabled(bool)));

	
	//undo and redo ui state manager
	UiStateManager*uistateInstance=UiStateManager::getInstance();
	//change redo and undo state
	QObject::connect(this,SIGNAL(setRedoEnabled(bool)),uistateInstance,SLOT(setRedoEnabledSlot(bool)));
	QObject::connect(this,SIGNAL(setUndoEnabled(bool)),uistateInstance,SLOT(setUndoEnabledSlot(bool)));

	temp = 	vtkSmartPointer<vtkPolyData>::New();
	vertexFilter = vtkSmartPointer<vtkVertexGlyphFilter>::New();
}
selectToolBarImple::~selectToolBarImple()
{
	temp->Delete();
	vertexFilter->Delete();
}
//Slot 
void selectToolBarImple::PolySelectSurfacePointSlot()
{
	//change the button state
	vtkDisplayClass*instance=vtkDisplayClass::getInstance();
	selectSurfacePointUsePoly*polySelectInteractorStyle=selectSurfacePointUsePoly::getInstance();
	polySelectInteractorStyle->setSlecterFieldAssociation(vtkDataObject::FIELD_ASSOCIATION_POINTS);
	////set polyData to be selected
	actorManagerClass*actorSturct=actorManagerClass::getInstance();
	polySelectInteractorStyle->setData(actorSturct->getCurrentActor()->getPolyData());
	////change the interactor style
	instance->getInteractor()->SetInteractorStyle(polySelectInteractorStyle);
	//change cursor shape
	instance->Qwindow->setCursor(Qt::PointingHandCursor);
}
//slot
void selectToolBarImple::PolySelectSurfaceCellSlot()
{
	vtkDisplayClass*instance=vtkDisplayClass::getInstance();
	selectSurfacePointUsePoly*polySelectInteractorStyle=selectSurfacePointUsePoly::getInstance();
	actorManagerClass*actorSturct=actorManagerClass::getInstance();
	polySelectInteractorStyle->setSlecterFieldAssociation(vtkDataObject::FIELD_ASSOCIATION_CELLS);
	//set polyData to be selected
	polySelectInteractorStyle->setData(actorSturct->getCurrentActor()->getPolyData());
	//change the interactor style
	instance->getInteractor()->SetInteractorStyle(polySelectInteractorStyle);
	//change cursor shape
	instance->Qwindow->setCursor(Qt::PointingHandCursor);
}
void selectToolBarImple::PolySelectActionDoneSlot()
{
	//selecttoolbarPointer->actionPolySelectSurfacePoint->setDisabled(true);
	//changge cursor to normal shape
	vtkDisplayClass*instance=vtkDisplayClass::getInstance();
	instance->Qwindow->setCursor(Qt::CustomCursor);
	normalInteractorStyle*normalstyle=normalInteractorStyle::getInstance();
	instance->getInteractor()->SetInteractorStyle(normalstyle);
}
//slot
void selectToolBarImple::SelectPointOnSlot()
{
}
//slot
void selectToolBarImple::SelectPointThrougSlot()
{
}
//slot
void selectToolBarImple::SelectCellOnSlot()
{
}
//slot
void selectToolBarImple::SelectCellThrougSlot()
{
}
//slot save selected part
void selectToolBarImple::SaveSelectedPartSlot()
{
	selectSurfacePointUsePoly*instance=selectSurfacePointUsePoly::getInstance();
	if(instance->isSelecteEmpty())
	{
		QString message=QString::fromStdString("Your selection is empty, please select again!");
		QMessageBox::information(0, tr("Info"), message);
		return;
	}
	QString path = QFileDialog::getSaveFileName(0, tr("save data"), ".", tr("xyz files(*.xyz);;txt files(*.txt);;stl files(*.stl)")); 
	if(path.isEmpty())return;
	std::string filename=path.toStdString();
	//get file type
	char dott[]=".";
	int i=filename.size()-1;
	while(filename[i]!=dott[0]&&i>=0)i--;
	int L=filename.size()-i;
	char *filetype=new char[L];
	filetype[L-1]=0;
	int j=0;
	i=i+1;
	while(i<filename.size())
	{
		filetype[j]=filename[i];
		i++;
		j++;
	}
	std::string ft(filetype);
	if(ft=="txt"||ft=="xyz")
	{	
		vtkSmartPointer<vtkSimplePointsWriter> writer=vtkSimplePointsWriter::New();
		writer->SetFileName(filename.c_str());	
		writer->SetInputData(instance->getSelectedData());
		writer->Write();
		writer->Delete();
	}
	if(ft=="stl")
	{
		vtkSmartPointer<vtkSTLWriter> stlWriter =
		vtkSmartPointer<vtkSTLWriter>::New();
		stlWriter->SetFileName(filename.c_str());
		stlWriter->SetInputData(instance->getSelectedData());
		stlWriter->Write();
		//stlWriter->Delete();
	}
	delete filetype;
	//inform the selecter to reselecte
	instance->requireReselect();
}
//the reaction of deleteSelectedPart
void selectToolBarImple::deleteSlectedPartSlot()
{
	selectSurfacePointUsePoly*instance=selectSurfacePointUsePoly::getInstance();
	if(instance->isSelecteEmpty())
	{
		QString message=QString::fromStdString("Your selection is empty, please select again!");
		QMessageBox::information(0, tr("Info"), message);
		return;
	}
	vtkPolyData*datasource=instance->getDataSelectedFrom();
	//dataVector is empty before first delete action, create a copy of source data and push it in datavector
	actorManagerClass*actorSturct=actorManagerClass::getInstance();
	//set data state vector for selecter 
	std::vector<vtkPolyData*>*dataVector=actorSturct->getCurrentActor()->getDataStateVector();
	//get current state
	undoAndRedoCount=actorSturct->getCurrentActor()->getCurrentState();

	if(dataVector->size()==0)
	{
		tempOfSourceData=vtkPolyData::New();
		tempOfSourceData->ShallowCopy(datasource);
		actorSturct->getCurrentActor()->addSate(tempOfSourceData);
		//dataVector->push_back(tempOfSourceData);
	}
	//get selected ids
	vtkIdTypeArray* deleteIds=instance->getSelectedIds();
	//get number of selected ids
	int numberOfIds=deleteIds->GetNumberOfTuples();
	//if()
	//new a vtkPoints object
	vtkSmartPointer<vtkPoints> newPoints = vtkSmartPointer<vtkPoints>::New();
	double p[3];   
	//delete points
	for(int i=0,j=0;i<datasource->GetNumberOfPoints();i++)
	{
		if(j<numberOfIds&&i==deleteIds->GetValue(j)){j++;}
		else 
		{
			datasource->GetPoint(i,p);
			newPoints->InsertNextPoint(p);
		}
	}
	temp->SetPoints(newPoints);
#if VTK_MAJOR_VERSION <= 5
  vertexFilter->SetInputConnection(temp->GetProducerPort());
#else
  vertexFilter->SetInputData(temp);
#endif
	vertexFilter->Update();
	//new a tempOfSourceData object 
	tempOfSourceData=vtkPolyData::New();
	//cpoy the result to tempOfSourceData
	tempOfSourceData->ShallowCopy(vertexFilter->GetOutput());
	//push back tempOfSourceData to data vector
	actorSturct->getCurrentActor()->addSate(tempOfSourceData);
	//update the datasource to deleted stae
	datasource->ShallowCopy(vertexFilter->GetOutput());
	//delete the selected part actor in selectSurfacePointUsePoly
	instance->removeActor();
	//inform the selecter to reselecte
	instance->requireReselect();
	//update the display window
	instance->display();
	//emit(setRedoEnabled(true));
	emit(setUndoEnabled(true));
}
