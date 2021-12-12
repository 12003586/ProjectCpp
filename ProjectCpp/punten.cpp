#include <punten.h>

punten::punten(QGraphicsItem* parent) : QGRaphicsTextItem(parent)
{
    setPlainText(QString("Healt: ") + QString::number(health) + \n + QString("Score: ")+ QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",24));
}

int punten::getScore()
{
    return score;
}

int punten::getHealth() const
{
    return health;
}

void punten::verhoogScore()
{
    //min 10:18 verdergaan
    score += 50;
    setPlainText(QString("Healt: ") + QString::number(health) + \n + QString("Score: ")+ QString::number(score));
}

void punten::verlaagScore()
{
    score -=50;
    setPlainText(QString("Healt: ") + QString::number(health) + \n + QString("Score: ")+ QString::number(score));
}


void punten::verlaagHealth()
{
    health --;
    setPlainText(QString("Healt: ") + QString::number(health) + \n + QString("Score: ")+ QString::number(score));
}


void punten::reset()
{
    score = 0;
    health = maxHealth;
    setPlainText(QString("Healt: ") + QString::number(health) + \n + QString("Score: ")+ QString::number(score));
}
