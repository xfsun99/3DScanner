/********************************************************************************
** Form generated from reading UI file 'MainControlsToolbar.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINCONTROLSTOOLBAR_H
#define UI_MAINCONTROLSTOOLBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolBar>

QT_BEGIN_NAMESPACE

class Ui_MainControlsToolbar
{
public:
    QAction *actionOpenData;
    QAction *actionSaveData;
    QAction *actionHelp;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionLoadImages;

    void setupUi(QToolBar *MainControlsToolbar)
    {
        if (MainControlsToolbar->objectName().isEmpty())
            MainControlsToolbar->setObjectName(QStringLiteral("MainControlsToolbar"));
        MainControlsToolbar->resize(234, 48);
        QFont font;
        font.setPointSize(9);
        MainControlsToolbar->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/scanner/Resources/Icons/3D.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainControlsToolbar->setWindowIcon(icon);
        MainControlsToolbar->setOrientation(Qt::Horizontal);
        MainControlsToolbar->setFloatable(true);
        actionOpenData = new QAction(MainControlsToolbar);
        actionOpenData->setObjectName(QStringLiteral("actionOpenData"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/scanner/Resources/Icons/pqOpen24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenData->setIcon(icon1);
        actionOpenData->setProperty("PV_MUST_BE_MASTER_TO_SHOW", QVariant(true));
        actionSaveData = new QAction(MainControlsToolbar);
        actionSaveData->setObjectName(QStringLiteral("actionSaveData"));
        actionSaveData->setEnabled(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/scanner/Resources/Icons/pqSave24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveData->setIcon(icon2);
        actionSaveData->setProperty("PV_MUST_BE_MASTER_TO_SHOW", QVariant(true));
        actionHelp = new QAction(MainControlsToolbar);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/scanner/Resources/Icons/pqHelp24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon3);
        actionUndo = new QAction(MainControlsToolbar);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/scanner/Resources/Icons/pqUndo24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon4);
        actionUndo->setVisible(true);
        actionRedo = new QAction(MainControlsToolbar);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/scanner/Resources/Icons/pqRedo24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon5);
        actionLoadImages = new QAction(MainControlsToolbar);
        actionLoadImages->setObjectName(QStringLiteral("actionLoadImages"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/scanner/Resources/Icons/importPictureDocument.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoadImages->setIcon(icon6);

        MainControlsToolbar->addAction(actionLoadImages);
        MainControlsToolbar->addAction(actionOpenData);
        MainControlsToolbar->addAction(actionSaveData);
        MainControlsToolbar->addSeparator();
        MainControlsToolbar->addAction(actionUndo);
        MainControlsToolbar->addAction(actionRedo);
        MainControlsToolbar->addSeparator();
        MainControlsToolbar->addAction(actionHelp);

        retranslateUi(MainControlsToolbar);

        QMetaObject::connectSlotsByName(MainControlsToolbar);
    } // setupUi

    void retranslateUi(QToolBar *MainControlsToolbar)
    {
        MainControlsToolbar->setWindowTitle(QApplication::translate("MainControlsToolbar", "Main Controls", 0));
        actionOpenData->setText(QApplication::translate("MainControlsToolbar", "Open...", 0));
#ifndef QT_NO_STATUSTIP
        actionOpenData->setStatusTip(QApplication::translate("MainControlsToolbar", "Open", 0));
#endif // QT_NO_STATUSTIP
        actionSaveData->setText(QApplication::translate("MainControlsToolbar", "Save Data...", 0));
        actionHelp->setText(QApplication::translate("MainControlsToolbar", "Help", 0));
        actionUndo->setText(QApplication::translate("MainControlsToolbar", "&Undo", 0));
        actionUndo->setIconText(QApplication::translate("MainControlsToolbar", "Undo", 0));
#ifndef QT_NO_TOOLTIP
        actionUndo->setToolTip(QApplication::translate("MainControlsToolbar", "Undo(Ctrl+Z)", 0));
#endif // QT_NO_TOOLTIP
        actionUndo->setShortcut(QApplication::translate("MainControlsToolbar", "Ctrl+Z", 0));
        actionRedo->setText(QApplication::translate("MainControlsToolbar", "&Redo", 0));
#ifndef QT_NO_TOOLTIP
        actionRedo->setToolTip(QApplication::translate("MainControlsToolbar", "Redo(Ctrl+R)", 0));
#endif // QT_NO_TOOLTIP
        actionRedo->setShortcut(QApplication::translate("MainControlsToolbar", "Ctrl+R", 0));
        actionLoadImages->setText(QApplication::translate("MainControlsToolbar", "LoadImages", 0));
    } // retranslateUi

};

namespace Ui {
    class MainControlsToolbar: public Ui_MainControlsToolbar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINCONTROLSTOOLBAR_H
