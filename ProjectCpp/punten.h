#ifndef PUNTEN_H
#define PUNTEN_H

#include <game.h>

class punten
{
    public :
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

#endif // PUNTEN_H
