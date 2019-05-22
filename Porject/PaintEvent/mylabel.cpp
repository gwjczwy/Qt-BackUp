#include "mylabel.h"
#include <QFileDialog>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{

}

void MyLabel::mousePressEvent(QMouseEvent *ev){
    QString Qpath = QFileDialog::getOpenFileName(this,"要打开什么文件？！","C:\\Users\\Administrator\\Desktop",
                                         tr("image(*.jpg *.jepg *.gif *.png)"));
    emit FilePath("C:\\Users\\Administrator\\Desktop\\1.jpg");
}

