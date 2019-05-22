#include "server.h"
#include "ui_server.h"
#include <QFileDialog>
#include <qDebug>
#include <QFileInfo>

Server::Server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
    setWindowTitle("Server 8810");

    //按钮不能按
    ui->pushButtonChouse->setEnabled(false);
    ui->pushButtonLoad->setEnabled(false);

    tcpServer = new QTcpServer(this);
    tcpServer->listen(QHostAddress::Any,8810);//监听端口
    connect(tcpServer,&QTcpServer::newConnection,
            [=]()
            {
                tcpSocket=tcpServer->nextPendingConnection();
                ui->textEdit->setText(QString("已与 %1 建立连接.").arg(tcpSocket->peerAddress().toString()));

                ui->pushButtonChouse->setEnabled(true);//恢复按钮
            }
    );

    //定时器
    connect(&timer,&QTimer::timeout,
            [=]()
            {
                timer.stop();
                sendData();
            }

            );
}

Server::~Server()
{
    delete ui;
}

void Server::on_pushButtonChouse_clicked()//选择文件
{
    QString path=QFileDialog::getOpenFileName(this,"open","C://");
    if(false == path.isEmpty()){
        fileName.clear();
        filesize=0;
        sendsize=0;
        QFileInfo info(path);
        fileName=info.fileName();//获取文件名
        filesize=info.size();//获取文件大小

        file.setFileName(path);
        if(true==file.open(QIODevice::ReadOnly)){//打开文件
            ui->pushButtonLoad->setEnabled(true);//按钮恢复
        }else{
            qDebug()<<"文件打开失败";
        }
        ui->textEdit->append(QString("选择文件 %1").arg(path));
    }else{
         ui->textEdit->append(QString("路径无效  %1").arg(path));
    }
}

void Server::on_pushButtonLoad_clicked()//发送文件 button
{
    QString head = QString("%1##%5").arg(fileName).arg(filesize);
    qint64 len = tcpSocket->write(head.toUtf8());
    if(len>0){
        //文件名发送成功 开始发送文件数据
        //为防止Tcp粘包 等待 20ms 再发送
         ui->textEdit->append("头文件发送成功");
        timer.start(20);

    }else{
        ui->textEdit->append("文件头发送失败 67");
        ui->pushButtonLoad->setEnabled(false);
        ui->pushButtonChouse->setEnabled(true);
    }
}

void Server::sendData(){
    qint64 len=0;
    do{
        len=0;
        char buf[1024]={0};
        len=file.read(buf,sizeof(buf));   //读多少
        tcpSocket->write(buf,len);          //发多少
        sendsize+=len;//累计统计发送数据量
        ui->textEdit->append(QString("%1/%2").arg(sendsize).arg(filesize));
    }while(len>0);//这种方法反而简单 小于零是出错 等于零是发完了
    //也可以用 while(sendsize!=filesize);
    if(sendsize==filesize){
        ui->textEdit->append("发送成功.");
    }else{
        ui->textEdit->append(QString("发送过程中出现错误 %1/%2").arg(sendsize).arg(filesize));
    }
//    tcpSocket->disconnectFromHost();//关闭套接字
//    tcpSocket->close();

}

