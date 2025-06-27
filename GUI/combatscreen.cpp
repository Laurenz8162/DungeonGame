#include "combatscreen.h"
#include "ui_combatscreen.h"
#include <QPushButton>
#include <QTime>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QElapsedTimer>
#include <QRandomGenerator>
#include <QProgressBar>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
Combatscreen::Combatscreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Combatscreen),
    currentActor(new Warrior())
{
    ui->setupUi(this);
    setFixedSize(1100, 750);

    // Scenes

    // Warrior
    {
        QGraphicsScene* Warriorscene = new QGraphicsScene(this);
        QPixmap Warriorimg(":/Sprites/warrior.jpg");
        Warriorscene->addPixmap(Warriorimg);
        ui->WarriorWidget->setScene(Warriorscene);
        ui->WarriorWidget->fitInView(Warriorscene->itemsBoundingRect(), Qt::KeepAspectRatioByExpanding);
        ui->WarriorWidget->setFrameStyle(QFrame::NoFrame);
    }
    // Wizard
    {
        QGraphicsScene* Wizardscene = new QGraphicsScene(this);
        QPixmap Wizardimg(":/Sprites/wizard.jpg");
        Wizardscene->addPixmap(Wizardimg);
        ui->WizardWidget->setScene(Wizardscene);
        ui->WizardWidget->fitInView(Wizardscene->itemsBoundingRect(), Qt::KeepAspectRatioByExpanding);
        ui->WizardWidget->setFrameStyle(QFrame::NoFrame);
    }
    // Ranger
    {
        QGraphicsScene* Rangerscene = new QGraphicsScene(this);
        QPixmap Rangerimg(":/Sprites/ranger.JPG");
        Rangerscene->addPixmap(Rangerimg);
        ui->RangerWidget->setScene(Rangerscene);
        ui->RangerWidget->fitInView(Rangerscene->itemsBoundingRect(), Qt::KeepAspectRatioByExpanding);
        ui->RangerWidget->setFrameStyle(QFrame::NoFrame);
    }
    // Cleric
    {
        QGraphicsScene* Clericscene = new QGraphicsScene(this);
        QPixmap Clericimg(":/Sprites/cleric.png");
        Clericscene->addPixmap(Clericimg);
        ui->ClericWidget->setScene(Clericscene);
        ui->ClericWidget->fitInView(Clericscene->itemsBoundingRect(), Qt::KeepAspectRatioByExpanding);
        ui->ClericWidget->setFrameStyle(QFrame::NoFrame);
    }
    // Drache
    {
        QGraphicsScene* Drachescene = new QGraphicsScene(this);
        QPixmap Dracheimg(":/Sprites/drache.PNG");
        Drachescene->addPixmap(Dracheimg);
        ui->DragonWidget->setScene(Drachescene);
        ui->DragonWidget->fitInView(Drachescene->itemsBoundingRect(), Qt::KeepAspectRatioByExpanding);
        ui->DragonWidget->setFrameStyle(QFrame::NoFrame);
    }

    //HealthBars
    {
        WarriorHealth = findChild<QProgressBar*>("warriorHealthBar");
        styleHealthBar(WarriorHealth, Qt::red);
        dragonHealth = findChild<QProgressBar*>("dragonHealthBar");
        WizardHealth = findChild<QProgressBar*>("wizardHealthBar");
        ClericHealth = findChild<QProgressBar*>("clericHealthBar");
        RangerHealth = findChild<QProgressBar*>("rangerHealthBar");
    }

    //Boxes


    // Connect ability buttons
    setupAbilityButtons();

}

Combatscreen::~Combatscreen() {
    delete ui;
}
/*
void Combatscreen::onturnStarter(Character *actor) {
    currentActor = actor;
    updateUI();
}
*/

