#ifndef _changeColor_H
#define _changeColor_H
#include <QObject>
#include <QAction>
class changeColor:public QObject
{
	Q_OBJECT
public:
	static QColor getQColor();
	changeColor(QAction* action);
	~changeColor();
	private slots:
		void setRenderBackground();
private:
	static QColor color;
};

#endif