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
                ui->progressBar->setMinimum(0);
                ui->progressBar->setMaximum(filesize/1024);
                //ui->progressBar->setValue(0);
                ui->progressBar->setValue((int)savesize/filesize);//进度条
                if(false == isFile){ //接受文件头
                    //初始化3
                    isFile=true;
                    fileName = QString(buf).section("##",0,0);
                    filesize = QString(buf).section("##",1,1).toInt();
                    savesize = 0;

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
                    if(savesize == filesize){//接收完毕时 关闭Tcp链接 关闭文件
                        file.close();
                        ui->textEditRead->append(QString("文件接收完成 %1").arg(fileName));

//                        tcpsocket->disconnectFromHost();
//                        tcpsocket->close();
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
    QString ip = ui->lineEditIP->text();
    quint16 post = ui->lineEditPort->text().toInt();

    tcpsocket->connectToHost(QHostAddress(ip),post);

}
