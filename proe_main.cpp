#include "proe.h"
#include <QApplication>
#include <QDebug>
#include "komputer.h"



 std::vector <Komputer*> komputery;
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    proe w;
    w.show();
    return a.exec();
}

