#ifndef ENEMYBALL_H
#define ENEMYBALL_H

#include <QObject>
#include <QGraphicsRectItem>

class enemyBall: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    enemyBall(int, int);
    ~enemyBall(){}

    void launch();
    void relaunch();
    bool canLaunch();

public slots:
    void move();
    void speedup();


private:
    int vmove = 0;
    int hmove = 0;
    int screenh;
    int screenw;
    int speed;
    bool launchable = true;
    int winPts = 10;
};


#endif // ENEMYBALL_H
