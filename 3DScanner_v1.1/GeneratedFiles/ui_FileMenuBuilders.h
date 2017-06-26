/********************************************************************************
** Form generated from reading UI file 'FileMenuBuilders.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEMENUBUILDERS_H
#define UI_FILEMENUBUILDERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMenu>

QT_BEGIN_NAMESPACE

class Ui_FileMenuBuilder
{
public:
    QAction *actionFileOpen;
    QAction *actionFileExit;
    QMenu *menuRecentFiles;

    void setupUi(QMenu *FileMenuBuilder)
    {
        if (FileMenuBuilder->objectName().isEmpty())
            FileMenuBuilder->setObjectName(QStringLiteral("FileMenuBuilder"));
        actionFileOpen = new QAction(FileMenuBuilder);
        actionFileOpen->setObjectName(QStringLiteral("actionFileOpen"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/pqWidgets/Icons/pqOpen24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFileOpen->setIcon(icon);
        actionFileOpen->setProperty("PV_MUST_BE_MASTER_TO_SHOW", QVariant(true));
        actionFileExit = new QAction(FileMenuBuilder);
        actionFileExit->setObjectName(QStringLiteral("actionFileExit"));
        menuRecentFiles = new QMenu(FileMenuBuilder);
        menuRecentFiles->setObjectName(QStringLiteral("menuRecentFiles"));

        FileMenuBuilder->addAction(actionFileOpen);
        FileMenuBuilder->addAction(menuRecentFiles->menuAction());
        FileMenuBuilder->addSeparator();
        FileMenuBuilder->addAction(actionFileExit);

        retranslateUi(FileMenuBuilder);

        QMetaObject::connectSlotsByName(FileMenuBuilder);
    } // setupUi

    void retranslateUi(QMenu *FileMenuBuilder)
    {
        FileMenuBuilder->setTitle(QApplication::translate("FileMenuBuilder", "&File", 0));
        actionFileOpen->setText(QApplication::translate("FileMenuBuilder", "&Open...", 0));
#ifndef QT_NO_STATUSTIP
        actionFileOpen->setStatusTip(QApplication::translate("FileMenuBuilder", "Open", 0));
#endif // QT_NO_STATUSTIP
        actionFileOpen->setShortcut(QApplication::translate("FileMenuBuilder", "Ctrl+O", 0));
        actionFileExit->setText(QApplication::translate("FileMenuBuilder", "E&xit", 0));
#ifndef QT_NO_STATUSTIP
        actionFileExit->setStatusTip(QApplication::translate("FileMenuBuilder", "Exit", 0));
#endif // QT_NO_STATUSTIP
        actionFileExit->setShortcut(QApplication::translate("FileMenuBuilder", "Ctrl+Q", 0));
        menuRecentFiles->setTitle(QApplication::translate("FileMenuBuilder", "Recent Files", 0));
    } // retranslateUi

};

namespace Ui {
    class FileMenuBuilder: public Ui_FileMenuBuilder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEMENUBUILDERS_H
