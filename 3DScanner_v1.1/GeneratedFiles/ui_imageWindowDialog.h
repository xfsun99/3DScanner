/********************************************************************************
** Form generated from reading UI file 'imageWindowDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEWINDOWDIALOG_H
#define UI_IMAGEWINDOWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_imageWindowDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsViewRightImg;
    QGraphicsView *graphicsViewLeftImg;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonLoadLeftImg;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonLoadRightImg;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *imageWindowDialog)
    {
        if (imageWindowDialog->objectName().isEmpty())
            imageWindowDialog->setObjectName(QStringLiteral("imageWindowDialog"));
        imageWindowDialog->resize(599, 391);
        imageWindowDialog->setMinimumSize(QSize(480, 360));
        gridLayout_2 = new QGridLayout(imageWindowDialog);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        graphicsViewRightImg = new QGraphicsView(imageWindowDialog);
        graphicsViewRightImg->setObjectName(QStringLiteral("graphicsViewRightImg"));

        gridLayout->addWidget(graphicsViewRightImg, 2, 1, 1, 1);

        graphicsViewLeftImg = new QGraphicsView(imageWindowDialog);
        graphicsViewLeftImg->setObjectName(QStringLiteral("graphicsViewLeftImg"));

        gridLayout->addWidget(graphicsViewLeftImg, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButtonLoadLeftImg = new QPushButton(imageWindowDialog);
        pushButtonLoadLeftImg->setObjectName(QStringLiteral("pushButtonLoadLeftImg"));
        pushButtonLoadLeftImg->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(pushButtonLoadLeftImg);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButtonLoadRightImg = new QPushButton(imageWindowDialog);
        pushButtonLoadRightImg->setObjectName(QStringLiteral("pushButtonLoadRightImg"));
        pushButtonLoadRightImg->setMinimumSize(QSize(100, 0));

        horizontalLayout_2->addWidget(pushButtonLoadRightImg);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_2, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(imageWindowDialog);

        QMetaObject::connectSlotsByName(imageWindowDialog);
    } // setupUi

    void retranslateUi(QWidget *imageWindowDialog)
    {
        imageWindowDialog->setWindowTitle(QApplication::translate("imageWindowDialog", "Load Image Dialog", 0));
        pushButtonLoadLeftImg->setText(QApplication::translate("imageWindowDialog", "Load Left Image", 0));
        pushButtonLoadRightImg->setText(QApplication::translate("imageWindowDialog", "Load Right Image", 0));
    } // retranslateUi

};

namespace Ui {
    class imageWindowDialog: public Ui_imageWindowDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEWINDOWDIALOG_H
