#include <QFile>

QFile file;
file.setFileName("C:\\Users\\Administreaotor\\Desktop\\");
file.open(Mode);//选择打开模式  if(true == file.open(Mode));
file.write();
file.read();

file.close();

QDataStream:二进制操作
QTextStream:文本操作 可以指定编码
QBuffer:内存操作 内容放在内存

