#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>

//#include "HexBoard.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:

    // constructors
    Game(QWidget* parent=NULL);

    // public methods
    void displayMainMenu();
    void displayHelpScreen();
    void displayScoreBoard();

    // public attributes
    QGraphicsScene* scene;
    //HexBoard* hexBoard;
    QString whosTurn;


public slots:
    void start();
    void helpDisplay();
    void closeGame();
    void mainMenu();
};

#endif // GAME_H
