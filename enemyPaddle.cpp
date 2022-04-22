#include <QKeyEvent>
#include <QGraphicsItem>
#include <QBrush>
#include <QTimer>
#include <cmath>
#include <QList>
#include <cstdlib> //for rand
#include <ctime>

#include "setup.h"
#include "enemyPaddle.h"

extern setup* newGame;

enemyPaddle::enemyPaddle(int h, int w) {
    setRect(0,0,75,10);
    setPos(420,50);
    screenh = h;
    screenw = w;
    paddlelength = 100;

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);

    QTimer *timer = new QTimer();
    timer->start(25);
    connect(timer, SIGNAL(timeout()), this, SLOT(follow()));

    QTimer *timer2 = new QTimer();
    timer2->start(100);
    connect(timer2, SIGNAL(timeout()), this, SLOT(autoLaunch()));

}

void enemyPaddle::autoLaunch(){

    if(firstball) {
        newGame->eb->launch();
        firstball = false;
    }

    else if(newGame->eb->canLaunch()) {
        newGame->eb->relaunch();
    }
}

void enemyPaddle::follow() {

    int Hdif = (x()+paddlelength/2) - (newGame->eb->x()+10);

    int accel = abs(Hdif/50);

    if(Hdif > 0)
        setPos(x()-(15/2)*accel, y());
    else if(Hdif < 0)
        setPos(x()+(15/2)*accel, y());
}
