#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QBuffer>
#include <QFile>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QPoint p,paintpos=QPoint(0,0),origin=QPoint(0,0);
    int SystemHigh,SystemWidth=1387;
    QBuffer buffer();


protected:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
