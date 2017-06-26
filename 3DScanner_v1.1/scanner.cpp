#include "scanner.h"
#include "MenuBuilders.h"
#include "vtkDisplayClass.h"
#include "actorManagerClass.h"
#include "PropertiesWidget.h"
#include "actorBuilder.h"
#include "ActorManagerDockWidget.h"
#include "dhx64.h"
//#include <vtkSMPropertyHelper.h>
scanner::scanner(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//Initialize display 
	vtkDisplayClass*displayInstance=vtkDisplayClass::getInstance();
	//Render window must be setted before selectSurfacePointUsePoly constructed
	displayInstance->setRenderWindow(ui.qvtkWidget->GetRenderWindow());
	displayInstance->Qwindow=this->window();
	//Menu builder
	MenuBuilder::buildFileMenu(*ui.menuFile);
	MenuBuilder::buildSettingMenu(*ui.menuSetting);
	MenuBuilder::buildToolbars(*this);
	//DockWidget builder
	new PropertiesWidget(ui.dockWidgetContentsProperty);
	new ActorManagerDockWidget(ui.dockWidgetContentsActorManager);
	//
	OpenCVPreprocessClass* cvPreProcessObject=OpenCVPreprocessClass::GetInstance();
	//
	OpenCLClass*clObject=OpenCLClass::GetInstance();
	//clObject->RunOpenCLInitialInDefault();
	clObject->getOpenCVPreprocessObject(cvPreProcessObject);

	//test button signal and slot connection
	connect(ui.pushButtonStereoReconstruct,SIGNAL(clicked()),this,SLOT(onStereoReconstruct()));

}
scanner::~scanner()
{
}
void scanner::onStereoReconstruct()
{
	setCursor(Qt::CursorShape::BusyCursor);
	OpenCVPreprocessClass* cvPreProcessObject=OpenCVPreprocessClass::GetInstance();
	dhx64* LoadLRImage=dhx64::getInstance();
	cvPreProcessObject->LoadLRImage(dhx64::imL,dhx64::imR);

	OpenCLClass*clObject=OpenCLClass::GetInstance();
	QString message=QString::fromStdString(clObject->RunOpenCLInDefault());

	QMessageBox::information(this, tr("Info"), message);
	if(!clObject->DoesOpenCLOperateSuccess())
	{
		setCursor(Qt::CursorShape::ArrowCursor);
		return;
	}

	StereoReconstruct*StereoReconstructObject=StereoReconstruct::GetInstance();
	StereoReconstructObject->StereoRecnstOpenCLUseImage(clObject);

	//vtkPointCloudProcessObject->setInputPlintCloud(StereoReconstructObject->getPoint3Vector());
	//vtkPointCloudProcessObject->pointCloudFilter(8);
	//vtkPointCloudProcessObject->DisplayPointCloud();

	actorBuilder* actorbuilder=new pointCloudActorBuilder();
	actorbuilder->buildPointCloudActor("");
	actorManagerClass*actorManager=actorManagerClass::getInstance();
	actorManager->addActor(actorbuilder->getActor());
	setCursor(Qt::CursorShape::ArrowCursor);

}
