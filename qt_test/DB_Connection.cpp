#include "qt_test.h"


void DB_connect(){

    qDebug() << QSqlDatabase::drivers();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("13.124.113.193");
    db.setPort(3306);
    db.setDatabaseName("qrpay");
    db.setUserName("root");
    db.setPassword("blaster1122");

    if(!db.open()){
        qDebug("DB Connection error!");
        return ;
    }

    qDebug("DB Connection OK!!!");

    QSqlQuery query;

    qDebug() << query.exec("select * from card_company_info");

    while(query.next()){
        qDebug() << query.value(0).toInt();
        //qDebug() << query.value(1).toInt();
        qDebug() << query.value(1).toString();
        qDebug("\n");
    }
    qDebug("Done\n");
}
