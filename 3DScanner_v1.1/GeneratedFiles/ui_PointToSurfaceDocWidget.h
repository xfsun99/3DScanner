/********************************************************************************
** Form generated from reading UI file 'PointToSurfaceDocWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POINTTOSURFACEDOCWIDGET_H
#define UI_POINTTOSURFACEDOCWIDGET_H

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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PointToSurfaceDocWidget
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QSlider *horizontalSliderItera;
    QSpinBox *spinBoxItera;
    QLabel *label;
    QGridLayout *gridLayout_2;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QSlider *horizontalSliderAlpha;
    QDoubleSpinBox *doubleSpinBoxAlpha;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QFrame *line;

    void setupUi(QDockWidget *PointToSurfaceDocWidget)
    {
        if (PointToSurfaceDocWidget->objectName().isEmpty())
            PointToSurfaceDocWidget->setObjectName(QStringLiteral("PointToSurfaceDocWidget"));
        PointToSurfaceDocWidget->resize(257, 300);
        layoutWidget = new QWidget();
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        gridLayout_4 = new QGridLayout(layoutWidget);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSliderItera = new QSlider(layoutWidget);
        horizontalSliderItera->setObjectName(QStringLiteral("horizontalSliderItera"));
        horizontalSliderItera->setMinimum(10);
        horizontalSliderItera->setMaximum(1500);
        horizontalSliderItera->setSingleStep(10);
        horizontalSliderItera->setSliderPosition(500);
        horizontalSliderItera->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSliderItera, 0, 1, 1, 1);

        spinBoxItera = new QSpinBox(layoutWidget);
        spinBoxItera->setObjectName(QStringLiteral("spinBoxItera"));
        spinBoxItera->setMinimumSize(QSize(60, 0));
        spinBoxItera->setMinimum(10);
        spinBoxItera->setMaximum(1500);
        spinBoxItera->setValue(500);

        gridLayout->addWidget(spinBoxItera, 0, 2, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(60, 0));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout, 2, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        gridLayout_2->addWidget(cancelButton, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);

        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QStringLiteral("okButton"));

        gridLayout_2->addWidget(okButton, 0, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 5, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(60, 0));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        horizontalSliderAlpha = new QSlider(layoutWidget);
        horizontalSliderAlpha->setObjectName(QStringLiteral("horizontalSliderAlpha"));
        horizontalSliderAlpha->setMaximum(250);
        horizontalSliderAlpha->setSliderPosition(100);
        horizontalSliderAlpha->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(horizontalSliderAlpha, 0, 1, 1, 1);

        doubleSpinBoxAlpha = new QDoubleSpinBox(layoutWidget);
        doubleSpinBoxAlpha->setObjectName(QStringLiteral("doubleSpinBoxAlpha"));
        doubleSpinBoxAlpha->setMinimumSize(QSize(60, 0));
        doubleSpinBoxAlpha->setMaximum(25);
        doubleSpinBoxAlpha->setValue(10);

        gridLayout_3->addWidget(doubleSpinBoxAlpha, 0, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 8, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_4, 6, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 7, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 4, 0, 1, 1);

        line = new QFrame(layoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line, 1, 0, 1, 1);

        PointToSurfaceDocWidget->setWidget(layoutWidget);

        retranslateUi(PointToSurfaceDocWidget);
        QObject::connect(okButton, SIGNAL(clicked()), PointToSurfaceDocWidget, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), PointToSurfaceDocWidget, SLOT(reject()));
        QObject::connect(horizontalSliderItera, SIGNAL(valueChanged(int)), spinBoxItera, SLOT(setValue(int)));
        QObject::connect(spinBoxItera, SIGNAL(valueChanged(int)), horizontalSliderItera, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(PointToSurfaceDocWidget);
    } // setupUi

    void retranslateUi(QDockWidget *PointToSurfaceDocWidget)
    {
        PointToSurfaceDocWidget->setWindowTitle(QApplication::translate("PointToSurfaceDocWidget", "Point To Surface", 0));
        label->setText(QApplication::translate("PointToSurfaceDocWidget", "Iterations", 0));
        cancelButton->setText(QApplication::translate("PointToSurfaceDocWidget", "Cancel", 0));
        okButton->setText(QApplication::translate("PointToSurfaceDocWidget", "OK", 0));
        label_2->setText(QApplication::translate("PointToSurfaceDocWidget", "Alpha", 0));
    } // retranslateUi

};

namespace Ui {
    class PointToSurfaceDocWidget: public Ui_PointToSurfaceDocWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POINTTOSURFACEDOCWIDGET_H
