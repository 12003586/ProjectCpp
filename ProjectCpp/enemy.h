#ifndef ENEMY_H
#define ENEMY_H

#include <game.h>



class enemy: public QObject
{
    Q_OBJECT
signals:
    void verlaagHealth();
    void gameOver();
public slots:
    void onMove();



};

#endif // ENEMY_H
