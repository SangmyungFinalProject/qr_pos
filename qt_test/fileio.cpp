#include "qt_test.h"


//파일 read test 함수, 지금 사용 X
void fileio::file_io(item_list *list){

    QString ApplicationPath=QApplication::applicationDirPath();
   // QFile file(ApplicationPath+"localdb.txt");
    QFile file("C:\\Users\\SangHyuk\\Documents\\qt_test\\localdb.txt");

    if(!file.open(QFile::ReadOnly|QFile::Text)){
         qDebug("error!");
    }
    QTextStream read(&file);

    int i=0;
    while(!read.atEnd()){
        QString tmp = read.readLine();
        QStringList tmpList = tmp.split(",");
        list[i].item_name = tmpList[0];
        list[i].item_amount = tmpList[1].toInt();
        list[i].price = tmpList[2].toInt();
        qDebug(qPrintable(tmp));
        i++;
    }

    file.close();

}

//void fileio::file_io2(item_list *list, QString location)//
//설명 : 로컬파일 읽어오는 함수                               //

void fileio::file_io2(item_list *list, QString location){
    QString ApplicationPath=QApplication::applicationDirPath(); //현재 프로그램이 수행되는 경로 저장 -> 현재 사용하지 않음
    QFile file(location);   //입력받은 경로를 QFile에 저장

    if(!file.open(QFile::ReadOnly|QFile::Text)){    //파일을 읽기전용, 텍스트 형식으로 읽음
         qDebug("error!");
    }
    QTextStream read(&file);    //읽은 파일을 QTextStream에 저장

    int i=0;    //list의 각 원소 접근을 위한 int i 변수 선언

    while(!read.atEnd()){   //파일 끝까지
        QString tmp = read.readLine();  //파일 한 줄을 읽어
        QStringList tmpList = tmp.split(",");   //,을 구분하여 temList에 배열로 저장
        list[i].item_name = tmpList[0]; //물품명 저장
        list[i].item_amount = tmpList[1].toInt();   //갯수 저장
        list[i].price = tmpList[2].toInt(); //가격 저장
        i++;    //변수 1 증가
    }

    //파일 끝까지 읽은 후 남은 구조체 배열 초기화
    for(i;i<25;i++){
        list[i].item_name =" ";
    }

    file.close();   //파일 닫음

}
