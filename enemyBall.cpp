#include <QCoreApplication>
#include <QGraphicsItem>
#include <QBrush>
#include <QList>
#include <QTimer>
#include <QTime>
#include <cstdlib>

#include "enemyBall.h"
#include "setup.h"
#include "block.h"

extern setup* newGame;

//sets up enemy ball
enemyBall::enemyBall() {

    //sets size and position of enemy ball
    setRect(0, 0, 8, 8);
    setPos(453, 80);

    //sets color and style of enenmy ball
    QBrush ballArt;
    ballArt.setStyle(Qt::SolidPattern);
    ballArt.setColor(Qt::red);
    setBrush(ballArt);
}

//manages the first ball
void enemyBall::startingBall() {

    transY = 1;

    srand(time(NULL));

    //randomly launches first enemy ball left or right
    if(rand() % 2 == 0) {

        transX = 1;
    }

    else {

        transX = -1;
    }

    startingPosition = false;

    //sets timer for enemy ball movement
    QTimer *timer = new QTimer();
    timer->start(15);
    connect(timer, SIGNAL(timeout()), this, SLOT(ballMovement()));
}

//manages all subsequent enemy balls
void enemyBall::subsequentBalls() {

    transY = 1;

    srand(time(NULL));

        //randomly launches subsequent enemy balls left or right
    if(rand() % 2 == 0) {

        transX = 1;
    }

    else {

        transX = -1;
    }

    startingPosition = false;
}

//manages enemy ball movement
void enemyBall::ballMovement() {

    //sets the speed that the enemy ball moves (currently at 3)
    setPos(x() + transX * 3, y() + transY * 3);

    //manages the collision conditions
    QList<QGraphicsItem *> Collisions = collidingItems();

    if(Collisions.size() >= 1) {

        if ((typeid(*(Collisions[0])) == typeid(enemyScore)) || (typeid(*(Collisions[0])) == typeid(playerScore))) {
            transY = -transY;
        }

        //causes enemy ball to move in opposite Y direction if it collides with any non-player paddle objects
        if(typeid(*(Collisions[0])) != typeid(playerPaddle)) {

            BlockCollision();
            transY *= -1;
        }

        //causes enemy ball to move in opposite Y direction if it collides with the player paddle
        //and resets player ball as penalty
        else if(typeid(*(Collisions[0])) == typeid(playerPaddle)) {

            transY *= -1;

            //stops ball movement and resets ball to starting position
            newGame->ps->changePlayerScore(-1);
            newGame->pb->transY = 0;
            newGame->pb->transX = 0;
            newGame->pb->setPos(453, 520);

            newGame->pb->startingPosition = true;
        }

    }

    //enemy ball changes X directions if colliding with left or right screen edge
    if(pos().x() <= 0 || pos().x() + 20 >= 900) {

        transX *= -1;
    }

    //enemy ball changes Y direction if colliding with bottom of screen
    if(pos().y() + 20 >= 600) {

        transY *= -1;
    }

    //5 second no ball movement penalty if enemy ball hits top of screen
    if(pos().y() <= 0) {

        //stops ball movement and resets ball to starting position
        newGame->es->changeEnemyScore(-2);
        transY = transX = 0;
        setPos(453, 80);

        QTime penaltyTime= QTime::currentTime().addSecs(5);

        while (QTime::currentTime() < penaltyTime) {

            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }

        startingPosition = true;
    }

}

void enemyBall::BlockCollision(){ // when the ball collides with a block
    QList<QGraphicsItem*> cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i){
        Block* block = dynamic_cast<Block*>(cItems[i]);
        if (block){
            newGame->scene->removeItem(block); //
            newGame->es->changeEnemyScore(1);
            delete block;
        }
    }
}

//allows enemy ball to be launched again
bool enemyBall::launch() {

    return startingPosition;
}
