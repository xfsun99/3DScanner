#ifndef _normalInteractorStyle_H
#define _normalInteractorStyle_H


#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkRenderWindowInteractor.h>
class normalInteractorStyle:public vtkInteractorStyleTrackballCamera
{
public:
	static normalInteractorStyle*getInstance();
private:
	static normalInteractorStyle* Instance;
	normalInteractorStyle();
};
#endif