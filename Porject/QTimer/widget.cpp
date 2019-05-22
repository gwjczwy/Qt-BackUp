#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    mainTime = new QTimer(this);

    connect(mainTime,&QTimer::timeout,
            [=](){
                    static int i=0;
                    i++;
                    QString time = QString::number(i/1000);
                    ui->label->setText(QString(time));
                    ui->lcdNumber->display(time);
                }

            );

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonStart_clicked()
{
    if(false == mainTime->isActive())//如果正在计时 就不用再启动了
        mainTime->start(1);
}

void Widget::on_pushButtonStop_clicked()
{
    if(true == mainTime->isActive())//如果正在计时 才关闭
        mainTime->stop();
}
