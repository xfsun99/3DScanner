#include "UiStateManager.h"
#include "actorManagerClass.h"
#include "selectSurfacePointUsePoly.h"
UiStateManager*UiStateManager::Instance=NULL;

UiStateManager::UiStateManager()
{
	Instance=this;
	//update ui state
	actorManagerClass*instance=actorManagerClass::getInstance();
	connect(instance,SIGNAL(actorIsValid(bool)),this,SLOT(uiRedoUndoStateUpdateSlot(bool)));

}
UiStateManager::~UiStateManager()
{
}
UiStateManager*UiStateManager::getInstance()
{
	if(Instance==NULL)
	{
		Instance=new UiStateManager;
	}
	return Instance;
}
//Redo and Undo State Control
void UiStateManager::setRedoEnabledSlot(bool state)
{
	emit setRedoEnabledSignal(state);
}
void UiStateManager::setUndoEnabledSlot(bool state)
{
	emit setUndoEnabledSignal(state);
}
void UiStateManager::RedoActionTriggeredSlot()
{
	actorManagerClass*actorSturct=actorManagerClass::getInstance();
	std::vector<vtkPolyData*>*dataVector=actorSturct->getCurrentActor()->getDataStateVector();
	int *undoAndRedoCount=actorSturct->getCurrentActor()->getCurrentState();
	if(*undoAndRedoCount<dataVector->size()-1)
	{	
		(*undoAndRedoCount)++;
		selectSurfacePointUsePoly*instance=selectSurfacePointUsePoly::getInstance();
		//get current data
		vtkPolyData*currentDate=actorSturct->getCurrentActor()->getPolyData();
		//change current data
		currentDate->ShallowCopy(dataVector->at(*undoAndRedoCount));
		//update display window
		instance->display();
		emit(setUndoEnabledSignal(true));
		if(*undoAndRedoCount==dataVector->size()-1)
		{
			emit(setRedoEnabledSignal(false));
		}
	}
}
void UiStateManager::UndoActionTriggeredSlot()
{
	actorManagerClass*actorSturct=actorManagerClass::getInstance();
	std::vector<vtkPolyData*>*dataVector=actorSturct->getCurrentActor()->getDataStateVector();
	int *undoAndRedoCount=actorSturct->getCurrentActor()->getCurrentState();
	if(*undoAndRedoCount>0)
	{
		(*undoAndRedoCount)--;
		//get current data
		vtkPolyData*currentDate=actorSturct->getCurrentActor()->getPolyData();
		//change current data
		currentDate->ShallowCopy(dataVector->at(*undoAndRedoCount));
		//update display window
		actorSturct->display();
		emit(setRedoEnabledSignal(true));
		if(*undoAndRedoCount==0)
		{
			emit(setUndoEnabledSignal(false));
		}
	}
}
void UiStateManager::uiRedoUndoStateUpdateSlot(bool)
{	
	actorManagerClass*actorSturct=actorManagerClass::getInstance();
	//set data state vector for selecter 
	std::vector<vtkPolyData*>*dataVector=actorSturct->getCurrentActor()->getDataStateVector();
	//get current state
	int *undoAndRedoCount=actorSturct->getCurrentActor()->getCurrentState();
	if(dataVector->size()==0)
	{
		emit(setRedoEnabledSignal(false));
		emit(setUndoEnabledSignal(false));
	}
	else if(*undoAndRedoCount&&*undoAndRedoCount<dataVector->size()-1)
	{
		emit(setRedoEnabledSignal(true));
		emit(setUndoEnabledSignal(true));
	}
	else if(*undoAndRedoCount==0&&*undoAndRedoCount<dataVector->size()-1)
	{
		emit(setRedoEnabledSignal(true));
		emit(setUndoEnabledSignal(false));
	}
	else
	{
		emit(setRedoEnabledSignal(false));
		emit(setUndoEnabledSignal(true));
	}
}

