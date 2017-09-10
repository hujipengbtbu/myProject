#include "snake.h"
#include "constants.h"
Snake::Snake(GameController & controller):
    head(0, 0),
    growing(7),
    speed(3),
    moveDirection(NoMove),
    controller(controller)
{

}

void Snake::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}


void Snake::setMoveDirection(Direction dt)
 {

 }

void Snake::moveLeft()
{

}

void Snake::moveRight()
{

}

void Snake::moveUp()
{

}

void Snake::moveDown()
{

}

QPainterPath Snake::shape() const
{
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);

    path.addRect(QRectF(0, 0, LINT_SIZE, LINT_SIZE));

    foreach (QPointF p, tail) {
        QPointF itemp = mapFromScene(p);
        path.addRect(QRectF(itemp.x(), itemp.y(), LINT_SIZE, LINT_SIZE));
    }

    return path;
}

QRectF Snake::boundingRect() const
{
    qreal minX = head.x();
    qreal minY = head.y();
    qreal maxX = head.x();
    qreal maxY = head.y();

    foreach (QPointF p, tail) {
        maxX = p.x() > maxX ? p.x() : maxX;
        maxY = p.y() > maxY ? p.y() : maxY;
        minX = p.x() < minX ? p.x() : minX;
        minY = p.y() < minY ? p.y() : minY;
    }

    QPointF tl = mapFromScene(QPointF(minX, minY));
    QPointF br = mapFromScene(QPointF(maxX, maxY));

    QRectF bound = QRectF(tl.x(),  // x
                          tl.y(),  // y
                          br.x() - tl.x() + LINT_SIZE,      // width
                          br.y() - tl.y() + LINT_SIZE       //height
                          );
    return bound;
}

