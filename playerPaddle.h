#ifndef PLAYERPADDLE_H
#define PLAYERPADDLE_H

#include <QGraphicsRectItem>
#include <QObject>

class playerPaddle: public QObject, public  QGraphicsRectItem {

    Q_OBJECT
public:

    playerPaddle();
    ~playerPaddle(){

    }

    void keyPressEvent(QKeyEvent* event);
    int getkeypress();

    bool startingBall = true;
};

#endif // PLAYERPADDLE_H