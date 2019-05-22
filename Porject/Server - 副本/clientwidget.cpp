#include "clientwidget.h"
#include "ui_clientwidget.h"
#include <QHostAddress>

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    tcpsocket = NULL;
    setWindowTitle("客户端");

    connect(tcpsocket,&QTcpSocket::connected,
            [=](){
                    ui->textBrowserRead->setText("已连接服务器");
    })

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
