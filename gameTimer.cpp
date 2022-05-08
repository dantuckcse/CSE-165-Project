#include "gameTimer.h"
#include <QFont>
#include <QTimer>
#include <QDebug>


gameTimer::gameTimer(){
    time = 10;
    //setPlainText(QString("Time remaning: ") + QString::number(time) + QString(" sec"));
    //setDefaultTextColor(Qt::black);
    //setFont(QFont("times", 16));
}

int gameTimer::getTime(){
    return time;
}



void gameTimer::endGame(){
    exit(0);
}

void gameTimer::decreaseTime(){
    time = time - 1;
    if(time == 0){
        endGame();
    }
}




