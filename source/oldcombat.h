//
// Created by Laurenz on 24.06.2025.
//
#ifndef COMBAT_H
#define COMBAT_H
#include <QObject>
#include <vector>
#include <memory>
#include "characters.h"
using namespace std;


class CombatLogic : public QObject {
public:
    //combat start
    explicit CombatLogic(QObject *parent = nullptr);

    void startCombat (vector<Character*>& Party, vector<Character*>& Foes);

    //turns
    void nextTurn ();
    bool isBattleover ();
    bool isPlayerTurn;

    //actions player
    void playerTurn();
    void passTurn();

    //get
    Character* CurrentActor() const;
    const vector<Character*>& getPlayerParty() const;
    const vector<Character*>& getEnemies() const;

private:
    vector<Character*> playerParty;
    vector<Character*> Enemies;
    int currentActorID;
    void turnOrder(vector<Character*> &playerParty, vector<Character*> &Enemies);
    void CombatStarted();

    void EnemyTurn();
    void EndBattle();
    void spawnNextWave();
    void checkStatus();
};


#endif //COMBAT_H
