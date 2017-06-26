/********************************************************************************
** Form generated from reading UI file 'pointCloudEditToolBar.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POINTCLOUDEDITTOOLBAR_H
#define UI_POINTCLOUDEDITTOOLBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolBar>

QT_BEGIN_NAMESPACE

class Ui_pointCloudEditToolBar
{
public:
    QAction *actionPointCloudFilter;
    QAction *actionPointToSurface;

    void setupUi(QToolBar *pointCloudEditToolBar)
    {
        if (pointCloudEditToolBar->objectName().isEmpty())
            pointCloudEditToolBar->setObjectName(QStringLiteral("pointCloudEditToolBar"));
        pointCloudEditToolBar->setEnabled(true);
        pointCloudEditToolBar->resize(128, 34);
        pointCloudEditToolBar->setOrientation(Qt::Horizontal);
        actionPointCloudFilter = new QAction(pointCloudEditToolBar);
        actionPointCloudFilter->setObjectName(QStringLiteral("actionPointCloudFilter"));
        actionPointCloudFilter->setCheckable(true);
        actionPointCloudFilter->setEnabled(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/scanner/Resources/Icons/filter.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPointCloudFilter->setIcon(icon);
        actionPointToSurface = new QAction(pointCloudEditToolBar);
        actionPointToSurface->setObjectName(QStringLiteral("actionPointToSurface"));
        actionPointToSurface->setCheckable(true);
        actionPointToSurface->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/scanner/Resources/Icons/pointToSurface.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPointToSurface->setIcon(icon1);

        pointCloudEditToolBar->addAction(actionPointCloudFilter);
        pointCloudEditToolBar->addAction(actionPointToSurface);

        retranslateUi(pointCloudEditToolBar);

        QMetaObject::connectSlotsByName(pointCloudEditToolBar);
    } // setupUi

    void retranslateUi(QToolBar *pointCloudEditToolBar)
    {
        pointCloudEditToolBar->setWindowTitle(QApplication::translate("pointCloudEditToolBar", "Center Axes Controls", 0));
        actionPointCloudFilter->setText(QApplication::translate("pointCloudEditToolBar", "Show Orientation Axes", 0));
#ifndef QT_NO_TOOLTIP
        actionPointCloudFilter->setToolTip(QApplication::translate("pointCloudEditToolBar", "Point Cloud Filter", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionPointCloudFilter->setStatusTip(QApplication::translate("pointCloudEditToolBar", "Point Cloud Filter", 0));
#endif // QT_NO_STATUSTIP
        actionPointToSurface->setText(QApplication::translate("pointCloudEditToolBar", "Show Center", 0));
#ifndef QT_NO_TOOLTIP
        actionPointToSurface->setToolTip(QApplication::translate("pointCloudEditToolBar", "Point To Surface", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionPointToSurface->setStatusTip(QApplication::translate("pointCloudEditToolBar", "Point To Surface", 0));
#endif // QT_NO_STATUSTIP
    } // retranslateUi

};

namespace Ui {
    class pointCloudEditToolBar: public Ui_pointCloudEditToolBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POINTCLOUDEDITTOOLBAR_H
