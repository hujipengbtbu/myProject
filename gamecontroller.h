#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <QTime>
#include <QGraphicsScene>
#include <QTimer>
#include "snake.h"
#include "food.h"
#include "wall.h"

class GameController : public QObject
{
    Q_OBJECT
public:
    explicit GameController(QGraphicsScene &scene,QObject *parent = 0);
    ~GameController();

    void snakeAteFood(Snake *snake,food * foo);
    void snakeHitWall(Snake *snake,Wall *wall);
    void snakeAteItself(Snake *snake);
signals:

public slots:
    void pause();
    void resume();
    void gameOver();
protected:
    bool eventFilter(QObject *obj,QEvent *event);
    void advance();
private:
    void handleKeyPressed(QKeyEvent *event);
    void addNewFood();

    QTimer timer;
    QGraphicsScene &scene;
    Snake *snake;
};

#endif // GAMECONTROLLER_H
