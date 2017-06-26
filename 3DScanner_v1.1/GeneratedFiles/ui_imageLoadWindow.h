/********************************************************************************
** Form generated from reading UI file 'imageLoadWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGELOADWINDOW_H
#define UI_IMAGELOADWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_imageLoadWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonLoadLeftImg;
    QSpacerItem *horizontalSpacer;
    QGraphicsView *graphicsViewRightImg;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonLoadRightImg;
    QSpacerItem *horizontalSpacer_4;
    QGraphicsView *graphicsViewLeftImg;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *imageLoadWindow)
    {
        if (imageLoadWindow->objectName().isEmpty())
            imageLoadWindow->setObjectName(QStringLiteral("imageLoadWindow"));
        imageLoadWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QStringLiteral(":/scanner/Resources/Icons/paraqlogo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        imageLoadWindow->setWindowIcon(icon);
        centralwidget = new QWidget(imageLoadWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButtonLoadLeftImg = new QPushButton(centralwidget);
        pushButtonLoadLeftImg->setObjectName(QStringLiteral("pushButtonLoadLeftImg"));
        pushButtonLoadLeftImg->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(pushButtonLoadLeftImg);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        graphicsViewRightImg = new QGraphicsView(centralwidget);
        graphicsViewRightImg->setObjectName(QStringLiteral("graphicsViewRightImg"));

        gridLayout->addWidget(graphicsViewRightImg, 2, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButtonLoadRightImg = new QPushButton(centralwidget);
        pushButtonLoadRightImg->setObjectName(QStringLiteral("pushButtonLoadRightImg"));
        pushButtonLoadRightImg->setMinimumSize(QSize(100, 0));

        horizontalLayout_2->addWidget(pushButtonLoadRightImg);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        graphicsViewLeftImg = new QGraphicsView(centralwidget);
        graphicsViewLeftImg->setObjectName(QStringLiteral("graphicsViewLeftImg"));

        gridLayout->addWidget(graphicsViewLeftImg, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        imageLoadWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(imageLoadWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        imageLoadWindow->setStatusBar(statusbar);

        retranslateUi(imageLoadWindow);

        QMetaObject::connectSlotsByName(imageLoadWindow);
    } // setupUi

    void retranslateUi(QMainWindow *imageLoadWindow)
    {
        imageLoadWindow->setWindowTitle(QApplication::translate("imageLoadWindow", "Image Load Window", 0));
        pushButtonLoadLeftImg->setText(QApplication::translate("imageLoadWindow", "Load Left Image", 0));
#ifndef QT_NO_STATUSTIP
        graphicsViewRightImg->setStatusTip(QApplication::translate("imageLoadWindow", "Right Image", 0));
#endif // QT_NO_STATUSTIP
        pushButtonLoadRightImg->setText(QApplication::translate("imageLoadWindow", "Load Right Image", 0));
#ifndef QT_NO_STATUSTIP
        graphicsViewLeftImg->setStatusTip(QApplication::translate("imageLoadWindow", "Left Image ", 0));
#endif // QT_NO_STATUSTIP
    } // retranslateUi

};

namespace Ui {
    class imageLoadWindow: public Ui_imageLoadWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGELOADWINDOW_H
