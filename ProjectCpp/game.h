#ifndef GAME_H
#define GAME_H

#include <QSize>
#include <QObject>



class Game
{

    private:
        QSize const kanonGrootte = QSize(100,100);
        int const kogelSnelheid = 5;
        int const enemySpeed = 50;
        int const maxHealth = 3;
};

#endif // GAME_H
