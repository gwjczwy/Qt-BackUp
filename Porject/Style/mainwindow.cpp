#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label->setStyleSheet("QLabel{color:red;"
                             "border-image:url(:/new/prefix1/C:/Users/Administrator/Desktop/无标题.png);}"
                             );//border-image 把背景设置成图片 拉伸
                               //background-image 把背景设置成图片 由多张图片组合形成背景
                               //background-color 设置背景色

    ui->pushButton->setStyleSheet("QPushButton{"//平时的状态
                                  "border-image:url(:/new/prefix1/C:/Users/Administrator/Desktop/无标题.png);"
                                  "}"

                                  "QPushButton:hover{"//伪状态 停留
                                  "border-image:url(:/new/prefix1/C:/Users/Administrator/Desktop/1.jpg);"
                                  "}"

                                  "QPushButton:pressed{"//被点击的状态
                                  "border-image:url(:/new/prefix1/C:/Users/Administrator/Desktop/2.jpg);"
                                  "}"
                                  );

    connect(ui->pushButton,&QPushButton::released,this,[=](){qDebug()<<"Button down!";});
}

MainWindow::~MainWindow()
{
    delete ui;
}
//:/new/prefix1/C:/Users/Administrator/Desktop/1.jpg
//:/new/prefix1/C:/Users/Administrator/Desktop/2.jpg

