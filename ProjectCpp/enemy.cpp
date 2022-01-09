#include <enemy.h>
#include <game.h>
#include <kanon.h>
#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsPixmapItem>
#include <QtWidgets/QGraphicsScene>

namespace BO {

    Enemy::Enemy(Kleur kleur, QGraphicsItem *Parent): QGraphicsItem(Parent)
    {
        setKleur(kleur);

        QTimer* Timer = new QTimer(this);
        connect(Timer, &QTimer::timeout, this ,Enemy::onMove());
        Timer->start(enemySpeed);
    }

    Kleur Enemy::getKleur() const
    {
        return m_kleur;
    }

    void Enemy::setKleur(Kleur kleur)
    {
        m_kleur = kleur;

        switch (kleur)
        {
            case Kleur :: Rood:
            {
                QPixmap Pixmap(":/Resources/RedAlien.png");
                break;
            }
            case Kleur :: Roze:
            {
                QPixmap Pixmap(":/Resources/PinkAlien.png");
                break;
            }
            case Kleur :: Blauw:
            {
                QPixmap Pixmap(":/Resources/BlueAlien.png");
                break;
            }
        }
    }

    void Enemy::onMove()
    {
        setPos(x(),y()+5);
        if(pos().y() >= (scene()->height()- kanonGrootte.height()))
        {
            scene()->removeItem(this);
            emit verlaagHealth();
            delete this;
        }

        QList<QGraphicsItem*> CollidingItem = collidingItems();
        for(auto const item : CollidingItem)
        {
            if(dynamic_cast<Kanon*>(item))
                emit gameOver();
        }
    }

}
