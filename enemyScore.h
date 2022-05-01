#ifndef ENEMYSCORE_H
#define ENEMYSCORE_H

#include <QGraphicsTextItem>

class enemyScore: public QGraphicsTextItem{
public:
    enemyScore(QGraphicsItem * parent=0);
    void changeEnemyScore(int num);
    int getEnemyScore();

private:
    int enemy_Score;
};


#endif // ENEMYSCORE_H
