#include "spaceinvaders.h"
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsPixmapItem>
#include <QtWidgets/QGraphicsItem>
#include "game.h"
#include <qtimer.h>
#include <QTimer>
#include <QSize>
#include <enemy.h>
#include <kanon.h>
#include <punten.h>
#include <QObject>


namespace BO {

    spaceInvaders::spaceInvaders(QSize ScreenSize, QWidget *Parent)
    {
        QGraphicsScene* pScene = new QGraphicsScene();
        setScene(pScene);

        pScene->setSceneRect(0,0,ScreenSize.width(), ScreenSize.height() );

        pScene->setBackgroundBrush(QBrush(QImage(":/Recources/Achtergrond.jpg")));

    }

    void spaceInvaders::Run()
    {
        scene()->clear();

        kanon = new Kanon(kleur::Rood);
        kanon->setPos(ScreenSize.width()/2, ScreenSize.height() - kanonGrootte.heigth());
        scene()->addItem(kanon);

        connect(kanon, &Kanon::verhoogScore, this, &spaceInvaders::onVerhoogScore);
        connect(kanon, &Kanon::verlaagScore, this, &spaceInvaders::onVerlaagScore);

        punten = new Punten();
        scene()->addItem(punten);

        QTimer* Timer = new QTimer(this);
        connect(Timer,&QTimer::timeout, this, &spaceInvaders::onCreatEnemy);
        Timer->start(2000);


    }

    void spaceInvaders::checkPoints()
    {
        if((punten->getScore() <0) || (punten->getHealth() <= 0))
        {
            punten->reset();
            onGameOver();
        }
    }

    void spaceInvaders::keyPressEvent(QEvent *Event)
    {
        if(kanon == nullptr)
            return;
        switch (Event->Key())
        {
            case Qt::Key_Left:
                if(kanon->pos().x()>0)
                    kanon->setPos(kanon->x() -20, kanon->y());
                break;
            case Qt::Key_Right:
                if((kanon->pos().x() + kanonGrootte.width()) < ScreenSize.width())
                    kanon->setPos(kanon->x() + 20,kanon->y());
                break;
            case Qt::Key_Space:
                kanon->Shoot();
                break;
        }
    }

    void spaceInvaders::onCreatEnemy()
    {
        int pos = 100+(rand()%ScreenSize.width() -100);
        int enemyKleur = rand() % 3;

        Enemy* enemy = new Enemy(static_cast<Kleur>(enemyKleur));
        enemy->setPos(pos, 0);
        scene()->addItem(enemy);


        connect(enemy, &Enemy::gameOver, this, &spaceInvaders::onGameOver);
        connect(enemy, &Enemy::verlaagHealth, this, &spaceInvaders::onVerlaagHealth);
    }

    void spaceInvaders::onVerhoogScore()
    {
        punten->verhoogScore();
        checkPoints();
    }

    void spaceInvaders::onVerlaagScore()
    {
        punten->verlaagScore();
        checkPoints();
    }

    void spaceInvaders::onVerlaagHealth()
    {
        punten->verlaagHealth();
        checkPoints();
    }

    void spaceInvaders::onGameOver()
    {
        close();
    }


}
