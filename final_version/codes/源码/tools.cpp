#include "mainwindow.h"

int blue_D = 0;//累计获得的蓝钻石数�
int red_D = 0;//累计获得的红钻石数
Tools::Tools()
{
    memset(section_tools, -1, sizeof(section_tools));
    section_tools[4][0] = 17;
    section_tools[4][1] = 4;
    section_tools[8][0] = 7;
    section_tools[8][1] = 16;
    section_tools[13][0] = 18;
    section_tools[17][0] = 15;
    section_tools[18][0] = 3;
    section_tools[21][0] = 10;
    section_tools[20][0] = 6;
    section_tools[20][1] = 10;
    section_tools[22][0] = 10;
    section_tools[27][0] = 11;
    section_tools[27][1] = 12;
    section_tools[28][0] = 11;
    section_tools[28][1] = 12;
    section_tools[29][0] = 11;
    section_tools[29][1] = 12;
    section_tools[29][2] = 13;
    section_tools[30][0] = 5;
    section_tools[30][2] = 12;
    section_tools[30][1] = 11;
    section_tools[30][3] = 14;
    section_tools[32][0] = 2;
    section_tools[36][0] = 0;
    section_tools[36][1] = 1;
    section_tools[40][0] = 8;
    section_tools[40][1] = 9;
}

Tools::~Tools()
{
}

void Tools::push(int direction)//推箱子
{
    int x = w->ui->box->x();
    int y = w->ui->box->y();
    if (x< 1460 && x >880)
    {
        w->ui->box->move(x + direction * SPEED, y);
    }
}

void Tools::judge_box()
{
    if (new_position.y >= w->ui->box->y() - 60)
    {
        if (new_position.x > w->ui->box->x() - 80 && new_position.x<w->ui->box->x() - 40 && new_position.x>cha->get_pos().x)//向右且紧贴箱子
            push(1);
        else if (new_position.x < w->ui->box->x() + 50 && new_position.x>w->ui->box->x() + 20 && new_position.x < cha->get_pos().x)//向左且紧贴箱子
            push(-1);
        cha->on_box = 0;
    }
    else if (new_position.x<w->ui->box->x() + 70 && new_position.x>w->ui->box->x() - 70)
    {
            cha->y_floor = 495;
        cha->on_box = 1;
        return;
    }
}


void Tools::judge_tools(Character *character,POINT new_pos) {
    cha = character;
    new_position = new_pos;
    int  section_index = w->map->judge_section(cha->get_pos());

    judge_button2();
    judge_button1();
    portal_show();

    for (int i = 0; i < 3; i++) {
        if (section_tools[section_index][i] >=0&&section_tools[section_index][i] <=18) {
            int tool = section_tools[section_index][i];
            switch (tool) {
            case DIOMAND1://钻石1
                if (cha->sex == 0 && new_position.x> 790 && new_position.x < 870 && new_position.y < 100+10 ) {
                    qDebug()<<"sex"<<endl;
                    w->ui->diamond1->setVisible(false);
                    if (diamonds[0] == 0) {
                        blue_D++;
                    }
                    diamonds[0] = 1;
                }
                break;
            case DIOMAND2://钻石2
                if (cha->sex == 1 && new_position.x > 680 - 90 && new_position.x < 680 + 30 && new_position.y < 100 + 10 && new_position.y > 100 - 10) {
                    w->ui->diamond2->setVisible(false);
                    if (diamonds[1] == 0) {
                        red_D++;
                    }
                    diamonds[1] = 1;
                }
                break;
            case DIOMAND3://钻石3
                if (cha->sex == 1 && new_position.x > 460 - 90 && new_position.x < 460 + 30 && new_position.y < 110 + 10 && new_position.y > 110 - 40) {

                    w->ui->diamond3->setVisible(false);
                    if (diamonds[2] == 0) {
                        red_D++;
                    }
                    diamonds[2] = 1;
                }
                break;
            case DIOMAND4:
                if (cha->sex == 1 && new_position.x > 280 && new_position.x < 410 && new_position.y < 540) {
                    w->ui->diamond4->setVisible(false);
                    if (diamonds[3] == 0) {
                        red_D++;
                    }
                    diamonds[3] = 1;
                }
                break;
            case DIOMAND5:
                if (cha->sex == 1 && new_position.x > 750 && new_position.x < 810 && new_position.y < 1020 && new_position.y > 980) {
                    w->ui->diamond5->setVisible(false);
                    if (diamonds[4] == 0) {
                        red_D++;
                    }
                    diamonds[4] = 1;
                }
                break;
            case DIOMAND6:
                if (cha->sex == 0 && new_position.x > 110 - 40 && new_position.x < 110 + 20 && new_position.y < 220) {
                    w->ui->diamond6->setVisible(false);
                    if (diamonds[5] == 0) {
                        blue_D++;
                    }
                    diamonds[5] = 1;
                }
                break;
            case DIOMAND7:
                if (cha->sex == 0 && new_position.x > 970 && new_position.x < 1090 && new_position.y < 580) {
                    w->ui->diamond7->setVisible(false);
                    if (diamonds[6] == 0) {
                        blue_D++;
                    }
                    diamonds[6] = 1;
                }
                break;
            case DIOMAND8:
                if (cha->sex == 0 && new_position.x > 1040 && new_position.x < 1170 && new_position.y < 1130 && new_position.y > 990) {
                    w->ui->diamond8->setVisible(false);
                    if (diamonds[7] == 0) {
                        blue_D++;
                    }
                    diamonds[7] = 1;
                }
                break;
            case DOOR1://��ɫ��
                if (cha->sex == 0 && new_position.x > 1380-45 && new_position.x < 1380 +45) {
                    w->ui->open_door_ice->setVisible(true);
                    blue_open =1;
                }
                else if(cha->sex == 0 && !(new_position.x > 1380 - 45 && new_position.x < 1380 + 45)){
                    w->ui->open_door_ice->setVisible(false);
                    blue_open = 0;
                }
                if(red_open == 1 && blue_open == 1){
                    emit w->success_signal(red_D,blue_D);
                }
                break;
            case DOOR2://��ɫ��
                if (cha->sex == 1 && new_position.x > 1260 - 45 && new_position.x < 1260 + 45) {
                    w->ui->open_door_fire->setVisible(true);
                    red_open = 1;
                }
                else if(cha->sex == 1 && !(new_position.x > 1260 - 45 && new_position.x < 1260 + 45)){
                    w->ui->open_door_fire->setVisible(false);
                    red_open = 0;
                }
                if(red_open == 1 && blue_open == 1){
                    emit w->success_signal(red_D,blue_D);
                }
                break;
            case BOX://����
                judge_box();
                break;
            case TRAMPOLINE://�Ĵ�
                judge_trampoline();
                break;
            case 16:
                judge_blue_pool();
                break;
            case POOL2:
                judge_red_pool();
                break;
            case POOL3:
                judge_green_pool();
                break;
            default:
                break;
            }
        }
    }



}

