#ifndef ENEMYPADDLE_H
#define ENEMYPADDLE_H

#include <QGraphicsRectItem>
#include <QObject>

class enemyPaddle: public QObject, public QGraphicsRectItem {

    Q_OBJECT
public:

    enemyPaddle();
    ~enemyPaddle(){

    }

    bool startingBall = true;

public slots:

    void enemyAIMovement();
    void enemyAILaunch();

};

#endif // ENEMYPADDLE_H
