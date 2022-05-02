#include <QKeyEvent>
#include <QGraphicsItem>
#include <QBrush>
#include <QTimer>
#include <cmath>

#include "setup.h"
#include "playerPaddle.h"

extern setup* newGame;

//sets up player paddle
playerPaddle::playerPaddle() {

    //sets size and position of player paddle
    setRect(0, 0, 75,10);
    setPos(420,550);

    //sets color and style for player paddle
    QBrush paddleArt;
    paddleArt.setStyle(Qt::SolidPattern);
    paddleArt.setColor(Qt::blue);
    setBrush(paddleArt);

    //allows player paddle to take key events
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

bool playerPaddle::hasStarted(){
    return started;
}

//key inputs for left movement, right movement, and space launch
//has conditions for paddle not being able to move off screen
void playerPaddle::keyPressEvent(QKeyEvent *event) {

    //left key event
    if(event->key() == Qt::Key_Left) {

        setPos(x() - 35, y());

        //stops paddle from moving off screen to the left
        if(pos().x() <= -35) {

           setPos(x() + 35, y());
        }

    }

    //right key event
    if(event->key() == Qt::Key_Right) {

        setPos(x() + 35, y());

        //stops paddle from moving off screen to the right
        if(pos().x() >= 850) {

            setPos(x() - 35, y());
        }

    }

    //space bar event
    if(event->key() == Qt::Key_Space) {

        //if first ball
        if(startingBall) {
            started = true;
            newGame->pb->startingBall();
            startingBall = false;
            newGame->gameTimer->start(120000);
        }

        //if subsequent ball (missed or hit by opposing ball)
        else if(newGame->pb->launch()) {
            newGame->pb->subsequentBalls();
        }

    }

}
