#include "mainwindow.h"
#include "ui_mainwindow.h"
//全局变量
bool ice_flag=0;//标志冰娃是否到达门口
bool fire_flag=0;//标志火娃是否到达门口

Character::Character(QLabel* label,bool sex_)
{
    /* 初始化人物图标、坐标 */
    img=label;
    old_position.x=label->x();
    old_position.y=label->y();
    y_floor = label->y();
    section_id = 0;//表示区号
    sex = sex_;
}

Character::~Character()
{
    delete img;
}

/* 移动人物到新的坐标点 */
 void Character::move(int dx,int dy)
 {
     /* 更新label坐标 */
     new_position.x=img->x()+dx;
     new_position.y=img->y()+dy;
    // if(new_position.x>300)
        // qDebug()<<"";

     //判断，能不能更新
     new_position = w->map->judge_move(this,new_position);
     w->tools.judge_tools(this,new_position);
     if(section_id==22)
     if (new_position.y >y_floor) {//达到地面以下
         new_position.y =y_floor;
         jump_state = 0;//停止跳跃
         jump_t = 0;
     }

     img->move(new_position.x, new_position.y);

     /* 更新上一次坐标 */
     old_position.x = img->x();
     old_position.y = img->y();
 }

 void Character::jump_stop()
 {
     jump_t = 0;
     jump_state = 0;
     h_jump=0;
     jump_v0 = JUMP_V0;
     img->move(img->x() + dx_jump, y_floor);
 }

 void Character::jump()
 {
     /* 若当前非跳起状态，直接返回 */
     if (jump_state == 0)
         return;
     else{//正常跳跃状态
         if (jump_t < (-2 * jump_v0 / JUMP_G)||new_position.y<y_floor)//跳跃时间没有到达最终
         {
             /* 计算当前时间单位高度偏移量 */
             float dh = jump_v0 + JUMP_G * jump_t + JUMP_G / 2;

             /* 移动 */
             move(dx_jump, -dh);

             jump_t++;
         }
         else//跳跃时间到达
         {
             /* 落回地面 */
             jump_stop();
         }
         dx_jump = 0;
     }
 }
