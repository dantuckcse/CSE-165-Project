#ifndef SETUP_H
#define SETUP_H

#include <QGraphicsView>
#include <QGraphicsScene>

#include "playerPaddle.h"
#include "PlayerBall.h"
#include "enemyPaddle.h"
#include "enemyBall.h"

class setup: public QGraphicsView
{
public:
    setup();
    QGraphicsScene* scene;
    playerPaddle* pp;
    enemyPaddle* ep;
    playerBall* pb;
    enemyBall* eb;

private:
    int height = 600;
    int width = 900;

};

#endif // SETUP_H
