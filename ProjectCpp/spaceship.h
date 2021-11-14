#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "player.h"
#include "game.h"

namespace BO {

    class Spaceship : public Player
    {
        const char* getName() const;


    };

}

#endif // SPACESHIP_H
