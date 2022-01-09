#include <kanon.h>
#include <kogel.h>
#include <game.h>
#include <QtWidgets/QGraphicsPixmapItem>
#include <QTimer>
#include <QtWidgets/QGraphicsScene>


namespace BO {


    Kanon::Kanon(Kleur kleur, QGraphicsItem *Parent) : QGraphicsItem(Parent)
    {
       setKleur(kleur);
    }

    void Kanon::Shoot()
    {
        Kogel* kogel = new Kogel(m_kleur);
        connect(kogel, &Kogel::verhoogScore, this, &Kanon::verhoogScore);
        connect(kogel, &Kogel::verlaagScore, this, &Kanon::verlaagScore);

        kogel->setPos(x()+27,y()-10);
        scene()->addItem(kogel);
    }

    Kleur Kanon::getKleur() const
    {
        return m_kleur;
    }

    void Kanon::setKleur(Kleur kleur)
    {
        m_kleur = kleur;

        switch (kleur)
        {
            case Kleur :: Rood:
            {
                QPixmap Pixmap(":/Resources/RedCannon.png");
                break;
            }
            case Kleur :: Roze:
            {
                QPixmap Pixmap(":/Resources/PinkCannon.png");
                break;
            }
            case Kleur :: Blauw:
            {
                QPixmap Pixmap(":/Resources/BlueCannon.png");
                break;
            }
            default:
            {
                QPixmap Pixmap(":/Resources/RedCannon.png");
                break;
            }
        }
    }

}
