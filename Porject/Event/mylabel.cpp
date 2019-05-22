#include "mylabel.h"            //自己写的控件类
#include <QMouseEvent>
#include <qDebug>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    //设置从一开始就追踪鼠标
    setMouseTracking(true);
}

void MyLabel::mousePressEvent(QMouseEvent *ev){
    int sx= ev->x();
    int sy= ev->y();

    QString str = QString("<center><h1>%1,%2    ^_^</h1></center>").arg(sx).arg(sy);
    setText(str);

    if(ev->button() == Qt::LeftButton){
        qDebug()<<"Left";
    }else if(ev->button() == Qt::RightButton){
        qDebug()<<"Right";
    }else if(ev->button() == Qt::MidButton){
        qDebug()<<"Mid";
    }
}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev){
    int sx = ev->x();
    int sy = ev->y();

    QString str=QString("<center><h2>%1,%1  *_*</h></center>").arg(sx).arg(sy);
    setText(str);
}

void MyLabel::mouseMoveEvent(QMouseEvent *ev){
    int sx = ev->x();
    int sy = ev->y();

    QString str=QString("<center><h3>%1,%1  @_@</h></center>").arg(sx).arg(sy);
    //setText(str);
}

void MyLabel::enterEvent(QEvent *event){
     QString str=QString("<center><h1>In</h></center>");
     setText(str);
}

void MyLabel::leaveEvent(QEvent *event){
    QString str=QString("<center><h1>Out</h></center>");
    setText(str);
}



