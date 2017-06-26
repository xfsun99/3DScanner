/********************************************************************************
** Form generated from reading UI file 'scanner.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANNER_H
#define UI_SCANNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_scannerClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVTKWidget *qvtkWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuView;
    QMenu *menuSetting;
    QStatusBar *statusBar;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_2;
    QGridLayout *gridLayout_3;
    QPushButton *pushButtonStereoReconstruct;
    QDockWidget *dockWidgetProperties;
    QWidget *dockWidgetContentsProperty;
    QDockWidget *dockWidgetActorManager;
    QWidget *dockWidgetContentsActorManager;

    void setupUi(QMainWindow *scannerClass)
    {
        if (scannerClass->objectName().isEmpty())
            scannerClass->setObjectName(QStringLiteral("scannerClass"));
        scannerClass->resize(900, 600);
        scannerClass->setMinimumSize(QSize(900, 600));
        QIcon icon;
        icon.addFile(QStringLiteral(":/scanner/Resources/Icons/3D.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        scannerClass->setWindowIcon(icon);
        scannerClass->setIconSize(QSize(24, 24));
        scannerClass->setDocumentMode(false);
        scannerClass->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        centralWidget = new QWidget(scannerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        qvtkWidget = new QVTKWidget(centralWidget);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));

        gridLayout->addWidget(qvtkWidget, 0, 0, 1, 1);

        scannerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(scannerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuSetting = new QMenu(menuBar);
        menuSetting->setObjectName(QStringLiteral("menuSetting"));
        scannerClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(scannerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        scannerClass->setStatusBar(statusBar);
        dockWidget_2 = new QDockWidget(scannerClass);
        dockWidget_2->setObjectName(QStringLiteral("dockWidget_2"));
        dockWidget_2->setMinimumSize(QSize(200, 100));
        dockWidget_2->setMaximumSize(QSize(240, 100));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        gridLayout_3 = new QGridLayout(dockWidgetContents_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButtonStereoReconstruct = new QPushButton(dockWidgetContents_2);
        pushButtonStereoReconstruct->setObjectName(QStringLiteral("pushButtonStereoReconstruct"));

        gridLayout_3->addWidget(pushButtonStereoReconstruct, 0, 0, 1, 1);

        dockWidget_2->setWidget(dockWidgetContents_2);
        scannerClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_2);
        dockWidgetProperties = new QDockWidget(scannerClass);
        dockWidgetProperties->setObjectName(QStringLiteral("dockWidgetProperties"));
        dockWidgetProperties->setMinimumSize(QSize(200, 111));
        dockWidgetProperties->setMaximumSize(QSize(240, 524287));
        dockWidgetContentsProperty = new QWidget();
        dockWidgetContentsProperty->setObjectName(QStringLiteral("dockWidgetContentsProperty"));
        dockWidgetProperties->setWidget(dockWidgetContentsProperty);
        scannerClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidgetProperties);
        dockWidgetActorManager = new QDockWidget(scannerClass);
        dockWidgetActorManager->setObjectName(QStringLiteral("dockWidgetActorManager"));
        dockWidgetActorManager->setMinimumSize(QSize(90, 100));
        dockWidgetContentsActorManager = new QWidget();
        dockWidgetContentsActorManager->setObjectName(QStringLiteral("dockWidgetContentsActorManager"));
        dockWidgetActorManager->setWidget(dockWidgetContentsActorManager);
        scannerClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidgetActorManager);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuSetting->menuAction());

        retranslateUi(scannerClass);

        QMetaObject::connectSlotsByName(scannerClass);
    } // setupUi

    void retranslateUi(QMainWindow *scannerClass)
    {
        scannerClass->setWindowTitle(QApplication::translate("scannerClass", "scanner", 0));
        menuFile->setTitle(QApplication::translate("scannerClass", "File", 0));
        menuView->setTitle(QApplication::translate("scannerClass", "view", 0));
        menuSetting->setTitle(QApplication::translate("scannerClass", "setting", 0));
        dockWidget_2->setWindowTitle(QApplication::translate("scannerClass", "Stereo Reconstruct", 0));
        pushButtonStereoReconstruct->setText(QApplication::translate("scannerClass", "Stereo Reconstruct", 0));
        dockWidgetProperties->setWindowTitle(QApplication::translate("scannerClass", "Properties", 0));
        dockWidgetActorManager->setWindowTitle(QApplication::translate("scannerClass", "Actor Manager", 0));
    } // retranslateUi

};

namespace Ui {
    class scannerClass: public Ui_scannerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANNER_H
