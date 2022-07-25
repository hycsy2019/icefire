#include "mainwindow.h"
#include <QApplication>

MainWindow *w;
GameOver *gameover;
success *success_window;
start * start_window;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    w = new MainWindow();
    gameover = new GameOver();
    success_window = new success();
    start_window = new start();
    start_window->setWindowFlags(start_window->windowFlags() | Qt::Dialog);
    start_window->setWindowModality(Qt::ApplicationModal);
    start_window->show();

    w->show();
    return a.exec();
}
