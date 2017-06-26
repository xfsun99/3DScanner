/********************************************************************************
** Form generated from reading UI file 'AxesToolbar.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AXESTOOLBAR_H
#define UI_AXESTOOLBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolBar>

QT_BEGIN_NAMESPACE

class Ui_axesToolbar
{
public:
    QAction *actionShowOrientationAxes;
    QAction *actionShowCenterAxes;
    QAction *actionPickCenter;
    QAction *actionResetCenter;

    void setupUi(QToolBar *axesToolbar)
    {
        if (axesToolbar->objectName().isEmpty())
            axesToolbar->setObjectName(QStringLiteral("axesToolbar"));
        axesToolbar->setEnabled(true);
        axesToolbar->resize(128, 34);
        axesToolbar->setOrientation(Qt::Horizontal);
        actionShowOrientationAxes = new QAction(axesToolbar);
        actionShowOrientationAxes->setObjectName(QStringLiteral("actionShowOrientationAxes"));
        actionShowOrientationAxes->setCheckable(true);
        actionShowOrientationAxes->setEnabled(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/scanner/Resources/Icons/pqShowOrientationAxes24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowOrientationAxes->setIcon(icon);
        actionShowCenterAxes = new QAction(axesToolbar);
        actionShowCenterAxes->setObjectName(QStringLiteral("actionShowCenterAxes"));
        actionShowCenterAxes->setCheckable(true);
        actionShowCenterAxes->setEnabled(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/scanner/Resources/Icons/pqShowCenterAxes24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowCenterAxes->setIcon(icon1);
        actionPickCenter = new QAction(axesToolbar);
        actionPickCenter->setObjectName(QStringLiteral("actionPickCenter"));
        actionPickCenter->setCheckable(true);
        actionPickCenter->setEnabled(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/scanner/Resources/Icons/pqPickCenter24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPickCenter->setIcon(icon2);
        actionResetCenter = new QAction(axesToolbar);
        actionResetCenter->setObjectName(QStringLiteral("actionResetCenter"));
        actionResetCenter->setEnabled(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/scanner/Resources/Icons/pqResetCenter24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionResetCenter->setIcon(icon3);

        axesToolbar->addAction(actionShowOrientationAxes);
        axesToolbar->addAction(actionShowCenterAxes);
        axesToolbar->addAction(actionResetCenter);
        axesToolbar->addAction(actionPickCenter);

        retranslateUi(axesToolbar);

        QMetaObject::connectSlotsByName(axesToolbar);
    } // setupUi

    void retranslateUi(QToolBar *axesToolbar)
    {
        axesToolbar->setWindowTitle(QApplication::translate("axesToolbar", "Center Axes Controls", 0));
        actionShowOrientationAxes->setText(QApplication::translate("axesToolbar", "Show Orientation Axes", 0));
#ifndef QT_NO_STATUSTIP
        actionShowOrientationAxes->setStatusTip(QApplication::translate("axesToolbar", "Show/Hide orientation axes", 0));
#endif // QT_NO_STATUSTIP
        actionShowCenterAxes->setText(QApplication::translate("axesToolbar", "Show Center", 0));
#ifndef QT_NO_STATUSTIP
        actionShowCenterAxes->setStatusTip(QApplication::translate("axesToolbar", "Show/Hide center of rotation", 0));
#endif // QT_NO_STATUSTIP
        actionPickCenter->setText(QApplication::translate("axesToolbar", "Pick Center", 0));
        actionPickCenter->setIconText(QApplication::translate("axesToolbar", "Pick Center", 0));
#ifndef QT_NO_TOOLTIP
        actionPickCenter->setToolTip(QApplication::translate("axesToolbar", "Pick Center", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionPickCenter->setStatusTip(QApplication::translate("axesToolbar", "Mouse press to pick center of rotation", 0));
#endif // QT_NO_STATUSTIP
        actionResetCenter->setText(QApplication::translate("axesToolbar", "Reset Center", 0));
#ifndef QT_NO_STATUSTIP
        actionResetCenter->setStatusTip(QApplication::translate("axesToolbar", "Reset center of rotation", 0));
#endif // QT_NO_STATUSTIP
    } // retranslateUi

};

namespace Ui {
    class axesToolbar: public Ui_axesToolbar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AXESTOOLBAR_H
