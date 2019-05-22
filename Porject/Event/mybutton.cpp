#include "mybutton.h"
#include <QMouseEvent>
#include <qDebug>
MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{

}

//基类保留的事件处理函数
void MyButton::mousePressEvent(QMouseEvent *e){//正常情况下 如果你不改写这个函数 它会将消息继续向下传递 而现
    if(e->button() == Qt::LeftButton){//在调用我们的事件处理函数之后消息并没有向下传
        qDebug()<<"Left-Button";
        e->ignore();//将信号继续传递 这里会传递给父组件
        //e->accept();//不再将信号继续传递
    }else{
    QPushButton::mousePressEvent(e);//继续将消息传递下去
    }
}

