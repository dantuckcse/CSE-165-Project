#ifndef PLAYERSCORE_H
#define PLAYERSCORE_H

#include <QGraphicsTextItem>

class playerScore: public QGraphicsTextItem{
public:
    playerScore(QGraphicsItem * parent=0);
    void changePlayerScore(int num);
    int getPlayerScore();

private:
    int player_Score;
};

#endif // PLAYERSCORE_H