void Combatscreen::updateUI(Character* currentActor, bool isPlayerTurn) {
    QString disabledStyle = "color: #777; background-color: #222;";
    QString enabledStyle = "color: white; background-color: #4CAF50;";
    QString medievalButtonStyle = R"(
    QPushButton {
        background-color: #3a2c1a;
        color: #e8d8a0;
        border: 3px solid #5a4a2a;
        border-radius: 0px; /* Sharp edges for pixel art */
        padding: 5px;
        font-family: "Courier New";
        font-size: 14px;
        font-weight: bold;
        min-width: 80px;
        min-height: 30px;
    }
    QPushButton:hover {
        background-color: #5a4a2a;
        border: 3px solid #7a6a4a;
    }
    QPushButton:pressed {
        background-color: #2a1c0a;
        border: 3px solid #4a3a1a;
    }
    QPushButton:disabled {
        background-color: #2a2a2a;
        color: #6a6a6a;
        border: 3px solid #3a3a3a;
    }
)";

    QPushButton* buttons[3] = {
        ui->Ability01,
        ui->Ability02,
        ui->Ability03
    };
    qDebug() << "nach qpusch";
    for (int i = 0; i < 3; ++i) {
        if(buttons[i]) {
            buttons[i]->setText(isPlayerTurn ? currentActor->getAbilityName(i) : "(Enemy Turn)");
            buttons[i]->setEnabled(isPlayerTurn);
            buttons[i]->setStyleSheet(isPlayerTurn ? medievalButtonStyle : disabledStyle);

            if (isPlayerTurn) {
                QGraphicsOpacityEffect* fade = new QGraphicsOpacityEffect(buttons[i]);
                buttons[i]->setGraphicsEffect(fade);

                QPropertyAnimation* anim = new QPropertyAnimation(fade, "opacity");
                anim->setDuration(300);
                anim->setStartValue(0.3);
                anim->setEndValue(1.0);
                anim->start(QAbstractAnimation::DeleteWhenStopped);
            }
        }
    }
}


void Combatscreen::setupCharacterScene(const QString& imagePath, QGraphicsView* view) {
    QGraphicsScene* scene = new QGraphicsScene(this);
    scene->addPixmap(QPixmap(imagePath));
    view->setScene(scene);
    view->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatioByExpanding);
    view->setFrameStyle(QFrame::NoFrame);
}

void Combatscreen::setupAbilityButtons() {
    auto connectButton = [this](QPushButton* button, int abilityId) {
        connect(button, &QPushButton::clicked, this, [this, abilityId]() {
            if(currentActor) {
                shakeView(ui->DragonWidget);
                emit AbilityRequest(abilityId, currentActor);
            }
        });
    };

    connectButton(ui->Ability01, 0);
    connectButton(ui->Ability02, 1);
    connectButton(ui->Ability03, 2);
}

void Combatscreen::shakeView(QGraphicsView* view) {
    if (!view) return;
    int durationMs = 800;
    int intervalMs = 30;
    int intensity = 5;

    // Store original position
    QPoint originalPos = view->pos();
    QElapsedTimer* elapsed = new QElapsedTimer();
    elapsed->start();

    QTimer* timer = new QTimer(view);  // parented to view for auto-cleanup

    QObject::connect(timer, &QTimer::timeout, view, [=]() mutable {
        if (elapsed->elapsed() > durationMs) {
            view->move(originalPos); // Reset position
            timer->stop();
            timer->deleteLater();
            delete elapsed;
            return;
        }

        // Generate random offset
        int dx = QRandomGenerator::global()->bounded(-intensity, intensity + 1);
        int dy = QRandomGenerator::global()->bounded(-intensity, intensity + 1);
        view->move(originalPos + QPoint(dx, dy));
    });

    timer->start(intervalMs);
}

void Combatscreen::updateEnemyHealth(int newHp, Character* target) {
    characterbar[target]->setValue(newHp);
}

void Combatscreen::updatePlayerHealth(int newHp, Character* target) {
    characterbar[target]->setValue(newHp);
}

void Combatscreen::enablePlayerInput(bool enabled) {
}

void Combatscreen::bindCharacterToUI(Character* character, QProgressBar* healthBar)
{
    if(healthBar) {
        healthBar->setRange(0, character->getHealth());
        healthBar->setValue(character->getHealth());
        character->healthbar = healthBar;
    }
    characterbar[character] = healthBar;
}

void Combatscreen::styleHealthBar(QProgressBar* bar, const QColor& color) {
    bar->setStyleSheet(QString(
        "QProgressBar {"
        "border: 2px solid %1;"
        "border-radius: 5px;"
        "text-align: center;"
        "}"
        "QProgressBar::chunk {"
        "background-color: %1;"
        "}"
    ).arg(color.name()));
}
