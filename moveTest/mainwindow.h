#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<qevent.h>
#include<QTimer>
#include<QtConcurrent/QtConcurrent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#define SPEED 20
#define KEYTIME 100

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *updateTimer;//刷新定时器
    QSet<int> pressedKeys;//保存按下的按键
    float x=0;//移动后label的x坐标
    float y=0;//移动后label的y坐标
    void keyPressEvent(QKeyEvent *event);//按键按下
   void  keyReleaseEvent(QKeyEvent *event);//按键释放
   void keyMove();//处理按键消息，移动label坐标
};
#endif // MAINWINDOW_H
