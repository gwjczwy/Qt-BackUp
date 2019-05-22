#include "widget.h"
#include "ui_widget.h"
#include <QBuffer>
#include <QDebug>
#include <QTextStream>

#define cout qDebug() << "[" << __FILE__ << ":" << __LINE__ << "]"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QBuffer buffer;//创建内存文件
    buffer.open(QIODevice::WriteOnly);//以只写方式打开
    QDataStream out(&buffer);//绑定创建的 out 流
    out<<QString("1111111111111");//写入 QSataStream 流相当于写入 QBuffer

    buffer.close();//关闭内存文件

    cout<<"QDataStream  "<<out;
    //cout<<"QBuffer   "<<buffer.buffer();//QBuffer    "\x00\x00\x00\x1A\x00""1\x00""1\x00""1\x00""1\x00""1\x00""1\x00""1\x00""1\x00""1\x00""1\x00""1\x00""1\x00""1"



    buffer.open(QIODevice::ReadOnly);//以只读方式打开
    QDataStream in;//创建流
    in.setDevice(&buffer);//绑定
    QString str;
    in>>str;//加载到 str 中
    //cout<<str.toUtf8().data();//1111111111111

    buffer.close();
}

Widget::~Widget()
{
    delete ui;
}
