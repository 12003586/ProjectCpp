#ifndef SPACEINVADERS_H
#define SPACEINVADERS_H

#include <QPointer>
#include <QEvent>
#include "kanon.h"
#include "punten.h"
#include <QtWidgets/QGraphicsView>

class spaceInvaders
{
public:
    spaceInvaders(QSize ScreenSize, QWidget* Parent = nullptr);

    void Run();
    void checkPoints();

protected:
    void keyPressEvent(QEvent* Event);
    void setScene(QGraphicsScene *scene);

public slots:
    void onCreatEnemy();
    void onVerhoogScore();
    void onVerlaagScore();
    void onVerlaagHealth();
    void onGameOver();


private:
    kanon*  Kanon = nullptr;
    punten* Punten = nullptr;
    QSize   ScreenSize;
};

#endif // SPACEINVADERS_H
