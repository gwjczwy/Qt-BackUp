#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>   //监听套接字
#include <QTcpSocket>   //通信套接字

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;


protected:

private slots:
    void on_buttonSend_clicked();

    void on_buttonClose_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
