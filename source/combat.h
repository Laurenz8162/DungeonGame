#pragma once
#include <QObject>
#include <vector>
#include "characters.h"

class CombatLogic : public QObject {
    Q_OBJECT
public:
    explicit CombatLogic(QObject *parent = nullptr);
    void startCombat(std::vector<Character*>& party, std::vector<Character*>& foes);
    void handleAIAbility();
    bool checkPlayerVictory();

    Character* currentActor = nullptr;
    const std::vector<Character*>& playerParty() const;
    const std::vector<Character*>& enemies() const;

    signals:
    void playerhealthChanged(int newhp, Character* target);
    void enemyhealthChanged(int newhp, Character* target);
    void combatEnded(bool playerWon);
    void statusApplied(Character* target, int statusType);
    void updateStatusDisplay();
    void enablePlayerInput(bool enabled);
    void updateAbilityUI(Character* currentActor, bool isPlayerTurn);

    public slots:
        void handleAbility(int index, Character* caster);
        void handleAreaAbility(int indext, bool targetsAllies);

private:
    void nextTurn();
    void endTurn();
    void checkBattleEnd();
    void sortTurnOrder();

    std::vector<Character*> m_playerParty;
    std::vector<Character*> m_enemies;
    std::vector<Character*> m_turnorder;
    int turnindex = -1;
    bool isPlayerTurn = true;
};