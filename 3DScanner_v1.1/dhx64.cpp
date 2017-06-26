#include "dhx64.h"
#include <QMessageBox>
#include <QStandardItemModel>
#include <QFont>
#include <QFileDialog>
static void ProcessData(BYTE *pImageBuf, BYTE *pImageRGBBuf,BYTE* m_pImgRaw8Buffer, 
				 int64_t nImageWidth, int64_t nImageHeight,int64_t m_nPixelFormat,int64_t m_nPixelColorFilter);
camera::camera()
{
}
camera::camera(QString devicename)
{
	deviceName=devicename;
	hDevice=NULL;
	deviceSate=CLOSE;
	deviceSate=STOP;
	needDisplay=false;
	imageInfo.Image=new Mat;
	imageInfo.grayImg=new Mat;
}
GX_DEV_HANDLE camera::getDevice()const
{
	return hDevice;
}
void camera::setDevice(GX_DEV_HANDLE hdevice)
{
	hDevice=hdevice;
}

QString camera::getDeviceName()const
{
	return deviceName;
}
bool camera::getDeviceSate()const
{
	return deviceSate;
}
void camera::setDeviceState(bool st)
{
	deviceSate=st;
}
int camera::getIndex()
{
	return 0;
}
camera::~camera()
{
}

Mat* dhx64::imL=NULL;
Mat* dhx64::imR=NULL;
dhx64* dhx64::instance=NULL;
dhx64* dhx64::getInstance()
{
	if(instance==NULL)
	{
		instance=new dhx64;
	}
	return instance;
}
dhx64::dhx64(QWidget *parent)
	: QMainWindow(parent)
{
	instance=this;

	serialport=NULL;

	count=0;
	imL=new Mat;
	imR=new Mat;
	ui.setupUi(this);
	InitializeDHX();
	onCheckSerialPort();
	readPath();

	connect(ui.listWidget,SIGNAL(itemClicked(QListWidgetItem * )),this,SLOT(itemclickedSlot(QListWidgetItem *)));
	//refresh device information
	connect(ui.actionReflashDeviceInfo,SIGNAL(triggered()),this,SLOT(refreshDeviceInfoSlot()));
	//connect 
	connect(ui.actionConnect,SIGNAL(triggered()),this,SLOT(onConnectActionSlot()));
	//disconnect
	connect(ui.actionDisconnect,SIGNAL(triggered()),this,SLOT(onDisconnectActionSlot()));
	//start action
	connect(ui.actionStart,SIGNAL(triggered()),this,SLOT(onStartActionSlot()));
	//stop action
	connect(ui.actionStop,SIGNAL(triggered()),this,SLOT(onStopActionSlot()));
	//ste gain
	connect(ui.spinBoxGain,SIGNAL(valueChanged(int)),this,SLOT(onGainAction()));
	//change trigger mode
	connect(ui.comboBox,SIGNAL(activated(int)),this,SLOT(onTriggerModeChageSLot(int)));
	//check serial port
	connect(ui.commandLinkButtonCheckport,SIGNAL(clicked()),this,SLOT(onCheckSerialPort()));
	//select serial port
	connect(ui.comboBoxSerialPort,SIGNAL(activated(int)),this,SLOT(onSelectedSerialport()));
	//open or close serial port
	connect(ui.commandLinkButtonOpenClose,SIGNAL(clicked()),this,SLOT(onOpenOrCloseSerialPort()));
	//catch image
	connect(ui.commandLinkButtonCatch,SIGNAL(clicked()),this,SLOT(onCatchImageActionSlot()));
	//read serial port
	connect(serialport,SIGNAL(readyRead()),this,SLOT(readSerialPort()));
	//save image
	connect(ui.actionSaveImage,SIGNAL(triggered()),this,SLOT(saveImageSlot()));
	//get corners
	connect(ui.commandLinkButtonSaveLRImg,SIGNAL(clicked()),this,SLOT(onSaveLRImages()));
	//load image in manual
	connect(ui.actionLoadLeftImg,SIGNAL(triggered()),this,SLOT(onLoadLeftImgManualActionSLot()));
	connect(ui.actionLoadRightImg,SIGNAL(triggered()),this,SLOT(onLoadRightImgManualActionSLot()));

}
void dhx64::readPath()
{
	FileStorage fs;
	string path;
	if(fs.open("Path.txt", FileStorage::READ))
	{
		fs["OpenPath"]>>openpath;
		fs["SavePath"]>>savepath;
	}
	fs.release();

}
void dhx64::writePath()
{
	FileStorage fsw("Path.txt", FileStorage::WRITE);
	fsw<<"OpenPath"<<openpath;
	fsw<<"SavePath"<<savepath;
	fsw.release();
}
void dhx64::InitializeDHX()
{
	status = GX_STATUS_SUCCESS;
   //在起始位置调用GXInitLib()进行初始化，申请资源
   status = GXInitLib();
   //refresh the device information after GXInitlize
   refreshDeviceInfoSlot();
}
dhx64::~dhx64()
{
	status = GXCloseLib();
}
void dhx64::onCheckSerialPort()
{
	INFO=new QList<QSerialPortInfo>;
	ui.comboBoxSerialPort->clear();
	*INFO=  QSerialPortInfo::availablePorts();	
	if(INFO->size()<1)
	{
		ui.commandLinkButtonOpenClose->setEnabled(false);
		return;
	}
	ui.commandLinkButtonOpenClose->setEnabled(true);
	for(int i=0;i<INFO->size();i++)
	{
		ui.comboBoxSerialPort->addItem(INFO->at(0).portName());
	}
	onSelectedSerialport();
}
void dhx64::onSelectedSerialport()
{
	if(serialport!=NULL)delete serialport;
	serialport=new QSerialPort(ui.comboBoxSerialPort->currentText(),this);
	serialport->setBaudRate(110);
}
void dhx64::onOpenOrCloseSerialPort()
{
	if(serialport->isOpen())
	{
		serialport->close();
		ui.commandLinkButtonOpenClose->setText("Open Serial Port");
		ui.commandLinkButtonCatch->setEnabled(false);
		return;
	}
	if(serialport->open(QIODevice::ReadWrite)==false)
	{
		QString message("Can not open serial port!");
		QMessageBox::warning(this, tr("Info"), message);
		ui.commandLinkButtonCatch->setEnabled(false);
		return;
	}
	ui.commandLinkButtonOpenClose->setText("Close Serial Port");
}
void dhx64::onCatchImageActionSlot()
{
	if(serialport!=NULL&&serialport->isOpen())
	{
		char dt=0;
		serialport->write(&dt,1);
		serialport->waitForReadyRead(10);
	}
	//for(int i=0;i<cameraList.size();i++)
	//{
	//	if(cameraList[i]->getDeviceSate()==OPEN)
	//	{
	//		GX_DEV_HANDLE hDevice=cameraList[i]->getDevice();
	//		GXSendCommand(hDevice, GX_COMMAND_ACQUISITION_START);
	//	}
	//}
}
void dhx64::onLoadLeftImgManualActionSLot()
{
	QString pathL = QFileDialog::getOpenFileName(this, tr("Load Left Image"),QString::fromStdString(openpath), tr("Image Files(*.jpg *.png *.bmp)")); 
	if(pathL.length() == 0) 
	{
		QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files.")); 
		return;
	 }
	openpath=pathL.toStdString();
	writePath();
	*imL= imread(openpath);
	if(imL->empty())return;
	diaplayImage();
}
void dhx64::onLoadRightImgManualActionSLot()
{
	QString pathR = QFileDialog::getOpenFileName(this, tr("Load Right Image"),QString::fromStdString(openpath), tr("Image Files(*.jpg *.png *.bmp)")); 
	if(pathR.length() == 0) 
	{
		QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files.")); 
		return;
	 } 
	openpath=pathR.toStdString();
	writePath();
	*imR= imread(openpath);
	if(imR->empty())return;
	diaplayImage();
}

