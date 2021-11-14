#include <kogel.h>
#include <enemy.h>

void kogel::onMove()
{
    QList<QGraphicsItem*>1stCollidingItem = collidingItems();

    for(auto const item : 1stCollidingItem)
    {
        enemy* Enemy = dynamic_cast<enemy*>(item);
        if(Enemy!= nullptr)
        {
            if(Enemy->getColor() == getColor())
            {
                scene()->removeItem(Enemy);
                scene()->removeItem(this):

                emit verhoogScore();
                delete Enemy;
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
