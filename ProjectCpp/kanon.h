#ifndef KANON_H
#define KANON_H
#include <QtWidgets/QGraphicsPixmapItem>
#include <game.h>

namespace BO {




    class Kanon: public QObject, public QGraphicsItem
    {
        Q_OBJECT
    public:
        Kanon(Kleur kleur, QGraphicsItem* Parent = nullptr);
        void Shoot();

        Kleur getKleur() const;
        void setKleur(Kleur kleur);

    signals:
        void verhoogScore();
        void verlaagScore();

    private:
        Kleur m_kleur;



    };

}
#endif // KANON_H
