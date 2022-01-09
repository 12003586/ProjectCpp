#include "spaceinvaders.h"
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsScene>
#include "game.h"
#include <qtimer.h>
#include <QTimer>

spaceInvaders::spaceInvaders(QSize ScreenSize, QWidget *Parent)
{
    QGraphicsScene* Scene = new QGraphicsScene();
    setScene(Scene);

    Scene->setSceneRect(0,0,ScreenSize.width(), ScreenSize.height() );

    Scene->setBackgroundBrush(QBrush(QImage(":/Recources/Achtergrond.jpg")));

}

void spaceInvaders::Run()
{
    scene()->clear();

    Kanon = new kanon();
    Kanon->setPos(ScreenSize.width()/2, ScreenSize.height() - kanonGrootte.heigth());
    Kanon->setFlag(QGraphicsItem::ItemIsFocusable);
    Kanon->setFocus();

    connect(Kanon, &kanon::verhoogScore, this, &spaceInvaders::onVerhoogScore);
    connect(Kanon, &kanon::verlaagScore, this, &spaceInvaders::onVerlaagScore);

    Punten = new punten();
    scene()->addItem(Punten);

    QTimer* Timer = new QTimer(this);
    connect(Timer,&QTimer::timeout, this, &spaceInvaders::onCreatEnemy);


}

void spaceInvaders::checkPoints()
{
    if((Punten->getScore() <0) || (Punten->getHealth() <= 0))
    {
        Punten->reset();
        onGameOver();
    }
}

void spaceInvaders::keyPressEvent(QEvent *Event)
{
    if(Kanon == nullptr)
        return;
    switch (Event->key())
    {
        case Qt::Key_Left:
            if(Kanon->pos().X()>0)
                Kanon->setPos(Kanon->x() -20, Kanon->y());
            break;
        case Qt::Key_Right:
            if((Kanon->pos().x() + kanonGrootte.width()) < ScreenSize.width())
                Kanon->setPos(Kanon->x() -20,Kanon->y());
            break;
        case Qt::Key_Space:
            Kanon->Shoot();
            break;
    }
}

void spaceInvaders::onCreatEnemy()
{
    int pos = 100+(rand()%ScreenSize.width() -100);
    Alien* alien = new Alien();

    connect(alien, &Alien::GameOver, this, &spaceInvaders::onGameOver);
    connect(alien, &Alien::verlaagHealth, this, &spaceInvaders::onVerlaagHealth);
}

void spaceInvaders::onVerhoogScore()
{
    Punten->verhoogScore();
    checkPoints();
}

void spaceInvaders::onVerlaagScore()
{
    Punten->verlaagScore();
    checkPoints();
}

void spaceInvaders::onVerlaagHealth()
{
    Punten->verlaagHealth();
    checkPoints();
}

void spaceInvaders::onGameOver()
{
    close();
}
