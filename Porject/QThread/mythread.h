#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = 0);

signals:
    void isDown();

protected:
//QThread的虚函数
//线程处理函数
//不能直接调用 要用 start()间接调用
    void run();

public slots:
};

#endif // MYTHREAD_H
