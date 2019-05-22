#ifndef LITTLE_H
#define LITTLE_H

#include <QWidget>
#include <QPushButton>
class little : public QWidget
{
    Q_OBJECT
public:
    explicit little(QWidget *parent = 0);
    void sendSlot();


signals://信号 只需声明 无需定义 就像调用一个函数一样发送信号 emit mySignal();
    void mySignal();                         //信号必须有 signals 关键字声明 信号无返回值 有参数 emit mySignal();
    void mySignal(int,QString);


public slots:

public:
    QPushButton b;
};

#endif // LITTLE_H
