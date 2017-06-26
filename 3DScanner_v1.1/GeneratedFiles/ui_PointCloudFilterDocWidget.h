/********************************************************************************
** Form generated from reading UI file 'PointCloudFilterDocWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POINTCLOUDFILTERDOCWIDGET_H
#define UI_POINTCLOUDFILTERDOCWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PointCloudFilter
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QSlider *horizontalSliderSigma;
    QDoubleSpinBox *doubleSpinBox_Sigma;
    QGridLayout *gridLayout_4;
    QLabel *label_3;
    QSlider *horizontalSliderThrd;
    QDoubleSpinBox *doubleSpinBox_Thrd;
    QGridLayout *gridLayout_2;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QDoubleSpinBox *doubleSpinBox_Rad;
    QSlider *horizontalSliderRad;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_3;
    QFrame *line;
    QFrame *line_2;

    void setupUi(QDockWidget *PointCloudFilter)
    {
        if (PointCloudFilter->objectName().isEmpty())
            PointCloudFilter->setObjectName(QStringLiteral("PointCloudFilter"));
        PointCloudFilter->resize(250, 300);
        PointCloudFilter->setMinimumSize(QSize(250, 250));
        PointCloudFilter->setMaximumSize(QSize(250, 524287));
        layoutWidget = new QWidget();
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        gridLayout_5 = new QGridLayout(layoutWidget);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(40, 0));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        horizontalSliderSigma = new QSlider(layoutWidget);
        horizontalSliderSigma->setObjectName(QStringLiteral("horizontalSliderSigma"));
        horizontalSliderSigma->setMaximum(100);
        horizontalSliderSigma->setSliderPosition(16);
        horizontalSliderSigma->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(horizontalSliderSigma, 0, 1, 1, 1);

        doubleSpinBox_Sigma = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_Sigma->setObjectName(QStringLiteral("doubleSpinBox_Sigma"));
        doubleSpinBox_Sigma->setMinimumSize(QSize(60, 0));
        doubleSpinBox_Sigma->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_Sigma->setMaximum(10);
        doubleSpinBox_Sigma->setSingleStep(0.1);
        doubleSpinBox_Sigma->setValue(1.6);

        gridLayout_3->addWidget(doubleSpinBox_Sigma, 0, 2, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 2, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(40, 0));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_3, 0, 0, 1, 1);

        horizontalSliderThrd = new QSlider(layoutWidget);
        horizontalSliderThrd->setObjectName(QStringLiteral("horizontalSliderThrd"));
        horizontalSliderThrd->setMinimum(10);
        horizontalSliderThrd->setMaximum(100);
        horizontalSliderThrd->setSliderPosition(34);
        horizontalSliderThrd->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(horizontalSliderThrd, 0, 1, 1, 1);

        doubleSpinBox_Thrd = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_Thrd->setObjectName(QStringLiteral("doubleSpinBox_Thrd"));
        doubleSpinBox_Thrd->setMinimumSize(QSize(60, 0));
        doubleSpinBox_Thrd->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_Thrd->setMinimum(1);
        doubleSpinBox_Thrd->setMaximum(10);
        doubleSpinBox_Thrd->setSingleStep(0.1);
        doubleSpinBox_Thrd->setValue(3.4);

        gridLayout_4->addWidget(doubleSpinBox_Thrd, 0, 3, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 4, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QStringLiteral("okButton"));

        gridLayout_2->addWidget(okButton, 0, 1, 1, 1);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        gridLayout_2->addWidget(cancelButton, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 6, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        doubleSpinBox_Rad = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_Rad->setObjectName(QStringLiteral("doubleSpinBox_Rad"));
        doubleSpinBox_Rad->setMinimumSize(QSize(60, 0));
        doubleSpinBox_Rad->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_Rad->setMinimum(1);
        doubleSpinBox_Rad->setMaximum(15);
        doubleSpinBox_Rad->setSingleStep(0.1);
        doubleSpinBox_Rad->setValue(4.6);

        gridLayout->addWidget(doubleSpinBox_Rad, 0, 3, 1, 1);

        horizontalSliderRad = new QSlider(layoutWidget);
        horizontalSliderRad->setObjectName(QStringLiteral("horizontalSliderRad"));
        horizontalSliderRad->setMinimum(10);
        horizontalSliderRad->setMaximum(150);
        horizontalSliderRad->setValue(46);
        horizontalSliderRad->setSliderPosition(46);
        horizontalSliderRad->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSliderRad, 0, 2, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(40, 0));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_2, 7, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer, 5, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_3, 8, 0, 1, 1);

        line = new QFrame(layoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setMaximumSize(QSize(200, 16777215));
        line->setLayoutDirection(Qt::RightToLeft);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line, 1, 0, 1, 1);

        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setMaximumSize(QSize(200, 16777215));
        line_2->setLayoutDirection(Qt::RightToLeft);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_2, 3, 0, 1, 1);

        PointCloudFilter->setWidget(layoutWidget);

        retranslateUi(PointCloudFilter);
        QObject::connect(okButton, SIGNAL(clicked()), PointCloudFilter, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), PointCloudFilter, SLOT(reject()));

        QMetaObject::connectSlotsByName(PointCloudFilter);
    } // setupUi

    void retranslateUi(QDockWidget *PointCloudFilter)
    {
        PointCloudFilter->setWindowTitle(QApplication::translate("PointCloudFilter", "Point Cloud Filter", 0));
        label_2->setText(QApplication::translate("PointCloudFilter", "sigma", 0));
        label_3->setText(QApplication::translate("PointCloudFilter", "threslod", 0));
        okButton->setText(QApplication::translate("PointCloudFilter", "OK", 0));
        cancelButton->setText(QApplication::translate("PointCloudFilter", "Cancel", 0));
        label->setText(QApplication::translate("PointCloudFilter", "rad", 0));
    } // retranslateUi

};

namespace Ui {
    class PointCloudFilter: public Ui_PointCloudFilter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POINTCLOUDFILTERDOCWIDGET_H
