#include "brother.h"

Brother::Brother(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("brother");
    resize(600,440);
    b.setParent(this);
    b.move(270,195);
    b.setText("Switch");

    connect(&b,&QPushButton::clicked,this,mes);

}

void Brother::mes(){
    emit change();
}

