#include <QPushButton>//包含 按钮 类

int main(int argc,char **argv){
  QApplication a(argc,argv);
  QWidget w;//创建主窗口
  
  QPushButton b;//创建 按钮
  b.setText("^_^");//设定按钮显示内容
  //b.show();//显示 按钮 但不指定父对象会单独显示一个窗口按钮
  
 /*
  *如果不指定父对象，对象和对象之间没有关联，是相互独立的
  *按钮b指定窗口w为它的父对象，按钮就会显示在窗口上
  *指定父对象
  *
  */
  
  return a.exec();
}