#include <QKeyEvent>
#include <QGraphicsItem>
#include <QBrush>
#include <QTimer>
#include <cmath>

#include "setup.h"
#include "playerPaddle.h"

extern setup* newGame;

playerPaddle::playerPaddle(int h) {
    setRect(0,0,75,10);
    setPos(420,550);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    screenh = h;
}

void playerPaddle::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Left || event->key() == Qt::Key_A){
        if(pos().x() >= 10){
            setPos(x()-10,y());
        }
    }

    if(event->key() == Qt::Key_Right || event->key() == Qt::Key_D){
        if(pos().x() <= 820){
            setPos(x()+10,y());
        }
    }

    if(event->key() == Qt::Key_Space){
        if(firstball) {
            newGame->pb->launch();
            firstball = false;
        }

        else if(newGame->pb->canLaunch()) {
            newGame->pb->relaunch();
        }
    }

}
