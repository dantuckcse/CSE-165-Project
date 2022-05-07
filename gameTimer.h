#ifndef GAMETIMER_H
#define GAMETIMER_H

#include <QObject>


class gameTimer: public QObject{
    int time;
    Q_OBJECT

public:
    gameTimer();
    ~gameTimer(){

    }
    int getTime();
    void showGameTime();
    void decreaseTime();

public slots:

    void endGame();
};


#endif // GAMETIMER_H
