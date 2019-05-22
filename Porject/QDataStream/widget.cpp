#include "widget.h"
#include "ui_widget.h"
#include <QDataStream>
#include <QFile>
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    WriteData();
    ReadData();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::WriteData(){
    QFile file("C:\\Users\\Administrator\\Desktop\\t.txt");
    if(file.open(QIODevice::WriteOnly) == true){
        QDataStream data(&file);

        //向数据流写数据 = 向文件写数据
        data << "Flag立的飞起";
    }
    file.close();
}

void Widget::ReadData(){
    QFile file("C:\\Users\\Administrator\\Desktop\\t.txt");
    if(file.open(QIODevice::ReadOnly) == true){
        QDataStream data(&file);
        while(!data.atEnd()){
        QString str;
        data>>&str;
        qDebug()<<str;
        }
    }
    file.close();
}


