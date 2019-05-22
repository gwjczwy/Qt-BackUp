#include "mythread.h"
#include <QThread>
#include <QDebug>

MyThread::MyThread(QObject *parent) : QObject(parent)
{
    isStop=false;
}

void MyThread::myTimeOut(){
    while(false==isStop){

        QThread::sleep(1);//一秒触发一次
        emit mySignal();
        qDebug()<<"子线程号:"<<QThread::currentThread();
    }
}

void MyThread::setFlag(bool flag){
    isStop=flag;

}

