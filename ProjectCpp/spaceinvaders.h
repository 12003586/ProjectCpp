#ifndef SPACEINVADERS_H
#define SPACEINVADERS_H

#include <QPointer>
#include <QEvent>
#include "kanon.h"
#include "punten.h"
#include <QtWidgets/QGraphicsView>

namespace BO {

    class spaceInvaders
    {
    public:
        spaceInvaders(QSize ScreenSize, QWidget* Parent = nullptr);

        void Run();
        void checkPoints();

    protected:
        virtual void keyPressEvent(QEvent* Event) override;
        void setScene(QGraphicsScene *scene);

    public slots:
        void onCreatEnemy();
        void onVerhoogScore();
        void onVerlaagScore();
        void onVerlaagHealth();
        void onGameOver();


    private:
        Kanon*  kanon = nullptr;
        Punten* punten = nullptr;
        QSize   ScreenSize;
    };

}

#endif // SPACEINVADERS_H
