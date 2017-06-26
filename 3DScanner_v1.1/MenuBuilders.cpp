#include "MenuBuilders.h"
#include "SaveDataReaction.h"
#include "LoadDataReaction.h"
#include "selectToolBarImple.h"
#include "UiStateManager.h"
#include "pointCloudFilter.h"
#include "pointToSurface.h"
void MenuBuilder::buildEditMenu(QMenu& menu)
{
}
void MenuBuilder::buildFileMenu(QMenu& menu)
{
	Ui::FileMenuBuilder ui;
	ui.setupUi(&menu);
	
	QObject::connect(ui.actionFileExit, SIGNAL(triggered()),
    QCoreApplication::instance(), SLOT(quit()));

	//new LoadImages(ui.actionFileOpen);
}
void MenuBuilder::buildToolbars(QMainWindow& mainWindow)
{
	///Build the mainToolBar
	QToolBar* mainToolBar = new QToolBar(&mainWindow);
    mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
    mainToolBar->setMinimumSize(QSize(0, 20));
	mainWindow.addToolBar(Qt::TopToolBarArea, mainToolBar);
	//build toolbar ui
	Ui::MainControlsToolbar ui;
	ui.setupUi(mainToolBar);
	ui.actionRedo->setDisabled(true);
	ui.actionSaveData->setEnabled(false);
	ui.actionUndo->setDisabled(true);
	//set reaction
	new LoadImages(ui.actionLoadImages);
	new SaveDataReaction(ui.actionSaveData);
	new LoadDataReaction(ui.actionOpenData);
	//undo and redo action
	UiStateManager*uistateInstance=UiStateManager::getInstance();
	QObject::connect(uistateInstance,SIGNAL(setRedoEnabledSignal(bool)),ui.actionRedo,SLOT(setEnabled(bool)));
	QObject::connect(uistateInstance,SIGNAL(setUndoEnabledSignal(bool)),ui.actionUndo,SLOT(setEnabled(bool)));
	QObject::connect(ui.actionRedo, SIGNAL(triggered()),uistateInstance, SLOT(RedoActionTriggeredSlot()));
	QObject::connect(ui.actionUndo, SIGNAL(triggered()),uistateInstance, SLOT(UndoActionTriggeredSlot()));

	///Build the axec tool bar
	QToolBar* axecToolBar=new QToolBar(&mainWindow);
	axecToolBar->setObjectName(QStringLiteral("axecToolBar"));
	axecToolBar->setMinimumSize(QSize(0, 20));
	mainWindow.addToolBar(Qt::TopToolBarArea, axecToolBar);
	//build toolbar ui
	Ui::axesToolbar axecToolBar_ui;
	axecToolBar_ui.setupUi(axecToolBar);
	//set reaction
	new axecToolBarFuncImple(&axecToolBar_ui);

	//build select toolbar
	QToolBar* selectToolBar=new QToolBar(&mainWindow);
	selectToolBar->setObjectName(QStringLiteral("selectToolBar"));
	selectToolBar->setMinimumSize(QSize(0, 20));
	mainWindow.addToolBar(Qt::TopToolBarArea, selectToolBar);
	//build select toolbar ui
	Ui::selectToolbar selectToolBar_ui;
	selectToolBar_ui.setupUi(selectToolBar);
	//set reaction
	new selectToolBarImple(&selectToolBar_ui);

	//build pointCloud Edit tool bar
	QToolBar* pointCloudEditToolBar=new QToolBar(&mainWindow);
	pointCloudEditToolBar->setObjectName(QStringLiteral("pointCloudEditToolBar"));
	pointCloudEditToolBar->setMinimumSize(QSize(0, 20));
	mainWindow.addToolBar(Qt::TopToolBarArea, pointCloudEditToolBar);
	//setup ui
	Ui::pointCloudEditToolBar pointCloudEditToolBar_ui;
	pointCloudEditToolBar_ui.setupUi(pointCloudEditToolBar);
	//set reaction
	new pointCloudFilter(mainWindow,&pointCloudEditToolBar_ui);
	new pointToSurface(mainWindow,&pointCloudEditToolBar_ui);
}
void MenuBuilder::buildSettingMenu(QMenu& menu)
{
	Ui::SettingMenuBuilder ui;
	ui.setupUi(&menu);

	new changeColor(ui.actionRenderWinBackColorSet);

}