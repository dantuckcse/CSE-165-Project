#include "Game.h"
#include "Button.h"
#include <QGraphicsTextItem>
#include "setup.h"
#include <string>

extern setup* newGame;
extern Game* ui;

Game::Game(QWidget *parent){
    // set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);

    // set up the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,768);
    scene->setBackgroundBrush(Qt::white);
    setScene(scene);
}

void Game::start(){
    // clear the screen
    //scene->clear();
    newGame = new setup();
    newGame->show();
}

void Game::helpDisplay(){
    scene->clear();
    ui = new Game();
    ui->show();
    ui->displayHelpScreen();
}

void Game::closeGame(){
    scene->clear();
    exit(0);
}

void Game::mainMenu(){
    scene->clear();
    ui = new Game();
    ui->show();
    ui->displayMainMenu();
}

//sets the graphics items for the main menu
void Game::displayMainMenu() {
    //create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Breakout"));
    QFont titleFont("sans serif",50);
    titleText->setFont(titleFont);
    int txPosition = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPosition = 150;
    titleText->setPos(txPosition,tyPosition);
    scene->addItem(titleText);

    //create the play button
    Button* playButton = new Button(QString("Play Game"));
    int bxPosition = this->width()/2 - playButton->boundingRect().width()/2;
    int byPosition = 250;
    playButton->setPos(bxPosition,byPosition);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    //create the help button
    Button* help = new Button(QString("Help"));
    int helpxPosition = this->width()/2 - help->boundingRect().width()/2;
    int helpyPosition = 330;
    help->setPos(helpxPosition,helpyPosition);
    connect(help,SIGNAL(clicked()),this,SLOT(helpDisplay()));
    scene->addItem(help);

    //create the quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPosition = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPosition = 410;
    quitButton->setPos(qxPosition,qyPosition);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(closeGame()));
    scene->addItem(quitButton);
}

//sets the graphics items for the help screen
void Game::displayHelpScreen(){
    QFont titleFont("sans serif",15);
    QFont titleFont2("sans serif",30);

    QGraphicsTextItem* text = new QGraphicsTextItem(QString("Rules"));
    text->setFont(titleFont2);
    text->setDefaultTextColor(Qt::red);
    int txPos = this->width()/2 - text->boundingRect().width()/2;
    int tyPos = 50;
    text->setPos(txPos,tyPos);
    scene->addItem(text);

    QGraphicsTextItem* text1 = new QGraphicsTextItem(QString("There are 90 seconds until the game ends."));
    text1->setFont(titleFont);
    int txPos1 = this->width()/2 - text1->boundingRect().width()/2;
    int tyPos1 = 120;
    text1->setPos(txPos1,tyPos1);
    scene->addItem(text1);

    QGraphicsTextItem* text2 = new QGraphicsTextItem(QString("You get 1 point per block you break."));
    text2->setFont(titleFont);
    int txPos2 = this->width()/2 - text2->boundingRect().width()/2;
    int tyPos2 = 160;
    text2->setPos(txPos2,tyPos2);
    scene->addItem(text2);

    QGraphicsTextItem* text3 = new QGraphicsTextItem(QString("The paddle with the most points wins."));
    text3->setFont(titleFont);
    int txPos3 = this->width()/2 - text3->boundingRect().width()/2;
    int tyPos3 = 360;
    text3->setPos(txPos3,tyPos3);
    scene->addItem(text3);

    QGraphicsTextItem* text4 = new QGraphicsTextItem(QString("Use the left and right arrow keys to move."));
    text4->setFont(titleFont);
    int txPos4 = this->width()/2 - text4->boundingRect().width()/2;
    int tyPos4 = 200;
    text4->setPos(txPos4,tyPos4);
    scene->addItem(text4);

    QGraphicsTextItem* text5  = new QGraphicsTextItem(QString("Press space to launch your ball."));
    text5->setFont(titleFont);
    int txPos5 = this->width()/2 - text5->boundingRect().width()/2;
    int tyPos5 = 240;
    text5->setPos(txPos5,tyPos5);
    scene->addItem(text5);

    QGraphicsTextItem* text6 = new QGraphicsTextItem(QString("If you are hit by your enemies ball you lose 1 point and your ball resets."));
    text6->setFont(titleFont);
    int txPos6 = this->width()/2 - text6->boundingRect().width()/2;
    int tyPos6 = 280;
    text6->setPos(txPos6,tyPos6);
    scene->addItem(text6);

    QGraphicsTextItem* text7 = new QGraphicsTextItem(QString("If you miss your ball, then you are stuck for 5 seconds and you lose 2 points."));
    text7->setFont(titleFont);
    int txPos7 = this->width()/2 - text7->boundingRect().width()/2;
    int tyPos7 = 320;
    text7->setPos(txPos7,tyPos7);
    scene->addItem(text7);

    QGraphicsTextItem* text8 = new QGraphicsTextItem(QString("ATTENTION! Remember to press on the blue paddle!"));
    text8->setFont(titleFont);
    text8->setDefaultTextColor(Qt::red);
    int txPos8 = this->width()/2 - text8->boundingRect().width()/2;
    int tyPos8 = 400;
    text8->setPos(txPos8,tyPos8);
    scene->addItem(text8);

    QGraphicsTextItem* text9 = new QGraphicsTextItem(QString("Press back button to go back to main menu."));
    text9->setFont(titleFont);
    int txPos9 = this->width()/2 - text9->boundingRect().width()/2;
    int tyPos9 = 500;
    text9->setPos(txPos9,tyPos9);
    scene->addItem(text9);

    Button* backButton = new Button(QString("Back"));

    int qxPos = 20;
    int qyPos = 20;
    backButton->setPos(qxPos,qyPos);
    connect(backButton,SIGNAL(clicked()),this,SLOT(mainMenu()));
    scene->addItem(backButton);
}

