#include "graph.h"
#include"graphkv.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    graph w;
    w.show();
    return a.exec();
}
