#include "vtkDisplayClass.h"
#include "selectSurfacePointUsePoly.h"
vtkDisplayClass*vtkDisplayClass::Instance=NULL;
vtkSmartPointer<vtkRenderer> vtkDisplayClass::Render=NULL;
vtkSmartPointer<vtkRenderWindow> vtkDisplayClass::RenderWindow=NULL;

vtkDisplayClass*vtkDisplayClass::getInstance()
{
	if(Instance==NULL)
	{
		Instance=new vtkDisplayClass();
	}
	return Instance;
}
vtkDisplayClass::vtkDisplayClass()
{
	Instance=this;
	Render=vtkRenderer::New();
}
vtkDisplayClass::~vtkDisplayClass()
{
	delete Instance;
}
vtkSmartPointer<vtkRenderer> vtkDisplayClass::getRender()
{
	return Render;
}
vtkSmartPointer<vtkRenderWindow>vtkDisplayClass::getRenderWindow()
{
	return RenderWindow;
}
void vtkDisplayClass::display()
{
	Render->ResetCamera();
	RenderWindow->Render();
}
//get Interactor
vtkSmartPointer<vtkRenderWindowInteractor> vtkDisplayClass::getInteractor()const
{
	if(RenderWindow!=NULL)
		return RenderWindow->GetInteractor();
	return NULL;
}
//set renderWindow
void vtkDisplayClass::setRenderWindow(vtkSmartPointer<vtkRenderWindow> win)
{
	RenderWindow=win;
	RenderWindow->AddRenderer(Render);

}
//add vtkActor* type actor to Render to display
void vtkDisplayClass::addActorToRender(vtkSmartPointer<vtkActor> actor)
{
	Render->AddActor(actor);
	display();
}