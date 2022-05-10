#include "enemyScore.h"
#include <QFont>

enemyScore::enemyScore(QGraphicsItem *parent): QGraphicsTextItem(parent){
    enemy_Score = 0;

    setPlainText(QString("Enemy Score: ") + QString::number(enemy_Score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 20));
}

void enemyScore::changeEnemyScore(int num){
    enemy_Score = enemy_Score + num;

    if (enemy_Score < 0){
        enemy_Score = 0;
    }

    setPlainText(QString("Enemy Score: ") + QString::number(enemy_Score));
}


int enemyScore::getEnemyScore()
{
    return enemy_Score;
}

void enemyScore::setToZero()
{
    enemy_Score = 0;
}
