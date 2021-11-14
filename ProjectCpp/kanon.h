#ifndef KANON_H
#define KANON_H

#include <game.h>

class kanon: public QObject
{
    Q_OBJECT
public:
    void Shoot();

signals:
    void verhoogScore();
    void verlaagScore();




};


#endif // KANON_H
