mainwidget.h   mainwidget.h   mainwidget.h   mainwidget.h    mainwidget.h   mainwidget.h   mainwidget.h   mainwidget.h    
#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
// .h �ļ��൱��һ�����Ŀ¼ ����������Щ�ӿ� ���� .cpp �ļ��ж���
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

signals://�ź� ֻ������ ���趨�� �������һ������һ�������ź� emit mySignal()	
    void mySignal();							//��ʵ &QPushButton::pressed Ҳ��һ���ź� �������Ѿ������˵Ķ��� ������Զ�����һ���ź�


private://�����ﴴ���������� ʹ���Զ�������ͱ������һ����������������ť
    QPushButton b1,*b2;
    //b1.setText("close");//���������͵��ú����Ļ��ᱨ��

};

#endif // MAINWIDGET_H

main.cpp   main.cpp   main.cpp   main.cpp   main.cpp    main.cpp   main.cpp   main.cpp   main.cpp   main.cpp    
#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.show();

    return a.exec();
}

mainwidget.cpp    mainwidget.cpp    mainwidget.cpp    mainwidget.cpp    mainwidget.cpp    mainwidget.cpp    

#include "mainwidget.h"
#include <QPushButton>
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    //QPushButton b(this);
    //b.setParent(this);
    //b.setText("hhh");
    //b.move(100,100);
    //���д������ �������򳬳�����Щ�������������� Ҳ�Ͳ�����ʾ����������

    b1.setParent(this);
    b1.setText("hhh");
    b1.move(100,100);

    b2 = new QPushButton(this);
    b2->setText("show");
    b2->move(245,234);
    
    connect       (&b1,         &QPushButton::pressed,     this,        &MainWidget::close);//���������ź�(������з�Ӧ)
  //�����źŲۺ���(�źŵķ�����,�����ߵ���  ::�����ź�����,�źŵĽ�����,�ۺ���|�źŴ�����
}