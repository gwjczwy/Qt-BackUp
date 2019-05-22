#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);

protected:
    //鼠标按下事件
    void mousePressEvent(QMouseEvent *ev);
    //鼠标松开事件
    void mouseReleaseEvent(QMouseEvent *ev);
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *ev);
    //鼠标进入事件
    void enterEvent(QEvent *event);
    //鼠标离开事件
    void leaveEvent(QEvent *event);
signals:

public slots:
};

#endif // MYLABEL_H
