#include "setup.h"
#include "playerPaddle.h"
#include "PlayerBall.h"
#include "enemyPaddle.h"
#include "enemyBall.h"

setup::setup()
{
    //Scene setup
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,width,height);

    pp = new playerPaddle(height);
    ep = new enemyPaddle(height, width);
    pb = new playerBall(height, width);
    eb = new enemyBall(height, width);

    scene->addItem(pp);
    scene->addItem(ep);
    scene->addItem(pb);
    scene->addItem(eb);

    //Setup View
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(width,height);
    show(); //Display gui
}
