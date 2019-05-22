#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QTcpServer>
#include <qDebug>
#include <QTcpSocket>
#include <QFile>
#include <QTimer>

namespace Ui {
class Server;
}

class Server : public QWidget
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = 0);
    ~Server();
    QTcpServer *tcpServer;//监听套接字
    QTcpSocket *tcpSocket;//通信套接字

    QFile file;//文件
    QString fileName;
    qint64 filesize;
    qint64 sendsize;

    void sendData();//发送函数

    QTimer timer;//定时器

private slots:
    void on_pushButtonChouse_clicked();

    void on_pushButtonLoad_clicked();

private:
    Ui::Server *ui;
};

#endif // SERVER_H
