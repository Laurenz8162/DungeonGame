#include <iostream>
#include <string>
#include "characters.h"
using namespace std;
Character::Character(const string& name,  int health,  int strength,  int magic,  int speed, int mana)
    : name(name), health(health), maxHealth(health),strength(strength), magic(magic), speed(speed), mana(mana)
{   critrate = strength/10; }
bool Character::isAlive() const {
    if (health == 0) {
        return false;
    }
    return true;
}
string Character::getName() const {
    return name;
}
int Character::getHealth () const {
    return health;
}
int Character::getStat(int select) {
    switch(select) {
        case 0: return strength;
        case 1: return magic;
        case 2: return speed;
        case 3: return mana;
        default: return 0;
    }
}

void Character::Ability(int index, Character *target) {
    qDebug() << "Why are you here";
}

QString Character::getAbilityName(int index) {
    return  "Angriff";
}