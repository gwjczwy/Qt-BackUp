#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class ClientWidget;
}

class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWidget(QWidget *parent = 0);
    ~ClientWidget();
    QTcpSocket *tcpsocket;

protected:

private slots:
    void on_buttonConnect_clicked();

    void on_buttonSend_clicked();

private:
    Ui::ClientWidget *ui;
};

#endif // CLIENTWIDGET_H
