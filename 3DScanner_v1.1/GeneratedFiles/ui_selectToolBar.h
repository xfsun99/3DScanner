/********************************************************************************
** Form generated from reading UI file 'selectToolBar.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTTOOLBAR_H
#define UI_SELECTTOOLBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolBar>

QT_BEGIN_NAMESPACE

class Ui_selectToolbar
{
public:
    QAction *actionSelectPointThroug;
    QAction *actionPolySelectSurfacePoint;
    QAction *actionSelectCellOn;
    QAction *actionSelectCellThroug;
    QAction *actionSelectPointOn;
    QAction *actionPolySelectSurfaceCell;
    QAction *actionSaveSelectedPart;
    QAction *actionDeleleSelectedPart;

    void setupUi(QToolBar *selectToolbar)
    {
        if (selectToolbar->objectName().isEmpty())
            selectToolbar->setObjectName(QStringLiteral("selectToolbar"));
        selectToolbar->setEnabled(true);
        selectToolbar->resize(274, 38);
        selectToolbar->setOrientation(Qt::Horizontal);
        actionSelectPointThroug = new QAction(selectToolbar);
        actionSelectPointThroug->setObjectName(QStringLiteral("actionSelectPointThroug"));
        actionSelectPointThroug->setCheckable(false);
        actionSelectPointThroug->setEnabled(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/scanner/Resources/Icons/pqFrustumSelectionPoint24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelectPointThroug->setIcon(icon);
        actionPolySelectSurfacePoint = new QAction(selectToolbar);
        actionPolySelectSurfacePoint->setObjectName(QStringLiteral("actionPolySelectSurfacePoint"));
        actionPolySelectSurfacePoint->setCheckable(false);
        actionPolySelectSurfacePoint->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/scanner/Resources/Icons/pqPolygonSelectSurfacePoint24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPolySelectSurfacePoint->setIcon(icon1);
        actionSelectCellOn = new QAction(selectToolbar);
        actionSelectCellOn->setObjectName(QStringLiteral("actionSelectCellOn"));
        actionSelectCellOn->setCheckable(false);
        actionSelectCellOn->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/scanner/Resources/Icons/pqSurfaceSelectionCell24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelectCellOn->setIcon(icon2);
        actionSelectCellThroug = new QAction(selectToolbar);
        actionSelectCellThroug->setObjectName(QStringLiteral("actionSelectCellThroug"));
        actionSelectCellThroug->setCheckable(false);
        actionSelectCellThroug->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/scanner/Resources/Icons/pqFrustumSelectionCell24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelectCellThroug->setIcon(icon3);
        actionSelectPointOn = new QAction(selectToolbar);
        actionSelectPointOn->setObjectName(QStringLiteral("actionSelectPointOn"));
        actionSelectPointOn->setCheckable(false);
        actionSelectPointOn->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/scanner/Resources/Icons/pqSurfaceSelectionPoint24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelectPointOn->setIcon(icon4);
        actionPolySelectSurfaceCell = new QAction(selectToolbar);
        actionPolySelectSurfaceCell->setObjectName(QStringLiteral("actionPolySelectSurfaceCell"));
        actionPolySelectSurfaceCell->setCheckable(false);
        actionPolySelectSurfaceCell->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/scanner/Resources/Icons/pqPolygonSelectSurfaceCell24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPolySelectSurfaceCell->setIcon(icon5);
        actionSaveSelectedPart = new QAction(selectToolbar);
        actionSaveSelectedPart->setObjectName(QStringLiteral("actionSaveSelectedPart"));
        actionSaveSelectedPart->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/scanner/Resources/Icons/pqFloppyDisk32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveSelectedPart->setIcon(icon6);
        actionDeleleSelectedPart = new QAction(selectToolbar);
        actionDeleleSelectedPart->setObjectName(QStringLiteral("actionDeleleSelectedPart"));
        actionDeleleSelectedPart->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/scanner/Resources/Icons/pqQuit22.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDeleleSelectedPart->setIcon(icon7);

        selectToolbar->addAction(actionSelectCellThroug);
        selectToolbar->addAction(actionSelectPointThroug);
        selectToolbar->addSeparator();
        selectToolbar->addAction(actionSelectCellOn);
        selectToolbar->addAction(actionSelectPointOn);
        selectToolbar->addSeparator();
        selectToolbar->addAction(actionPolySelectSurfaceCell);
        selectToolbar->addAction(actionPolySelectSurfacePoint);
        selectToolbar->addSeparator();
        selectToolbar->addAction(actionSaveSelectedPart);
        selectToolbar->addAction(actionDeleleSelectedPart);

        retranslateUi(selectToolbar);

        QMetaObject::connectSlotsByName(selectToolbar);
    } // setupUi

    void retranslateUi(QToolBar *selectToolbar)
    {
        selectToolbar->setWindowTitle(QApplication::translate("selectToolbar", "Center Axes Controls", 0));
        actionSelectPointThroug->setText(QApplication::translate("selectToolbar", "Show Orientation Axes", 0));
#ifndef QT_NO_TOOLTIP
        actionSelectPointThroug->setToolTip(QApplication::translate("selectToolbar", "Select Points Through", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSelectPointThroug->setStatusTip(QApplication::translate("selectToolbar", "Select Points Through", 0));
#endif // QT_NO_STATUSTIP
        actionPolySelectSurfacePoint->setText(QApplication::translate("selectToolbar", "Show Center", 0));
#ifndef QT_NO_TOOLTIP
        actionPolySelectSurfacePoint->setToolTip(QApplication::translate("selectToolbar", "Poly Select Points On Surface", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionPolySelectSurfacePoint->setStatusTip(QApplication::translate("selectToolbar", "Poly Select Points On Surface", 0));
#endif // QT_NO_STATUSTIP
        actionSelectCellOn->setText(QApplication::translate("selectToolbar", "Pick Center", 0));
        actionSelectCellOn->setIconText(QApplication::translate("selectToolbar", "Pick Center", 0));
#ifndef QT_NO_TOOLTIP
        actionSelectCellOn->setToolTip(QApplication::translate("selectToolbar", "Select Cells On Surface", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSelectCellOn->setStatusTip(QApplication::translate("selectToolbar", "Select Cells On Surface", 0));
#endif // QT_NO_STATUSTIP
        actionSelectCellThroug->setText(QApplication::translate("selectToolbar", "Reset Center", 0));
#ifndef QT_NO_TOOLTIP
        actionSelectCellThroug->setToolTip(QApplication::translate("selectToolbar", "Select Cells Through", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSelectCellThroug->setStatusTip(QApplication::translate("selectToolbar", "Select Cells Through", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionSelectCellThroug->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        actionSelectPointOn->setText(QApplication::translate("selectToolbar", "selectPointOn", 0));
#ifndef QT_NO_TOOLTIP
        actionSelectPointOn->setToolTip(QApplication::translate("selectToolbar", "Select Points On Surface", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSelectPointOn->setStatusTip(QApplication::translate("selectToolbar", "Select Points On Surface", 0));
#endif // QT_NO_STATUSTIP
        actionPolySelectSurfaceCell->setText(QApplication::translate("selectToolbar", "selectSurfaceCell", 0));
#ifndef QT_NO_TOOLTIP
        actionPolySelectSurfaceCell->setToolTip(QApplication::translate("selectToolbar", "Poly Select Cells On Surface", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionPolySelectSurfaceCell->setStatusTip(QApplication::translate("selectToolbar", "Poly Select Cells On Surface", 0));
#endif // QT_NO_STATUSTIP
        actionSaveSelectedPart->setText(QApplication::translate("selectToolbar", "saveSelectedPart", 0));
#ifndef QT_NO_TOOLTIP
        actionSaveSelectedPart->setToolTip(QApplication::translate("selectToolbar", "Save Selected Part", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSaveSelectedPart->setStatusTip(QApplication::translate("selectToolbar", "Save Selected Part", 0));
#endif // QT_NO_STATUSTIP
        actionDeleleSelectedPart->setText(QApplication::translate("selectToolbar", "DeleleSelectedPart", 0));
#ifndef QT_NO_TOOLTIP
        actionDeleleSelectedPart->setToolTip(QApplication::translate("selectToolbar", "Delele Selected Part", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionDeleleSelectedPart->setStatusTip(QApplication::translate("selectToolbar", "Delele Selected Part", 0));
#endif // QT_NO_STATUSTIP
    } // retranslateUi

};

namespace Ui {
    class selectToolbar: public Ui_selectToolbar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTTOOLBAR_H
