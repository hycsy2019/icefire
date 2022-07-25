
#include "mainwindow.h"
#include "ui_mainwindow.h"

QTimer *jumpTimer_ice;//跳跃刷新计时器
QTimer *jumpTimer_fire;//跳跃刷新计时器

QImage *ice_girl_right=new QImage(":/character/resource/ice_girl_toRight_1.0.png");
QImage *ice_girl_left=new QImage(":/character/resource/ice_girl_toLeft_1.0.png");
QImage *ice_girl_front=new QImage(":/character/resource/ice_girl_front_1.0.png");
QImage *fire_boy_right=new QImage(":/character/resource/fire_boy_toRight_1.0.png");
QImage *fire_boy_left=new QImage(":/character/resource/fire_boy_toLeft_1.0.png");
QImage *fire_boy_front=new QImage(":/character/resource/fire_boy_front_1.0.png");

void MainWindow::judge_h_jump(Character *cha)
{
    if (!cha->jump_state&&cha->h_jump)
    {
        cha->jump_state = 1;
        cha->jump_v0 = 5;
        cha->jump();
        if (cha->sex == 0)
            jumpTimer_ice->start(JUMP_UPDATE_TIME);
        else
            jumpTimer_fire->start(JUMP_UPDATE_TIME);
    }
}

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
                    ui->icegirl->setPixmap(QPixmap::fromImage(*ice_girl_front));
                    // 若人物在地面上则起跳，否则不处理 */
                    if (!icegirl->jump_state)
                    {
                        icegirl->jump_state = 1;
                        icegirl->jump();
                        jumpTimer_ice->start(JUMP_UPDATE_TIME);
                    }
                    break;

                case Qt::Key_Right:
                    ui->icegirl->setPixmap(QPixmap::fromImage(*ice_girl_right));
                    if (!icegirl->jump_state)
                        icegirl->move(SPEED, 0);
                    else
                        // 如果在空中按下方向键，则设置跳跃水平位移 */
                        icegirl->dx_jump = SPEED;
                    break;

                case Qt::Key_Left:
                    ui->icegirl->setPixmap(QPixmap::fromImage(*ice_girl_left));
                    if (!icegirl->jump_state)
                        icegirl->move(-SPEED, 0);
                    else
                        icegirl->dx_jump = -SPEED;
                    break;

                case Qt::Key_W:
                    //若人物在地面上则起跳，否则不处理 */
                     ui->fireboy->setPixmap(QPixmap::fromImage(*fire_boy_front));
                    if (fireboy->jump_state == 0)
                    {
                        fireboy->jump_state = 1;
                        fireboy->jump();
                        jumpTimer_fire->start(JUMP_UPDATE_TIME);
                    }
                    break;

                case Qt::Key_D:
                     ui->fireboy->setPixmap(QPixmap::fromImage(*fire_boy_right));
                    if (!fireboy->jump_state)
                        fireboy->move(SPEED, 0);
                    else
                        //如果在空中按下方向键，则设置跳跃水平位移 */
                        fireboy->dx_jump = SPEED;
                    break;

                case Qt::Key_A:
                     ui->fireboy->setPixmap(QPixmap::fromImage(*fire_boy_left));
                    if (!fireboy->jump_state)
                        fireboy->move(-SPEED, 0);
                    else
                        fireboy->dx_jump = -SPEED;
                    break;

                default:
                    break;
                }
                judge_h_jump(icegirl);
                judge_h_jump(fireboy);
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
    icegirl = new Character(ui->icegirl,0);
    fireboy = new Character(ui->fireboy,1);
    ui->open_door_fire->setVisible(false);
    ui->open_door_ice->setVisible(false);
    ui->portal1->setVisible(false);
    ui->portal2->setVisible(false);
    ui->dead_blue->setVisible(false);
    ui->dead_red->setVisible(false);
    ui->dead_green->setVisible(false);

    //创建计时器
    keyTimer=new QTimer(this);
    jumpTimer_ice = new QTimer(this);
    jumpTimer_fire = new QTimer(this);

    //创建地图
    map = new MAP_TEST();//初始化地图信息

    connect(this, SIGNAL(gameover_signal()), this, SLOT(gameover_slot()));

    connect(this, SIGNAL(success_signal(int,int)), this, SLOT(success_slot(int,int)));


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

void MainWindow::mousePressEvent(QMouseEvent *event)//鼠标点击显示坐标
{
    if(event->button() == Qt::LeftButton){
        // todo ...
        qDebug()<<"position:"<< event->pos()<<endl;

    }
}

void MainWindow::sleep(unsigned int msec)  //msec为毫秒
{
    QTime reachTime = QTime::currentTime().addMSecs(msec);
    while (QTime::currentTime() < reachTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}



