#include <punten.h>
#include <game.h>
#include <QtWidgets/QGraphicsPixmapItem>
#include <QtWidgets/QGraphicsTextItem>
#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QAbstractScrollArea>

namespace BO {

    Punten::Punten(QGraphicsItem* parent) : QGraphicsTextItem(parent)
    {
        setPlainText(QString("Healt: ") + QString::number(health) + "\n" + QString("Score: ")+ QString::number(score));
        setDefaultTextColor(Qt::red);
        setFont(QFont("times",24));
    }

    void Punten::verhoogScore()
    {

        score += 50;
        setPlainText(QString("Healt: ") + QString::number(health) + "\n" + QString("Score: ")+ QString::number(score));
    }

    void Punten::verlaagScore()
    {
        score -=50;
        setPlainText(QString("Healt: ") + QString::number(health) + "\n" + QString("Score: ")+ QString::number(score));
    }


    void Punten::verlaagHealth()
    {
        health --;
        setPlainText(QString("Healt: ") + QString::number(health) + "\n" + QString("Score: ")+ QString::number(score));
    }


    void Punten::reset()
    {
        score = 0;
        health = maxHealth;
        setPlainText(QString("Healt: ") + QString::number(health) + "\n" + QString("Score: ")+ QString::number(score));
    }

    int Punten::getHealth() const
    {
        return health;
    }

    int Punten::getScore() const
    {
        return score;
    }

}

