/********************************************************************************
** Form generated from reading UI file 'dhx64.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DHX64_H
#define UI_DHX64_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dhx64Class
{
public:
    QAction *actionReflashDeviceInfo;
    QAction *actionSaveImage;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionStart;
    QAction *actionStop;
    QAction *actionLoadLeftImg;
    QAction *actionLoadRightImg;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QLabel *labelLeft;
    QLabel *labelRight;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidgetDeviceManager;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QDockWidget *dockWidgetCameraProperty;
    QWidget *dockWidgetContents_2;
    QGridLayout *gridLayout_5;
    QCommandLinkButton *commandLinkButtonCatch;
    QCommandLinkButton *commandLinkButtonSaveLRImg;
    QGroupBox *groupBoxCamera;
    QGridLayout *gridLayout_4;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSlider *horizontalSliderGain;
    QSpinBox *spinBoxGain;
    QFrame *line;
    QGroupBox *groupBoxSerialPort;
    QGridLayout *gridLayout_3;
    QCommandLinkButton *commandLinkButtonCheckport;
    QCommandLinkButton *commandLinkButtonOpenClose;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboBoxSerialPort;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QMainWindow *dhx64Class)
    {
        if (dhx64Class->objectName().isEmpty())
            dhx64Class->setObjectName(QStringLiteral("dhx64Class"));
        dhx64Class->resize(1104, 712);
        QIcon icon;
        icon.addFile(QStringLiteral(":/dhx64/Resources/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        dhx64Class->setWindowIcon(icon);
        actionReflashDeviceInfo = new QAction(dhx64Class);
        actionReflashDeviceInfo->setObjectName(QStringLiteral("actionReflashDeviceInfo"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/scanner/Resources/Icons/synchronized.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReflashDeviceInfo->setIcon(icon1);
        actionSaveImage = new QAction(dhx64Class);
        actionSaveImage->setObjectName(QStringLiteral("actionSaveImage"));
        actionSaveImage->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/scanner/Resources/Icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveImage->setIcon(icon2);
        actionConnect = new QAction(dhx64Class);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionConnect->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/scanner/Resources/Icons/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon3);
        actionDisconnect = new QAction(dhx64Class);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        actionDisconnect->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/scanner/Resources/Icons/dicconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnect->setIcon(icon4);
        actionStart = new QAction(dhx64Class);
        actionStart->setObjectName(QStringLiteral("actionStart"));
        actionStart->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/scanner/Resources/Icons/start-here.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStart->setIcon(icon5);
        actionStop = new QAction(dhx64Class);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        actionStop->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/scanner/Resources/Icons/Stop1NormalBlue.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon6);
        actionLoadLeftImg = new QAction(dhx64Class);
        actionLoadLeftImg->setObjectName(QStringLiteral("actionLoadLeftImg"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/scanner/Resources/Icons/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoadLeftImg->setIcon(icon7);
        actionLoadRightImg = new QAction(dhx64Class);
        actionLoadRightImg->setObjectName(QStringLiteral("actionLoadRightImg"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/scanner/Resources/Icons/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoadRightImg->setIcon(icon8);
        centralWidget = new QWidget(dhx64Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        labelLeft = new QLabel(centralWidget);
        labelLeft->setObjectName(QStringLiteral("labelLeft"));
        labelLeft->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelLeft, 0, 0, 1, 1);

        labelRight = new QLabel(centralWidget);
        labelRight->setObjectName(QStringLiteral("labelRight"));
        labelRight->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelRight, 0, 1, 1, 1);

        dhx64Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(dhx64Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1104, 26));
        dhx64Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(dhx64Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        dhx64Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(dhx64Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        dhx64Class->setStatusBar(statusBar);
        dockWidgetDeviceManager = new QDockWidget(dhx64Class);
        dockWidgetDeviceManager->setObjectName(QStringLiteral("dockWidgetDeviceManager"));
        dockWidgetDeviceManager->setMinimumSize(QSize(300, 120));
        dockWidgetDeviceManager->setMaximumSize(QSize(300, 120));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        gridLayout = new QGridLayout(dockWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        listWidget = new QListWidget(dockWidgetContents);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout->addWidget(listWidget, 0, 0, 1, 1);

        dockWidgetDeviceManager->setWidget(dockWidgetContents);
        dhx64Class->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidgetDeviceManager);
        dockWidgetCameraProperty = new QDockWidget(dhx64Class);
        dockWidgetCameraProperty->setObjectName(QStringLiteral("dockWidgetCameraProperty"));
        dockWidgetCameraProperty->setMinimumSize(QSize(300, 446));
        dockWidgetCameraProperty->setMaximumSize(QSize(300, 524287));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        gridLayout_5 = new QGridLayout(dockWidgetContents_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        commandLinkButtonCatch = new QCommandLinkButton(dockWidgetContents_2);
        commandLinkButtonCatch->setObjectName(QStringLiteral("commandLinkButtonCatch"));
        commandLinkButtonCatch->setEnabled(false);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/scanner/Resources/Icons/catch.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButtonCatch->setIcon(icon9);

        gridLayout_5->addWidget(commandLinkButtonCatch, 3, 0, 1, 1);

        commandLinkButtonSaveLRImg = new QCommandLinkButton(dockWidgetContents_2);
        commandLinkButtonSaveLRImg->setObjectName(QStringLiteral("commandLinkButtonSaveLRImg"));
        commandLinkButtonSaveLRImg->setIcon(icon2);

        gridLayout_5->addWidget(commandLinkButtonSaveLRImg, 4, 0, 1, 1);

        groupBoxCamera = new QGroupBox(dockWidgetContents_2);
        groupBoxCamera->setObjectName(QStringLiteral("groupBoxCamera"));
        groupBoxCamera->setEnabled(false);
        gridLayout_4 = new QGridLayout(groupBoxCamera);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(groupBoxCamera);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboBox = new QComboBox(groupBoxCamera);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox);


        gridLayout_4->addLayout(formLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(groupBoxCamera);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        horizontalSliderGain = new QSlider(groupBoxCamera);
        horizontalSliderGain->setObjectName(QStringLiteral("horizontalSliderGain"));
        horizontalSliderGain->setMaximum(1023);
        horizontalSliderGain->setValue(400);
        horizontalSliderGain->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSliderGain);

        spinBoxGain = new QSpinBox(groupBoxCamera);
        spinBoxGain->setObjectName(QStringLiteral("spinBoxGain"));
        spinBoxGain->setMinimumSize(QSize(50, 0));
        spinBoxGain->setMaximum(1023);
        spinBoxGain->setValue(400);

        horizontalLayout_2->addWidget(spinBoxGain);


        gridLayout_4->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        line = new QFrame(groupBoxCamera);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line, 1, 0, 1, 1);


        gridLayout_5->addWidget(groupBoxCamera, 0, 0, 1, 1);

        groupBoxSerialPort = new QGroupBox(dockWidgetContents_2);
        groupBoxSerialPort->setObjectName(QStringLiteral("groupBoxSerialPort"));
        gridLayout_3 = new QGridLayout(groupBoxSerialPort);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        commandLinkButtonCheckport = new QCommandLinkButton(groupBoxSerialPort);
        commandLinkButtonCheckport->setObjectName(QStringLiteral("commandLinkButtonCheckport"));
        commandLinkButtonCheckport->setMaximumSize(QSize(220, 16777215));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/dhx64/Resources/synchronized.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButtonCheckport->setIcon(icon10);

        gridLayout_3->addWidget(commandLinkButtonCheckport, 0, 0, 1, 1);

        commandLinkButtonOpenClose = new QCommandLinkButton(groupBoxSerialPort);
        commandLinkButtonOpenClose->setObjectName(QStringLiteral("commandLinkButtonOpenClose"));
        commandLinkButtonOpenClose->setEnabled(false);
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/dhx64/Resources/serialport.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButtonOpenClose->setIcon(icon11);

        gridLayout_3->addWidget(commandLinkButtonOpenClose, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(groupBoxSerialPort);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        comboBoxSerialPort = new QComboBox(groupBoxSerialPort);
        comboBoxSerialPort->setObjectName(QStringLiteral("comboBoxSerialPort"));

        horizontalLayout->addWidget(comboBoxSerialPort);


        gridLayout_3->addLayout(horizontalLayout, 1, 0, 1, 1);


        gridLayout_5->addWidget(groupBoxSerialPort, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_2, 10, 0, 1, 1);

        dockWidgetCameraProperty->setWidget(dockWidgetContents_2);
        dhx64Class->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidgetCameraProperty);

        mainToolBar->addAction(actionReflashDeviceInfo);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionLoadLeftImg);
        mainToolBar->addAction(actionLoadRightImg);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionConnect);
        mainToolBar->addAction(actionDisconnect);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionStart);
        mainToolBar->addAction(actionStop);
        mainToolBar->addAction(actionSaveImage);

        retranslateUi(dhx64Class);
        QObject::connect(horizontalSliderGain, SIGNAL(valueChanged(int)), spinBoxGain, SLOT(setValue(int)));
        QObject::connect(spinBoxGain, SIGNAL(valueChanged(int)), horizontalSliderGain, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(dhx64Class);
    } // setupUi

    void retranslateUi(QMainWindow *dhx64Class)
    {
        dhx64Class->setWindowTitle(QApplication::translate("dhx64Class", "dhx64", 0));
        actionReflashDeviceInfo->setText(QApplication::translate("dhx64Class", "reflashDeviceInfo", 0));
#ifndef QT_NO_TOOLTIP
        actionReflashDeviceInfo->setToolTip(QApplication::translate("dhx64Class", "Find Decices", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionReflashDeviceInfo->setStatusTip(QApplication::translate("dhx64Class", "Find Decices", 0));
#endif // QT_NO_STATUSTIP
        actionSaveImage->setText(QApplication::translate("dhx64Class", "saveImage", 0));
#ifndef QT_NO_TOOLTIP
        actionSaveImage->setToolTip(QApplication::translate("dhx64Class", "Save Image", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSaveImage->setStatusTip(QApplication::translate("dhx64Class", "Save Image", 0));
#endif // QT_NO_STATUSTIP
        actionConnect->setText(QApplication::translate("dhx64Class", "connect", 0));
#ifndef QT_NO_TOOLTIP
        actionConnect->setToolTip(QApplication::translate("dhx64Class", "Connect Device", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionConnect->setStatusTip(QApplication::translate("dhx64Class", "Connect Device", 0));
#endif // QT_NO_STATUSTIP
        actionDisconnect->setText(QApplication::translate("dhx64Class", "disconnect", 0));
#ifndef QT_NO_TOOLTIP
        actionDisconnect->setToolTip(QApplication::translate("dhx64Class", "Disonnect Device", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionDisconnect->setStatusTip(QApplication::translate("dhx64Class", "Disonnect Device", 0));
#endif // QT_NO_STATUSTIP
        actionStart->setText(QApplication::translate("dhx64Class", "start", 0));
        actionStop->setText(QApplication::translate("dhx64Class", "stop", 0));
        actionLoadLeftImg->setText(QApplication::translate("dhx64Class", "LoadLeftImg", 0));
#ifndef QT_NO_TOOLTIP
        actionLoadLeftImg->setToolTip(QApplication::translate("dhx64Class", "Load Left Image", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        actionLoadLeftImg->setWhatsThis(QApplication::translate("dhx64Class", "Load Left Image", 0));
#endif // QT_NO_WHATSTHIS
        actionLoadRightImg->setText(QApplication::translate("dhx64Class", "LoadRightImg", 0));
#ifndef QT_NO_TOOLTIP
        actionLoadRightImg->setToolTip(QApplication::translate("dhx64Class", "Load Right Image", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        actionLoadRightImg->setWhatsThis(QApplication::translate("dhx64Class", "Load Right Image", 0));
#endif // QT_NO_WHATSTHIS
        labelLeft->setText(QApplication::translate("dhx64Class", "Left Image", 0));
        labelRight->setText(QApplication::translate("dhx64Class", "Right Image", 0));
        dockWidgetDeviceManager->setWindowTitle(QApplication::translate("dhx64Class", "Device Manager", 0));
        dockWidgetCameraProperty->setWindowTitle(QApplication::translate("dhx64Class", "Camera Property", 0));
        commandLinkButtonCatch->setText(QApplication::translate("dhx64Class", "Catch Image", 0));
        commandLinkButtonSaveLRImg->setText(QApplication::translate("dhx64Class", "Save LR Image", 0));
        groupBoxCamera->setTitle(QApplication::translate("dhx64Class", "Camera", 0));
        label->setText(QApplication::translate("dhx64Class", "Capture Mode", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("dhx64Class", "Software Trigger", 0)
         << QApplication::translate("dhx64Class", "Hardware Trigger", 0)
        );
        label_3->setText(QApplication::translate("dhx64Class", "Gain", 0));
        groupBoxSerialPort->setTitle(QApplication::translate("dhx64Class", "Serial Port", 0));
        commandLinkButtonCheckport->setText(QApplication::translate("dhx64Class", "Check Serial Prot", 0));
        commandLinkButtonOpenClose->setText(QApplication::translate("dhx64Class", "Open Serial Port", 0));
        label_2->setText(QApplication::translate("dhx64Class", "Serial Port", 0));
    } // retranslateUi

};

namespace Ui {
    class dhx64Class: public Ui_dhx64Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DHX64_H
