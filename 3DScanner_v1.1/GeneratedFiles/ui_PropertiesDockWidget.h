/********************************************************************************
** Form generated from reading UI file 'PropertiesDockWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROPERTIESDOCKWIDGET_H
#define UI_PROPERTIESDOCKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dockWidgetContentsProperty
{
public:
    QGridLayout *gridLayout;
    QFrame *line_2;
    QSpacerItem *verticalSpacer;
    QFrame *line;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QCommandLinkButton *toolButtonSetColor;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSlider *horizontalSlider_2;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *horizontalSlider;
    QDoubleSpinBox *doubleSpinBox;
    QFrame *line_3;
    QCommandLinkButton *commandLinkButtonVisable;

    void setupUi(QWidget *dockWidgetContentsProperty)
    {
        if (dockWidgetContentsProperty->objectName().isEmpty())
            dockWidgetContentsProperty->setObjectName(QStringLiteral("dockWidgetContentsProperty"));
        dockWidgetContentsProperty->setEnabled(false);
        dockWidgetContentsProperty->resize(239, 282);
        gridLayout = new QGridLayout(dockWidgetContentsProperty);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        line_2 = new QFrame(dockWidgetContentsProperty);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 0, 1, 1);

        line = new QFrame(dockWidgetContentsProperty);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(dockWidgetContentsProperty);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        toolButtonSetColor = new QCommandLinkButton(dockWidgetContentsProperty);
        toolButtonSetColor->setObjectName(QStringLiteral("toolButtonSetColor"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/scanner/Resources/Icons/colorA.ico"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonSetColor->setIcon(icon);

        horizontalLayout_3->addWidget(toolButtonSetColor);


        gridLayout->addLayout(horizontalLayout_3, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(dockWidgetContentsProperty);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        horizontalSlider_2 = new QSlider(dockWidgetContentsProperty);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setMinimum(1);
        horizontalSlider_2->setMaximum(20);
        horizontalSlider_2->setValue(1);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider_2);

        spinBox = new QSpinBox(dockWidgetContentsProperty);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(20);

        horizontalLayout_2->addWidget(spinBox);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(dockWidgetContentsProperty);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSlider = new QSlider(dockWidgetContentsProperty);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setValue(100);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        doubleSpinBox = new QDoubleSpinBox(dockWidgetContentsProperty);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setMaximum(1);
        doubleSpinBox->setSingleStep(0.01);
        doubleSpinBox->setValue(1);

        horizontalLayout->addWidget(doubleSpinBox);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        line_3 = new QFrame(dockWidgetContentsProperty);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 5, 0, 1, 1);

        commandLinkButtonVisable = new QCommandLinkButton(dockWidgetContentsProperty);
        commandLinkButtonVisable->setObjectName(QStringLiteral("commandLinkButtonVisable"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/scanner/Resources/Icons/eye_open.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButtonVisable->setIcon(icon1);
        commandLinkButtonVisable->setAutoRepeat(true);

        gridLayout->addWidget(commandLinkButtonVisable, 6, 0, 1, 1);


        retranslateUi(dockWidgetContentsProperty);
        QObject::connect(horizontalSlider_2, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), horizontalSlider_2, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(dockWidgetContentsProperty);
    } // setupUi

    void retranslateUi(QWidget *dockWidgetContentsProperty)
    {
        label_2->setText(QApplication::translate("dockWidgetContentsProperty", "Color", 0));
#ifndef QT_NO_STATUSTIP
        toolButtonSetColor->setStatusTip(QApplication::translate("dockWidgetContentsProperty", "Set Actor Color", 0));
#endif // QT_NO_STATUSTIP
        toolButtonSetColor->setText(QApplication::translate("dockWidgetContentsProperty", "Set Color", 0));
        label_3->setText(QApplication::translate("dockWidgetContentsProperty", "Point Size", 0));
        label->setText(QApplication::translate("dockWidgetContentsProperty", "Opacity", 0));
#ifndef QT_NO_TOOLTIP
        commandLinkButtonVisable->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        commandLinkButtonVisable->setStatusTip(QApplication::translate("dockWidgetContentsProperty", "Hide or Visable", 0));
#endif // QT_NO_STATUSTIP
        commandLinkButtonVisable->setText(QApplication::translate("dockWidgetContentsProperty", "Visable", 0));
        Q_UNUSED(dockWidgetContentsProperty);
    } // retranslateUi

};

namespace Ui {
    class dockWidgetContentsProperty: public Ui_dockWidgetContentsProperty {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROPERTIESDOCKWIDGET_H
