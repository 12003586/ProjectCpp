#include <punten.h>

punten::punten(QGraphicsItem* parent) : QGRaphicsTextItem(parent)
{
    setPlainText(QString("Healt: ") + QString::number(health) + \n + QString("Score: ")+ QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",24));
}

void punten::verhoogScore()
{
    //min 10:18 verdergaan
}
