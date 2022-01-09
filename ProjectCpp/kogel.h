#ifndef KOGEL_H
#define KOGEL_H

#include <game.h>


namespace BO {

    class Kogel:public QObject, public QGraphicsItem
    {
        Q_OBJECT

    public:
        Kogel(Kleur kleur, QGraphicsItem* Parent = nullptr);

        Kleur getKleur() const;
        void setKleur(Kleur kleur);

    signals:
        void verhoogScore();
        void verlaagScore();

    public slots:
        void onMove();

    private:
        Kleur m_kleur;
    };


}
#endif // KOGEL_H
