#include "LoadDataReaction.h"
#include "actorManagerClass.h"
#include <vtkSmartPointer.h>
#include <vtkSimplePointsReader.h>

LoadDataReaction::LoadDataReaction(QAction* action)
{
	connect(action,SIGNAL(triggered()),this,SLOT(loadDataSlot()));
}
LoadDataReaction::~LoadDataReaction()
{

}
//slot reaction of LoadData action
void LoadDataReaction::loadDataSlot()
{
	QString path = QFileDialog::getOpenFileName(0, tr("load data"), ".", tr("3D Files(*.xyz *.txt)")); 
	if(path.isEmpty())return;
	std::string filename=path.toStdString();
	//path.
	vtkSmartPointer<vtkSimplePointsReader> reader = vtkSmartPointer<vtkSimplePointsReader>::New();
	reader->SetFileName (filename.c_str());
	reader->Update();
	if(reader->GetOutput()->GetNumberOfPoints()<=0)
	{
		QString message=QString::fromStdString("Can't open file or file selected is empty, please select a new file!");
		QMessageBox::warning(0, tr("error"), message);		
		return;
	}
	//get the opened file name
	char dott[]="./";
	int i=filename.size()-1;
	while(filename[i]!=dott[0]&&i>=0)i--;
	int j=i;
	while(filename[j]!=dott[1]&&j>=0)j--;
	char *actorname=new char[i-j];
	actorname[i-j-1]=0;
	i--;
	j++;
	while(j<=i)
	{
		actorname[i-j]=filename[i];
		i--;
	}
	std::string actorName(actorname);
	delete actorname;
	//new a actor object 
	actor* newActor=new actor;
	newActor->setActorName(actorName);
	newActor->getPolyData()->ShallowCopy(reader->GetOutput());
	actorManagerClass*actorManager=actorManagerClass::getInstance();
	actorManager->addActor(newActor);
}