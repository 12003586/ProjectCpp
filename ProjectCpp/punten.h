#ifndef PUNTEN_H
#define PUNTEN_H

#include <game.h>

namespace BO {

    class Punten : public QObject, public QGraphicsItem
    {
        public :
            Punten(QGraphicsItem* Parent = nullptr);
            void verhoogScore();
            void verlaagScore();
            void verlaagHealth();

            int getHealth()const;
            int getScore() const;

            void reset();

        private:
            int health = maxHealth;
            int score = 0;


    };

}

#endif // PUNTEN_H
