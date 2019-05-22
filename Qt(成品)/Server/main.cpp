#include "widget.h"
#include <QApplication>
#include "clientwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    w.move(300,130);

    ClientWidget w2;
    w2.show();
    w2.move(700,100);

    return a.exec();
}
