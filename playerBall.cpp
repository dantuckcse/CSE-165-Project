#include <QCoreApplication>
#include <QGraphicsItem>
#include <QBrush>
#include <QList>
#include <QTimer>
#include <QTime>
#include <cstdlib>

#include "PlayerBall.h"
#include "setup.h"
#include "block.h"


extern setup* newGame;

//sets up player ball
playerBall::playerBall() {

    //sets size and position of player ball
    setRect(0, 0, 8, 8);
    setPos(453, 520);

    //sets color and style of player ball
    QBrush ballArt;
    ballArt.setStyle(Qt::SolidPattern);
    ballArt.setColor(Qt::blue);
    setBrush(ballArt);
}

//manages the first ball
void playerBall::startingBall() {

    transY = 1;

    srand(time(NULL));

    //randomly launches first player ball left or right
    if(rand() % 2 == 0) {

        transX = 1;
    }

    else {

        transX = -1;
    }

    startingPosition = false;

    //sets timer for player ball movement
    QTimer *timer = new QTimer();
    timer->start(15);
    connect(timer, SIGNAL(timeout()), this, SLOT(ballMovement()));
}

//manages all subsequent player balls
void playerBall::subsequentBalls() {

    transY = 1;

    srand(time(NULL));

    //randomly launches subsequent player balls left or right
    if(rand() % 2 == 0) {

        transX = 1;
    }

    else {

        transX = -1;
    }

    startingPosition = false;
}

//manages player ball movement
void playerBall::ballMovement() {

    //sets the speed that the enemy ball moves (currently at 3)
    setPos(x() - transX * 3, y() - transY * 3);

    //manages the collision conditions
    QList<QGraphicsItem *> Collisions = collidingItems();

    if(Collisions.size() == 1) {

        //causes enemy ball to move in opposite Y direction if it collides with any non-enemy paddle objects
        if(typeid(*(Collisions[0])) != typeid(enemyPaddle)) {

            BlockCollision();
            transY *= -1;
        }

        //causes player ball to move in opposite Y direction if it collides with the enemy paddle
        //and resets enemy ball as penalty
        //WIP: will remove points from enemy
        else if(typeid(*(Collisions[0])) == typeid(enemyPaddle)) {

            transY *= -1;

            //stops ball movement and resets ball to starting position
            newGame->es->changeEnemyScore(-1);
            newGame->eb->transY = 0;
            newGame->eb->transX = 0;
            newGame->eb->setPos(453, 80);

            newGame->eb->startingPosition = true;
        }

    }
    //player ball changes X directions if colliding with left or right screen edge
    if(pos().x() <= 0 || pos().x() + 20 >= 900) {

        transX *= -1;
    }

    //player ball changes Y direction if colliding with top of screen
    if(pos().y() <= 0) {

        transY *= -1;
    }

    //5 second no ball movement penalty if player ball hits bottom of screen
    if(pos().y() + 20 >= 600) {

        //stops ball movement and resets ball to starting position
        newGame->ps->changePlayerScore(-2);
        transY = transX = 0;
        setPos(453, 520);

        QTime penaltyTime= QTime::currentTime().addSecs(5);

        while (QTime::currentTime() < penaltyTime) {

            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }

        startingPosition = true;
    }

 }

void playerBall::BlockCollision(){ //when the ball collides with a block
    QList<QGraphicsItem*> cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i){
        Block* block = dynamic_cast<Block*>(cItems[i]);
        if (block){
            newGame->scene->removeItem(block); // remove the block from screen
            newGame->ps->changePlayerScore(1); // add a point to the player score
            delete block; // delete that block object
        }
    }
}


//allows enemy ball to be launched again
bool playerBall::launch() {

    return startingPosition;
}
