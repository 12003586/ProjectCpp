#ifndef GAME_H
#define GAME_H

#include <QSize>
#include <QObject>
#include <QTimer>
#include <QtWidgets/QGraphicsPixmapItem>
#include <QtWidgets/QGraphicsSimpleTextItem>
#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>


namespace BO  {


    enum class Kleur
    {
        Rood, Roze,Blauw
    };
            QSize const kanonGrootte    = QSize(100,100);
            int const kogelSnelheid     = 5;
            int const enemySpeed        = 50;
            int const maxHealth         = 3;

}

#endif // GAME_H
