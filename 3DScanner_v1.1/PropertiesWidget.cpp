#include "PropertiesWidget.h"
#include "actorManagerClass.h"
#define Visable 1
#define Hide    0
PropertiesWidget::PropertiesWidget(QWidget*widget)
{
	ui.setupUi(widget);
	Widget=widget;
	//Opacity
	connect(ui.horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(boxValueChangeSlot(int)));
	connect(ui.doubleSpinBox,SIGNAL(valueChanged(double)),this,SLOT(sliderMoveSlot(double)));
	//update properity ui state
	connect(actorManagerClass::getInstance(),SIGNAL(actorIsValid(bool)),this,SLOT(updateEnableState(bool)));
	//color
	connect(ui.toolButtonSetColor,SIGNAL(clicked()),actorManagerClass::getInstance(),SLOT(setActorColor()));
	//point size
	connect(ui.spinBox,SIGNAL(valueChanged(int)),actorManagerClass::getInstance(),SLOT(setActorPointSize(int)));
	//hide or visable
	connect(ui.commandLinkButtonVisable,SIGNAL(clicked()),this,SLOT(actorVisableState()));
}
PropertiesWidget::~PropertiesWidget()
{
}
//slot
void PropertiesWidget::boxValueChangeSlot(int v)
{
	ui.doubleSpinBox->setValue(v/100.0);
	actorManagerClass*instance=actorManagerClass::getInstance();
	instance->setActorOpacity(v/100.0);
}
//slot
void PropertiesWidget::sliderMoveSlot(double v)
{
	ui.horizontalSlider->setValue(v*100);
}
//slot
void PropertiesWidget::updateEnableState(bool state)
{
	Widget->setEnabled(true);
	actorManagerClass*instance=actorManagerClass::getInstance();
	double op=instance->getSelectActor()->GetProperty()->GetOpacity();
	int size=instance->getSelectActor()->GetProperty()->GetPointSize();
	sliderMoveSlot(op);
	ui.horizontalSlider_2->setValue(size);

	int isVisable;
	isVisable=instance->getSelectActor()->GetVisibility();
	if(isVisable==Visable)
	{
		ui.commandLinkButtonVisable->setText("Visable");
	}
	else
	{
		ui.commandLinkButtonVisable->setText("Hide");
	}
}
//slot
void PropertiesWidget::actorVisableState()
{
	int isVisable;
	actorManagerClass*instance=actorManagerClass::getInstance();
	isVisable=instance->getSelectActor()->GetVisibility();
	if(isVisable==Visable)
	{
		instance->setVisable(Hide);		
		ui.commandLinkButtonVisable->setText("Hide");
	}
	else
	{
		instance->setVisable(Visable);
		ui.commandLinkButtonVisable->setText("Visable");
	}
}