#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QBitmap>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event){
    QPainter p(this);

    //彩色图片
    //p.drawPixmap(0,0,QPixmap("D:\\as the king of the road\\note\\Qt\\Project\\1.jpg"));

    //灰色图片
    //p.drawPixmap(0,0,QBitmap("D:\\as the king of the road\\note\\Qt\\Project\\1.jpg"));


    //QPixmap pixmap;//指定图片用对象
    //pixmap.load("D:\\as the king of the road\\note\\Qt\\Project\\1.jpg");
    //p.drawPixmap(0,0,pixmap);

    //QBitmap bitmap;//指定图片用对象
    //bitmap.load("D:\\as the king of the road\\note\\Qt\\Project\\1.jpg");
    //p.drawPixmap(0,0,bitmap);


}


