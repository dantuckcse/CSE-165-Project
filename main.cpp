#include <QApplication>
#include "setup.h"

setup* newGame;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    newGame = new setup();
    newGame -> show();

    return a.exec();
}
