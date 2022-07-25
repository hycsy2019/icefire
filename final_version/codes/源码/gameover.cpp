#include"mainwindow.h"
#include "gameover.h"
#include "ui_gameover.h"

extern MainWindow *w;

GameOver::GameOver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameOver)
{
    setWindowOpacity(1);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    ui->setupUi(this);
}

GameOver::~GameOver()
{
    delete ui;
}

void GameOver::on_pushButton_clicked()//再试一次
{
    this->hide();
	/*w->icegirl->new_position.x=70;
	w->icegirl->new_position.y=890;
	w->fireboy->new_position.x = 70;
	w->fireboy->new_position.y = 1050;*/
	delete w;
	w = new MainWindow();
	w->show();
}

void GameOver::on_pushButton_2_clicked()//返回菜单
{
    this->close();
}
