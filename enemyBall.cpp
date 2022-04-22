#include "enemyBall.h"
#include "setup.h"

#include <QGraphicsItem>
#include <QBrush>
#include <QList>
#include <QTimer>
#include <cstdlib>
#include <ctime>
#include <QTime>
#include <QCoreApplication>

extern setup* newGame;

enemyBall::enemyBall(int h, int w) {
    setRect(0,0,8,8);
    setPos(453,80);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);

    speed = 2;
    screenh = h;
    screenw = w;

}

void enemyBall::launch(){
    srand(time(NULL));

    vmove = 1;

    if(rand() % 2 == 0)
        hmove = -1;
    else
        hmove = 1;
    launchable = false;

    QTimer *timer = new QTimer();
    timer->start(12.5);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    QTimer *timer2 = new QTimer();
    timer2->start(10000);
    connect(timer2, SIGNAL(timeout()), this, SLOT(speedup()));

    QTimer *timer3 = new QTimer();
    timer3->start(10000);
    connect(timer3, SIGNAL(timeout()), this, SLOT(penalty()));
}

void enemyBall::relaunch()
{
    //Display prompt

    speed = 2;
    srand(time(NULL));  //randomize random numbers

    vmove = 1;

    if(rand() % 2 == 0)
        hmove = -1;
    else
        hmove = 1;

    launchable = false;
}

bool enemyBall::canLaunch()
{
    return launchable;
}

void enemyBall::speedup() {
    speed += 0.5;
}

void enemyBall::move() {

    setPos(x() + hmove * speed, y() + vmove * speed);

    //Collision management
    QList<QGraphicsItem *> Collisions = collidingItems();

    if(Collisions.size() == 1) {
        if(typeid(*(Collisions[0])) != typeid(playerPaddle))
            vmove = -vmove;

        else if(typeid(*(Collisions[0])) == typeid(playerPaddle)){
            vmove = -vmove;


        }
    }
    else if(Collisions.size() != 0) {
        vmove = -vmove;
    }

    if(pos().x() <= 0 || pos().x() + 25 >= screenw){
        hmove = -hmove;
    }

    if(pos().y() + 25 >= screenh){
        vmove = -vmove;
    }

    if(pos().y() <= 0){ //PlayerMisses
        QTime penaltyTime= QTime::currentTime().addSecs(5);
        vmove = hmove = 0;
        setPos(453,80);
        while (QTime::currentTime() < penaltyTime){
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }

        launchable = true;

    }
}
