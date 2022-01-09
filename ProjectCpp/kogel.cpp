#include <kogel.h>
#include <enemy.h>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QGraphicsPixmapItem>
#include <QtWidgets/QGraphicsScene>


namespace BO {

    Kogel::Kogel(Kleur kleur, QGraphicsItem *Parent): QGraphicsItem(Parent)
    {
        setKleur(kleur);

        QTimer* Timer = new QTimer(this);
        connect(Timer, &QTimer::timeout, this, &Kogel::onMove);
        Timer->start(kogelSnelheid);
    }

    Kleur Kogel::getKleur() const
    {
        return m_kleur;
    }

    void Kogel::setKleur(Kleur kleur)
    {
        m_kleur = kleur;

        switch (kleur)
        {
            case Kleur :: Rood:
            {
                QPixmap Pixmap(":/Resources/RedBullet.png");
                break;
            }
            case Kleur :: Roze:
            {
                QPixmap Pixmap(":/Resources/PinkBullet.png");
                break;
            }
            case Kleur :: Blauw:
            {
                QPixmap Pixmap(":/Resources/BlueBullet.png");
                break;
            }
        }
    }

    void Kogel::onMove()
    {
        QList<QGraphicsItem*> CollidingItem = collidingItems();



        for(auto const item : CollidingItem)
        {
            Enemy* enemy = dynamic_cast<Enemy*>(item);
            if(enemy!= nullptr)
            {
                if(enemy->getKleur() == getKleur())
                {
                    scene()->removeItem(enemy);
                    scene()->removeItem(this);

                    emit verhoogScore();
                    delete enemy;
                    delete this;
                }
                else
                {
                    emit verlaagScore();
                    scene()->removeItem(this);
                    delete this;
                }
                return;
            }
        }
        setPos(x(),y()-10);

        if(pos().y()<0)
        {
            scene()->removeItem(this);
            delete this;
        }
    }
}
