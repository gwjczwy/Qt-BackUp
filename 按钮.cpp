#include <QPushButton>//���� ��ť ��

int main(int argc,char **argv){
  QApplication a(argc,argv);
  QWidget w;//����������
  
  QPushButton b;//���� ��ť
  b.setText("^_^");//�趨��ť��ʾ����
  //b.show();//��ʾ ��ť ����ָ��������ᵥ����ʾһ�����ڰ�ť
  
 /*
  *�����ָ�������󣬶���Ͷ���֮��û�й��������໥������
  *��ťbָ������wΪ���ĸ����󣬰�ť�ͻ���ʾ�ڴ�����
  *ָ��������
  *
  */
  
  return a.exec();
}