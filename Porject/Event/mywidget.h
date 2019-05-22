#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();
protected:
    //键盘按下事件
    void keyPressEvent(QKeyEvent *event);
    //计时器事件
    void timerEvent(QTimerEvent *event);

    //鼠标点击事件
    void mousePressEvent(QMouseEvent *e);

    //事件拦截
    bool event(QEvent *event);

    //事件过滤
    bool eventFilter(QObject *obj, QEvent *event);

private:
    Ui::MyWidget *ui;

    int TimeId;
    int QuckTimeId;
};

#endif // MYWIDGET_H
