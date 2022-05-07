#ifndef PLAYERBALL_H
#define PLAYERBALL_H

#include <QObject>
#include <QGraphicsRectItem>

class playerBall: public QObject, public QGraphicsRectItem {

    Q_OBJECT
public:

   playerBall();
   ~playerBall(){

   }

   void startingBall();
   void subsequentBalls();
   bool launch();
   void BlockCollision();

   int transY = 0;
   int transX = 0;
   bool startingPosition = true;

public slots:

   void ballMovement();


};

#endif // PLAYERBALL_H
