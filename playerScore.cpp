#include "playerScore.h"
#include <QFont>

playerScore::playerScore(QGraphicsItem *parent): QGraphicsTextItem(parent){
    player_Score = 0;

    setPlainText(QString("Your Score: ") + QString::number(player_Score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 20));
}

void playerScore::changePlayerScore(int num){
    player_Score = player_Score + num;

    if (player_Score < 0){
        player_Score = 0;
    }

    setPlainText(QString("Your Score: ") + QString::number(player_Score));
}


int playerScore::getPlayerScore()
{
    return player_Score;
}
