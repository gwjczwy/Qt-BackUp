#include "mythread.h"
#include <QPainter>
#include <QImage>
#include <QPen>
#include <QBrush>


MyThread::MyThread(QObject *parent) : QObject(parent)
{

}

void MyThread::drawImage(){
    //定义绘图设备
    QImage temp(500,500,QImage::Format_ARGB32);
    //定义画家 指定绘图设备
    QPainter p(&temp);

    QPoint a[5]= {
        QPoint(qrand()%500,qrand()%500),
        QPoint(qrand()%500,qrand()%500),
        QPoint(qrand()%500,qrand()%500),
        QPoint(qrand()%500,qrand()%500),
        QPoint(qrand()%500,qrand()%500)
    };
    QPen pen;//定义笔
    pen.setWidth(5);
    p.setPen(pen);

    QBrush brush;
    brush.setColor(Qt::red);//设定颜色
    brush.setStyle(Qt::Dense1Pattern);//风格
    p.setBrush(brush);

    p.drawPolygon(a,5);

    emit updataImage(temp);
}


