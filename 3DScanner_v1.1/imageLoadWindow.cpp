#include "imageLoadWindow.h"
#include "OpenCVPreprocessClass.h"
std::string *imageLoadWindow::leftImgPath=NULL;
std::string *imageLoadWindow::rightImgPath=NULL;
imageLoadWindow*imageLoadWindow::Instance=NULL;

imageLoadWindow*imageLoadWindow::GetInstance()
{
	if(Instance==NULL)
	{
		Instance=new imageLoadWindow;
	}
	return Instance;
}
imageLoadWindow::imageLoadWindow()
{
	ui.setupUi(this);
	Instance=this;
	sceneRight=new QGraphicsScene;
	sceneLeft=new QGraphicsScene;
	leftImgPath=new std::string;
	rightImgPath=new std::string;
	connect(ui.pushButtonLoadLeftImg,SIGNAL(clicked()),this,SLOT(LoadLeftImage()));
	connect(ui.pushButtonLoadRightImg,SIGNAL(clicked()),this,SLOT(LoadRightImage()));
	connect(this,SIGNAL(getLRImagePath()),this,SLOT(LRImagePathGot()));
}
imageLoadWindow::~imageLoadWindow()
{
	delete sceneLeft;
	sceneLeft=NULL;
	delete sceneRight;
	sceneRight=NULL;
	delete leftImgPath;
	leftImgPath=NULL;
	delete rightImgPath;
	rightImgPath=NULL;
}
std::string* imageLoadWindow::getLeftImgPath()
{
	return leftImgPath;
}
std::string* imageLoadWindow::getRightImgPath()
{
	return rightImgPath;
}
void imageLoadWindow::LoadLeftImage()
{
	QString path = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg *.png *.bmp)")); 
	if(path.length() == 0) 
	{
		QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files.")); 
	 } 
	else 
	{ 
		pixLeft.load(path);	
		if(pixLeft.isNull())
		{
			QMessageBox::information(NULL, tr("error"), tr("Can not open ") + path);
			return;
		}
		QPixmap pixLeft1=pixLeft.scaledToWidth(ui.graphicsViewLeftImg->width()-5);
		delete sceneLeft;
		sceneLeft=new QGraphicsScene;
		sceneLeft->addPixmap(pixLeft1);
		ui.graphicsViewLeftImg->setScene(sceneLeft);
		ui.graphicsViewLeftImg->update();
		ui.graphicsViewLeftImg->show();
		if(pixRight.isNull()==false)
		{
			if(pixLeft.size()!=pixRight.size())
			{
				QMessageBox::information(NULL, tr("error"), tr("Left and right image are different in size!"));
				return;
			}
			*leftImgPath=path.toStdString();
			emit getLRImagePath();
		}
		*leftImgPath=path.toStdString();
	} 
}
void imageLoadWindow::LoadRightImage()
{
	QString path = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg *.png *.bmp)")); 
	if(path.length() == 0) 
	{
		QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files.")); 
	 } 
	else 
	{ 
		pixRight.load(path);
		if(pixRight.isNull())
		{
			QMessageBox::information(NULL, tr("error"), tr("Can not open ") + path);
			return;
		}
		QPixmap pixRight1=pixRight.scaledToWidth(ui.graphicsViewRightImg->width()-5);
		delete sceneRight;
		sceneRight=new QGraphicsScene;
		sceneRight->addPixmap(pixRight1);
		ui.graphicsViewRightImg->setScene(sceneRight);
		ui.graphicsViewRightImg->update();
		ui.graphicsViewRightImg->show();
		if(pixLeft.isNull()==false)
		{
			if(pixLeft.size()!=pixRight.size())
			{
				QMessageBox::information(NULL, tr("error"), tr("Left and right image are different in size!"));
				return;
			}
			*rightImgPath=path.toStdString();
			emit getLRImagePath();
		}
		*rightImgPath=path.toStdString();
	} 
}
void imageLoadWindow::LRImagePathGot()
{
	OpenCVPreprocessClass* cvPreProcessInstance=OpenCVPreprocessClass::GetInstance();
	cvPreProcessInstance->LoadLeftImg(*leftImgPath);
	cvPreProcessInstance->LoadRightImg(*rightImgPath);
}
void imageLoadWindow::paintEvent(QPaintEvent *event)
{
}
void imageLoadWindow::resizeEvent(QResizeEvent*event)
{
	QPixmap pixLeft1=pixLeft.scaledToWidth(ui.graphicsViewLeftImg->width()-5);
	delete sceneLeft;
	sceneLeft=new QGraphicsScene;
	sceneLeft->addPixmap(pixLeft1);
	ui.graphicsViewLeftImg->setScene(sceneLeft);
	ui.graphicsViewLeftImg->update();
	ui.graphicsViewLeftImg->show();

	QPixmap pixRight1=pixRight.scaledToWidth(ui.graphicsViewRightImg->width()-5);
	delete sceneRight;
	sceneRight=new QGraphicsScene;
	sceneRight->addPixmap(pixRight1);
	//ui.graphicsViewRightImg->resize(pixRight1.width(),pixRight1.height());
	ui.graphicsViewRightImg->setScene(sceneRight);
	ui.graphicsViewRightImg->update();
	ui.graphicsViewRightImg->show();
}