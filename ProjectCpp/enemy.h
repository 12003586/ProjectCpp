#ifndef ENEMY_H
#define ENEMY_H

#include <game.h>

namespace BO {


    class Enemy: public QObject, public QGraphicsItem
    {
        Q_OBJECT
    public:
        Enemy(Kleur kleur, QGraphicsItem* Parent = nullptr);

        Kleur getKleur() const;
        void setKleur(Kleur kleur);

    signals:
        void verlaagHealth();
        void gameOver();

    public slots:
        void onMove();


    private:
        Kleur m_kleur;


    };

}

#endif // ENEMY_H
