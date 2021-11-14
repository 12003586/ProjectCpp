#include <enemy.h>
#include <game.h>

void enemy::onMove()
{
    setPos(x(),y()+5);
    if(pos().y() >= (scene()->height()- kanonGrootte.height()))
    {
        scene()->removeItem(this);
        emit verlaagHealth();
        delete this;
    }

    QList<QGraphicsItem*> 1stCollidingItem = collidingItems();
    for(auto const item : 1stCollidingItem)
    {
        if(dynamic_cast<kanon*>(item))
            emit gameOver();
    }
}
