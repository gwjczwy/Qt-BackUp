#include <QApplication>

int main(int argc,char **argv){
  QApplication a(argc,argv);
  //����ֻ��һ��Ӧ�ó�����Ķ���
  
  QWidget w;
  //QWidget��һ�����ڻ��� w��һ������
  
  w.show();
  
  return a.exec();
  //�ó���һֱִ�� ֱ���¼��ķ���
}