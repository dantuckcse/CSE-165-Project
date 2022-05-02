#ifndef SETUP_H
#define SETUP_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>

#include "playerPaddle.h"
#include "PlayerBall.h"
#include "enemyPaddle.h"
#include "enemyBall.h"
#include "playerScore.h"
#include "enemyScore.h"

class setup: public QGraphicsView {

public:

    setup();
    void createBlockCol(double x);
    void createBlockGrid();

    QGraphicsScene* scene;
    QTimer *gameTimer;
    playerPaddle* pp;
    enemyPaddle* ep;
    playerBall* pb;
    enemyBall* eb;
    playerScore* ps;
    enemyScore* es;
};

#endif // SETUP_H
