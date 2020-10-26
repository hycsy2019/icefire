/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *icegirl;
    QLabel *fireboy;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1604, 1207);
        MainWindow->setMinimumSize(QSize(1604, 1207));
        MainWindow->setMaximumSize(QSize(1604, 1207));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setMinimumSize(QSize(1604, 1207));
        centralwidget->setMaximumSize(QSize(1604, 1207));
        centralwidget->setStyleSheet(QStringLiteral("#centralwidget{border-image: url(:/background/resource/background1.png);}"));
        icegirl = new QLabel(centralwidget);
        icegirl->setObjectName(QStringLiteral("icegirl"));
        icegirl->setGeometry(QRect(70, 1050, 60, 90));
        icegirl->setPixmap(QPixmap(QString::fromUtf8(":/character/resource/ice_girl_front_1.0.png")));
        icegirl->setScaledContents(true);
        fireboy = new QLabel(centralwidget);
        fireboy->setObjectName(QStringLiteral("fireboy"));
        fireboy->setGeometry(QRect(150, 1050, 60, 90));
        fireboy->setPixmap(QPixmap(QString::fromUtf8(":/character/resource/fire_boy_front_1.0.png")));
        fireboy->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1604, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        icegirl->setText(QString());
        fireboy->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
