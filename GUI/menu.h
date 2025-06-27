#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <vector>
#include "characters.h"
#include <QPushButton>

class Menu : public QWidget {
    Q_OBJECT
public:
    explicit Menu(QWidget *parent = nullptr);

    signals:
        void startGame(std::vector<Character*>& party, std::vector<Character*>& foes);

    private slots:
        void onStartClicked();

private:
    QPushButton* startButton;
};

#endif // MENU_H