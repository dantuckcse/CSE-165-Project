#include <QApplication>
#include <QTimer>

#include "setup.h"
//#include "Combine.h"
#include "Game.h"

Game* ui;
setup* newGame;
//Combine* newerGame;

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    ui = new Game();
    ui -> show();
    ui -> displayMainMenu();

    return a.exec();
}
