#include "axecToolBarFuncImple.h"

axecToolBarFuncImple::axecToolBarFuncImple(Ui::axesToolbar*toolBar)
{
	connect(toolBar->actionShowOrientationAxes,SIGNAL(triggered()),this,SLOT(hideShowAxec()));
}
axecToolBarFuncImple::~axecToolBarFuncImple()
{

}
void axecToolBarFuncImple::hideShowOrientationAxes()
{

}

void axecToolBarFuncImple::hideShowCenter()
{
}

void axecToolBarFuncImple::pickedCenter()
{
}