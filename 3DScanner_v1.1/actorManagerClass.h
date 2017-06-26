#ifndef _actorManagerClass_H
#define _actorManagerClass_H
#include <QObject>
#include <QtWidgets>
#include "vtkDisplayClass.h"
#include <vtkProperty.h>
#include "actor.h"
class actorManagerClass:public QObject
{
	Q_OBJECT
public:
	static actorManagerClass*getInstance();
	~actorManagerClass();
	//return vtkActor* type actor 
	vtkSmartPointer<vtkActor> getSelectActor() const;
	//add actor* type actor struct
	void addActor(actor*m_actor);
	//return actor* type actor struct
	actor* getCurrentActor()const;
	//update window
	void display();
signals:
	void actorIsValid(bool);
	void addActorSignal(std::string actorName);
	void visableStateChange(bool);
public slots:
		void addActorSlot();
		void selectActorSlot(QModelIndex id);
		void setActorColor();
		void setActorPointSize(int);
		void setActorOpacity(double value);
		void setVisable(int);
private:
	std::vector<actor*> actorVector;
	actorManagerClass();
	int actorNumCount;
	static actorManagerClass* Instance;
	vtkSmartPointer<vtkActor> selectActor;
	actor* currentActor;
};
#endif