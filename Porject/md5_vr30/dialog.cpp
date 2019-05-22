#include "dialog.h"
#include "ui_dialog.h"
#include <QFileDialog>
#include <QPushButton>
#include <QDebug>
#include <string>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("Md5修改器_vr3.0 阿诺出品");
    connect(ui->FileChouse,SIGNAL(QPushButton::clicked),this,SLOT(chouse_path()));

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::chouse_path(){
    QStringList Qpath = QFileDialog::getOpenFileNames(this,"要打开什么文件？！","C:\\Users\\Administrator\\Desktop",
                                         tr("image(*.jpg *.jepg *.gif *.png);;text(*.txt *.text *.doc *.docx)"));

}



