#ifndef _PropertiesWidget_H
#define _PropertiesWidget_H
#include "ui_PropertiesDockWidget.h"
#include <QObject>
class PropertiesWidget:public QObject
{
	Q_OBJECT
public:
	PropertiesWidget(QWidget*widget);
	~PropertiesWidget();
	private slots:
		void boxValueChangeSlot(int);
		void sliderMoveSlot(double);
		void updateEnableState(bool state);
		void actorVisableState();
private:
	Ui::dockWidgetContentsProperty ui;
	QWidget*Widget;
};

#endif