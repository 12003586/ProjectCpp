#include "spaceinvaders.h"
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);

    spaceInvaders* Game = new spaceInvaders(qApp->screens()[0]->size());

    Game->Run();

    return a.exec();
}
