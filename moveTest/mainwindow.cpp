#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::keyMove()
{
    connect(jumpTimer, &QTimer::timeout, [this]
    {
        /*跳跃处理*/
        icegirl->jump();

        /*暂停计时器*/
        jumpTimer->stop();

        /*判断是否继续执行跳跃动画*/
        if (icegirl->jump_state&&icegirl->y_new!=icegirl->y_floor)
            jumpTimer->start(JUMP_UPDATE_TIME);
    });

        /*计时结束处理按键消息*/
        connect(keyTimer, &QTimer::timeout, [this]
        {
            if (pressedKeys.isEmpty())
            {
                keyTimer->stop();
            }
            for (int key : pressedKeys)
            {
                /*由方向键消息移动label*/
                switch (key)
                {
                case Qt::Key_Up:
                    /* 若人物在地面上则起跳，否则不处理 */
                    if (icegirl->jump_state == 0)
                    {
                        icegirl->jump();
                        jumpTimer->start(JUMP_UPDATE_TIME);
                    }
                    break;

                case Qt::Key_Right:
                    icegirl->move(SPEED, 0);
                    break;

                case Qt::Key_Left:
                    icegirl->move(-SPEED, 0);
                    break;

                default:
                    break;
                }
            }
        });
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    /*建立图形界面*/
    ui->setupUi(this);

    /*创建人物*/
    icegirl = new Character(ui->icegirl);

    /*创建计时器*/
    keyTimer=new QTimer(this);
    jumpTimer = new QTimer(this);

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
        if (!keyTimer->isActive())
        {
            keyTimer->start(KEY_TIME);
            if (!icegirl->jump_state)
            {
                ui->icegirl->setPixmap(QPixmap(QString::fromUtf8(":/character/resource/icegirl_front.png")));
                ui->icegirl->setScaledContents(true);
            }
        }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    /*按键释放，从容器中移除，如果是长按触发的repeat就不判断*/
    if(!event->isAutoRepeat())
        pressedKeys.remove(event->key());

    /*若键盘消息容器为空，提前结束计时*/
    if(pressedKeys.isEmpty())
        keyTimer->stop();
}

