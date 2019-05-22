#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>   //计时器

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QTimer *mainTime;

private slots:
    void on_pushButtonStart_clicked();

    void on_pushButtonStop_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
