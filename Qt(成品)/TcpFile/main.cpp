#include "server.h"
#include "client.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Server w;
    Client m;
    w.show();
    m.show();
    w.move(250,220);
    m.move(700,220);

    return a.exec();
}
