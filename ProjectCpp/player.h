#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <QEvent>
#include <QObject>




class Game;

class Player
{
public:
    virtual ~Player()                               {}
    virtual const char* getName(void) const         = 0;
    bool isDead(void) const                         {return (lives ==0);}
    unsigned int getHits() const                    {return hits;}
    void moveRight();
    void moveLeft();
    void gotHit();


protected:
    const Game* getGame(void) const                 {return(game);}



private:
    unsigned int lives = 3;
    unsigned int hits;
    const Game * game;
};
#endif // PLAYER_H
