#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QMouseEvent>
#include <qDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //去掉窗口边框
    //setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    //把窗口背景设置成透明
    //setAttribute(Qt::WA_TranslucentBackground);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event){
    QPainter per(this);
    per.drawPixmap(paintpos,QPixmap("C:\\Users\\Administrator\\Desktop\\01.jpg"));

}
void Widget::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
                        //全局坐标
        //p = event->globalPos()-this->frameGeometry().topLeft();
        p.setX(event->x());
        p.setY(event->y());
        origin=paintpos;//设置原坐标

    }else if(event->button() == Qt::RightButton){
        close();
    }
}
void Widget::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons() & Qt::LeftButton){
        //move(event->globalPos()-p);
        //新坐标  = 原坐标 +移动的坐标
        paintpos = origin+event->pos()-p;
        update();
    }
}






