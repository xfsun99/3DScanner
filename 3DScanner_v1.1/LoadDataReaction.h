#ifndef _LoadDataReaction_H
#define _LoadDataReaction_H
#include <QObject>
#include <QAction>


class LoadDataReaction:public QObject
{
	Q_OBJECT
public:
	LoadDataReaction(QAction* action);
	~LoadDataReaction();
private slots:
	void loadDataSlot();
};

#endif