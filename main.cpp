#include <QApplication>
#include <QTimer>

#include "setup.h"
#include "Game.h"

Game* ui;
setup* newGame;

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    ui = new Game();
    ui -> show();
    ui -> displayMainMenu();

    return a.exec();
}
