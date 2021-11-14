#include <kanon.h>
#include <kogel.h>

#include <qtimer.h>


void kanon::Shoot()
{
    kogel* Kogel = new kogel();
    connect(Kogel, &kogel::verhoogScore, this, &kanon::verhoogScore);
    connect(Kogel, &kogel::verlaagScore, this, &kanon::verlaagScore);

    Kogel->setPos(x()+27,y()-10);
    scene()->addItem(Kogel);


}