void Tools::judge_button1() {//�判断是否站在�button1��
    if (new_position.y == 370 && new_position.x > 360 && new_position.x < 460) {
        cha->on_button1 = true;
    }else{
        cha->on_button1=false;
    }
    if(w->icegirl->on_button1||w->fireboy->on_button1){
        w->ui->button1->setVisible(false);
        w->ui->portal1->setVisible(true);
        w->ui->portal2->setVisible(true);
    }
    else {
        w->ui->button1->setVisible(true);
        w->ui->portal1->setVisible(false);
        w->ui->portal2->setVisible(false);
    }


}

void Tools::judge_button2() {//�判断是否站在��button2��
    if (new_position.y == 210 && new_position.x > 100 && new_position.x < 210) {
        cha->on_button2 = true;
    }
    else{
        cha->on_button2=false;
    }
    if(w->icegirl->on_button2||w->fireboy->on_button2){
        w->ui->button2->setVisible(false);
        w->ui->portal1->setVisible(true);
        w->ui->portal2->setVisible(true);
    }
    else {
        w->ui->button2->setVisible(true);
        w->ui->portal1->setVisible(false);
        w->ui->portal2->setVisible(false);
    }

}

void Tools::judge_trampoline() {//判断是否在蹦床范围内��
    if (new_position.y == 730 && new_position.x > 70 && new_position.x < 140) {
        cha->jump_v0 = JUMP_V0_1;
    }
}

void Tools::judge_blue_pool() {//判断蓝池子����
    if (cha->sex == 1 && cha->jump_state==0&& new_position.x>1030 && new_position.x < 1160) {
        w->ui->fireboy->setVisible(false);
        w->ui->dead_blue->setVisible(true);
        //触发游戏结束ui
        emit w->gameover_signal();
    }

}

void Tools::judge_red_pool() {//判断红池子
    if (cha->sex == 0 && cha->jump_state==0 && new_position.x>730 && new_position.x < 840) {
        w->ui->icegirl->setVisible(false);
        w->ui->dead_red->setVisible(true);
        //触发游戏结束ui
        emit w->gameover_signal();
    }

}

void Tools::judge_green_pool() {//绿池子���������ˮ����
    if (cha->jump_state==0 && new_position.x>980 && new_position.x < 1080) {
        w->ui->icegirl->setVisible(false);
        w->ui->fireboy->setVisible(false);
        w->ui->dead_green->setVisible(true);
        //触发游戏结束ui
        emit w->gameover_signal();
    }

}

void Tools::portal_show() {//传送门瞬移
    if (w->icegirl->on_button1 || w->icegirl->on_button2||w->fireboy->on_button1||w->fireboy->on_button2) {
        if (cha->get_pos().x <= 80 && cha->get_pos().y == 210) {
            if(cha->entering==0){
                cha->entering=1;
                cha->move(220, 160);
            }
            else{
                cha->entering=0;
            }

        }
        else if (cha->get_pos().x <= 280 && cha->get_pos().y == 370) {
            if(cha->entering==0){
                cha->entering=1;
                cha->move(-180, -160);
            }
            else{
                cha->entering=0;
            }
        }
    }
    else {
        w->ui->portal1->setVisible(false);
        w->ui->portal2->setVisible(false);
        w->ui->button1->setVisible(true);
        w->ui->button2->setVisible(true);
    }
}
