#include "PlayerBall.h"
#include "setup.h"

#include <QCoreApplication>

#include <QGraphicsItem>
#include <QBrush>
#include <QList>
#include <QTimer>
#include <QTime>
#include <cstdlib> //for rand
#include <ctime>   //for rand seed

extern setup* newGame;

playerBall::playerBall(int h, int w) {
    setRect(0,0,8,8);
    setPos(453,520);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);

    speed = 2;
    screenh = h;
    screenw = w;

}

void playerBall::launch(){
    srand(time(NULL));  //randomize random numbers

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

    //QTimer *timer3 = new QTimer();
    //timer3->start(20000);
    //connect(timer3, SIGNAL(timeout()), this, SLOT(penalty()));
}

void playerBall::relaunch()
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

bool playerBall::canLaunch()
{
    return launchable;
}

void playerBall::speedup() {
    speed += 0.5;
}

void playerBall::move() {

    setPos(x() - hmove * speed, y() - vmove * speed);

    //Collision management
    QList<QGraphicsItem *> Collisions = collidingItems();

    if(Collisions.size() == 1) {
        if(typeid(*(Collisions[0])) != typeid(enemyPaddle))
            vmove = -vmove;

        else if(typeid(*(Collisions[0])) == typeid(enemyPaddle)){
            vmove = -vmove;


        }
    }
    else if(Collisions.size() != 0) {
        vmove = -vmove;
    }



    //Top of screen and Bottom of screen
    if(pos().x() <= 0 || pos().x() + 20 >= screenw){
        hmove = -hmove;
    }

    if(pos().y() <= 0){
        vmove = -vmove;
    }

    if(pos().y() + 20 >= screenh){ //PlayerMisses
        vmove = hmove = 0;
        setPos(453,520);
        QTime penaltyTime= QTime::currentTime().addSecs(5);
        while (QTime::currentTime() < penaltyTime){
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }

        launchable = true;
    }

 }
