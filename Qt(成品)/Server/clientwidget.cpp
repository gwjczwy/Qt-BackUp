#include "clientwidget.h"
#include "ui_clientwidget.h"
#include <QHostAddress>

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    tcpsocket = new QTcpSocket(this);
    setWindowTitle("Tcp Client");

    connect(tcpsocket,&QTcpSocket::connected,
            [=](){
                    ui->textBrowserRead->setText("已连接");
    });

    connect(tcpsocket,&QTcpSocket::readyRead,
           [=](){
                    QByteArray array = tcpsocket->readAll();//从通讯套接字中取出内容
                    ui->textBrowserRead->setTextColor(Qt::red);
                    ui->textBrowserRead->append(array);//追加显示到文本框中
                });

}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_buttonConnect_clicked()
{
    //获取服务器IP 端口号
    QString ip = ui->lineEditIP->text();
    qint16 port = ui->lineEditPort->text().toInt();

    qDebug()<<QString("获取服务器IP %1 端口号 %2").arg(ip).arg(port);
    tcpsocket->connectToHost(QHostAddress(ip),port);
    qDebug()<<"创建连接";
}

void ClientWidget::on_buttonSend_clicked()
{
    if(NULL == tcpsocket){
        return;
    }
    QString str = ui->textBrowserWrite->toPlainText();//获取编辑区内容
    tcpsocket->write(str.toUtf8().data());//发送数据
    ui->textBrowserRead->setTextColor(Qt::blue);
    ui->textBrowserRead->append(str);
    ui->textBrowserWrite->clear();
}