void dhx64::readSerialPort()
{
	QByteArray data = serialport->readAll();
}
bool dhx64::deviceIsOpening(QString deviceName)
{
	for(int i=0;i<cameraList.size();i++)
	{
		if(cameraList[i]->getDeviceName()==deviceName&&cameraList[i]->getDeviceSate()==OPEN)
		{
			return true;
		}
	}
	return false;
}
void dhx64::OpenDivice(QString deviceName)
{
	for(int i=0;i<cameraList.size();i++)
	{
		if(cameraList[i]->getDeviceSate()==CLOSE&&cameraList[i]->getDeviceName()==deviceName)
		{
			GX_DEV_HANDLE hDevice = cameraList[i]->getDevice();
			int id=getCameraIndex(deviceName);
			if(id)
			{
				status = GXOpenDeviceByIndex(id, &hDevice);
				cameraList[i]->setDevice(hDevice);
				cameraList[i]->setDeviceState(OPEN);
				initialCamera(deviceName);
				return;
			}
		}
	}
}
void dhx64::CloseDevice(QString devicename)
{
	for(int i=0;i<cameraList.size();i++)
	{
		if(cameraList[i]->getDeviceSate()==OPEN&&cameraList[i]->getDeviceName()==devicename)
		{
			GX_DEV_HANDLE hDevice = cameraList[i]->getDevice();
			status = GXCloseDevice(hDevice);
			cameraList[i]->setDeviceState(CLOSE);
			//注销采集回调
			status = GXUnregisterCaptureCallback(hDevice);
			return;
		}
	}
}
void dhx64::initialCamera(QString devicename)
{
	camera* cameraToInitial=getACameraInList(devicename);
	if(cameraToInitial==NULL)
	{
		return;
	}
	GX_DEV_HANDLE hDevice =cameraToInitial->getDevice();
	//获取宽高
	status = GXGetInt(hDevice,GX_INT_WIDTH,&cameraToInitial->imageInfo.ImageWidth);
	status = GXGetInt(hDevice,GX_INT_HEIGHT,&cameraToInitial->imageInfo.ImageHeight);

	status = GXGetEnum(hDevice, GX_ENUM_PIXEL_FORMAT, &cameraToInitial->imageInfo.PixelFormat);

	//是否支持colorfilter
	status = GXGetEnum(hDevice, GX_ENUM_PIXEL_COLOR_FILTER, &cameraToInitial->imageInfo.PixelColorFilter);

	cameraToInitial->imageInfo.ImgRaw8Buffer=new BYTE[size_t(cameraToInitial->imageInfo.ImageWidth * cameraToInitial->imageInfo.ImageHeight)];

	cameraToInitial->imageInfo.ImgRGBBuffer=new BYTE[size_t(cameraToInitial->imageInfo.ImageWidth * cameraToInitial->imageInfo.ImageHeight*3)];

	cameraToInitial->imageInfo.Image->create(cameraToInitial->imageInfo.ImageHeight,cameraToInitial->imageInfo.ImageWidth,CV_8UC3);

	cameraToInitial->imageInfo.grayImg->create(cameraToInitial->imageInfo.ImageHeight,cameraToInitial->imageInfo.ImageWidth,CV_8UC1);
		
	//设置采集模式。一般相机的默认采集模式为连续模式。
	//SPEED_LEVEL
	status = GXGetInt(hDevice,GX_INT_ACQUISITION_SPEED_LEVEL,0);
	int64_t nAcqMode = GX_ACQ_MODE_SINGLE_FRAME;
	status = GXSetEnum(hDevice, GX_ENUM_ACQUISITION_MODE, nAcqMode);
	//设置连续自动白平衡
	status=GXSetEnum(hDevice,GX_ENUM_BALANCE_WHITE_AUTO,GX_BALANCE_WHITE_AUTO_CONTINUOUS);
	//注册图像处理回调函数
	if(getCameraIndex(cameraToInitial->getDeviceName())==1)
		status = GXRegisterCaptureCallback(hDevice, this, OnFrameCallbackFun_Left);
	else 
		status = GXRegisterCaptureCallback(hDevice, this, OnFrameCallbackFun_Right);
	////设置触发模式为OFF
	//status = GXSetEnum(hDevice, GX_ENUM_TRIGGER_MODE, GX_TRIGGER_MODE_ON);
 //   status = GXSetEnum(hDevice,GX_ENUM_TRIGGER_ACTIVATION,GX_TRIGGER_ACTIVATION_RISINGEDGE);
}
void dhx64::onSaveLRImages()
{
	QDir *temp = new QDir;
	bool exist = temp->exists(QString::fromStdString(saveImagePath));
	delete temp;
	if(exist==false)
	{
		QString fileName = QFileDialog::getExistingDirectory(this, tr("Open Directory"), ".", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
		if(fileName.isEmpty()==false)
		{
			saveImagePath=fileName.toStdString();
		}
	}
	if(cameraList.size()==2)
	{
		char cnt[2];
		sprintf(cnt,"%d",count);
		count++;
		string st=cnt;
		string Ln=saveImagePath+"/l"+st+".bmp";
		string Rn=saveImagePath+"/r"+st+".bmp";
		imwrite(Ln,*cameraList[0]->imageInfo.grayImg);
		imwrite(Rn,*cameraList[1]->imageInfo.grayImg);
	}
}
void dhx64::startCamera(QString devicename)
{
	camera* cameraToStart=getACameraInList(devicename);
	if(cameraToStart!=NULL)
	{
		GX_DEV_HANDLE hDevice =cameraToStart->getDevice();
		
		//发送开采命令
        if(GXSendCommand(hDevice, GX_COMMAND_ACQUISITION_START)==GX_STATUS_SUCCESS) 
		{
			cameraToStart->stopOrStartSate=START;
			ui.actionSaveImage->setEnabled(true);
			ui.commandLinkButtonCatch->setEnabled(true);
		}
		
	}

}
void dhx64::stopCamera(QString devicename)
{
	camera* cameraToStop=getACameraInList(devicename);

	if(cameraToStop!=NULL)
	{
		GX_DEV_HANDLE hDevice =cameraToStop->getDevice();
       //发送停采命令
		status = GXSendCommand(hDevice, GX_COMMAND_ACQUISITION_STOP);
		if(status==GX_STATUS_SUCCESS)
		{
			cameraToStop->stopOrStartSate=STOP;
			ui.commandLinkButtonCatch->setEnabled(false);
		}
	}
}
//slot set gain
void dhx64::onGainAction()
{
	camera*currentCamera=getACameraInList(selectedDeviceName);
	GX_DEV_HANDLE hDevice=currentCamera->getDevice();
	if(hDevice==NULL)return;
	status = GXSetEnum(hDevice, GX_ENUM_GAIN_SELECTOR, GX_GAIN_SELECTOR_ALL);
	int value=ui.spinBoxGain->value();
	status =GXSetInt(hDevice,GX_INT_GAIN,value);
}
//trigger mode change
void dhx64::onTriggerModeChageSLot(int triggermode)
{
	camera*currentCamera=getACameraInList(selectedDeviceName);
	GX_DEV_HANDLE hDevice=currentCamera->getDevice();
	if(hDevice==NULL)return;
	stopCamera(selectedDeviceName);
	if(triggermode==0)
	{
		status = GXSetEnum(hDevice, GX_ENUM_TRIGGER_MODE, GX_TRIGGER_MODE_OFF);
		int64_t nAcqMode = GX_ACQ_MODE_SINGLE_FRAME;
		status = GXSetEnum(hDevice, GX_ENUM_ACQUISITION_MODE, nAcqMode);
	}
	else
	{
			int64_t nAcqMode = GX_ACQ_MODE_CONTINUOUS;
	   status = GXSetEnum(hDevice, GX_ENUM_ACQUISITION_MODE, nAcqMode);

		//设置触发激活方式为上升沿
	   status = GXSetEnum(hDevice, GX_ENUM_TRIGGER_MODE, GX_TRIGGER_MODE_ON);
       status = GXSetEnum(hDevice,GX_ENUM_TRIGGER_ACTIVATION,GX_TRIGGER_ACTIVATION_RISINGEDGE);
	}
	startCamera(selectedDeviceName);
}

//slot
void dhx64::itemclickedSlot(QListWidgetItem * item)
{
	selecteditem=item;
	selectedDeviceName=selecteditem->text();
	camera* currentCamera=getACameraInList(selectedDeviceName);
	if(deviceIsOpening(selecteditem->text())==true)
	{
		ui.actionConnect->setDisabled(true);
		ui.actionDisconnect->setDisabled(false);
		if(currentCamera->stopOrStartSate==STOP)
		{
			ui.actionStart->setEnabled(true);
			ui.actionStop->setEnabled(false);
			ui.commandLinkButtonCatch->setEnabled(false);
		}
		else
		{
			ui.actionStart->setEnabled(false);
			ui.actionStop->setEnabled(true);
			ui.commandLinkButtonCatch->setEnabled(true);
		}
	}
	else
	{
		ui.actionConnect->setDisabled(false);
		ui.actionDisconnect->setDisabled(true);
		ui.actionStart->setEnabled(false);
		ui.actionStop->setEnabled(false);
		ui.commandLinkButtonCatch->setEnabled(false);
	}
	//set item to selected or unselected state
	reFreshItemStateInUi();	
	ui.groupBoxCamera->setEnabled(true);
}
//slot
void dhx64::refreshDeviceInfoSlot()
{
	uint32_t nDeviceNum = 0;
	status = GX_STATUS_SUCCESS;
	status = GXUpdateDeviceList(&nDeviceNum, 1000);
	
	if (status == GX_STATUS_SUCCESS && nDeviceNum > 0)
	{
		GX_DEVICE_BASE_INFO *baseinfo = new GX_DEVICE_BASE_INFO[nDeviceNum]; 

		uint64_t nSize = nDeviceNum * sizeof(GX_DEVICE_BASE_INFO);

		status = GXGetAllDeviceBaseInfo(baseinfo, &nSize);
		//add device name to list widget
		ui.listWidget->clear();
		QList<QString>DevicesNameTemp;
		QList<QListWidgetItem *>itemListTemp;
		for(int i=0;i<nDeviceNum;i++)
		{
			QString name(baseinfo[i].szDisplayName);
			DevicesNameTemp.push_back(name);
			QListWidgetItem*it=new QListWidgetItem;
			it->setText(name);
			//set item in opening state
			if(deviceIsOpening(name))
			{
				QFont f;
				f.setBold(true);
				it->font().setBold(true);
				it->setFont(f);
			}
			//record selected item
			if(name==selectedDeviceName)
			{
				selecteditem=it;
				setItemSelectedState(it);
			}
			ui.listWidget->addItem(it);
			itemListTemp.push_back(it);
		}
		DevicesName=DevicesNameTemp;
		itemList=itemListTemp;
		addCameraToList();
		delete []baseinfo;
	} 
	else
	{
		QString message("No device!");
		QMessageBox::information(this, tr("Info"), message);
		ui.groupBoxCamera->setEnabled(false);
	}
}
//slot
void dhx64::saveImageSlot()
{
	QString path = QFileDialog::getSaveFileName(0, tr("save data"), QString::fromStdString(savepath), tr("bmp files(*.bmp)")); 
	if(path.isEmpty())return;
	savepath=path.toStdString();
	writePath();
	camera*currentCamera=getACameraInList(selectedDeviceName);
	imwrite(savepath,*currentCamera->imageInfo.grayImg);
}
//slot
void dhx64::onConnectActionSlot()
{
	//get selected device name
	QString devicename=selecteditem->text();
	//open device
	OpenDivice(devicename);
	//set item in Opening state
	setItemInOpeningState(true);

	ui.actionStart->setEnabled(true);
}
//slot
void dhx64::onDisconnectActionSlot()
{
	//get selected device name
	QString devicename=selecteditem->text();
	//close device
	CloseDevice(devicename);
	//set item in closed state
	setItemInOpeningState(false);

	ui.actionStart->setEnabled(false);
	ui.actionStop->setEnabled(false);
}
//slot
void dhx64::onStartActionSlot()
{
	
	startCamera(selectedDeviceName);
	ui.actionStart->setEnabled(false);
	ui.actionStop->setEnabled(true);
}
//slot
void dhx64::onStopActionSlot()
{
	stopCamera(selectedDeviceName);
	ui.actionStart->setEnabled(true);
	ui.actionStop->setEnabled(false);
}

void dhx64::setItemSelectedState(QListWidgetItem * item)
{
	QColor backcolor(85,170,255,255);
	item->setBackgroundColor(backcolor);
	QColor textcolor(255,255,255,255);
	item->setTextColor(textcolor);
}
void dhx64::setItemNormalState(QListWidgetItem * item)
{
	QColor backcolor(255,255,255,255);
	item->setBackgroundColor(backcolor);
	QColor textcolor(0,0,0,255);
	item->setTextColor(textcolor);
}
void dhx64::setItemInOpeningState(bool state)
{
	//change item text font
	QFont f;
	f.setBold(state);
	selecteditem->setFont(f);
	ui.actionConnect->setDisabled(state);
	ui.actionDisconnect->setEnabled(state);
}
void dhx64::reFreshItemStateInUi()
{
	for(int i=0;i<itemList.size();i++)
	{
		if(selectedDeviceName==itemList[i]->text())
		{
			setItemSelectedState(itemList[i]);
		}
		else
			setItemNormalState(itemList[i]);
	}
}
void dhx64::addCameraToList()
{
	if(cameraList.size()==0)
	{
		for(int i=0;i<DevicesName.size();i++)
		{
			camera* newcamera=new camera(DevicesName[i]);
			cameraList.push_back(newcamera);
		}
		return;
	}
	QList<camera*>cameraListTemp;
	for(int i=0;i<DevicesName.size();i++)
	{
		int j=0;
		while(j<cameraList.size())
		{
			if(DevicesName[i]==cameraList[j]->getDeviceName())
			{
				cameraListTemp.push_back(cameraList[j]);
				break;
			}
			j++;
		}
		if(j==cameraList.size())
		{
			camera* newcamera=new camera(DevicesName[i]);
			cameraListTemp.push_back(newcamera);
		}
	}
	cameraList=cameraListTemp;
}
int dhx64::getCameraIndex(QString devicename)
{
	for(int i=0;i<DevicesName.size();i++)
	{
		if(devicename==DevicesName[i])
			return i+1;
	}
	return 0;
}
camera* dhx64::getACameraInList(QString devicename)
{
	for(int i=0;i<cameraList.size();i++)
	{
		if(cameraList[i]->getDeviceName()==devicename)
			return cameraList[i];
	}
	return NULL;
}
void dhx64::resizeEvent(QResizeEvent*event)
{
	diaplayImage();
}
void dhx64::displayLeftImage(Mat *img)
{
	imgL=QImage(img->data,img->cols,img->rows,QImage::Format::Format_RGB888);
	int h=ui.labelLeft->height();
	int w=ui.labelLeft->width();
	 QImage scaledImage=imgL.scaled(w,h,Qt::KeepAspectRatio);
	ui.labelLeft->setPixmap(QPixmap::fromImage(scaledImage));
	ui.labelLeft->show();
}
void dhx64::displayRightImage(Mat *img)
{
	imgR=QImage(img->data,img->cols,img->rows,QImage::Format::Format_RGB888);
	int h=ui.labelRight->height();
	int w=ui.labelRight->width();
	QImage scaledImage=imgR.scaled(w,h,Qt::KeepAspectRatio);
	ui.labelRight->setPixmap(QPixmap::fromImage(scaledImage));
	ui.labelRight->show();
	//ui.labelLeft->setPixmap(QPixmap::fromImage(scaledImage));
	//ui.labelRight->show();
}
void dhx64::diaplayImage()
{
	displayBusy=true;
	if(imL->empty()==false)
	{
		displayLeftImage(imL);
		if(cameraList.isEmpty()==false)
			cameraList[0]->needDisplay=false;
	}
	if(imR->empty()==false)
	{
		displayRightImage(imR);
		if(cameraList.size()>1)
			cameraList[1]->needDisplay=false;
	}
	displayBusy=false;
}

void __stdcall dhx64::OnFrameCallbackFun_Left(GX_FRAME_CALLBACK_PARAM* pFrame)
{
	if(pFrame->status!=0)
	{		
		return;
	}
	dhx64 *pf = (dhx64*)(pFrame->pUserParam);
	if(pf->displayBusy==true)return;
	camera* currentCamera=pf->getACameraInList(pf->DevicesName[0]);

	BYTE* m_pImgRGBBuffer=currentCamera->imageInfo.ImgRGBBuffer;
	BYTE* pImgRaw8Buffer=currentCamera->imageInfo.ImgRaw8Buffer;
	int64_t m_nImageWidth=currentCamera->imageInfo.ImageWidth;
	int64_t m_nImageHeight=currentCamera->imageInfo.ImageHeight;
	int64_t m_nPixelFormat=currentCamera->imageInfo.PixelFormat;
	int64_t nPixelColorFilter=currentCamera->imageInfo.PixelColorFilter;

    //对图像进行某些操作
	//首先将回调中输出的图像数据，处理成RGB数据，以备后面的显示和存储
	
	ProcessData((BYTE*)pFrame->pImgBuf, m_pImgRGBBuffer,pImgRaw8Buffer, m_nImageWidth, m_nImageHeight,m_nPixelFormat,nPixelColorFilter);
	pf->imL->create(m_nImageHeight,m_nImageWidth,CV_8UC3);
	//pf->imL->data=m_pImgRGBBuffer;
	currentCamera->imageInfo.Image->data=m_pImgRGBBuffer;
	pf->imL->data=currentCamera->imageInfo.Image->data;
	flip(*currentCamera->imageInfo.Image,*currentCamera->imageInfo.Image,0);
	cvtColor(*currentCamera->imageInfo.Image,*currentCamera->imageInfo.grayImg,CV_BGR2GRAY);
	currentCamera->needDisplay=true;
	for(int i=0;i<pf->cameraList.size();i++)
	{
		if(pf->cameraList[i]->needDisplay==false)
		{
			return;
		}
	}
	pf->diaplayImage();
	//pf->displayLeftImage(currentCamera);
   return;  
}
void __stdcall dhx64::OnFrameCallbackFun_Right(GX_FRAME_CALLBACK_PARAM* pFrame)
{
	if(pFrame->status!=0)
	{		
		return;
	}
	dhx64 *pf = (dhx64*)(pFrame->pUserParam);
	if(pf->displayBusy==true)return;
	camera* currentCamera=pf->getACameraInList(pf->DevicesName[1]);

	BYTE* m_pImgRGBBuffer=currentCamera->imageInfo.ImgRGBBuffer;
	BYTE* pImgRaw8Buffer=currentCamera->imageInfo.ImgRaw8Buffer;
	int64_t m_nImageWidth=currentCamera->imageInfo.ImageWidth;
	int64_t m_nImageHeight=currentCamera->imageInfo.ImageHeight;
	int64_t m_nPixelFormat=currentCamera->imageInfo.PixelFormat;
	int64_t nPixelColorFilter=currentCamera->imageInfo.PixelColorFilter;

    //对图像进行某些操作
	//首先将回调中输出的图像数据，处理成RGB数据，以备后面的显示和存储
	ProcessData((BYTE*)pFrame->pImgBuf, m_pImgRGBBuffer,pImgRaw8Buffer, m_nImageWidth, m_nImageHeight,m_nPixelFormat,nPixelColorFilter);
	pf->imR->create(m_nImageHeight,m_nImageWidth,CV_8UC3);	
	currentCamera->imageInfo.Image->data=m_pImgRGBBuffer;
	pf->imR->data=currentCamera->imageInfo.Image->data;
	flip(*currentCamera->imageInfo.Image,*currentCamera->imageInfo.Image,0);
	cvtColor(*currentCamera->imageInfo.Image,*currentCamera->imageInfo.grayImg,CV_BGR2GRAY);
	//imshow("imgR",*currentCamera->imageInfo.Image);
	//cvWaitKey(100);
	currentCamera->needDisplay=true;
	for(int i=0;i<pf->cameraList.size();i++)
	{
		if(pf->cameraList[i]->needDisplay==false)
		{
			return;
		}
	}
	pf->diaplayImage();

	//pf->displayRightImage(currentCamera);
   return;  

}
static void ProcessData(BYTE *pImageBuf, BYTE *pImageRGBBuf,BYTE* m_pImgRaw8Buffer, 
				 int64_t nImageWidth, int64_t nImageHeight,int64_t m_nPixelFormat,int64_t m_nPixelColorFilter)
{
	switch(m_nPixelFormat)
	{
		//当数据格式为12位时，位数转换为4-11
	case GX_PIXEL_FORMAT_BAYER_GR12:
	case GX_PIXEL_FORMAT_BAYER_RG12:
	case GX_PIXEL_FORMAT_BAYER_GB12:
	case GX_PIXEL_FORMAT_BAYER_BG12:
		//将12位格式的图像转换为8位格式
		DxRaw16toRaw8(pImageBuf, m_pImgRaw8Buffer, (VxUint32)nImageWidth, (VxUint32)nImageHeight, DX_BIT_4_11);	

		//将Raw8图像转换为RGB图像以供显示
		DxRaw8toRGB24(m_pImgRaw8Buffer,pImageRGBBuf, (VxUint32)nImageWidth, (VxUint32)nImageHeight, RAW2RGB_NEIGHBOUR,
		   	          DX_PIXEL_COLOR_FILTER(m_nPixelColorFilter), TRUE);		        
		break;
		
		//当数据格式为12位时，位数转换为2-9
	case GX_PIXEL_FORMAT_BAYER_GR10:
	case GX_PIXEL_FORMAT_BAYER_RG10:
	case GX_PIXEL_FORMAT_BAYER_GB10:
	case GX_PIXEL_FORMAT_BAYER_BG10:
		////将12位格式的图像转换为8位格式,有效位数2-9
		DxRaw16toRaw8(pImageBuf, m_pImgRaw8Buffer, (VxUint32)nImageWidth, (VxUint32)nImageHeight, DX_BIT_2_9);

		//将Raw8图像转换为RGB图像以供显示
		DxRaw8toRGB24(m_pImgRaw8Buffer, pImageRGBBuf, (VxUint32)nImageWidth, (VxUint32)nImageHeight, RAW2RGB_NEIGHBOUR,
			          DX_PIXEL_COLOR_FILTER(m_nPixelColorFilter), TRUE);	
		break;
		
	case GX_PIXEL_FORMAT_BAYER_GR8:
	case GX_PIXEL_FORMAT_BAYER_RG8:
	case GX_PIXEL_FORMAT_BAYER_GB8:
	case GX_PIXEL_FORMAT_BAYER_BG8:
		//将Raw8图像转换为RGB图像以供显示
		DxRaw8toRGB24(pImageBuf, pImageRGBBuf, (VxUint32)nImageWidth, (VxUint32)nImageHeight, RAW2RGB_NEIGHBOUR,
			          DX_PIXEL_COLOR_FILTER(m_nPixelColorFilter), TRUE);	
		break;
		
	case GX_PIXEL_FORMAT_MONO12:
		//将12位格式的图像转换为8位格式
		DxRaw16toRaw8(pImageBuf, m_pImgRaw8Buffer, (VxUint32)nImageWidth, (VxUint32)nImageHeight, DX_BIT_4_11);	

		//将Raw8图像转换为RGB图像以供显示
		DxRaw8toRGB24(m_pImgRaw8Buffer, pImageRGBBuf, (VxUint32)nImageWidth, (VxUint32)nImageHeight, RAW2RGB_NEIGHBOUR,
		   	          DX_PIXEL_COLOR_FILTER(NONE), TRUE);		        
		break;
		
	case GX_PIXEL_FORMAT_MONO10:
		//将10位格式的图像转换为8位格式
		DxRaw16toRaw8(pImageBuf, m_pImgRaw8Buffer, (VxUint32)nImageWidth, (VxUint32)nImageHeight, DX_BIT_4_11);	

		//将Raw8图像转换为RGB图像以供显示
		DxRaw8toRGB24(m_pImgRaw8Buffer, pImageRGBBuf, (VxUint32)nImageWidth, (VxUint32)nImageHeight, RAW2RGB_NEIGHBOUR,
			          DX_PIXEL_COLOR_FILTER(NONE), TRUE);		        
		break;
		
	case GX_PIXEL_FORMAT_MONO8:
		//将Raw8图像转换为RGB图像以供显示
		DxRaw8toRGB24(pImageBuf, pImageRGBBuf, (VxUint32)nImageWidth, (VxUint32)nImageHeight, RAW2RGB_NEIGHBOUR,
		          	  DX_PIXEL_COLOR_FILTER(NONE), TRUE);		        
		break;
		
	default:
		break;
	}
}
