#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建一个绘图设备               背景是透明
    QImage image(600,400,QImage::Format_ARGB32);

    QPainter p(&image);//创建画师 并指定在 绘图设备:image 上画图

    //画上 C:\Users\Administrator\Desktop\1.jpg
    p.drawImage(0,0,QImage("C:\\Users\\Administrator\\Desktop\\1.jpg"));

    //将绘图设备 image 上的内容保存到 C:\Users\Administrator\Desktop\q.q.jpg
    image.save("C:\\Users\\Administrator\\Desktop\\1.1.jpg");

}

Widget::~Widget()
{
    delete ui;
}
