#include "mainwindow.h"
#include "GUI/menu.h"
#include <QApplication>
#include <QStackedWidget>
#include "GUI/combatscreen.h"
#include "source/combat.h"
#include "source/characters.h"
#include <memory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStackedWidget stack;

    auto warrior = std::make_shared<Warrior>();
    auto wizard = std::make_shared<Wizard>();
    auto ranger = std::make_shared<Ranger>();
    auto cleric = std::make_shared<Cleric>();
    auto dragon = std::make_shared<Dragon>();

    std::vector<std::shared_ptr<Character>> allCharacters = {
        warrior, wizard, ranger, cleric, dragon
    };


    Menu menu;
    Combatscreen screen;
    CombatLogic logic;

    screen.bindCharacterToUI(warrior.get(), screen.WarriorHealth);
    screen.bindCharacterToUI(wizard.get(), screen.WizardHealth);
    screen.bindCharacterToUI(ranger.get(), screen.RangerHealth);
    screen.bindCharacterToUI(cleric.get(), screen.ClericHealth);
    screen.bindCharacterToUI(dragon.get(), screen.dragonHealth);

    stack.addWidget(&menu);
    stack.addWidget(&screen);

    //Connections
    {
        QObject::connect(&menu, &Menu::startGame, [&](std::vector<Character*>& party, std::vector<Character*>& foes) {
            std::vector<Character*> combatParty = {warrior.get(), wizard.get(), ranger.get(), cleric.get()};
            std::vector<Character*> combatFoes = {dragon.get()};

            stack.setCurrentIndex(1);
            qDebug() <<"wir sind hier";
            logic.startCombat(combatParty, combatFoes);
        });
/*
        QObject::connect(&logic, &CombatLogic::turnStarter,
                         &screen, &Combatscreen::onturnStarter);
*/
        //QObject::connect(&logic, &CombatLogic::turnChanged,
        //                &screen, &Combatscreen::enablePlayerInput);

        QObject::connect(&logic, &CombatLogic::updateAbilityUI,
                        &screen, &Combatscreen::updateUI);

        QObject::connect(&logic, &CombatLogic::playerhealthChanged,
                         &screen, &Combatscreen::updatePlayerHealth);

        QObject::connect(&logic, &CombatLogic::enemyhealthChanged,
                         &screen, &Combatscreen::updateEnemyHealth);

        QObject::connect(&screen, &Combatscreen::AbilityRequest,
                         &logic, &CombatLogic::handleAbility);

    }

    stack.show();
    return a.exec();
}