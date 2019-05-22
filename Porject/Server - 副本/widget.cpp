#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("server 2471");

    tcpServer = NULL;
    tcpSocket = NULL;//初始化为空

    //监听套接字 指定父对象可以自动回收内存
    tcpServer = new QTcpServer(this);
    qDebug()<<"QTcpServer";

    tcpServer->listen(QHostAddress::Any,2471);//监听8888端口
    qDebug()<<"监听8888端口";

    connect(tcpServer,&QTcpServer::newConnection,//如果服务器发送连接请求 就与服务器建立链接
            [=](){
                    qDebug()<<"与服务器建立链接";
                    qDebug()<<"取出建立好链接的套接字";
                    tcpSocket = tcpServer->nextPendingConnection();//取出建立好链接的套接字
                    //取出ip地址和端口
                    qDebug()<<"取出ip地址和端口";
                    QString ip=tcpSocket->peerAddress().toString();
                    qint16 port=tcpSocket->peerPort();

                    QString temp=QString("成功连接[%1:%2]").arg(ip).arg(port);
                    ui->textRead->setText(temp);

                    connect(tcpSocket,&QTcpSocket::readyRead,
                           [=](){
                                    QByteArray array = tcpSocket->readAll();//从通讯套接字中取出内容
                                    ui->textRead->append(array);//追加显示到文本框中
                                });
                 });



}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonSend_clicked()
{
    if(NULL == tcpSocket){
        return;
    }
    QString str = ui->textWrite->toPlainText();//获取编辑区内容
    tcpSocket->write(str.toUtf8().data());//发送数据
    ui->textWrite->clear();
}

void Widget::on_buttonClose_clicked()
{
    if(NULL == tcpSocket){
        close();
        return;
    }
    tcpSocket->disconnectFromHost();//主动断开连接
    close();//关闭窗口
    tcpSocket = NULL;
}
