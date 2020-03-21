#include "denasui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DenasUI w;
    w.show();
    return a.exec();
}
