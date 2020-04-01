#include "DenasUI.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DenasUI w;

    w.show();
    w.setFixedSize(w.width(), w.height());

    return a.exec();
}
