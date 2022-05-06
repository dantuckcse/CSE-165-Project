#include "setup.h"
#include "playerPaddle.h"
#include "PlayerBall.h"
#include "enemyPaddle.h"
#include "enemyBall.h"
#include "block.h"
#include <QBrush>

setup::setup() {

    //sets up scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 900, 600);
    // QLinearGradient gradient(0, 0, 900, 600);
    //gradient.setSpread(QGradient::PadSpread);
    scene->setBackgroundBrush(QColor(255, 255, 255));

    //defines items
    pp = new playerPaddle();
    ep = new enemyPaddle();
    pb = new playerBall();
    eb = new enemyBall();
    ps = new playerScore();
    es = new enemyScore();
    gameTimer = new QTimer(this);
    es->setPos(es->x() + 680, es->y()); //changing the position of the enemy score text to be on the right side of the screen

    //adds items to scene
    scene->addItem(pp);
    scene->addItem(ep);
    scene->addItem(pb);
    scene->addItem(eb);
    scene->addItem(ps);
    scene->addItem(es);
    createBlockGrid();

    //sets scene & disables scrollbar
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900, 600);
    show();
}

void setup::createBlockCol(double x){
    for (size_t i = 0, n = 5; i < n; ++i){ // n = how many rows of rectangles
        Block* block = new Block();
        block->setPos(x,(i+220)+(i*28)); //use x cord from other funct, y cord is set manually to start in middle of screen
        scene->addItem(block); // add block to game
    }
}

void setup::createBlockGrid(){
    for (size_t i = 0, n = 10; i < n; ++i){ // n = how many rectangles in one row
        createBlockCol(i*90); //setting the starting x coord for the rectangle
    }
}
