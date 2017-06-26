#include "SaveDataReaction.h"
#include "actorManagerClass.h"

SaveDataReaction::SaveDataReaction(QAction* action)
{
	m_action=action;
	sampleWriter=vtkSmartPointer<vtkSimplePointsWriter>::New();
	stlWriter =	vtkSmartPointer<vtkSTLWriter>::New();
	//save data action
	connect(action,SIGNAL(triggered()),this,SLOT(saveData()));
	//
	actorManagerClass*actorManager=actorManagerClass::getInstance();
	connect(actorManager,SIGNAL(actorIsValid(bool)),this,SLOT(setActionEnable(bool)));
}
SaveDataReaction::~SaveDataReaction()
{
	sampleWriter->Delete();
}
//slot
void SaveDataReaction::saveData()
{
	QString path = QFileDialog::getSaveFileName(0, tr("save data"), ".", tr("xyz files(*.xyz);;txt files(*.txt);;stl files(*.stl)")); 
	if(path.isEmpty())return;
	std::string filename=path.toStdString();
	//get the file type
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
		saveSampleData(filename);
		delete filetype;
	}
	else if(ft=="stl")
	{
		savestlData(filename);
		delete filetype;
	}
	else 
		delete filetype;
		return;
}
//slot
void SaveDataReaction::setActionEnable(bool state)
{
	m_action->setEnabled(state);
}
void SaveDataReaction::savestlData(std::string filename)
{
	stlWriter->SetFileName(filename.c_str());
	actorManagerClass*actorManager=actorManagerClass::getInstance();
	stlWriter->SetInputData(actorManager->getCurrentActor()->getPolyData());
	stlWriter->Write();
}
void SaveDataReaction::saveSampleData(std::string filename)
{
	actorManagerClass*actorManager=actorManagerClass::getInstance();
	sampleWriter->SetFileName(filename.c_str());	
	sampleWriter->SetInputData(actorManager->getCurrentActor()->getPolyData());
	sampleWriter->Write();
}