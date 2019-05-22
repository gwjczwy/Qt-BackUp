#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    int x=0;
    void PathChange(QString);

private slots:
    void on_pushButton_clicked();

private:
    //重写绘图事件，虚函数
    //如果在窗口绘图，必须放在绘图事件里实现
    //绘图事件内部自动调用这个函数 （窗口重绘）
    void paintEvent(QPaintEvent *event);
private:
    Ui::Widget *ui;

};

#endif // WIDGET_H
