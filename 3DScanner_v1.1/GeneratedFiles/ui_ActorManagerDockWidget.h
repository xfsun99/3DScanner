/********************************************************************************
** Form generated from reading UI file 'ActorManagerDockWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTORMANAGERDOCKWIDGET_H
#define UI_ACTORMANAGERDOCKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ActorManagerDockWidget
{
public:
    QGridLayout *gridLayout;
    QListWidget *listWidget;

    void setupUi(QWidget *ActorManagerDockWidget)
    {
        if (ActorManagerDockWidget->objectName().isEmpty())
            ActorManagerDockWidget->setObjectName(QStringLiteral("ActorManagerDockWidget"));
        ActorManagerDockWidget->setEnabled(true);
        ActorManagerDockWidget->resize(239, 282);
        gridLayout = new QGridLayout(ActorManagerDockWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        listWidget = new QListWidget(ActorManagerDockWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout->addWidget(listWidget, 0, 0, 1, 1);


        retranslateUi(ActorManagerDockWidget);

        QMetaObject::connectSlotsByName(ActorManagerDockWidget);
    } // setupUi

    void retranslateUi(QWidget *ActorManagerDockWidget)
    {
        Q_UNUSED(ActorManagerDockWidget);
    } // retranslateUi

};

namespace Ui {
    class ActorManagerDockWidget: public Ui_ActorManagerDockWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTORMANAGERDOCKWIDGET_H
