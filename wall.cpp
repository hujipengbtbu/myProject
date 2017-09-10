#include "wall.h"

Wall::Wall()
{

}

void Wall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

QRectF Wall::boundingRect() const
{
    return QRectF(0,0,20,20);

}

QPainterPath Wall::shape() const
{
    QPainterPath p;
    p.addRoundRect(0,0,100,100,22);
    return p;
}
