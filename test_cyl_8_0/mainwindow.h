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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#define SPEED 19 //左右移动速度
#define KEY_TIME 53 //定时器在每次按键后接收按键消息的时间
#define JUMP_UPDATE_TIME 70//跳跃动画延迟时间
#define JUMP_V0 33 //跳起的初速度
#define JUMP_G -6 //重力加速度

//结构体定义
typedef struct POINT{
    int x;
    int y;
}POINT;//坐标结构体

typedef struct TOOL{
    POINT start;//起始点坐标
    POINT end;//结尾点坐标
    int type;//类型
}TOOL;

typedef struct SECTION_INFO{

    int left_x;//区域左边的范围
    int right_x;//区域右边的范围
    int ceiling_y;//天花板高度
    int ground_y;//层级的地面高度
    int down_y;//如果有断崖的话，记录跳下去的层高
    int up_y;//如果能够跳上更高层数的话，记录跳上去的层高
    int level;//记录层数信息
}SECTION_INFO;//每区的地形信息

//地图类
class MAP_TEST{
public:
    MAP_TEST();//构造函数
    ~MAP_TEST();//析构函数

    //功能函数——判断运动范围
    POINT judge_move(POINT new_position,POINT old_position);
    int judge_level(POINT new_position);//判断在哪一层

private:
    int section_num = 27;//区域数
    QVector<SECTION_INFO> section_vector;//创建section动态数据结构
    //QMap<int,TOOL> tool;//机关范围数组
};


class Character
{
public:
    bool jump_state = 0;//是否在跳跃状态
    int jump_t = 0;//起跳时间单位数
    float y_floor;//当前所处的地面高度
    float y_head;//跳起能达到的最高高度
    float dx_jump=0;//跳起时单位时间内水平位移
    //add by cyl

    bool fall_state=0;//是否在下落状态
    bool toleft_state = 0;//去左边
    bool toright_state = 0 ;//去右边
    MAP_TEST *map;

    Character(QLabel* label);//传入label指针
    ~Character();
    void move(float dx,float dy);//移动人物到新的坐标点,形参为坐标变化量
    void jump();//根据jump_state处理人物跳跃


private:
    POINT old_position;
    POINT new_position;
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

private:
    Ui::MainWindow *ui;
    QTimer *keyTimer;//按键定时器
    QTimer *jumpTimer_ice;//跳跃刷新计时器
    QTimer *jumpTimer_fire;//跳跃刷新计时器
    QSet<int> pressedKeys;//保存按下的按键
    Character *icegirl;//冰娃移动对象
    Character *fireboy;//火娃移动对象


};


#endif // MAINWINDOW_H
