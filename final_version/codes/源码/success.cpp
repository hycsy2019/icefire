#include "success.h"
#include "ui_success.h"
#include"mainwindow.h"

success::success(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::success)
{
    setWindowOpacity(1);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    ui->setupUi(this);
}

success::~success(){
    delete ui;
}

void success::on_pushButton_clicked()
{
    //me.show();

    this->close();
	delete w;
	w = new MainWindow();
	w->show();
}