//sets the graphics items for the scoreboard
void Game::displayScoreBoard(){
    QFont titleFont("sans serif",50);
    QFont titleFont2("sans serif",40);

    QGraphicsTextItem* playerScore = new QGraphicsTextItem(QString("Player Score: ") + QString::number(newGame->ps->getPlayerScore()));
    playerScore->setFont(titleFont2);
    int txPos1 = this->width()/2 - playerScore->boundingRect().width()/2;
    int tyPos1 = 100;
    playerScore->setPos(txPos1,tyPos1);
    scene->addItem(playerScore);

    QGraphicsTextItem* enemyScore = new QGraphicsTextItem(QString("Enemy Score: ") + QString::number(newGame->es->getEnemyScore()));
    enemyScore->setFont(titleFont2);
    int txPos2 = this->width()/2 - enemyScore->boundingRect().width()/2;
    int tyPos2 = 300;
    enemyScore->setPos(txPos2,tyPos2);
    scene->addItem(enemyScore);

    if(newGame->ps->getPlayerScore() > newGame->es->getEnemyScore()){
        QGraphicsTextItem* win = new QGraphicsTextItem(QString("You Won!"));
        win->setFont(titleFont);
        win->setDefaultTextColor(Qt::blue);
        int txPos2 = this->width()/2 - win->boundingRect().width()/2;
        int tyPos2 = 500;
        win->setPos(txPos2,tyPos2);
        scene->addItem(win);
    }
    else if(newGame->ps->getPlayerScore() < newGame->es->getEnemyScore()){
        QGraphicsTextItem* loss = new QGraphicsTextItem(QString("You Lost!"));
        loss->setFont(titleFont);
        loss->setDefaultTextColor(Qt::red);
        int txPos2 = this->width()/2 - loss->boundingRect().width()/2;
        int tyPos2 = 500;
        loss->setPos(txPos2,tyPos2);
        scene->addItem(loss);
    }
    else{
        QGraphicsTextItem* draw = new QGraphicsTextItem(QString("Draw! Better Luck Next Time."));
        draw->setFont(titleFont);
        draw->setDefaultTextColor(Qt::green);
        int txPos2 = this->width()/2 - draw->boundingRect().width()/2;
        int tyPos2 = 500;
        draw->setPos(txPos2,tyPos2);
        scene->addItem(draw);
    }

    Button* backButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - backButton->boundingRect().width()/2;
    int qyPos = 650;
    backButton->setPos(qxPos,qyPos);
    connect(backButton,SIGNAL(clicked()),this,SLOT(closeGame()));
    scene->addItem(backButton);
}


