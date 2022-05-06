#include "Game.h"
//#include "Score.h"
#include "Button.h"
#include <QGraphicsTextItem>
#include "setup.h"
#include "Combine.h"

extern setup* newGame;
Combine* newerGame;
Game::Game(QWidget *parent){
    // set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);

    // set up the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,768);
    setScene(scene);
}

void Game::start(){
    // clear the screen
    scene->clear();

    newGame = new setup();
    newGame -> show();
}

void Game::helpDisplay(){
    scene->clear();
    newerGame = new Combine();
    newerGame -> show();
}

void Game::closeGame(){
    scene->clear();
    exit(0);
}

void Game::displayMainMenu(){
    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("BreakOut"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

     /*
    Button* mainMenu = new Button(QString("Main Menu"));
    int mainxPos = this->width()/2 - mainMenu->boundingRect().width()/2;
    int mainyPos = 250;
    mainMenu->setPos(mainxPos,mainyPos);
    connect(mainMenu,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(mainMenu);
    */

    // create the play button
    Button* playButton = new Button(QString("Play Game"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 250;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    /*
    Button* settings = new Button(QString("Settings"));
    int settingsxPos = this->width()/2 - settings->boundingRect().width()/2;
    int settingsyPos = 410;
    settings->setPos(settingsxPos,settingsxPos);
    connect(settings,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(settings);
    */

    Button* help = new Button(QString("Help"));
    int helpxPos = this->width()/2 - help->boundingRect().width()/2;
    int helpyPos = 330;
    help->setPos(helpxPos,helpyPos);
    connect(help,SIGNAL(clicked()),this,SLOT(helpDisplay()));
    scene->addItem(help);

    // create the quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 410;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(closeGame()));
    scene->addItem(quitButton);
}


