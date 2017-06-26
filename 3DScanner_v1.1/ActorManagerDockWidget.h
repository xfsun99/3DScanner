#ifndef _ActorManagerDockWidget_H
#define _ActorManagerDockWidget_H
#include "ui_ActorManagerDockWidget.h"
#include <QObject>
#include <QtWidgets>
class ActorManagerDockWidget:public QObject
{
	Q_OBJECT
public:
	ActorManagerDockWidget(QWidget*widget);
	~ActorManagerDockWidget();
signals:
	void deleteList(QModelIndex id);
private slots:
	void addListSlot(std::string listname);
	void changeItemSteteSlot(QListWidgetItem*);
	void testSlot();
	void setItemInVisableState(bool state);
private:
	Ui::ActorManagerDockWidget ui;

	QListWidgetItem* currentItem;

	QList<QListWidgetItem*>itemList;
	void setItemNormalState(QListWidgetItem * item);
	void setItemSelectedState(QListWidgetItem * item);
	
};
#endif