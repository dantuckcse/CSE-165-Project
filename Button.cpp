#include "Button.h"
#include <QGraphicsTextItem>
#include <QBrush>

Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent) {
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::lightGray);
    setBrush(brush);

    text = new QGraphicsTextItem(name,this);
    int xPosition = rect().width()/2 - text->boundingRect().width()/2;
    int yPosition = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPosition,yPosition);

    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::lightGray);
    setBrush(brush);
}
