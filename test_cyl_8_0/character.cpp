#include "mainwindow.h"
#include "ui_mainwindow.h"

Character::Character(QLabel* label)
{
    /* 初始化人物图标、坐标 */
    img=label;
    old_position.x=label->x();
    old_position.y=label->y();
    new_position.x=label->x();
    new_position.y=label->y();
    y_floor = label->y();
    map = new MAP_TEST();//初始化地图信息
}

Character::~Character()
{
    delete img;
    delete map;
}

/* 移动人物到新的坐标点 */
 void Character::move(float dx,float dy)
 {
     /* 更新label坐标 */
     new_position.x=img->x()+dx;
     new_position.y=img->y()+dy;

     /* 更新上一次坐标 */
     old_position.x = img->x();
     old_position.y = img->y();

     //判断，能不能更新
    new_position = map->judge_move(new_position,old_position);

     /* 移动 */
     qDebug()<<"show the icegirl's position:("<<new_position.x<<","<<new_position.y<<")."<<endl;
     img->move(new_position.x,new_position.y);//QLabel自带的move函数
 }

 void Character::jump()
  {
      /* 若当前非跳起状态，直接返回 */
      if (jump_state == 0) return;
      else
      {
          if (jump_t < (-2 * JUMP_V0 / JUMP_G))
          {
              /* 计算当前时间单位高度偏移量 */
              float dh = JUMP_V0 + JUMP_G * jump_t + JUMP_G / 2;

              /*判断是否达到最大高度*/
              if (new_position.y < y_head)
              {
                  old_position.y=new_position.y;
                  new_position.y = y_head;
                  img->move(new_position.x, new_position.y);
                  jump_t = -2 * JUMP_V0 / JUMP_G - jump_t+1;
                  return;
              }

              /* 移动 */
              move(dx_jump, -dh);
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
