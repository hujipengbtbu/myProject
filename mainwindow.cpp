#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constants.h"
#include "gamecontroller.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _Scene(new QGraphicsScene(this)),
    _View(new QGraphicsView(_Scene,this)),
    game(new GameController(*_Scene, this))
{
    setCentralWidget(_View);
    QPixmap b(LINT_SIZE,LINT_SIZE);
    QPainter p(&b);
    resize(600,600);
    p.setBrush(QBrush(Qt::gray));

    p.drawRect(0,0,LINT_SIZE,LINT_SIZE);
    _View->setBackgroundBrush(QBrush(b));

    //ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
