#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>

class Game: public QGraphicsView{
    Q_OBJECT
public:

    Game(QWidget* parent=NULL);

    // public methods
    void displayMainMenu();
    void displayHelpScreen();
    void displayScoreBoard();
    QGraphicsScene* scene;


public slots:
    void start();
    void helpDisplay();
    void closeGame();
    void mainMenu();
};

#endif // GAME_H
