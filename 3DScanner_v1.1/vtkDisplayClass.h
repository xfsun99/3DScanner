#ifndef _vtkDisplayClass_H
#define _vtkDisplayClass_H
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkActor.h>
#include <vtkSmartPointer.h>
#include <vector>
#include "actorManagerClass.h"
#include "actor.h"
#include <vtkRenderWindowInteractor.h>
#include <QObject>
#include <QtWidgets/QWidget>
class vtkDisplayClass:public QObject
{
	Q_OBJECT
signals:
	void actorAddSignal();
public slots:
	void display();
public:
	//get the static instance
	static vtkDisplayClass*					getInstance();
	//get render
	static vtkSmartPointer<vtkRenderer>		getRender();
	//get get renderWindow
	static vtkSmartPointer<vtkRenderWindow>	getRenderWindow();
	//set renderWindow
	static void								setRenderWindow(vtkSmartPointer<vtkRenderWindow> win);
	//add vtkActor* type actor to display class
	void									addActorToRender(vtkSmartPointer<vtkActor>);
	//get Interactor in the renderWindow
	vtkSmartPointer<vtkRenderWindowInteractor> getInteractor()const;
	//QmainWindow pointer
	QWidget* Qwindow;
	//dieconstruct function
	~vtkDisplayClass();
private:
	//private ststic instance
	static vtkDisplayClass* Instance;
	//construct function
	vtkDisplayClass();
	//static render pointer
	static vtkSmartPointer<vtkRenderer> Render;
	//static renderwindow pointer
	static vtkSmartPointer<vtkRenderWindow> RenderWindow;
};

#endif