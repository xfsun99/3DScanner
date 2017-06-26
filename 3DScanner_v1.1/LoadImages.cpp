#include "LoadImages.h"
#include "dhx64.h"
LoadImages::LoadImages(QAction*action)
{
	QObject::connect(action,SIGNAL(triggered()),this,SLOT(loadImageWiondowOpen()));
}
LoadImages::~LoadImages()
{
}
void LoadImages::loadImageWiondowOpen()
{
	imageLoadWindow*loadwindow=imageLoadWindow::GetInstance();
	dhx64 *loadImage=dhx64::getInstance();
	loadImage->show();
	//loadwindow->show();
}