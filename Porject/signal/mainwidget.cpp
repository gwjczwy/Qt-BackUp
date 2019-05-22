#include "mainwidget.h"
#include <QPushButton>
#include <windows.h>
#include <QDebug>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    resize(379,264);
    //QPushButton b(this);
    //b.setParent(this);
    //b.setText("hhh");
    //b.move(100,100);
    //如果写在这里 在作用域超出后这些变量将不复存在 也就不会显示在主窗口上

    b1.setParent(this);
    b1.setText("exit");
    b1.move(100,100);

    b2 = new QPushButton(this);
    b2->setText("@_@");
    b2->move(245,234);
                                                        //点击后关闭窗口
    connect    (&b1,       &QPushButton::released,  this,      &MainWidget::close);//用来接收信号(点击后有反应)
  //接收信号槽函数(信号的发出者,发出者的类    ::发出信号类型,信号的接收者,槽函数，信号处理函数


    connect(b2,&QPushButton::pressed,this,&MainWidget::happy);
    connect(b2,&QPushButton::released,this,&MainWidget::shit);

    connect(b2,&QPushButton::released,&b1,&QPushButton::show);
    connect(b2,&QPushButton::pressed,&b1,&QPushButton::hide);


    b3.setParent(this);
    b3.setText("切换到little");


    //connect(&b3,&QPushButton::released,this,&MainWidget::changeLittle);//单机后交换窗口

    //lambda 表达式可以更加简便的代替后两个参数
    connect(&b3,&QPushButton::released,
            [this](){
                    changeLittle();
                }
            );


{    //处理子窗口的信号
    //用一个函数指针指向 才能传达信号到主窗口
    //void (little::*fi)()=&little::mySignal;
    //connect(&l,fi,this,&MainWidget::changeMain);

    //void (little::*fii)(int,QString)=&little::mySignal;
    //connect(&l,fii,this,&MainWidget::printSignal);
}

{        //使用这种方法大大简化了槽函数的编写 但是如果信号名写错了的话 是不会报错的
    connect(&l,SIGNAL(mySignal()),this,SLOT(changeMain()));
    //connect(&l,SIGNAL(mySignal(int,QString)),this,SLOT(printSignal(int,QString)));
}

    void (little::*fii)(int,QString)=&little::mySignal;
    connect(&l,fii,[this](int n,QString s)//如果要传递参数 就写在这里
                    {
                        qDebug()<<n<<s;
                        &MainWidget::printSignal;
                    }
            );
}
void MainWidget::shit(){
    b2->setText("@_@");
}
void MainWidget::happy(){
    b2->setText("^_^");
}


void MainWidget::changeMain(){
    show();//显示主窗口
    l.hide();//隐藏子窗口
}

void MainWidget::changeLittle(){
    hide();//隐藏主窗口
    l.show();//显示子窗口
}

void MainWidget::printSignal(int a,QString s){
    qDebug()<<a<<s;

}

MainWidget::~MainWidget()
{

}
