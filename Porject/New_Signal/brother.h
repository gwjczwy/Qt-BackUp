#ifndef BROTHER_H
#define BROTHER_H

#include <QWidget>
#include <QPushButton>

class Brother : public QWidget
{
    Q_OBJECT
public:
    explicit Brother(QWidget *parent = 0);
    QPushButton b;
    void mes();

signals:
    void change();

public slots:
};

#endif // BROTHER_H
