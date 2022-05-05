#ifndef PLAYERPADDLE_H
#define PLAYERPADDLE_H

#include <QGraphicsRectItem>
#include <QObject>

class playerPaddle: public QObject, public  QGraphicsRectItem
{
    Q_OBJECT
public:
    playerPaddle(int);
    ~playerPaddle(){}
    void keyPressEvent(QKeyEvent* event);
    int getkeypress();
private:
    bool firstball = true;
    int screenh;
};

#endif // PLAYERPADDLE_H
