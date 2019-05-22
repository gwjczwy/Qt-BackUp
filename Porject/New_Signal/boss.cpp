#include "boss.h"

Boss::Boss(QWidget *parent)
    : QWidget(parent)
{
    //b.setParent(this);
    setWindowTitle("Boss");
    resize(600,440);
    bt1.move(270,195);
    bt2.move(100,220);
    bt1.setText("Switch");
    bt2.setText("@_@");
    bt1.setParent(this);
    bt2.setParent(this);
                                //点击后更改按钮内容
    connect(&bt2,&QPushButton::pressed,this,&Boss::good);
    connect(&bt2,&QPushButton::released,this,&Boss::bad);

    connect(&bt1,&QPushButton::released,this,&Boss::toBrother);

    void (Brother::*pchange)()=&Brother::change;
    connect(&b,pchange,this,&Boss::toBoss);
}

void Boss::good(){
    bt2.setText("^_^");
}
void Boss::bad(){
    bt2.setText("@_@");
}
void Boss::toBrother(){
    hide();
    b.show();
}
void Boss::toBoss(){
    show();
    b.hide();
}

Boss::~Boss()
{

}
