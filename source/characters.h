//
// Created by Laurenz on 24.06.2025.
//

#ifndef CHARACTERS_H
#define CHARACTERS_H
#include <QProgressBar>

using namespace std;
#include <string>
#include <QWidget>
#include <QGraphicsView>
#include <QString>

class Character {
public:
    Character(const string& name, int health, int strength, int magic, int speed, int mana);
    bool isAlive() const;
    string getName() const;
    int getHealth() const;
    int getStat (int select);

    virtual void Ability(int index, Character* target);
    virtual QString getAbilityName(int index);
    QProgressBar* healthbar;

    void receiveDamage(int amount) {
        health = max(0, health - amount);
        healthbar->setValue(health);
    }
    void receiveHealing(int amount) {
        health = max(0, health + amount);
        healthbar->setValue(health);
    }

    QGraphicsView* getWidget() const {
        return widget;
    }

    void setWidget(QGraphicsView* newwidget) {
        this->widget = newwidget;
    }


private:
    int maxHealth;
    string name;
    int health;
    int strength;
    int magic;
    int speed;
    int critrate;
    int mana;
    QGraphicsView* widget = nullptr;
};

class Warrior : public Character {
public:
    Warrior()
    : Character("Magnus Machtfaust", 80, 20, 5, 8, 10){}
    void Ability(int index, Character* target) override {
        switch(index) {
        case 0:
                 slash(target);
                 break;
        case 1:
                 bolster(target);
            break;
            case 2:
                 randomhit(target);
            break;
            default:
            break;
        }
    };
    void slash(Character* target) {
        target->receiveDamage( 10 + (rand()%10 + this->getStat(0)/10));
        qDebug() << "slashing";
    };
    void bolster(Character* target){
        this->receiveHealing(100);
    }
    void randomhit(Character* target){
        target->receiveDamage(rand() % 100);
    }
    QString getAbilityName(int index) override {
        switch(index){
            case 0:
                return "slash";
            case 1:
                return "bolster";
            case 2:
                return "randomhit";
            default:
                return "";
        }
    }
};

class Wizard : public Character {
public:
    Wizard()
    : Character("Salabrius der Weise", 25, 2, 20, 4, 100) {}
    void Ability(int index, Character* target) override {
        switch(index) {
            case 0:
                fireball(target);
            break;
            case 1:
                barrier(target);
            break;
            case 2:
                magicmissile(target);
            break;
            default:
                break;
        }
    };
    void fireball(Character* target) {
        int damage = 15 + (rand() % 10 + getStat(1)/5);  // Magic stat boosts damage
        target->receiveDamage(damage);
        qDebug() << "Fireball! (" << damage << "damage + Burn)";
    }
    void barrier(Character* target){}
    void magicmissile(Character* target){}
    QString getAbilityName(int index) override {
        switch(index){
            case 0:
                return "fireball";
            case 1:
                return "barrier";
            case 2:
                return "magicmissile";
            default:
                return "";
        }
    }
};

class Ranger : public Character {
public:
    Ranger()
        : Character("Helga Hartholz", 60, 15, 10, 10, 25) {}
    void arrow();
    void poison();
    void hide();
    QString getAbilityName(int index) override {
        switch(index){
            case 0:
                return "fireball";
            case 1:
                return "barrier";
            case 2:
                return "magicmissile";
            default:
                return "";
        }
    }
};

class Cleric : public Character {
public:
    Cleric()
        : Character("Vater Umpfred", 50, 10, 17, 2, 80) {}
    void heal();
    void smite();
    void healall(vector<Character*>& allies) {
        for (Character* ally : allies) {
            if (ally->isAlive()) {
                ally->receiveHealing(30 + getStat(1)); // Magic stat boosts healing
            }
        }
        qDebug() << "Mass healing wave!";
    }
};


class Dragon : public Character  {
public:
    Dragon()
    : Character("Tyrax der Grüne", 400, 20, 20, 1, 200) {}
    void Ability(int index, Character* target) override {
        switch(index) {
            case 0:
                Biss(target);
            break;
            case 1:
            break;
            case 2:
                stun(target);
            break;
            default:
                break;
        }
    };
    void Biss(Character* target) {
        target->receiveDamage(45);
    }
    void Feuer(vector<Character*>& targets) {
        for (Character* target : targets) {
            if (target->isAlive()) {
                int damage = 50 + (rand() % 20);
                target->receiveDamage(damage);
            }
        }
        qDebug() << "Drache speit";
    }
    void stun(Character* target){
        target->receiveDamage(100);
    }
};



#endif //CHARACTERS_H
