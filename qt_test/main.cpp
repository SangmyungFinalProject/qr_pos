#include "qt_test.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    fileio file;
    file.file_io();

    QApplication a(argc, argv);
    qt_test w;
    w.show();
    return a.exec();
}
