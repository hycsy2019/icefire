#include "mainwindow.h"
#include "ui_mainwindow.h"

#define SIMPLE 0//和隔壁区域直接相连
#define JUMP_UP 1//有向上的平台，且没有墙
#define JUMP_DOWN 2//有向下的平台
#define JUMP_BOTH 3//既可以向上，也可向下
#define WALL 4//墙壁
#define JUMP_UP_WALL 5//有墙且可以跳上
//#define STEEP_SIMPLE 6//斜坡与平台连接
//#define STEEP_JUMP_DOWN 7//斜坡且可以向下跳跃
#define WIDTH 120//墙壁
#define HEIGTH 90//有墙且可以跳上

MAP_TEST::MAP_TEST() {//构造函数
//    section_num = 27;//27个区域
    //构造第一层的区域信息
    SECTION_INFO section;
    //0 区信息
    section.level = 0;
    section.left_x = 66;
    section.right_x = 544;
    section.ground_y = 1142;
    section.ceiling_y = 1024;
    section.left_status.state = WALL;
    section.left_status.up_or_down_num.insert(section.left_status.up_or_down_num.end(), 1142);
    section.right_status.state = SIMPLE;
    section.right_status.up_or_down_num.insert(section.right_status.up_or_down_num.end(), 1142);
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
    //1区
    section.level = 0;
    section.left_x = 544;
    section.right_x = 624;
    section.ground_y = 1142;
    section.ceiling_y = 866;
    section.left_status.state = JUMP_UP;
    section.left_status.up_or_down_num[0] = 866;
    section.right_status.state = SIMPLE;
    section.right_status.up_or_down_num[0] = 1142;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    section.left_status.up_or_down_num.erase(section.left_status.up_or_down_num.begin());//删除vector中最后一个元素
//    section.right_status.up_or_down_num.erase(section.right_status.up_or_down_num.begin());//删除vector中最后一个元素
    //2区
    section.level = 0;
    section.left_x = 624;
    section.right_x = 706;
    section.ground_y = 1142;
    section.ceiling_y = 906;
    section.left_status.state = SIMPLE;
    section.left_status.up_or_down_num[0] = 1142;
    section.right_status.state = SIMPLE;
    section.right_status.up_or_down_num[0] = 1142;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
    //3区分开，水池左边
    section.level = 0;
    section.left_x = 706;
    section.right_x = 787;
    section.ground_y = 1142;
    section.ceiling_y = 945;
    section.left_status.state = SIMPLE;
    section.left_status.up_or_down_num[0] = 1142;
    section.right_status.state = JUMP_DOWN;
    section.right_status.up_or_down_num[0] = 1162;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    section.left_status.up_or_down_num.erase(section.left_status.up_or_down_num.begin());//删除vector中最后一个元素
//    section.right_status.up_or_down_num.erase(section.right_status.up_or_down_num.begin());//删除vector中最后一个元素
    //3区分开，水池
    section.level = 0;
    section.left_x = 787;
    section.right_x = 905;
    section.ground_y = 1162;
    section.ceiling_y = 945;
    section.left_status.state = JUMP_UP;
    section.left_status.up_or_down_num[0] = 1142;
    section.right_status.state = JUMP_UP;
    section.right_status.up_or_down_num[0] = 1142;
    section.is_Air = 1;//表示上方有空气
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    section.left_status.up_or_down_num.erase(section.left_status.up_or_down_num.begin());//删除vector中最后一个元素
//    section.right_status.up_or_down_num.erase(section.right_status.up_or_down_num.begin());//删除vector中最后一个元素
    //3区分开，水池右
    section.level = 0;
    section.left_x = 905;
    section.right_x = 984;
    section.ground_y = 1142;
    section.ceiling_y = 945;
    section.left_status.state = JUMP_DOWN;
    section.left_status.up_or_down_num[0] = 1162;
    section.right_status.state = SIMPLE;
    section.right_status.up_or_down_num[0] = 1142;
    section.is_Air = 0;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    section.left_status.up_or_down_num.erase(section.left_status.up_or_down_num.begin());//删除vector中最后一个元素
//    section.right_status.up_or_down_num.erase(section.right_status.up_or_down_num.begin());//删除vector中最后一个元素
    //4区
    section.level = 0;
    section.left_x = 984;
    section.right_x = 1030;
    section.ground_y = 1142;
    section.ceiling_y = 985;
    section.left_status.state = SIMPLE;
    section.left_status.up_or_down_num[0] = 1142;
    section.right_status.state = SIMPLE;
    section.right_status.up_or_down_num[0] = 1142;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    section.left_status.up_or_down_num.erase(section.left_status.up_or_down_num.begin());//删除vector中最后一个元素
//    section.right_status.up_or_down_num.erase(section.right_status.up_or_down_num.begin());//删除vector中最后一个元素
    //5区分开，水池左边
    section.level = 0;
    section.left_x = 1030;
    section.right_x = 1110;
    section.ground_y = 1142;
    section.ceiling_y = 945;
    section.left_status.state = SIMPLE;
    section.left_status.up_or_down_num[0] = 1142;
    section.right_status.state = JUMP_DOWN;
    section.right_status.up_or_down_num[0] = 1162;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    section.left_status.up_or_down_num.erase(section.left_status.up_or_down_num.begin());//删除vector中最后一个元素
//    section.right_status.up_or_down_num.erase(section.right_status.up_or_down_num.begin());//删除vector中最后一个元素
    //5区分开，水池
    section.level = 0;
    section.left_x = 1110;
    section.right_x = 1225;
    section.ground_y = 1162;
    section.ceiling_y = 945;
    section.left_status.state = JUMP_UP;
    section.left_status.up_or_down_num[0] = 1142;
    section.right_status.state = JUMP_UP;
    section.right_status.up_or_down_num[0] = 1142;
    section.is_Air = 1;//表示此处有空气
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    section.left_status.up_or_down_num.erase(section.left_status.up_or_down_num.begin());//删除vector中最后一个元素
//    section.right_status.up_or_down_num.erase(section.right_status.up_or_down_num.begin());//删除vector中最后一个元素
    //5区分开，水池右边
    section.level = 0;
    section.left_x = 1225;
    section.right_x = 1424;
    section.ground_y = 1142;
    section.ceiling_y = 945;
    section.left_status.state = JUMP_DOWN;
    section.left_status.up_or_down_num[0] = 1162;
    section.right_status.state = JUMP_UP_WALL;
    section.right_status.up_or_down_num[0] = 1062;
    section.is_Air = 0;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    section.left_status.up_or_down_num.erase(section.left_status.up_or_down_num.begin());//删除vector中最后一个元素
//    section.right_status.up_or_down_num.erase(section.right_status.up_or_down_num.begin());//删除vector中最后一个元素
    //6区
    section.level = 1;
    section.left_x = 66;
    section.right_x = 544;
    section.ground_y = 977;
    section.ceiling_y = 867;
    section.left_status.state = WALL;
    section.left_status.up_or_down_num[0] = 977;
    section.right_status.state = JUMP_DOWN;
    section.right_status.up_or_down_num[0] = 1142;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    section.left_status.up_or_down_num.erase(section.left_status.up_or_down_num.begin());//删除vector中最后一个元素
//    section.right_status.up_or_down_num.erase(section.right_status.up_or_down_num.begin());//删除vector中最后一个元素
    //7区
    section.level = 2;
    section.left_x = 1424;
    section.right_x = 1543;
    section.ground_y = 1021;
    section.ceiling_y = 827;
    section.left_status.state = JUMP_BOTH;
    section.left_status.up_or_down_num[0] = 1142;
    section.left_status.up_or_down_num.insert(section.left_status.up_or_down_num.end(),900); //num[1]表示下降高度
    section.right_status.state = WALL;
    section.right_status.up_or_down_num[0] = 1543;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    //7区-2 平台
//    section.level = 2;
//    section.left_x = 1466;
//    section.right_x = 1543;
//    section.ground_y = 1021;
//    section.ceiling_y = 827;
//    section.left_status.state = JUMP_BOTH;
//    section.left_status.up_or_down_num[0] = 1142;
//    section.left_status.up_or_down_num.insert(section.left_status.up_or_down_num.end(),900); //num[1]表示下降高度
//    section.right_status.state = WALL;
//    section.right_status.up_or_down_num[0] = 1021;
//    section.is_Air = 0;
//    section.is_Steep =0;
//    section_vector.insert(section_vector.end(),section);      //在数组最后，添加元素
    //8区分开 水池右边-1 斜坡
    section.level = 3;
    section.left_x = 1147;
    section.right_x = 1424;
    section.ground_y = 900;
    section.ceiling_y = 705;
    section.left_status.state = JUMP_DOWN;
    section.left_status.up_or_down_num[0] = 921;
    section.right_status.state = JUMP_DOWN;
    section.right_status.up_or_down_num[0] = 1021;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    //8区分开 水池右边
//     section.level = 3;
//     section.left_x = 1147;
//     section.right_x = 1344;
//     section.ground_y = 900;
//     section.ceiling_y = 705;
//     section.left_status.state = JUMP_DOWN;
//     section.left_status.up_or_down_num[0] = 921;
//     section.right_status.state = SIMPLE;
//     section.right_status.up_or_down_num[0]= 1021;
//     section.is_Steep = 0;
//     section.is_Air = 0;
//     section_vector.insert(section_vector.end(),section);      //在数组最后，添加元素
    //8区分开 水池
    section.level = 3;
    section.left_x = 1028;
    section.right_x = 1147;
    section.ground_y = 921;
    section.ceiling_y = 705;
    section.left_status.state = JUMP_UP;
    section.left_status.up_or_down_num[0] = 900;
    section.right_status.state = JUMP_UP;
    section.right_status.up_or_down_num[0] = 900;
    section.is_Air = 1;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    section.left_status.up_or_down_num.erase(section.left_status.up_or_down_num.begin());//删除vector中最后一个元素
//    section.right_status.up_or_down_num.erase(section.right_status.up_or_down_num.begin());//删除vector中最后一个元素
    //8区分开 水池左边
    section.level = 3;
    section.left_x = 784;
    section.right_x = 1028;
    section.ground_y = 900;
    section.ceiling_y = 705;
    section.left_status.state = SIMPLE;
    section.left_status.up_or_down_num[0] = 820;
    section.right_status.state = JUMP_DOWN;
    section.right_status.up_or_down_num[0] = 921;
    section.is_Air = 0;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    section.left_status.up_or_down_num.erase(section.left_status.up_or_down_num.begin());//删除vector中最后一个元素
//    section.right_status.up_or_down_num.erase(section.right_status.up_or_down_num.begin());//删除vector中最后一个元素
    //9区-1 斜坡
    section.level = 4;
    section.left_x = 703;
    section.right_x = 784;
    section.ground_y = 900;
    section.ceiling_y = 705;
    section.left_status.state = SIMPLE;//斜坡和隔壁平面相连
    section.left_status.up_or_down_num[0] = 820;
    section.right_status.state = SIMPLE;//斜坡和隔壁平面相连
    section.right_status.up_or_down_num[0] = 900;
    section.is_Steep = 1;//表明此处是斜坡,值为斜率
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
    //9区-2 平台
    section.level = 4;
    section.left_x = 225;
    section.right_x = 784;
    section.ground_y = 820;
    section.ceiling_y = 663;
    section.left_status.state = SIMPLE;
    section.left_status.up_or_down_num[0] = 820;
    section.right_status.state = SIMPLE;
    section.right_status.up_or_down_num[0] = 900;
    section.is_Air = 0;//表明此处不是空气
    section.is_Steep = 0;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
    //10区
    section.level = 4;
    section.left_x = 67;
    section.right_x = 225;
    section.ground_y = 820;
    section.ceiling_y = 509;
    section.left_status.state = WALL;
    section.left_status.up_or_down_num[0] = 820;
    section.right_status.state = JUMP_UP;
    section.right_status.up_or_down_num[0] = 620;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    section.left_status.up_or_down_num.erase(section.left_status.up_or_down_num.begin());//删除vector中最后一个元素
//    section.right_status.up_or_down_num.erase(section.right_status.up_or_down_num.begin());//删除vector中最后一个元素
    //11区-平台区
    section.level = 5;
    section.left_x = 225;
    section.right_x = 827;
    section.ground_y = 620;
    section.ceiling_y = 509;
    section.left_status.state = JUMP_DOWN;
    section.left_status.up_or_down_num[0] = 820;
    section.right_status.state = SIMPLE;
    section.right_status.up_or_down_num[0] = 660;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
    //11区-2 斜坡
    section.level = 5;
    section.left_x = 827;
    section.right_x = 868;
    section.ground_y = 660;
    section.ceiling_y = 509;
    section.left_status.state = SIMPLE;
    section.left_status.up_or_down_num[0] = 820;
    section.right_status.state = SIMPLE;
    section.right_status.up_or_down_num[0] = 660;
    section.is_Steep = 1;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    section.left_status.up_or_down_num.erase(section.left_status.up_or_down_num.begin());//删除vector中最后一个元素
//    section.right_status.up_or_down_num.erase(section.right_status.up_or_down_num.begin());//删除vector中最后一个元素
    //12区
    section.level = 6;
    section.left_x = 868;
    section.right_x = 1191;
    section.ground_y = 660;
    section.ceiling_y = 500;
    section.left_status.state = SIMPLE;
    section.left_status.up_or_down_num[0] = 620;
    section.right_status.state = SIMPLE;
    section.right_status.up_or_down_num[0] = 660;
    section.is_Steep = 0;//非斜坡
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    section.left_status.up_or_down_num.erase(section.left_status.up_or_down_num.begin());//删除vector中最后一个元素
//    section.right_status.up_or_down_num.erase(section.right_status.up_or_down_num.begin());//删除vector中最后一个元素
    //13区
    section.level = 6;
    section.left_x = 1191;
    section.right_x = 1391;
    section.ground_y = 660;
    section.ceiling_y = 545;
    section.left_status.state = SIMPLE;
    section.left_status.up_or_down_num[0] = 660;
    section.right_status.state = SIMPLE;
    section.right_status.up_or_down_num[0] = 660;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
    //14区
    section.level = 6;
    section.left_x = 1391;
    section.right_x = 1542;
    section.ground_y = 660;
    section.ceiling_y = 307;
    section.left_status.state = JUMP_UP;
    section.left_status.up_or_down_num[0] = 460;
    section.right_status.state = WALL;
    section.right_status.up_or_down_num[0] = 660;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    section.left_status.up_or_down_num.erase(section.left_status.up_or_down_num.begin());//删除vector中最后一个元素
//    section.right_status.up_or_down_num.erase(section.right_status.up_or_down_num.begin());//删除vector中最后一个元素
    //15区
    section.level = 7;
    section.left_x = 1145;
    section.right_x = 1391;
    section.ground_y = 460;
    section.ceiling_y = 307;
    section.left_status.state = SIMPLE;
    section.left_status.up_or_down_num[0] = 380;
    section.right_status.state = JUMP_DOWN;
    section.right_status.up_or_down_num[0] = 660;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    section.left_status.up_or_down_num.erase(section.left_status.up_or_down_num.begin());//删除vector中最后一个元素
//    section.right_status.up_or_down_num.erase(section.right_status.up_or_down_num.begin());//删除vector中最后一个元素
    //16区-1 斜坡
    section.level = 8;
    section.left_x = 1068;
    section.right_x = 1145;
    section.ground_y = 460;
    section.ceiling_y = 300;
    section.left_status.state = SIMPLE;
    section.left_status.up_or_down_num[0] = 460;
    section.right_status.state = SIMPLE;
    section.right_status.up_or_down_num[0] = 460;
    section.is_Steep = 1;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
    //16区-2 平台
    section.level = 8;
    section.left_x = 783;
    section.right_x = 1068;
    section.ground_y = 380;
    section.ceiling_y = 300;
    section.left_status.state = JUMP_DOWN;
    section.left_status.up_or_down_num[0] = 460;
    section.right_status.state = SIMPLE;
    section.right_status.up_or_down_num[0] = 460;
    section.is_Steep = 0;//不是斜坡
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    section.left_status.up_or_down_num.erase(section.left_status.up_or_down_num.begin());//删除vector中最后一个元素
//    section.right_status.up_or_down_num.erase(section.right_status.up_or_down_num.begin());//删除vector中最后一个元素
    //17区
    section.level = 7;
    section.left_x = 670;
    section.right_x = 783;
    section.ground_y = 460;
    section.ceiling_y = 307;
    section.left_status.state = SIMPLE;
    section.left_status.up_or_down_num[0] = 460;
    section.right_status.state = JUMP_UP_WALL;
    section.right_status.up_or_down_num[0] = 380;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    section.left_status.up_or_down_num.erase(section.left_status.up_or_down_num.begin());//删除vector中最后一个元素
//    section.right_status.up_or_down_num.erase(section.right_status.up_or_down_num.begin());//删除vector中最后一个元素
    //18区
    section.level = 7;
    section.left_x = 466;
    section.right_x = 670;
    section.ground_y = 460;
    section.ceiling_y = 380;
    section.left_status.state = SIMPLE;
    section.left_status.up_or_down_num[0] = 460;
    section.right_status.state = SIMPLE;
    section.right_status.up_or_down_num[0] = 460;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    section.left_status.up_or_down_num.erase(section.left_status.up_or_down_num.begin());//删除vector中最后一个元素
//    section.right_status.up_or_down_num.erase(section.right_status.up_or_down_num.begin());//删除vector中最后一个元素
    //19区
    section.level = 7;
    section.left_x = 350;
    section.right_x = 466;
    section.ground_y = 460;
    section.ceiling_y = 250;
    section.left_status.state = SIMPLE;
    section.left_status.up_or_down_num[0] = 460;
    section.right_status.state = SIMPLE;
    section.right_status.up_or_down_num[0] = 460;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    section.left_status.up_or_down_num.erase(section.left_status.up_or_down_num.begin());//删除vector中最后一个元素
//    section.right_status.up_or_down_num.erase(section.right_status.up_or_down_num.begin());//删除vector中最后一个元素
    //20区
    section.level = 7;
    section.left_x = 265;
    section.right_x = 350;
    section.ground_y = 460;
    section.ceiling_y = 62;
    section.left_status.state = JUMP_UP_WALL;
    section.left_status.up_or_down_num[0] = 300;
    section.right_status.state = SIMPLE;
    section.right_status.up_or_down_num[0] = 460;
    section.is_Air = 1;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    section.left_status.up_or_down_num.erase(section.left_status.up_or_down_num.begin());//删除vector中最后一个元素
//    section.right_status.up_or_down_num.erase(section.right_status.up_or_down_num.begin());//删除vector中最后一个元素
    //21区
    section.level = 9;
    section.left_x = 66;
    section.right_x = 265;
    section.ground_y = 300;
    section.ceiling_y = 62;
    section.left_status.state = WALL;
    section.left_status.up_or_down_num[0] = 300;
    section.right_status.state = JUMP_BOTH;
    section.right_status.up_or_down_num[0] = 180;
    section.right_status.up_or_down_num.insert(section.right_status.up_or_down_num.end(), 460);
    section.is_Air = 0;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    section.left_status.up_or_down_num.erase(section.left_status.up_or_down_num.begin());//删除vector中最后一个元素
//    section.right_status.up_or_down_num.erase(section.right_status.up_or_down_num.begin()+1);//删除vector中最后一个元素
//    section.right_status.up_or_down_num.erase(section.right_status.up_or_down_num.begin());//删除vector中最后一个元素
    //22区-1 左侧斜坡
    section.level = 10;
    section.left_x = 350;
    section.right_x = 420;
    section.ground_y = 250;
    section.ceiling_y = 62;
    section.left_status.state = JUMP_DOWN;
    section.left_status.up_or_down_num[0] = 300;
    section.right_status.state = SIMPLE;
    section.right_status.up_or_down_num[0] = 220;
    section.is_Steep = -1;
    section.is_Air = 1;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
    //22区-2 平台
    section.level = 10;
    section.left_x = 420;
    section.right_x = 511;
    section.ground_y = 180;
    section.ceiling_y = 62;
    section.left_status.state = SIMPLE;
    section.left_status.up_or_down_num[0] = 300;
    section.right_status.state = SIMPLE;
    section.right_status.up_or_down_num[0] = 220;
    section.is_Steep = 0;
    section.is_Air = 0;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
    //22区-3 斜坡
    section.level = 10;
    section.left_x = 511;
    section.right_x = 544;
    section.ground_y = 220;
    section.ceiling_y = 62;
    section.left_status.state = SIMPLE;
    section.left_status.up_or_down_num[0] = 300;
    section.right_status.state = SIMPLE;
    section.right_status.up_or_down_num[0] = 220;
    section.is_Steep = 1;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    section.left_status.up_or_down_num.erase(section.left_status.up_or_down_num.begin());//删除vector中最后一个元素
//    section.right_status.up_or_down_num.erase(section.right_status.up_or_down_num.begin());//删除vector中最后一个元素
    //23区-1 平台区
    section.level = 11;
    section.left_x = 544;
    section.right_x = 582;
    section.ground_y = 220;
    section.ceiling_y = 62;
    section.left_status.state = SIMPLE;
    section.left_status.up_or_down_num[0] = 180;
    section.right_status.state = SIMPLE;
    section.right_status.up_or_down_num[0] = 260;
    section.is_Steep = 0;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
    //23区-2 斜坡
    section.level = 11;
    section.left_x = 582;
    section.right_x = 617;
    section.ground_y = 265;
    section.ceiling_y = 62;
    section.left_status.state = SIMPLE;
    section.left_status.up_or_down_num[0] = 180;
    section.right_status.state = SIMPLE;
    section.right_status.up_or_down_num[0] = 260;
    section.is_Steep = 1;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    section.left_status.up_or_down_num.remove(0,1);//删除vector中最后一个元素
//    section.right_status.up_or_down_num.remove(0,1);//删除vector中最后一个元素
    //24区
    section.level = 12;
    section.left_x = 617;
    section.right_x = 1062;
    section.ground_y = 265;
    section.ceiling_y = 62;
    section.left_status.state = SIMPLE;
    section.left_status.up_or_down_num[0] = 220;
    section.right_status.state = SIMPLE;
    section.right_status.up_or_down_num[0] = 220;
    section.is_Steep = 0;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    section.left_status.up_or_down_num.remove(0,1);//删除vector中最后一个元素
//    section.right_status.up_or_down_num.remove(0,1);//删除vector中最后一个元素
    //25区-1 左侧斜坡
    section.level = 11;
    section.left_x = 1062;
    section.right_x = 1100;
    section.ground_y = 265;
    section.ceiling_y = 62;
    section.left_status.state = SIMPLE;
    section.left_status.up_or_down_num[0] = 260;
    section.right_status.state = SIMPLE;
    section.right_status.up_or_down_num[0] = 260;
    section.is_Steep = -1;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
    //25区-2 平台区
    section.level = 11;
    section.left_x = 1100;
    section.right_x = 1225;
    section.ground_y = 220;
    section.ceiling_y = 62;
    section.left_status.state = SIMPLE;
    section.left_status.up_or_down_num[0] = 260;
    section.right_status.state = SIMPLE;
    section.right_status.up_or_down_num[0] = 260;
    section.is_Steep = 0;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
    //25区-1 左侧斜坡
    section.level = 11;
    section.left_x = 1225;
    section.right_x = 1261;
    section.ground_y = 261;
    section.ceiling_y = 62;
    section.left_status.state = SIMPLE;
    section.left_status.up_or_down_num[0] = 260;
    section.right_status.state = SIMPLE;
    section.right_status.up_or_down_num[0] = 260;
    section.is_Steep = 1;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    section.left_status.up_or_down_num.remove(0,1);//删除vector中最后一个元素
//    section.right_status.up_or_down_num.remove(0,1);//删除vector中最后一个元素
    //26区
    section.level = 12;
    section.left_x = 1261;
    section.right_x = 1539;
    section.ground_y = 260;
    section.ceiling_y = 62;
    section.left_status.state = JUMP_UP;
    section.left_status.up_or_down_num[0] = 220;
    section.right_status.state = WALL;
    section.right_status.up_or_down_num[0] = 260;
    section.is_Steep = 0;
    section_vector.insert(section_vector.end(), section);      //在数组最后，添加元素
//    section.left_status.up_or_down_num.remove(0,1);//删除vector中最后一个元素
//    section.right_status.up_or_down_num.remove(0,1);//删除vector中最后一个元素
    //qDebug() << "section_vector.size = " << section_vector.size() << endl;

}

