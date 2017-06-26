#include "actorManagerClass.h"
actorManagerClass* actorManagerClass::Instance=NULL;
actorManagerClass* actorManagerClass::getInstance()
{
	if(Instance==NULL)
	{
		Instance=new actorManagerClass;
	}
	return Instance;
}
actorManagerClass::actorManagerClass()
{
	Instance=this;
	actorNumCount=0;
	currentActor=NULL;
	vtkDisplayClass* Instance=vtkDisplayClass::getInstance();
	connect(Instance,SIGNAL(actorAddSignal()),this,SLOT(addActorSlot()));
}
actorManagerClass::~actorManagerClass()
{
	delete Instance;
}
vtkSmartPointer<vtkActor> actorManagerClass::getSelectActor() const
{
	return selectActor;
}
//add actor struct
void actorManagerClass::addActor(actor*m_actor)
{
	actorVector.push_back(m_actor);
	vtkDisplayClass *instance=vtkDisplayClass::getInstance();
	instance->addActorToRender(m_actor->getActor());
	//sent signal to ActorManagerDockWidget.
	emit  addActorSignal(m_actor->getActorName());
}
//slot
void actorManagerClass::addActorSlot()
{
}
//slot
void actorManagerClass::selectActorSlot(QModelIndex id)
{
	//set select actor for render
	selectActor=actorVector[id.row()]->getActor();
	//set current actor
	currentActor=actorVector[id.row()];
	currentActor->actorSate.isSelected=true;
	//sent signal to PropertiesWidget and selecToolBar to change the state of buttons 
	emit actorIsValid(true);
}
actor* actorManagerClass::getCurrentActor()const
{
	//return actor* type actor struct
	return currentActor;
}
//slot
void actorManagerClass::setActorColor()
{
	QColor color = QColorDialog::getColor(Qt::white,0); 
	double r=color.red()/255.0;
	double g=color.green()/255.0;
	double b=color.blue()/255.0;
	selectActor->GetProperty()->SetColor(r,g,b);
	display();
}
//slot
void actorManagerClass::setActorPointSize(int size=2)
{
	selectActor->GetProperty()->SetPointSize(size);
	display();
}
//slot
void actorManagerClass::setActorOpacity(double value=1)
{
	selectActor->GetProperty()->SetOpacity(value);
	display();
}
//slot
void actorManagerClass::setVisable(int value)
{
	selectActor->SetVisibility(value);
	display();
	bool state=(value>0);
	emit visableStateChange(state);
}
void actorManagerClass::display()
{
	vtkDisplayClass::getRenderWindow()->Render();
}
