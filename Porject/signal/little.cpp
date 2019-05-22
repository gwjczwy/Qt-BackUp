#include "little.h"

little::little(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("little windows");
    b.setParent(this);
    b.setText("切换到boss");

    connect(&b,&QPushButton::released,this,&little::sendSlot);
    resize(379,264);
}

void little::sendSlot(){
    emit mySignal();
    emit mySignal(15,"子窗口发话了!");
}

