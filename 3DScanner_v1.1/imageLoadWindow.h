#ifndef _imageWindoe_H
#define _imageWindoe_H
#include "ui_imageLoadWindow.h"
#include <QtWidgets>
class imageLoadWindow:public QMainWindow
{
	Q_OBJECT
public:
	static imageLoadWindow*GetInstance();
	~imageLoadWindow();
	static	std::string* getLeftImgPath();
	static	std::string* getRightImgPath();

signals:
	void getLRImagePath();

public slots:
	void LoadLeftImage();
	void LoadRightImage();

	void LRImagePathGot();

	void paintEvent(QPaintEvent *event);
	void resizeEvent(QResizeEvent*event);

private:
	imageLoadWindow();
	static imageLoadWindow*Instance;
	Ui::imageLoadWindow		ui;
	QPixmap pixLeft;
	QPixmap pixRight;
	QGraphicsScene *sceneLeft;
	QGraphicsScene *sceneRight;
	static std::string *leftImgPath;
	static std::string *rightImgPath;
};

#endif
