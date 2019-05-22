#include "mythread.h"
#include <QDebug>

MyThread::MyThread(QObject *parent) : QThread(parent)
{

}

void MyThread::run(){
    //模拟非常复杂的任务
//    qDebug()<<"start";
    int a=0;
    for(int s=0;s<2000000000;s++){
        a=s*s;
    }
    emit isDown();
//    qDebug()<<"finsh";
}
