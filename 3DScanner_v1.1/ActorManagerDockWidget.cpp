#include "ActorManagerDockWidget.h"
#include "actorManagerClass.h"
ActorManagerDockWidget::ActorManagerDockWidget(QWidget*widget)
{
	ui.setupUi(widget);
	actorManagerClass* instance=actorManagerClass::getInstance();
	//select actor
	//add actor
	connect(instance,SIGNAL(addActorSignal(std::string)),this,SLOT(addListSlot(std::string)));
	//
	//
	connect(ui.listWidget,SIGNAL(clicked(QModelIndex)),instance,SLOT(selectActorSlot(QModelIndex)));
	//
	connect(ui.listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(changeItemSteteSlot(QListWidgetItem*)));
	//c
	connect(instance,SIGNAL(visableStateChange(bool)),this,SLOT(setItemInVisableState(bool)));
}
ActorManagerDockWidget::~ActorManagerDockWidget()
{
}
//
void ActorManagerDockWidget::changeItemSteteSlot(QListWidgetItem*item)
{
	currentItem=item;
	for(int i=0;i<itemList.size();i++)
	{
		if(item==itemList[i])
		{
			setItemSelectedState(item);
		}
		else
		{
			setItemNormalState(itemList[i]);
		}
	}
}
//slot
void ActorManagerDockWidget::addListSlot(std::string listname)
{
	QString stringTemp=QString::fromStdString(listname);
	QListWidgetItem*it=new QListWidgetItem;
	it->setText(stringTemp);
	ui.listWidget->addItem(it);
	itemList.push_back(it);

	QFont f;
	f.setBold(true);
	it->setFont(f);
}
//
void ActorManagerDockWidget::testSlot()
{
}
void ActorManagerDockWidget::setItemSelectedState(QListWidgetItem * item)
{
	QColor backcolor(85,170,255,255);
	item->setBackgroundColor(backcolor);
	QColor textcolor(255,255,255,255);
	item->setTextColor(textcolor);
}
void ActorManagerDockWidget::setItemNormalState(QListWidgetItem * item)
{
	QColor backcolor(255,255,255,255);
	item->setBackgroundColor(backcolor);
	QColor textcolor(0,0,0,255);
	item->setTextColor(textcolor);
}
void ActorManagerDockWidget::setItemInVisableState(bool state)
{
	//change item text font
	QFont f;
	f.setBold(state);
	currentItem->setFont(f);
}