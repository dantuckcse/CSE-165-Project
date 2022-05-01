#include <QKeyEvent>
#include <QGraphicsItem>
#include <QBrush>
#include <QTimer>
#include <QList>
#include <cmath>
#include <cstdlib>

#include "setup.h"
#include "enemyPaddle.h"

extern setup* newGame;

//sets up enemy paddle
enemyPaddle::enemyPaddle() {

    //sets size and position of enemy paddle
    setRect(0, 0, 75, 10);
    setPos(420, 50);

    //sets color and style for enemy paddle
    QBrush paddleArt;
    paddleArt.setStyle(Qt::SolidPattern);
    paddleArt.setColor(Qt::red);
    setBrush(paddleArt);

    //timer for enemy paddle ai movement
    QTimer *timer = new QTimer();
    timer->start(20);
    connect(timer, SIGNAL(timeout()), this, SLOT(enemyAIMovement()));

    //timer for enemy paddle ai lauching ball
    QTimer *timer2 = new QTimer();
    timer2->start(50);
    connect(timer2, SIGNAL(timeout()), this, SLOT(enemyAILaunch()));

}

void enemyPaddle::enemyAIMovement() {

    //creates a modifiable vector for enemy ball to be followed by the enemy paddle
    int vectorX = (x() + 75 * 0.5) - (newGame->eb->x() + 10);

    //calculates speed that enemy paddle will follow enemy ball
    int paddleSpeed = abs(vectorX / 40);

    //ball vector direction change will change enemy paddle direction and sets the speed
    if(vectorX > 0) {


        setPos(x() - 10* paddleSpeed, y());
    }

    else if(vectorX < 0) {


        setPos(x() + 10 * paddleSpeed, y());
    }

}

//allows the enemies ball to be lanuched by the enemy
void enemyPaddle::enemyAILaunch(){

    //if first ball
    if(startingBall && newGame->pp->started) {

        newGame->eb->startingBall();
        startingBall = false;
    }

    //if subsequent ball (missed or hit by opposing ball)
    else if(newGame->eb->launch()) {

        newGame->eb->subsequentBalls();
    }

}
