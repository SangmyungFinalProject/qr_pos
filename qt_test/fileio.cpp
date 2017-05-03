#include "qt_test.h"

void fileio::file_io(){

    QString ApplicationPath=QApplication::applicationDirPath();
    QFile file("/home/pi/Desktop/qt/qt_test/localdb.txt");
    //qDebug(qPrintable(ApplicationPath));
    //QFile file("C:\\Users\\SangHyuk\\Documents\\qt_test\\localdb.txt");

    if(!file.open(QFile::ReadOnly|QFile::Text)){
         qDebug("error!");
    }
    QTextStream read(&file);


    while(!read.atEnd()){
        QString tmp = read.readLine();
        qDebug(qPrintable(tmp));
    }

    file.close();
}
