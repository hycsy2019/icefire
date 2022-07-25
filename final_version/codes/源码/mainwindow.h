#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<qevent.h>
#include<QTimer>
#include<QVector>
#include<QLabel>
#include<QtConcurrent/QtConcurrent>
#include<thread>
#include <qmap.h>//用于地图数据存储
#include "ui_mainwindow.h"
#include "gameover.h"
#include "success.h"
#include "ui_success.h"
#include "start.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#define SPEED 18 //左右移动速度
#define KEY_TIME 53 //定时器在每次按键后接收按键消息的时间
#define JUMP_UPDATE_TIME 69//跳跃动画延迟时间
#define JUMP_V0 42 //跳起的初速度
#define JUMP_V0_1 57//加了蹦床以后的初速度
#define JUMP_G -6 //重力加速度

#define DIOMAND1 0   //蓝钻石1
#define DIOMAND2 1   //红钻石1
#define DIOMAND3 2   //红钻石2
#define DIOMAND4 3   //红钻石3
#define DIOMAND5 4   //红钻石4
#define DIOMAND6 5   //蓝钻石2
#define DIOMAND7 6   //蓝钻石3
#define DIOMAND8 7   //蓝钻石4
#define DOOR1 8  //女厕所门
#define DOOR2 9  //男厕所门
#define BOX 10   //箱子
#define BUTTON1 11    //按钮1
#define BUTTON2 12    //按钮2
#define PORTAL1 13    //传送门1
#define PORTAL2 14    //传送门2
#define TRAMPOLINE 15    //蹦床
#define POOL1 16  //蓝水池
#define POOL2 17  //红水池
#define POOL3 18  //绿水池

//结构体定义
typedef struct POINT{
    int x;
    int y;
}POINT;//坐标结构体

typedef struct BORDER_STATE {//存储边界状况
    int state = 0;//int jump_up jump_both
    QVector<int> up_or_down_num;// 跳上或者跳下的高度
}BORDER_STATE;

typedef struct SECTION_INFO {
    int left_x;//区域左边的范围
    int right_x;//区域右边的范围
    int ceiling_y;//天花板高度
    int ground_y;//层级的地面高度
    //没用
    int level;//记录层数信息

    BORDER_STATE left_status;//每区的左边界地形情况：0表示平地，1表示有跳跃向上平台，2表示有跳跃向下平台.3表示两者都有，4表示边界有墙
    BORDER_STATE right_status;//每区的右边界地形情况

    int is_Steep = 0;//判断是不是斜坡
    int is_Air = 0;//判断此处是不是空气区域
}SECTION_INFO;//每区的地形信息

class MainWindow;
class Character;

extern GameOver *gameover;
extern MainWindow *w;
extern success *success_window;
extern start *start_window;

class Tools {
public:
    void judge_tools(Character *cha, POINT new_pos);
    Tools();
    ~Tools();
    int blue_open = 0;
    int red_open = 0;
private:
    Character *cha;
    POINT new_position;
    int section_tools[41][4];
    bool on_button1;//是否踩着按钮1
    bool on_button2;//是否踩着按钮2
    void push(int direction);//推动箱子
    void judge_box();//判断与箱子交互
    void judge_button1();//判断是否站在button1上
    void judge_button2();
    void judge_trampoline();//判断是否在蹦床范围内
    void judge_blue_pool();//水池
    void judge_red_pool();//火池
    void judge_green_pool();//绿池
    void portal_show();//传送门瞬移

    int diamonds[8] = { 0 };//存储每颗钻石被吃掉的情况避免重复计数
};

//地图类
class MAP_TEST{
public:
    MAP_TEST();//构造函数
    ~MAP_TEST();//析构函数

    //功能函数——判断运动范围
    float get_Slope(POINT left, POINT right);
    POINT judge_move(Character *cha,POINT new_position);
    int judge_section(POINT new_position);//判断在哪个区域
    SECTION_INFO get_section_info(int section_num);//获取某个区域的信息
    void horizontal_jump(Character *cha);
    //void head_collide(Character *cha);
private:
    QVector<SECTION_INFO> section_vector;//创建section动态数据结构
    //QMap<int,TOOL> tool;//机关范围数组
};


class Character
{
public:
    float y_floor;//当前所处的地面高度
    float dx_jump=0;//跳起时单位时间内水平位移
    int section_id;//section区号
    bool fall_state=0;//是否在平抛下落状态
    bool jump_state = 0;//是否在跳跃状态
    int jump_v0 = JUMP_V0;//跳起初速度
    bool on_box;//是否在箱子上
    bool entering=0;//是否在穿越
    bool h_jump=0;//判断下一帧是否开始平抛

    bool on_button1 = 0;
    bool on_button2 = 0;

    Character(QLabel* label, bool sex);//传入label指针
    ~Character();
    void jump_stop();//停止跳跃
    POINT get_pos() { return old_position; }
    void move(int dx,int dy);//移动人物到新的坐标点,形参为坐标变化量
    void jump();//根据jump_state处理人物跳跃
    //void judge_open(POINT position);//根据位置判断是否该开门
    //void get_diamonds(POINT position);//根据位置恰钻石
    bool sex;

private:
    int jump_t = 0;//起跳时间单位数
    POINT new_position;
    POINT old_position;
    QLabel* img;//人物图标

};

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);//移动背景窗口
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);//按键按下
   void  keyReleaseEvent(QKeyEvent *event);//按键释放
   void keyMove();//处理按键消息处理移动
   //鼠标事件
   void mousePressEvent(QMouseEvent *event);
   void sleep(unsigned int msec);
     Ui::MainWindow *ui;
     MAP_TEST *map;
     Tools tools;
     void judge_h_jump(Character *cha);

     Character *icegirl;//冰娃移动对象
     Character *fireboy;//火娃移动对象



private:
    QTimer *keyTimer;//按键定时器
    QSet<int> pressedKeys;//保存按下的按键
signals://信号的声明不区分public和private
    void gameover_signal();
    void success_signal(int,int);
    //void start_signal( );

private slots:
    void gameover_slot() {
        sleep(1000);
         gameover->show();
         w->hide();
    };
    void success_slot(int red_num,int blue_num) {
        sleep(1000);
        success_window->show();
        success_window->ui->redNum->setText(QString::number(red_num));
        success_window->ui->blueNum->setText(QString::number(blue_num));
        if (red_num + blue_num >= 7) {
            success_window->ui->level->setText("A");
        }
        else if(red_num + blue_num >= 5) {
            success_window->ui->level->setText("B");
        }
        else if (red_num + blue_num >= 3) {
            success_window->ui->level->setText("C");
        }
        else {
            success_window->ui->level->setText("D");
        }
        w->hide();
    };

};



extern QTimer *jumpTimer_ice;//跳跃刷新计时器
extern QTimer *jumpTimer_fire;//跳跃刷新计时器

#endif // MAINWINDOW_H
