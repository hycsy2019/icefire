#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<qevent.h>
#include<QTimer>
#include<QLabel>
#include<QtConcurrent/QtConcurrent>
#include<thread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#define SPEED 16 //左右移动速度
#define KEY_TIME 53 //定时器在每次按键后接收按键消息的时间
#define JUMP_UPDATE_TIME 69//跳跃动画延迟时间
#define JUMP_V0 33 //跳起的初速度
#define JUMP_G -7 //重力加速度

class Character
{
public:
    bool jump_state = 0;//是否在跳跃状态
    int jump_t = 0;//起跳时间单位数
    float y_floor;//当前所处的地面高度
<<<<<<< Updated upstream
=======
    float y_head;//跳起能达到的最高高度
>>>>>>> Stashed changes
    float dx_jump=0;//跳起时单位时间内水平位移
    Character(QLabel* label);//传入label指针
    ~Character();
    void move(float dx,float dy);//移动人物到新的坐标点,形参为坐标变化量
    void jump();//根据jump_state处理人物跳跃

private:
<<<<<<< Updated upstream
    float x_old,y_old;//人物的初始坐标
    float x_new,y_new;//人物移动后的坐标
=======
    float x,y;//人物的坐标
>>>>>>> Stashed changes
    QLabel* img;//人物图标
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);//移动背景窗口
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *keyTimer;//按键定时器
    QTimer *jumpTimer_ice;//跳跃刷新计时器
    QTimer *jumpTimer_fire;//跳跃刷新计时器
    QSet<int> pressedKeys;//保存按下的按键
    Character *icegirl;//冰娃移动对象
    Character *fireboy;//火娃移动对象
    void keyPressEvent(QKeyEvent *event);//按键按下
   void  keyReleaseEvent(QKeyEvent *event);//按键释放
   void keyMove();//处理按键消息处理移动
};


#endif // MAINWINDOW_H
