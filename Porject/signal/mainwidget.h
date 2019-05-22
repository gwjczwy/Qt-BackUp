#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "little.h"
// .h 文件相当于一本书的目录 先声明有哪些接口 再在 .cpp 文件中定义
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
public slots:
    void printSignal(int,QString);
    void changeMain();
private://在这里创建两个变量 使得自定义的类型本身就是一个窗口上有两个按钮
    QPushButton b1,*b2,b3;
    //b1.setText("close");//如果在这里就调用函数的话会报错

    void happy();
    void shit();

    void changeLittle();

    little l;


};

#endif // MAINWIDGET_H
