#include "setup.h"
#include "playerPaddle.h"
#include "PlayerBall.h"
#include "enemyPaddle.h"
#include "enemyBall.h"

setup::setup() {

    //sets up scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 900, 600);

    //defines items
    pp = new playerPaddle();
    ep = new enemyPaddle();
    pb = new playerBall();
    eb = new enemyBall();

    //adds items to scene
    scene->addItem(pp);
    scene->addItem(ep);
    scene->addItem(pb);
    scene->addItem(eb);

    //sets scene & disables scrollbar
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900, 600);
    show();
}
