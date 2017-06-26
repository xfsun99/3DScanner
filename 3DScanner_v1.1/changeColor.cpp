#include "changeColor.h"
#include <QtWidgets>
#include "vtkDisplayClass.h"
QColor changeColor::color=Qt::black;
changeColor::changeColor(QAction* action)
{
	connect(action,SIGNAL(triggered()),this,SLOT(setRenderBackground()));
}
changeColor::~changeColor()
{
}
void changeColor::setRenderBackground()
{
	color = QColorDialog::getColor(Qt::white,0); 
	double r=color.red()/255.0;
	double g=color.green()/255.0;
	double b=color.blue()/255.0;
	vtkDisplayClass::getRender()->SetBackground(r,g,b);
}