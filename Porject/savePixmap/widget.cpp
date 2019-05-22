#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPixmap pixmap(400,400);//绘图设备
    QPainter p(&pixmap);
    p.drawPixmap(0,0,400,400,QPixmap("D:\\as the king of the road\\note\\Qt\\Project\\1.jpg"));
    pixmap.save("D:\\as the king of the road\\note\\Qt\\Project\\1-1.jpg");


}

Widget::~Widget()
{
    delete ui;
}
