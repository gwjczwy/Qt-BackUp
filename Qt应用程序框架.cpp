#include <QApplication>

int main(int argc,char **argv){
  QApplication a(argc,argv);
  //有且只有一个应用程序类的对象
  
  QWidget w;
  //QWidget是一个窗口基类 w是一个窗口
  
  w.show();
  
  return a.exec();
  //让程序一直执行 直到事件的发生
}