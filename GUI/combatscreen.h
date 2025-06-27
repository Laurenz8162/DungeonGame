#ifndef COMBATSCREEN_H
#define COMBATSCREEN_H

#include <QWidget>
#include <QGraphicsScene>
#include <QProgressBar>
#include "../source/characters.h"
#include <QGraphicsView>
#include <QLabel>
namespace Ui {
    class Combatscreen;
}
QT_BEGIN_NAMESPACE
namespace Ui { class Combatscreen; }
QT_END_NAMESPACE

class Combatscreen : public QWidget
{
    Q_OBJECT

public:
    explicit Combatscreen(QWidget *parent = nullptr);
    ~Combatscreen();

    void updateEnemyHealth(int newHp, Character* target);
    void updatePlayerHealth(int newHp, Character* target);
    void enablePlayerInput(bool enabled);
    void bindCharacterToUI(Character* actor, QProgressBar* healthBar);
    void bindCharacterWidgets();
    //Bars
    QProgressBar* dragonHealth;
    QProgressBar* WarriorHealth;
    QProgressBar* WizardHealth;
    QProgressBar* RangerHealth;
    QProgressBar* ClericHealth;

    QHash <Character*, QProgressBar*> characterbar;

    QGraphicsView* getWarriorWidget();
    QGraphicsView* getWizardWidget();
    QGraphicsView* getClericWidget();
    QGraphicsView* getRangerWidget();
    QGraphicsView* getDragonWidget();
    signals:
        void AbilityRequest(int index, Character* actor);
public slots:
    void updateUI(Character* currentActor, bool isPlayerTurn);
    //void onturnStarter(Character* actor);
private:
    QHash<Character*, QVector<QLabel*>> statusIcons;
    void updateStatusDisplay(Character* character);
    Ui::Combatscreen *ui;
    Character* currentActor;
    // UI Setup helpers
    void setupCharacterScene(const QString& imagePath, QGraphicsView* view);
    void setupAbilityButtons();
    void styleHealthBar(QProgressBar* bar, const QColor& color);

    // Effects
    void shakeView(QGraphicsView* view);
};

#endif // COMBATSCREEN_H