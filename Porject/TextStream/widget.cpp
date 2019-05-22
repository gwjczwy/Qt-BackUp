#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>

#define cout qDebug() << "[" << __FILE__ << ":" << __LINE__ << "]"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    WriteStream();
    ReadStream();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::WriteStream(){
    QFile file;
    file.setFileName("C:\\Users\\Administrator\\Desktop\\t.txt");
    if(true == file.open(QIODevice::WriteOnly)){
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        stream<<QString("Flag立的飞起。");
    }
    file.close();
}


void Widget::ReadStream(){
    QFile file;
    file.setFileName("C:\\Users\\Administrator\\Desktop\\t.txt");
    if(true == file.open(QIODevice::ReadOnly)){
        QTextStream text(&file);
        QString str;
        text >> str;
        cout<<str.toUtf8().data();
    }
    file.close();
}
void Widget::on_pushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,"Open","C:\\");
    if(false==path.isEmpty()){
        QFile file;
        file.setFileName(path);
        if(true == file.open(QIODevice::ReadOnly)){
            QTextStream stream(&file);
            stream.setCodec("UTF-8");
            QString str = stream.readAll();
            ui->textBrowser->setText(str);
        }
        file.close();
    }

}
