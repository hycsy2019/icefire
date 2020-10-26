#include "mainwindow.h"
#include "ui_mainwindow.h"

MAP_TEST::MAP_TEST(){//构造函数
    section_num = 27;//27个区域
    //构造第一层的区域信息
    SECTION_INFO section;
    //0 区信息
    section.level = 0;
    section.left_x = 66;
    section.right_x = 544;
    section.ground_y = 1142;
    section.ceiling_y = 1024;
    section.down_y = 1142;
    section.up_y =1024;
    section_vector.insert(section_vector.end(),section);      //在数组最后，添加元素
    //1区
    section.level = 0;
    section.left_x = 544;
    section.right_x = 624;
    section.ground_y = 1142;
    section.ceiling_y = 866;
    section.down_y = 1142;
    section.up_y =866;
    section_vector.insert(section_vector.end(),section);      //在数组最后，添加元素
    //2区
    section.level = 0;
    section.left_x = 624;
    section.right_x = 706;
    section.ground_y = 1142;
    section.ceiling_y = 906;
    section.down_y = 1142;
    section.up_y =906;
    section_vector.insert(section_vector.end(),section);      //在数组最后，添加元素
    //3区
    section.level = 0;
    section.left_x = 706;
    section.right_x = 984;
    section.ground_y = 1142;
    section.ceiling_y = 945;
    section.down_y = 1142;
    section.up_y =945;
    section_vector.insert(section_vector.end(),section);      //在数组最后，添加元素
    //4区
    section.level = 0;
    section.left_x = 984;
    section.right_x = 1030;
    section.ground_y = 1142;
    section.ceiling_y = 985;
    section.down_y = 1142;
    section.up_y =985;
    section_vector.insert(section_vector.end(),section);      //在数组最后，添加元素
    //5区
    section.level = 0;
    section.left_x = 1030;
    section.right_x = 1423;
    section.ground_y = 1142;
    section.ceiling_y = 945;
    section.down_y = 1142;
    section.up_y =1021;
    section_vector.insert(section_vector.end(),section);      //在数组最后，添加元素
    //6区
    section.level = 1;
    section.left_x = 66;
    section.right_x = 544;
    section.ground_y = 977;
    section.ceiling_y = 867;
    section.down_y = 1142;
    section.up_y =867;
    section_vector.insert(section_vector.end(),section);      //在数组最后，添加元素
    //7区
    section.level = 2;
    section.left_x = 1424;
    section.right_x = 1543;
    section.ground_y = 1021;
    section.ceiling_y = 827;
    section.down_y = 1142;
    section.up_y =898;
    section_vector.insert(section_vector.end(),section);      //在数组最后，添加元素
    qDebug()<<"section_vector.size = " << section_vector.size()<<endl;

}

MAP_TEST::~MAP_TEST(){//析构函数
    //delete section_vector;
}

POINT MAP_TEST::judge_move(POINT new_position,POINT old_position){//下一秒的位置信息传入，输出的是实际可到达的位置
    POINT next = new_position;
   //传入的坐标，需要引用类中的私有变量——地图坐标，来进行判断
   //先判断区数
    int section_index = this->judge_level(new_position);//遍历返回最终的区域数据
    qDebug()<<"section_index : ="<<section_index <<endl;

    //判断左右
    if(section_vector.at(section_index).level == 0){
        if(new_position.x <= 66 || new_position.x + 60 >= 1424){

            next.x = old_position.x;
            qDebug()<<"THE ICE GIRL CAN NOT MOVE"<<endl;
            if(section_vector.at(section_index).ceiling_y!=section_vector.at(section_index).up_y){//说明有可跳跃高台
                if(new_position.y + 50 <= section_vector.at(section_index).up_y
                && new_position.x + 60 >= section_vector.at(section_index).right_x){
                    next.y = section_vector.at(section_index).up_y - 90;
                    next.x = new_position.x;
                }
            }
        }
        else{
            next.x = new_position.x;
            qDebug()<<"THE ICE GIRL CAN MOVE"<<endl;
        }

    }

    //判断高度
    if(new_position.y +10 < section_vector.at(section_index).ceiling_y){
        next.y = old_position.y;
        qDebug()<<"THE ICE GIRL CAN NOT MOVE"<<endl;
    }
    else{
        next.y = new_position.y;
        qDebug()<<"THE ICE GIRL CAN MOVE"<<endl;
    }

    //判断能不能登上高台



    //是否处于斜坡
    //是否处于
     return next;
}

int MAP_TEST::judge_level(POINT new_position){
    int i;
    for(i = 0;i<section_vector.size();i++){
        if(new_position.x +30 >= section_vector.at(i).left_x &&
           new_position.x +30 < section_vector.at(i).right_x &&
           new_position.y +45 >= section_vector.at(i).ceiling_y &&
           new_position.y +45 < section_vector.at(i).ground_y){
           break;
        }
    }
    return i;
}
