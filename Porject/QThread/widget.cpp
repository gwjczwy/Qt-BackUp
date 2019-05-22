#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    time = new QTimer(this);

    connect(time,&QTimer::timeout,[=](){
        static int i=0;
        ui->lcdNumber->display(++i);
    });

    thread = new MyThread(this);//分配空间
    connect(thread,&MyThread::isDown,this,&Widget::DealDown);//当线程完成工作的时侯触发 停止计时

    connect(this,&Widget::destroyed,this,&Widget::StopThread);//当线程完成后 关闭线程

}

Widget::~Widget()
{
    delete ui;
}

void Widget::DealDown(){
    time->stop();
}

void Widget::StopThread(){
    thread->quit();//停止线程
    thread->wait();//等待线程处理完手头工作
}

void Widget::on_pushButton_clicked()
{
    if(time->isActive() == false){
        time->start(10);
    }

//    for(int s=0;s<2000000000;s++){
//        int a=s*s;
//    }//被线程代替.
    thread->start();

}
