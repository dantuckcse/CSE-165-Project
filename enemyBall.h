#ifndef ENEMYBALL_H
#define ENEMYBALL_H

#include <QObject>
#include <QGraphicsRectItem>

class enemyBall: public QObject, public QGraphicsRectItem {

    Q_OBJECT
public:

    enemyBall();
    ~enemyBall() {

    }

    void startingBall();
    void subsequentBalls();
    bool launch();

    int transY = 0;
    int transX = 0;
    bool startingPosition = true;

public slots:

    void ballMovement();
};

#endif // ENEMYBALL_H
