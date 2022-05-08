#include "block.h"
#include <QBrush>
#include <QRandomGenerator>

Block::Block(QGraphicsItem *parent): QGraphicsRectItem(parent){
    // draw rect
    setRect(0,0,90,25);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    quint32 n = QRandomGenerator::global()->bounded(0, 9); // generates a random number between 0 and 9
    QColor colors[10] = {QColor(175, 20, 144), QColor(235, 153, 0), QColor(89, 159, 0), QColor(62, 67, 229), QColor(226, 0, 0), //an array of colors
                         QColor(255, 60, 56), QColor(57, 246, 255), QColor(255, 236, 0), QColor(0, 240, 91), QColor(255, 132, 166)};
    brush.setColor(colors[n]); //sets the color of the block using the array of colors
    setBrush(brush);
}
