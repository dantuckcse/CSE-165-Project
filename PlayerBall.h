#ifndef PLAYERBALL_H
#define PLAYERBALL_H

#include <QObject>
#include <QGraphicsRectItem>

class playerBall: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
   playerBall(int, int);
   ~playerBall(){}

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

#endif // PLAYERBALL_H
