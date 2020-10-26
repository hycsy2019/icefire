#include "mainwindow.h"
#include "ui_mainwindow.h"

int rebound;//记录下一次跳跃是否反弹

Character::Character(QLabel* label)
{
    /* 初始化人物图标、坐标 */
    img=label;
    x=label->x();
    y=label->y();
    y_floor = label->y();
    y_head = 0;
}

Character::~Character()
{
    delete img;
}

/* 移动人物到新的坐标点 */
 void Character::move(float dx,float dy)
 {
     /* 更新label坐标 */
     x=img->x()+dx;
     y=img->y()+dy;

     /* 移动 */
     img->move(x,y);
 }

 void Character::jump()
 {
     /* 若当前非跳起状态，直接返回 */
     if (jump_state == 0) return;
     else
     {
<<<<<<< Updated upstream
=======
         if (rebound == 1)
             rebound = 0;
>>>>>>> Stashed changes
         if (jump_t < (-2 * JUMP_V0 / JUMP_G))
         {
             /* 计算当前时间单位高度偏移量 */
             float dh = JUMP_V0 + JUMP_G * jump_t + JUMP_G / 2;

<<<<<<< Updated upstream
             /* 移动 */
             move(dx_jump, -dh);

=======
             /*判断是否达到最大高度*/
             if (y < y_head)
             {
                 y = y_head;
                 img->move(x, y);
                 jump_t = -2 * JUMP_V0 / JUMP_G - jump_t+1;
                 rebound = 1;
                 return;
             }

             /* 移动 */
             move(dx_jump, -dh);
>>>>>>> Stashed changes
             jump_t++;
         }
         else
         {
             /* 落回地面 */
             jump_t = 0;
             jump_state = 0;
             img->move(img->x()+dx_jump, y_floor);
         }
         dx_jump = 0;
     }
 }
