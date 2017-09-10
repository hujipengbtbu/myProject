#include "gamecontroller.h"
#include <QKeyEvent>

#include "gamecontroller.h"
GameController::GameController(QGraphicsScene &scene,QObject *parent) : QObject(parent)
,scene(scene),
 snake(new Snake(*this))
{
        timer.start(1000/33);
        for(int i=0;i<10;i++)
        {
            food *fod=new food(600,600);
            scene.addItem(fod);
        }

        scene.addItem(snake);
        scene.installEventFilter(this);

        resume();
}


GameController::~GameController()
{
}



void GameController::snakeAteFood(Snake *snake, food *foo)
{
    //  scene.removeItem(fod);
    //  delete food;
    //  addNewFood();
}

 bool GameController::eventFilter(QObject *obj,QEvent *event)
 {
    if(event->type()==QEvent::KeyPress)
    {
        handleKeyPressed((QKeyEvent *)event);
        return true;
    }else{
        return QObject::eventFilter(obj,event);

    }
 }

 void GameController::handleKeyPressed(QKeyEvent *event)
 {
     switch (event->key()) {
     case Qt::Key_Left:
         snake->setMoveDirection(Snake::MoveLeft);
         break;
     case Qt::Key_Right:
         snake->setMoveDirection(Snake::MoveRight);
         break;
     case Qt::Key_Down:
         snake->setMoveDirection(Snake::MoveDown);
         break;
     case Qt::Key_Up:
         snake->setMoveDirection(Snake::MoveUp);
         break;
     default:
         break;
     }
 }

 void GameController::addNewFood()
 {
    int x,y;
    do{
        x=(int)(qrand()%100)/10;
        y=(int)(qrand()%100)/10;

        x*=10;
        y*=10;
    }while(snake->shape().contains(snake->mapFromScene(QPointF(x+5,y+5))));
    food *fod=new food(x,y);
    scene.addItem(fod);
 }

 void GameController::resume()
 {
     connect(&timer, SIGNAL(timeout()),
             &scene, SLOT(advance()));
 }
 void GameController::gameOver()
 {
     scene.clear();

     snake = new Snake(*this);
     scene.addItem(snake);
     addNewFood();
 }

 void GameController::pause()
 {
     disconnect(&timer, SIGNAL(timeout()),
                &scene, SLOT(advance()));
 }
