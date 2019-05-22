#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //打印Qt支持的数据库驱动
    qDebug() << QSqlDatabase::drivers();

    //添加MySql数据库
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    //连接数据库
    db.setHostName("127.0.0.1");//服务器IP
    db.setUserName("root");//User
    db.setPassword("123456");//PW
    db.setDatabaseName("info");//使用那个数据库

    //打开数据库
    if(!db.open() ){//数据库打开失败
        QMessageBox::warning(this,"错误",db.lastError().text());
        return ;
    }
}

Widget::~Widget()
{
    delete ui;
}
