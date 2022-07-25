#ifndef SUCCESS_H
#define SUCCESS_H

#include <QWidget>
#include "gameover.h"

namespace Ui {
class success;
}

class success : public QWidget
{
    Q_OBJECT

public:
    explicit success(QWidget *parent = nullptr);
    ~success();
	Ui::success *ui;

private slots:
    void on_pushButton_clicked();

private:

   //ameOver game;//子窗口
};

#endif // SUCCESS_H
