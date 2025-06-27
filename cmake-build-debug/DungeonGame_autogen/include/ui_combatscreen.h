/********************************************************************************
** Form generated from reading UI file 'combatscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMBATSCREEN_H
#define UI_COMBATSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Combatscreen
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Ability01;
    QPushButton *Ability02;
    QPushButton *Ability03;
    QGraphicsView *RangerWidget;
    QGraphicsView *ClericWidget;
    QGraphicsView *WizardWidget;
    QGraphicsView *WarriorWidget;
    QGraphicsView *DragonWidget;
    QProgressBar *clericHealthBar;
    QProgressBar *rangerHealthBar;
    QProgressBar *wizardHealthBar;
    QProgressBar *warriorHealthBar;
    QProgressBar *dragonHealthBar;

    void setupUi(QWidget *Combatscreen)
    {
        if (Combatscreen->objectName().isEmpty())
            Combatscreen->setObjectName("Combatscreen");
        Combatscreen->resize(1116, 797);
        verticalLayoutWidget = new QWidget(Combatscreen);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(150, 500, 251, 181));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Ability01 = new QPushButton(verticalLayoutWidget);
        Ability01->setObjectName("Ability01");

        verticalLayout->addWidget(Ability01);

        Ability02 = new QPushButton(verticalLayoutWidget);
        Ability02->setObjectName("Ability02");

        verticalLayout->addWidget(Ability02);

        Ability03 = new QPushButton(verticalLayoutWidget);
        Ability03->setObjectName("Ability03");

        verticalLayout->addWidget(Ability03);

        RangerWidget = new QGraphicsView(Combatscreen);
        RangerWidget->setObjectName("RangerWidget");
        RangerWidget->setGeometry(QRect(50, 200, 141, 141));
        ClericWidget = new QGraphicsView(Combatscreen);
        ClericWidget->setObjectName("ClericWidget");
        ClericWidget->setGeometry(QRect(210, 90, 141, 141));
        WizardWidget = new QGraphicsView(Combatscreen);
        WizardWidget->setObjectName("WizardWidget");
        WizardWidget->setGeometry(QRect(210, 320, 141, 141));
        WarriorWidget = new QGraphicsView(Combatscreen);
        WarriorWidget->setObjectName("WarriorWidget");
        WarriorWidget->setGeometry(QRect(380, 200, 161, 161));
        DragonWidget = new QGraphicsView(Combatscreen);
        DragonWidget->setObjectName("DragonWidget");
        DragonWidget->setGeometry(QRect(670, 80, 401, 401));
        clericHealthBar = new QProgressBar(Combatscreen);
        clericHealthBar->setObjectName("clericHealthBar");
        clericHealthBar->setGeometry(QRect(220, 50, 118, 23));
        clericHealthBar->setValue(24);
        rangerHealthBar = new QProgressBar(Combatscreen);
        rangerHealthBar->setObjectName("rangerHealthBar");
        rangerHealthBar->setGeometry(QRect(60, 160, 118, 23));
        rangerHealthBar->setValue(24);
        wizardHealthBar = new QProgressBar(Combatscreen);
        wizardHealthBar->setObjectName("wizardHealthBar");
        wizardHealthBar->setGeometry(QRect(220, 280, 118, 23));
        wizardHealthBar->setValue(24);
        warriorHealthBar = new QProgressBar(Combatscreen);
        warriorHealthBar->setObjectName("warriorHealthBar");
        warriorHealthBar->setGeometry(QRect(400, 160, 118, 23));
        warriorHealthBar->setValue(24);
        dragonHealthBar = new QProgressBar(Combatscreen);
        dragonHealthBar->setObjectName("dragonHealthBar");
        dragonHealthBar->setGeometry(QRect(760, 500, 251, 41));
        dragonHealthBar->setValue(24);

        retranslateUi(Combatscreen);

        QMetaObject::connectSlotsByName(Combatscreen);
    } // setupUi

    void retranslateUi(QWidget *Combatscreen)
    {
        Combatscreen->setWindowTitle(QCoreApplication::translate("Combatscreen", "Combatscreen", nullptr));
        Ability01->setText(QCoreApplication::translate("Combatscreen", "PushButton", nullptr));
        Ability02->setText(QCoreApplication::translate("Combatscreen", "PushButton", nullptr));
        Ability03->setText(QCoreApplication::translate("Combatscreen", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Combatscreen: public Ui_Combatscreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMBATSCREEN_H
