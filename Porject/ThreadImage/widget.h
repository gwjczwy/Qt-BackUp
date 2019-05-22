#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mythread.h"
#include <QThread>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void paintEvent(QPaintEvent *event);//重写绘图函数
    void getImage(QImage);//从子线程获取画好的图片
    void ExitThread();//退出线程
private:
    Ui::Widget *ui;
    QImage image;
    MyThread *myT;//定义线程对象
    QThread *thread;//子线程
};

#endif // WIDGET_H
