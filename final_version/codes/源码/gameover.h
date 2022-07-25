#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QWidget>
//#include "mainwindow.h"

namespace Ui {
class GameOver;
}

class GameOver : public QWidget
{
    Q_OBJECT

public:
    explicit GameOver(QWidget *parent = nullptr);
    ~GameOver();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::GameOver *ui;
    //MainWindow *mainwindow;//主窗口

};

#endif // GAMEOVER_H
