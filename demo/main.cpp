#include "homepage.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Homepage h;
    h.show();
    return a.exec();
}
