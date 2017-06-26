#ifndef _LoadImages_H
#define _LoadImages_H
#include <QObject>
#include <QAction>
#include "imageLoadWindow.h"

class LoadImages:public QObject
{
	Q_OBJECT
public:
	LoadImages(QAction* action);
	~LoadImages();
private:
private slots:
	void loadImageWiondowOpen();
};

#endif
