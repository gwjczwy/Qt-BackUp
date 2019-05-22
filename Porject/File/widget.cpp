#include "widget.h"
#include "ui_widget.h"
#include <QFile>//创建文件对象
#include <QFileDialog>//打开文件的对话框
#include <QFileInfo>//查看详细的文件信息

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_ReadFileButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,"Open",
                   "C:\\Users\\administrator\\desktop\\","TXT(*.txt);;*.*(*.*)");

    QFile file(path);//创建文件对象
    if(true == file.open(QIODevice::ReadOnly)){//以只读打开文件并检查文件打开是否成功
        QByteArray text = file.readAll();//默认只能查看 UTF-8 的编码 否则为乱码
        ui->textEdit->setText(text);
        file.close();
    }
    QFileInfo fileinfo(path);
    QString infomation;

    infomation += fileinfo.baseName() += '\n';
    infomation += fileinfo.absoluteFilePath() += '\n';

    ui->label->setText(infomation);

}

void Widget::on_WriteFileButton_clicked()
{
    QString path = QFileDialog::getSaveFileName(this,"Save",
                                  "C:\\Users\\administrator\\desktop\\",
                                  "TXT(*.txt));;*.*(*.*)");
    if(path.isEmpty()==false){
        QFile file;//创建文件对象
        file.setFileName(path);//绑定文件路径

        if(file.open(QIODevice::WriteOnly)){
            QString txt = ui->textEdit->toPlainText();//获取编辑区内容
            file.write(txt.toUtf8());//用 utf-8 格式写入
        }
        file.close();
    }


}
























