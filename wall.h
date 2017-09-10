#ifndef WALL_H
#define WALL_H
#include <QGraphicsItem>


class Wall : public QGraphicsItem
{
public:
    Wall();

    virtual void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget = Q_NULLPTR);

    virtual QRectF boundingRect() const ;
    QPainterPath shape()const;
};

#endif // WALL_H
