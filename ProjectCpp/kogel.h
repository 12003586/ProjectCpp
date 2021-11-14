#ifndef KOGEL_H
#define KOGEL_H

#include <game.h>

class kogel:public QObject
{
    Q_OBJECT
signals:
    void verhoogScore();
    void verlaagScore();

public slots:
    void onMove();
};

#endif // KOGEL_H
