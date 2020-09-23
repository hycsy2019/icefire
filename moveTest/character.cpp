#include "mainwindow.h"
#include "ui_mainwindow.h"

Character::Character(QLabel* label)
{
    /* 初始化人物图标、坐标 */
    img=label;
    x_old=label->x();
    y_old=label->y();
    y_floor = label->y();
}

Character::~Character()
{
    delete img;
}

/* 移动人物到新的坐标点 */
 void Character::move(float dx,float dy)
 {
     /* 更新label坐标 */
     x_new=img->x()+dx;
     y_new=img->y()+dy;

     /* 更新上一次坐标 */
     x_old = img->x();
     y_old = img->y();

     /* 移动 */
     img->move(x_new,y_new);
 }

 void Character::jump()
 {
         if (jump_t < (-2 * JUMP_V0 / JUMP_G))
         {
             jump_state=1;

             /* 计算当前时间单位高度偏移量 */
             float dh = JUMP_V0 + JUMP_G * jump_t + JUMP_G / 2;

             /*判断是否在下落态*/
             if(dh<0)
                 fall_state=1;

             /* 移动 */
             move(0, -dh);

             jump_t++;
         }
         else
         {
             /* 落回地面 */
             fall_state=0;
             jump_t = 0;
             move(0,y_floor-img->y());
             jump_state = 0;
         }
 }
