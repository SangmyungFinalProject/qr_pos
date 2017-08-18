#include "qt_test.h"

bool DB_connect(){

    qDebug() << QSqlDatabase::drivers();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("13.124.113.193");
    db.setPort(3306);
    db.setDatabaseName("qrpay");
    db.setUserName("root");
    db.setPassword("blaster1122");

    if(!db.open()){
        qDebug("DB Connection error!");
        return false;
    }

    qDebug("DB Connection OK!!!");

    return true;
}

void get_item_info(item_list *list, int num){

    //DB_connect();

    int i=0;

    QSqlQuery query;

    qDebug() << query.exec(QString("select * from item_info where category=%1").arg(num));

    while(query.next()){
        //qDebug() << query.value(1).toInt();
        //qDebug() << query.value(2).toString();
        //qDebug() << query.value(3).toInt();
        list[i].item_name = query.value(2).toString();
        list[i].price = query.value(3).toInt();
        list[i].item_amount = 30;
        i++;
    }

    for(i;i<25;i++){
        list[i].item_name =" ";
    }

    qDebug("put_item Done\n");
}
