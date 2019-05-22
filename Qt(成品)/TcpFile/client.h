#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QFile>

namespace Ui {
class Client;
}

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();
    QTcpSocket *tcpsocket;

    QFile file;//文件
    QString fileName;
    qint64 filesize;
    qint64 savesize;

    bool isFile=false;//是不是文件

private slots:
    void on_pushButtonConnect_clicked();

private:
    Ui::Client *ui;
};

#endif // CLIENT_H
