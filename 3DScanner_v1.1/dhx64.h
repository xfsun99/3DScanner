#ifndef DHX64_H
#define DHX64_H
#include "GxIAPI.h"
#include "DxImageProc.h"
#include <QtWidgets/QMainWindow>
#include "ui_dhx64.h"

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
//header for opencv
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include <opencv2\opencv.hpp>

using namespace cv;
#define OPEN true
#define CLOSE false
#define STOP false
#define START true
struct imageInfoStruct
{
	int64_t ImageWidth;
	int64_t ImageHeight;
	int64_t PixelFormat; 
	int64_t PixelColorFilter;
	BYTE*	ImgRaw8Buffer;
	IplImage*cvimage;
	BYTE*	ImgRGBBuffer;
	Mat *Image;
	Mat *grayImg;
};
class camera
{
public:
	camera();
	camera(QString devicename);
	GX_DEV_HANDLE getDevice()const;
	void setDevice(GX_DEV_HANDLE hdevice);
	QString getDeviceName()const;
	bool getDeviceSate()const;
	void setDeviceState(bool);
	int getIndex();
	~camera();
	imageInfoStruct imageInfo;
	bool stopOrStartSate;
	bool needDisplay;
private:
	GX_DEV_HANDLE hDevice;
	QString deviceName;
	bool deviceSate;
};

class dhx64 : public QMainWindow
{
	Q_OBJECT

public:
	static dhx64* getInstance();
	~dhx64();
	void InitializeDHX();

	static	void __stdcall OnFrameCallbackFun_Left(GX_FRAME_CALLBACK_PARAM* pFrame);
	static	void __stdcall OnFrameCallbackFun_Right(GX_FRAME_CALLBACK_PARAM* pFrame);
	static Mat *imL;
	static Mat *imR;

	private slots:
		void refreshDeviceInfoSlot();
		void saveImageSlot();
		void itemclickedSlot(QListWidgetItem*);
		void onConnectActionSlot();
		void onDisconnectActionSlot();
		void onStartActionSlot();
		void onStopActionSlot();
		void onGainAction();
		void onTriggerModeChageSLot(int);
		void onCheckSerialPort();
		void onOpenOrCloseSerialPort();
		void onSelectedSerialport();
		void onCatchImageActionSlot();
		void readSerialPort();
		void onSaveLRImages();
		void onLoadLeftImgManualActionSLot();
		void onLoadRightImgManualActionSLot();
		void resizeEvent(QResizeEvent*event);
			
private:

	static dhx64* instance;
	dhx64(QWidget *parent = 0);

	//check if the device is opening or closed
	bool deviceIsOpening(QString deviceName);
	//set item to selected state
	void setItemSelectedState(QListWidgetItem * selecteditem);
	//set item to unselected state
	void setItemNormalState(QListWidgetItem * selecteditem);
	//set item to selected state or unselected state 
	void reFreshItemStateInUi();
	//add a camera to cameraList
	void addCameraToList();
	//get camera in camera list
	camera* getACameraInList(QString devicename);
	//get camera index in device list
	int getCameraIndex(QString devicename);
	//open device
	void OpenDivice(QString deviceName);
	//Close device
	void CloseDevice(QString devicename);
	//set item to opening or closed state
	void setItemInOpeningState(bool);
	//initialize camera
	void initialCamera(QString devicename);
	//start
	void startCamera(QString devicename);
	//stop
	void stopCamera(QString devicename);
	//display left image
	void displayLeftImage(Mat *img);
	//display right image
	void displayRightImage(Mat *img);
	//display 
	void diaplayImage();
	//read path
	void readPath();
	//write path
	void writePath();

	bool displayBusy;
	int count;

	string openpath;
	string savepath;
	string saveImagePath;

	Ui::dhx64Class ui;
	GX_STATUS status;
	QList<QString>DevicesName;
	QList<QListWidgetItem *>itemList;
	QListWidgetItem * selecteditem;
	QString selectedDeviceName;
	QList<camera*>cameraList;

	QImage imgLtest;

	QImage imgL;
	QImage imgR;	


	Mat imtemp;
	QImage imgScaledL;
	QImage imgScaledR;
		
	QSerialPort* serialport;
	QList<QSerialPortInfo>*INFO;
};

#endif // DHX64_H
