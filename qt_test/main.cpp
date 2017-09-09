#include "qt_test.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    qt_test w;

    w.move(QApplication::desktop()->screen()->rect().center() -  w.rect().center()); //화면 중앙 정렬
    w.show();

    return a.exec();
}
