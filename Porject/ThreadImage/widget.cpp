#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QThread>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    myT=new MyThread;
    thread=new QThread(this);

    myT->moveToThread(thread);//添加到子线程
    thread->start();//启动子线程,但不启动子线程处理函数
    //通过 signal-slot 启动线程处理函数
    connect(ui->pushButton,&QPushButton::clicked,myT,&MyThread::drawImage);
    //通过 signal-slot 接收画好的图片
    connect(myT,&MyThread::updataImage,this,&Widget::getImage);
    //关闭窗口时退出线程
    connect(this,&Widget::destroyed,this,&Widget::ExitThread);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::ExitThread(){
    //退出子线程
    thread->quit();
    //回收资源
    thread->wait();
    delete myT;
}

void Widget::paintEvent(QPaintEvent *event){
    QPainter p(this);
    p.drawImage(50,50,image);
}

void Widget::getImage(QImage temp){
    image = temp;
    update();

}



