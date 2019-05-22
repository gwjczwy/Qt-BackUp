#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);

private:
    void mousePressEvent(QMouseEvent *ev);

signals:
    void FilePath(QString);

public slots:
};

#endif // MYLABEL_H
