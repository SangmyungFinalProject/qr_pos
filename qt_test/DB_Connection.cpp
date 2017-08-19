#include "qt_test.h"

//DB_Connect()                                   //
//설명 : 물품 정보를 받아오기 위해 MYSQL DB에 연결한다.//
bool DB_connect(){

    qDebug() << QSqlDatabase::drivers();    //DB 드라이버 설치 유무를 확인

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");  //MYSQL과 연결하기 위해 QSqlDatabase을 정의한다.
    db.setHostName("13.124.113.193");
    db.setPort(3306);
    db.setDatabaseName("qrpay");
    db.setUserName("root");
    db.setPassword("blaster1122");

    if(!db.open()){ //DB Open이 되지 않을 경우
        qDebug("DB Connection error!"); //에러 메세지를 출력하고
        return false;   //false를 리턴한다
    }

    qDebug("DB Connection OK!!!");

    return true;    //DB가 정상적으로 연결되었다면 true를 리턴
}

//void get_item_info(item_list *list, int category_no)       //
//설명 : DB에서 해당하는 Category의 물품들을 가져와 list에 저장한다//
void get_item_info(item_list *list, int category_no){

    int i=0;    //현재 list 위치를 임시로 저장할 변수

    QSqlQuery query;    //DB로 전송할 Query를 저장하여 수행할 query 선언

    qDebug() << query.exec(QString("select * from item_info where category=%1").arg(category_no));   //해당하는 category의 물품을 DB에서 가져온다

    while(query.next()){    //아직 물품이 남아있다면
        list[i].item_name = query.value(2).toString();  //읽어온 colum의 2번째 값을 list의 item_name에 넣는다
        list[i].price = query.value(3).toInt(); //읽어온 colum의 3번째 값을 list의 price에 넣는다
        list[i].item_amount = 30;   //임시로 30으로 넣어준다(추후 수정 예정)
        i++;    //list의 위치를 1 증가시킨다.
    }

    for(i;i<25;i++){   //현재의 i(list의 현 위치) 부터 25까지 채워지지 않은 값 들을
        list[i].item_name =" "; //" " 로 채워준다
    }

    qDebug("put_item Done\n");  //콘솔에 확인 메세지 출력
}
