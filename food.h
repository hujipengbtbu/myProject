#ifndef FOOD_H
#define FOOD_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPainterPath>
class food : public QGraphicsItem
{
public:
    food(qreal x, qreal y);

    virtual void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget = Q_NULLPTR);

    virtual QRectF boundingRect() const ;
    QPainterPath shape()const;
private:
    qreal _readius;

};



#endif // FOOD_H
