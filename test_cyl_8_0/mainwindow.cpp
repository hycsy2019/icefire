#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::keyMove()
{
        // 计时结束处理按键消息 */
        connect(keyTimer, &QTimer::timeout, [this]
        {
            if (pressedKeys.isEmpty())
            {
                keyTimer->stop();
            }
            for (int key : pressedKeys)
            {
                // 由方向键消息移动label */
                switch (key)
                {
                case Qt::Key_Up:
                    // 若人物在地面上则起跳，否则不处理 */
                    if (!icegirl->jump_state)
                    {
                        icegirl->jump_state = 1;
                        icegirl->jump();
                        jumpTimer_ice->start(JUMP_UPDATE_TIME);
                    }
                    break;

                case Qt::Key_Right:
                    if (!icegirl->jump_state)
                        icegirl->move(SPEED, 0);
                    else
                        // 如果在空中按下方向键，则设置跳跃水平位移 */
                        icegirl->dx_jump = SPEED;
                    break;

                case Qt::Key_Left:
                    if (!icegirl->jump_state)
                        icegirl->move(-SPEED, 0);
                    else
                        icegirl->dx_jump = -SPEED;
                    break;

                case Qt::Key_W:
                    //若人物在地面上则起跳，否则不处理 */
                    if (fireboy->jump_state == 0)
                    {
                        fireboy->jump_state = 1;
                        fireboy->jump();
                        jumpTimer_fire->start(JUMP_UPDATE_TIME);
                    }
                    break;

                case Qt::Key_D:
                    if (!fireboy->jump_state)
                        fireboy->move(SPEED, 0);
                    else
                        //如果在空中按下方向键，则设置跳跃水平位移 */
                        fireboy->dx_jump = SPEED;
                    break;

                case Qt::Key_A:
                    if (!fireboy->jump_state)
                        fireboy->move(-SPEED, 0);
                    else
                        fireboy->dx_jump = -SPEED;
                    break;

                default:
                    break;
                }
            }
        });

        connect(jumpTimer_ice, &QTimer::timeout, [this]
        {
            // 跳跃处理 */
            icegirl->jump();

            //暂停计时器*/
            jumpTimer_ice->stop();

            //判断是否继续执行跳跃动画
            if (icegirl->jump_state)
                jumpTimer_ice->start(JUMP_UPDATE_TIME);
        });

        connect(jumpTimer_fire, &QTimer::timeout, [this]
        {
            //跳跃处理
            fireboy->jump();

            //暂停计时器
            jumpTimer_fire->stop();

            //判断是否继续执行跳跃动画
            if (fireboy->jump_state)
                jumpTimer_fire->start(JUMP_UPDATE_TIME);
        });
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    //建立图形界面
    ui->setupUi(this);

    //创建人物
    icegirl = new Character(ui->icegirl);
    fireboy = new Character(ui->fireboy);

    //设置顶部最大高度
    // fireboy->y_head = 1020;
     icegirl->y_head = 1020;

    //创建计时器
    keyTimer=new QTimer(this);
    jumpTimer_ice = new QTimer(this);
    jumpTimer_fire = new QTimer(this);

    //将label的移动处理单独放入一个子线程，主线程接收键盘消息，优化移动控制
     QtConcurrent::run(this,&MainWindow::keyMove);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
       //按键按下，key值放入容器，如果是长按触发的repeat就不判断
    if (!event->isAutoRepeat())
        pressedKeys.insert(event->key());

       // 判断是否运行，不然一直触发就一直不能timeout，在计时时间内接收键盘消息
        if (!keyTimer->isActive())
        {
            keyTimer->start(KEY_TIME);
        }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    //按键释放，从容器中移除，如果是长按触发的repeat就不判断
    if(!event->isAutoRepeat())
        pressedKeys.remove(event->key());

    //若键盘消息容器为空，提前结束计时
    if(pressedKeys.isEmpty())
        keyTimer->stop();
}

