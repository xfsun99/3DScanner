/********************************************************************************
** Form generated from reading UI file 'SettingMenuBuilders.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGMENUBUILDERS_H
#define UI_SETTINGMENUBUILDERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMenu>

QT_BEGIN_NAMESPACE

class Ui_SettingMenuBuilder
{
public:
    QAction *actionRenderWinBackColorSet;

    void setupUi(QMenu *SettingMenuBuilder)
    {
        if (SettingMenuBuilder->objectName().isEmpty())
            SettingMenuBuilder->setObjectName(QStringLiteral("SettingMenuBuilder"));
        actionRenderWinBackColorSet = new QAction(SettingMenuBuilder);
        actionRenderWinBackColorSet->setObjectName(QStringLiteral("actionRenderWinBackColorSet"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/scanner/Resources/Icons/colorA.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionRenderWinBackColorSet->setIcon(icon);

        SettingMenuBuilder->addAction(actionRenderWinBackColorSet);

        retranslateUi(SettingMenuBuilder);

        QMetaObject::connectSlotsByName(SettingMenuBuilder);
    } // setupUi

    void retranslateUi(QMenu *SettingMenuBuilder)
    {
#ifndef QT_NO_STATUSTIP
        SettingMenuBuilder->setStatusTip(QApplication::translate("SettingMenuBuilder", "Set Render Window Color", 0));
#endif // QT_NO_STATUSTIP
        SettingMenuBuilder->setTitle(QApplication::translate("SettingMenuBuilder", "Setting", 0));
        actionRenderWinBackColorSet->setText(QApplication::translate("SettingMenuBuilder", "Set Render Window Background", 0));
#ifndef QT_NO_TOOLTIP
        actionRenderWinBackColorSet->setToolTip(QApplication::translate("SettingMenuBuilder", "Set Render Window Backcolor", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionRenderWinBackColorSet->setStatusTip(QApplication::translate("SettingMenuBuilder", "Set Render Window Background", 0));
#endif // QT_NO_STATUSTIP
    } // retranslateUi

};

namespace Ui {
    class SettingMenuBuilder: public Ui_SettingMenuBuilder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGMENUBUILDERS_H
