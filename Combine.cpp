#include "Combine.h"
#include <QBrush>
#include <QDebug>

Combine::Combine() {
    //sets up scene
    QString mStr = "You get points by breaking blocks.";
    QString aStr = "The paddle with the most points wins.";
    QString bStr = "Use the left and right arrow keys to move.";
    QString cStr = "Press space to launch your ball.";
    QString dStr = "If you are hit by your enemies ball you lose 1 point and your ball resets.";
    QString eStr = "If you miss your ball, then you are stuck for 5 seconds and you lose 2 points.";
    QString fStr = "Press esc to go back to main menu.";
}
