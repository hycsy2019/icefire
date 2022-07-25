#include "start.h"
#include "ui_start.h"

start::start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::start)
{
    setWindowOpacity(1);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    ui->setupUi(this);
}

start::~start()
{
    delete ui;
}

void start::on_start_game_clicked()
{
    this->close();
}
