mainwidget.h   mainwidget.h   mainwidget.h   mainwidget.h    mainwidget.h   mainwidget.h   mainwidget.h   mainwidget.h    
#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
// .h 文件相当于一本书的目录 先声明有哪些接口 再在 .cpp 文件中定义
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

signals://信号 只需声明 无需定义 就像调用一个函数一样发送信号 emit mySignal()	
    void mySignal();							//其实 &QPushButton::pressed 也是一种信号 不过是已经定义了的而已 这里就自定义了一个信号


private://在这里创建两个变量 使得自定义的类型本身就是一个窗口上有两个按钮
    QPushButton b1,*b2;
    //b1.setText("close");//如果在这里就调用函数的话会报错

};

#endif // MAINWIDGET_H

main.cpp   main.cpp   main.cpp   main.cpp   main.cpp    main.cpp   main.cpp   main.cpp   main.cpp   main.cpp    
#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.show();

    return a.exec();
}

mainwidget.cpp    mainwidget.cpp    mainwidget.cpp    mainwidget.cpp    mainwidget.cpp    mainwidget.cpp    

#include "mainwidget.h"
#include <QPushButton>
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    //QPushButton b(this);
    //b.setParent(this);
    //b.setText("hhh");
    //b.move(100,100);
    //如果写在这里 在作用域超出后这些变量将不复存在 也就不会显示在主窗口上

    b1.setParent(this);
    b1.setText("hhh");
    b1.move(100,100);

    b2 = new QPushButton(this);
    b2->setText("show");
    b2->move(245,234);
    
    connect       (&b1,         &QPushButton::pressed,     this,        &MainWidget::close);//用来接收信号(点击后有反应)
  //接收信号槽函数(信号的发出者,发出者的类  ::发出信号类型,信号的接收者,槽函数|信号处理函数
}