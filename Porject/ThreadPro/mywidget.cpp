#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>


MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    myT = new MyThread;//动态分配空间 不能指定父对象 否则一会不能设为子线程
    thread = new QThread(this);//创建子线程 可以指定父对象
    myT->moveToThread(thread);//把子线程加入自己创建的

    connect(myT,&MyThread::mySignal,this,&MyWidget::DealSignal);//调用线程处理函数
    qDebug()<<"主线程号:"<<QThread::currentThread();
    connect(this,&MyWidget::startThread,myT,&MyThread::myTimeOut);//启动子线程
    connect(this,&MyWidget::destroyed,this,on_pushButtonStop_clicked);//关闭窗口时停止子线程
    //connect 函数的第五个参数 只有在多线程时才有意义
    //直接 Qt::AutoConnection 单线程的默认情况 使用直接方式 在同一个线程内
    //Qt::DirectConnection 多线程的默认情况 使用队列方式 在不同线程内
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::DealSignal(){
    static int i=0;
    i++;
    ui->lcdNumber->display(i);
}

void MyWidget::on_pushButtonStart_clicked()
{
    myT->setFlag(false);
    thread->start();//启动线程但没有开始线程处理函数
    //不能直接调用线程处理函数
    //直接调用 导致 线程处理函数和主线程是一个线程
    //myT->myTimeOut();//只能通过signal -- slot 方式调用
            //主线程号: QThread(0x847898)
            //子线程号: QThread(0x847898)
            //子线程号: QThread(0x847898)
            //子线程号: QThread(0x847898)
            //子线程号: QThread(0x847898)
    emit startThread();
}

void MyWidget::on_pushButtonStop_clicked()
{
    myT->setFlag(true);
    thread->quit();
    thread->wait();
}
