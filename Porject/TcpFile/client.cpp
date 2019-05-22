#include "client.h"
#include "ui_client.h"
#include <QDebug>
#include <QHostAddress>

Client::Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);

    tcpsocket = new QTcpSocket(this);

    connect(tcpsocket,&QTcpSocket::readyRead,
            [=]()
            {
                QByteArray buf = tcpsocket->readAll();
                if(false == isFile){ //接受文件头
                    //初始化3
                    isFile=true;
                    fileName = QString(buf).section("##",0,0);
                    filesize = QString(buf).section("##",1,1).toInt();
                    savesize = 0;

                    //进度条
                    ui->progressBar->setMinimum(0);
                    ui->progressBar->setMaximum(filesize/1024);
                    ui->progressBar->setValue((int)savesize/filesize);
                    //打开文件
                    QString path = QString("C:\\Users\\Administrator\\Desktop\\%1").arg(fileName);
                    file.setFileName(path);

                    if(false == file.open(QIODevice::WriteOnly)){
                        ui->textEditRead->append("文件打开失败. 29");
                    }
                }
                else{
                    //接收文件
                    qint64 len = file.write(buf);//保存接收的数据
                    savesize  += len;//累加数据大小
                    ui->progressBar->setValue(savesize/1024);
                    ui->textEditRead->append(QString("%1/%2").arg(savesize).arg(filesize));
                    if(savesize == filesize){//接收完毕时 关闭Tcp链接 关闭文件
                        file.close();
                        ui->textEditRead->append(QString("文件接收完成 %1").arg(fileName));
                        ui->progressBar->setValue(filesize/1024);
//                        tcpsocket->disconnectFromHost();
//                        tcpsocket->close();

                        ui->progressBar->setValue(filesize/1024);
                        isFile =false;
                    }

                }
            });
}

Client::~Client()
{
    delete ui;
}

void Client::on_pushButtonConnect_clicked()//申请链接
{
    if(NULL != tcpsocket){//如果已连接 断开 重连
        tcpsocket->disconnectFromHost();
        tcpsocket->close();
    }
    QString ip = ui->lineEditIP->text();
    quint16 post = ui->lineEditPort->text().toInt();

    tcpsocket->connectToHost(QHostAddress(ip),post);

}