MAP_TEST::~MAP_TEST() {//析构函数
    //delete section_vector;
}

//void MAP_TEST::horizontal_jump(Character *cha)
//{
//    if (!cha->jump_state) {//如果没有跳跃，自由落体
//        cha->jump_v0 = 5;
//        cha->jump();
//        cha->jump_state = 1;
//        if (cha->sex == 0)
//            jumpTimer_ice->start(JUMP_UPDATE_TIME);
//        else
//            jumpTimer_fire->start(JUMP_UPDATE_TIME);
//    }
//}



POINT MAP_TEST::judge_move(Character *cha,POINT new_position) {//下一秒的位置信息传入，输出的是实际可到达的位置
    POINT next = new_position;//传入的坐标，需要引用类中的私有变量——地图坐标，来进行判断
   //先判断区号
    int section_index = this->judge_section(cha->get_pos());
    cha->section_id = section_index;
    int section_index_new = this->judge_section(new_position);

    if (section_index < section_index_new - 1 || section_index>section_index_new + 1)
        section_index = section_index_new;

    //如果此时的区域信息或者之后的区域信息有错误情况，则错误处理——此刻不动
    if (section_index_new == -1) {
        return next;
    }
    //正常区域
    //获得当前区域的斜率
    int slope = section_vector.at(section_index_new).is_Steep;
    int ground_y = section_vector.at(section_index_new).ground_y;
    int ceiling_y = section_vector.at(section_index_new).ceiling_y;
    int left_x = section_vector.at(section_index_new).left_x;
    int right_x = section_vector.at(section_index_new).right_x;
    if(slope == 1){
        cha->y_floor = ground_y +
                    (cha->get_pos().x+WIDTH/2 - section_vector.at(section_index_new).right_x)*slope - 90;
    }
    else {
        cha->y_floor = ground_y +
                    (cha->get_pos().x+WIDTH/2 - section_vector.at(section_index_new).left_x)*slope - 90;
    }


    //平抛
    if (cha->y_floor > new_position.y && !cha->jump_state){
        cha->jump_stop();
        cha->h_jump=1;
    }

    if (next.y >= cha->y_floor){//如果此时的坐标信息处在地面下方
         next.y = cha->y_floor;//将人物固定在地面上
         if(cha->jump_state){
            cha->jump_stop();
         }
    }
    else if (next.y <= ceiling_y) {//抵到天花板
            next.y = cha->get_pos().y;
    }

    /*判断x方向*/
    if (new_position.x < left_x){//边界处
            if(section_vector.at(section_index_new).left_status.state == JUMP_UP_WALL){
                if(next.y + 45 >= section_vector.at(section_index_new).left_status.up_or_down_num[0]){
                    //没跳上来
                    next.x = cha->get_pos().x;
                }
                else{
                    next.x = new_position.x;
                }
            }
            else if(section_vector.at(section_index_new).left_status.state == WALL){
                 next.x = cha->get_pos().x;
             }
            else{
                next.x = new_position.x;
            }

    }
    if (new_position.x + WIDTH > right_x){
            if(section_vector.at(section_index_new).right_status.state == JUMP_UP_WALL){
                if(next.y + 45 >= section_vector.at(section_index_new).right_status.up_or_down_num[0]){//没跳上来
                    next.x = cha->get_pos().x;
                }
                else{//可以跳上
                    next.x = new_position.x;
                }
            }
            else if(section_vector.at(section_index_new).right_status.state == WALL){
                 next.x = cha->get_pos().x;
            }
            else{
                next.x = new_position.x;
            }
    }
    return next;
}


int MAP_TEST::judge_section(POINT position) {
    int i;
    for (i = 0; i < section_vector.size(); i++) {
        if (position.x+WIDTH/2  >= section_vector.at(i).left_x &&
            position.x +WIDTH/2 < section_vector.at(i).right_x &&
            position.y  +HEIGTH/2>= section_vector.at(i).ceiling_y &&
            position.y + HEIGTH/2 < section_vector.at(i).ground_y) {
            //qDebug()<<""wrong
            return i;
        }
    }
    return -1;
}

SECTION_INFO MAP_TEST::get_section_info(int section_num) {
    return section_vector.at(section_num);
}
float MAP_TEST::get_Slope(POINT left, POINT right) {
    float dx = float(right.x - left.x);
    float dy = float(right.y - left.y);
    float slope = dy / dx;
    return slope;
}


