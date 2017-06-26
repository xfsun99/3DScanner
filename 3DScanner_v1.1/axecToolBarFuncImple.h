#ifndef _axecToolBarFuncImple_H
#define _axecToolBarFuncImple_H
#include <QObject>
#include <QAction>
#include "ui_AxesToolbar.h"
class axecToolBarFuncImple:public QObject
{
	Q_OBJECT
public:
	axecToolBarFuncImple(Ui::axesToolbar*toolBar);
	~axecToolBarFuncImple();
	private slots:
		void hideShowOrientationAxes();
		void hideShowCenter();
		void pickedCenter();
};

#endif