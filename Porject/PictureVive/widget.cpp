#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QMouseEvent>
#include <qDebug>
#include <QBuffer>
#include <QFile>
#include <QFileInfo>

#define cout qDebug()<<"["<<__FILE__<<":"<<__LINE__<<"]"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //去掉窗口边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    //把窗口背景设置成透明
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowState(Qt::WindowMaximized);//窗口最大化

    QString path=QString("C:\\Users\\Administrator\\Desktop\\01.jpg");
    QFile image(path);
    if(ture==image.open(QIODevice::ReadOnly)){
        QFileInfo imageinfo(path);

    }

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event){
    QPainter per(this);
    QPixmap picture("C:\\Users\\Administrator\\Desktop\\01.jpg");
    //QBuffer buffer();
    int i=(SystemWidth-picture.width())/2;//设置图片位置
    if(i>0){
        per.drawPixmap(i,paintpos.y(),picture);//图片没有屏幕宽 的显示方法
    }else{
        per.drawPixmap(paintpos,picture);//否则还是正常显示吧！^_^ 这样也不错
    }



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

        SystemWidth = width();

        cout<<"width:"<<SystemWidth;
    }
}






