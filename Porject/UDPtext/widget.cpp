#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("端口 9056");
    udpSocket = new QUdpSocket(this);//分配空间

    udpSocket->bind(9056);//绑定端口

    //当数据发送过来时 触发槽函数
    connect(udpSocket,&QUdpSocket::readyRead,this,&Widget::dealMsg);

}

void Widget::dealMsg(){//显示接受的内容
    char buf[1024]={0};
    QHostAddress addr;
    quint16 post;
    qint64 len = udpSocket->readDatagram(buf,1024,&addr,&post);
    if(len>0){
        QString str=QString("[%1:%2]    %3").arg(addr.toString()).arg(post).arg(buf);
        ui->textEditRead->setText(str);
    }

}

Widget::~Widget()
{
    delete ui;
}

//发送数据
void Widget::on_buttonSend_clicked()
{
    QString ip=ui->lineEditIP->text();//ip
    qint16 post=ui->lineEditPost->text().toInt();//端口
    QString str=ui->textEditWrite->toPlainText();//获取编辑区内容
    udpSocket->writeDatagram(str.toUtf8(),QHostAddress(ip),post);
    ui->textEditWrite->clear();

}

void Widget::on_buttonClose_clicked()
{
    close();
}
