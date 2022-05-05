#ifndef ENEMYPADDLE_H
#define ENEMYPADDLE_H

#include <QGraphicsRectItem>
#include <QObject>

class enemyPaddle: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    enemyPaddle(int, int);
    ~enemyPaddle(){}

public slots:
    void follow();
    void autoLaunch();

private:
    bool firstball = true;
    int screenh;
    int screenw;
    int paddlelength;
};

#endif // ENEMYPADDLE_H
