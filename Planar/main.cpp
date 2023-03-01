#include <QtWidgets/QApplication>
#include "Planar.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Planar w;

    w.show();
    return a.exec();
}
