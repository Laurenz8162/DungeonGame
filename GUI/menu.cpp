#include "menu.h"
#include <QVBoxLayout>

Menu::Menu(QWidget *parent) : QWidget(parent) {
    startButton = new QPushButton("Start Game", this);
    startButton->setStyleSheet("font-size: 18px; padding: 10px;");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(startButton);
    layout->setSpacing(20);
    layout->setContentsMargins(50, 50, 50, 50);

    connect(startButton, &QPushButton::clicked, this, &Menu::onStartClicked);
    setWindowTitle("RPG Main Menu");
    resize(400, 300);
}

void Menu::onStartClicked() {
    std::vector<Character*> emptyParty;
    std::vector<Character*> emptyFoes;
    emit startGame(emptyParty, emptyFoes);
}