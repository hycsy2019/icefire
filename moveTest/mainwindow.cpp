#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::keyMove()
{
    /*计时结束处理按键消息*/
    connect(updateTimer,&QTimer::timeout,[this]
    {
        if(pressedKeys.isEmpty())
        {
            updateTimer->stop();
            return;
        }
    for(int key:pressedKeys)
    {
        /*由方向键消息移动label*/
        switch(key)
        {
        case Qt::Key_Up:
            y =ui->label->y() - SPEED;
            if(y > -10)//边界判断
                ui->label->move(ui->label->x(), y);//向上移动就是x不变y减小
            break;
        case Qt::Key_Down:
            y = ui->label->y() + SPEED;
            if(y < this->height() - 40)
            {
                ui->label->move(ui->label->x(), y);//向下移动是x不变y 变大
            }
            break;
        case Qt::Key_Right:
            x = ui->label->x() + SPEED;
            if(x < this->width() - 40)
            {
                ui->label->move(x, ui->label->y());
            }
            break;
        case Qt::Key_Left:
            x = ui->label->x() -SPEED;
            if(x > -10)
                ui->label->move(x, ui->label->y());
            break;
        default:
            break;
        }
    }
    /*更新界面*/
    update();
    });
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    /*建立图形界面*/
    ui->setupUi(this);

    /*创建计时器*/
    updateTimer=new QTimer(this);

    /*将label的移动处理单独放入一个子线程，主线程接收键盘消息，优化移动控制*/
     QtConcurrent::run(this,&MainWindow::keyMove);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
       /*按键按下，key值放入容器，如果是长按触发的repeat就不判断*/
        if(!event->isAutoRepeat())
           pressedKeys.insert(event->key());

       /*判断是否运行，不然一直触发就一直不能timeout，在计时时间内接收键盘消息*/
       if(!updateTimer->isActive())
           updateTimer->start(KEYTIME);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    /*按键释放，从容器中移除，如果是长按触发的repeat就不判断*/
    if(!event->isAutoRepeat())
        pressedKeys.remove(event->key());

    /*若键盘消息容器为空，提前结束计时*/
    if(pressedKeys.isEmpty())
        updateTimer->stop();
}

