#ifndef SNAKE_H
#define SNAKE_H
#include <QGraphicsItem>
#include <QRectF>

class GameController;

class Snake : public QGraphicsItem
{
public:
    enum Direction{
        NoMove,
        MoveLeft,
        MoveRight,
        MoveUp,
        MoveDown
    };
    Snake(GameController & controller);

    virtual void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget = Q_NULLPTR);

    virtual QRectF boundingRect() const ;

    QPainterPath shape() const;

    void setMoveDirection(Direction dt);

private:
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

    QPointF        head;
    int            growing;
    int            speed;
    QList<QPointF> tail;
    int            tickCounter;
    Direction      moveDirection;
    GameController &controller;
};

#endif // SNAKE_H
