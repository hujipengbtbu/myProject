#include "food.h"
#include "constants.h"

static const qreal food_RADIUS = 3;

food::food(qreal x, qreal y)
    :_readius(3)
{
    setPos(x,y);

    //setData(GD_Type, GO_food);
}

void food::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(shape(),Qt::red);
    painter->restore();
}

QRectF food::boundingRect() const
{
    return QRectF(0,0,LINT_SIZE*2,LINT_SIZE*2);
}

QPainterPath food::shape() const
{
    QPainterPath qp;
    qp.addEllipse(QPointF(LINT_SIZE/2,LINT_SIZE/2),_readius,_readius);
    return qp;
}

