#include "combat.h"
#include "characters.h"
#include <QTimer>

CombatLogic::CombatLogic(QObject *parent) : QObject(parent) {}

void CombatLogic::startCombat(std::vector<Character*>& party, std::vector<Character*>& foes) {
    m_playerParty = party;
    m_enemies = foes;
    sortTurnOrder();
    nextTurn();
}

void CombatLogic::nextTurn() {


    turnindex = (turnindex + 1) % m_turnorder.size();
    currentActor = m_turnorder[turnindex];

    // emit highlightActor(currentActor);

    if (!currentActor->isAlive()) {
        QTimer::singleShot(100, this, &CombatLogic::nextTurn);  // Fast-forward
        return;
    }

    isPlayerTurn = (find(m_playerParty.begin(), m_playerParty.end(), currentActor) != m_playerParty.end());
    emit updateAbilityUI(currentActor,isPlayerTurn);

    //emit turnStarter(currentActor);
    //emit enablePlayerInput(isPlayerTurn);

    if (!isPlayerTurn) {
        QTimer::singleShot(1000, this, [this]() {
            handleAIAbility();
        });
    }
}

void CombatLogic::handleAIAbility() {
    std::vector<Character*> alivePlayers;
    for (Character* c : m_playerParty) {
        if (c->isAlive()) alivePlayers.push_back(c);
    }

    if (!alivePlayers.empty()) {
        Character* target = alivePlayers[rand() % alivePlayers.size()];
        int abilityIndex = rand() % 3;

        currentActor->Ability(abilityIndex, target);
        emit playerhealthChanged(target->getHealth(), target);
        endTurn();
    }
}

void CombatLogic::endTurn() {

        sortTurnOrder();
    qDebug()<<"check check";
    QTimer::singleShot(1000, this, &CombatLogic::nextTurn);
}

void CombatLogic::handleAbility(int index, Character* caster) {
    int random = rand() % 4;
    caster->Ability(index, isPlayerTurn ? m_enemies[0] : m_playerParty[random]);
    isPlayerTurn ? emit enemyhealthChanged(m_enemies[0]->getHealth(), m_enemies[0])
                        : emit playerhealthChanged(m_playerParty[random]->getHealth(),m_playerParty[random]);
    endTurn();
}

void CombatLogic::sortTurnOrder() {

        m_turnorder.clear();

        std::vector<Character*> allCombatants;
        allCombatants.insert(allCombatants.end(), m_playerParty.begin(), m_playerParty.end());
        allCombatants.insert(allCombatants.end(), m_enemies.begin(), m_enemies.end());

        auto speedCompare = [](Character* a, Character* b) {
            return a->getStat(3) > b->getStat(3);
        };

        std::sort(allCombatants.begin(), allCombatants.end(), speedCompare);

        for (Character* c : allCombatants) {
            if (c->isAlive()) {
                m_turnorder.push_back(c);
            }
        }
}

    bool CombatLogic::checkPlayerVictory()  {
        // Players win if at least one enemy is dead and one player is alive
        for (Character* enemy : m_enemies) {
            if (!enemy->isAlive()) {
                for (Character* player : m_playerParty) {
                    if (player->isAlive()) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

void CombatLogic::handleAreaAbility(int index, bool targetsAllies) {
    if (!currentActor || !isPlayerTurn) return;

    std::vector<Character*> targets;
    if (targetsAllies) {
        targets = m_playerParty;
    } else {
        targets = m_enemies;
    }

    if (dynamic_cast<Cleric*>(currentActor) && index == 2) { // Healall
        dynamic_cast<Cleric*>(currentActor)->healall(m_playerParty);
        emit updateStatusDisplay();
    }
    else if (dynamic_cast<Dragon*>(currentActor) && index == 1) { // Fire breath
        dynamic_cast<Dragon*>(currentActor)->Feuer(m_playerParty);
        emit updateStatusDisplay();
    }

    endTurn();
}