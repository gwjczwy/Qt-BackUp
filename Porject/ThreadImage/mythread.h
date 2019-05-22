#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QImage>
#include <QObject>

class MyThread : public QObject
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = 0);
    //线程处理函数
    void drawImage();

signals:
    void  updataImage(QImage );

public slots:
};

#endif // MYTHREAD_H
