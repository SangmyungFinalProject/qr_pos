#include "qt_test.h"

struct qr_and_price qp; //QR Code로 읽은 값을 값 별로 분리 저장하기 위해 구조체 선언
extern string qr_code_str;  //QR Code로 읽은 값이 저장된 string
extern int TOTAL_PRICE; //현재 결제할 금액이 저장된 int

//get 테스트 함수, 사용 X
void getRequest(){

    // create custom temporary event loop on stack
    QEventLoop eventLoop;

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    // the HTTP request
    QNetworkRequest req( QUrl( QString("http://wearhouse.azurewebsites.net/cards/1234") ) );
    QNetworkReply *reply = mgr.get(req);
    eventLoop.exec(); // blocks stack until "finished()" has been called

    if (reply->error() == QNetworkReply::NoError) {
        //success
        qDebug() << "Success" <<reply->readAll();
        delete reply;
    }
    else {
        //failure
        qDebug() << "Failure" <<reply->errorString();
        delete reply;
    }
}

/*
//postRequest()                                    //
//설명 : 서버로 읽은 QR Code와 결제 금액 정보를 post한다//
QString postRequest(){

    QEventLoop eventLoop;   //이벤트 루프 생성

    QNetworkAccessManager mgr;  //NetworkAccessManager 선언
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit())); //연결이 끝나면 종료함수가 실행되도록 connect

    QNetworkRequest req(QUrl("http://wearhouse.azurewebsites.net/pay"));    //결제 서버의 주소 입력
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded"); //requset의 헤더 선언

    QUrlQuery q;    //쿼리문을 저장할 q 선언

    q.addQueryItem("number",qp.card_no);    //카드 정보를 q에 넣는다
    q.addQueryItem("cvc", qp.cvc);  //cvc 정보를 q에 넣는다.
    q.addQueryItem("price",QString::number(qp.price));  //결제 금액을 q에 넣는다.
    q.addQueryItem("time",qp.time); //현재 시간을 q에 넣는다.
    q.addQueryItem("company",qp.company);   //카드 회사 정보를 q에 넣는다.

    QByteArray data;    //QUrlQuery를 담을 QByteArray 선언

    data.append(q.query()); //q를 쿼리로써 담고

    qDebug(data);
    QNetworkReply *rep = mgr.post(req,data);    //서버로 data를 POST

    eventLoop.exec();
    if (rep->error() == QNetworkReply::NoError) {   //에러가 발생하지 않았다면 성공
        //success
        qDebug() << "Success" <<rep->readAll(); //로그에 리퀘스트 찍고
        delete rep; //리퀘스트 삭제

        return dlsplay_success_log();   //화면에 성공 창을 띄운다.
    }
    else {
        //failure
        qDebug() << "Failure" <<rep->errorString(); //로그에 실패 띄우고
        delete rep; //리퀘스트 삭제

        return "";
    }
}
*/
//test code
QString postRequest(){

    QEventLoop eventLoop;   //이벤트 루프 생성

    QNetworkAccessManager mgr;  //NetworkAccessManager 선언
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit())); //연결이 끝나면 종료함수가 실행되도록 connect

    QNetworkRequest req(QUrl("http://wearhouse.azurewebsites.net/pay"));    //결제 서버의 주소 입력
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded"); //requset의 헤더 선언


    QUrlQuery q;    //쿼리문을 저장할 q 선언

    //q.addQueryItem("number",qp.card_no);    //카드 정보를 q에 넣는다
    //q.addQueryItem("cvc", qp.cvc);  //cvc 정보를 q에 넣는다.
    q.addQueryItem("price",QString::number(qp.price));  //결제 금액을 q에 넣는다.
    //q.addQueryItem("time",qp.time); //현재 시간을 q에 넣는다.
    //q.addQueryItem("company",qp.company);   //카드 회사 정보를 q에 넣는다.

    QByteArray data;    //QUrlQuery를 담을 QByteArray 선언

    data.append(q.query()); //q를 쿼리로써 담고
    QString qr_data = QString::fromStdString(qr_code_str);
    data.append(qr_data);
    qDebug(data);
    QNetworkReply *rep = mgr.post(req,data);    //서버로 data를 POST

    eventLoop.exec();
    if (rep->error() == QNetworkReply::NoError) {   //에러가 발생하지 않았다면 성공
        //success
        qDebug() << "Success" <<rep->readAll(); //로그에 리퀘스트 찍고
        delete rep; //리퀘스트 삭제

        return dlsplay_success_log();   //화면에 성공 창을 띄운다.
    }
    else {
        //failure
        qDebug() << "Failure" <<rep->errorString(); //로그에 실패 띄우고
        delete rep; //리퀘스트 삭제

        return "";
    }
}

QString cancel_post_request(QString cancel_pay_no)
{
    QEventLoop eventLoop;   //이벤트 루프 생성

    QNetworkAccessManager mgr;  //NetworkAccessManager 선언
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit())); //연결이 끝나면 종료함수가 실행되도록 connect

    QNetworkRequest req(QUrl("http://wearhouse.azurewebsites.net/pay/cancel"));    //결제 서버의 주소 입력
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded"); //requset의 헤더 선언

    QUrlQuery q;

    q.addQueryItem("pay_id", cancel_pay_no);

    QByteArray data;
    data.append(q.query());
    qDebug(data);

    QNetworkReply *rep = mgr.post(req,data);

    eventLoop.exec();
    if (rep->error() == QNetworkReply::NoError) {   //에러가 발생하지 않았다면 성공
        //success
        qDebug() << "Cancel Success" <<rep->readAll(); //로그에 리퀘스트 찍고
        delete rep; //리퀘스트 삭제

        return dlsplay_success_log();   //화면에 성공 창을 띄운다.
    }
    else {
        //failure
        qDebug() << "Failure" <<rep->errorString(); //로그에 실패 띄우고
        delete rep; //리퀘스트 삭제

        return "";
    }
}


//current_time()                                                                            //
//시스템의 현재시간을 YYYYMMDDHHMMSS의 14자리로 저장, QR코드에 시간 정보 오기 전까지 임시로 사용할 함수//
string current_time()
{
    time_t now;
    struct tm *tstruct;
    char buf[80];   //시간 값 임시로 저장할 buf 선언
    string time_arr;
    now=time(NULL); //현재 시간 저장
    tstruct=localtime(&now);    //시간 구조체에 현재 시간 저장

    //sprintf를 이용해 YYYYMMDDHHMMSS의 형태로 저장
    sprintf(buf, "%04d%02d%02d%02d%02d%02d",tstruct->tm_year+1900, tstruct->tm_mon+1, tstruct->tm_mday, tstruct->tm_hour, tstruct->tm_min, tstruct->tm_sec);
    time_arr = buf; //string으로 buf 값 저장
    cout << "지금 시간은:" << buf << endl;
    return time_arr;    //time_arr 리턴
}

//save_JSON_format()               //
//QR Code 정보를 구조체에 저장하는 함수//
void save_JSON_format(){
    QString data = QString::fromStdString(qr_code_str); //QR Code의 내용을 QString으로 저장
    QJsonDocument jdoc = QJsonDocument::fromJson(data.toUtf8());    //QJsonDocument에 data 저장
    QJsonObject jobj = jdoc.object();   //jdoc에 대한 object 선언하여 저장


    qp.card_no =  jobj["number"].toString();    //jobj에서 number에 해당하는 값을 뽑아 저장
    qp.cvc = jobj["cvc"].toString();    //jobj에서 cvc에 해당하는 값을 뽑아 저장
    qp.time =  QString::fromStdString(current_time());  //current_time 수행 결과 저장
    qp.price = TOTAL_PRICE; //TOTAL_PRICE 저장
    qp.company =  jobj["company"].toString();   //jobj에서 company에 해당하는 값을 뽑아 저장

    qDebug()<<qp.card_no << qp.cvc << qp.time << qp.price;


}

//dlsplay_success_log()                  //
//POST 성공시 화면에 표시할 위젯 설정하는 함수//
QString dlsplay_success_log(){
    QWidget *success = new QWidget();   //새로운 위젯 선언
    QVBoxLayout *layout = new QVBoxLayout;  //버티컬 레이아웃 선언
    QFont font( "Arial", 120, QFont::Bold); //폰트 설정
    QLabel *label = new QLabel("결제 완료");    //라벨 생성 후 텍스트 설정
    label->setFont(font);   //라벨에 폰트 적용


    layout->addWidget(label);   //레이아웃에 라벨 넣고
    success->setLayout(layout); //success 위젯에 layout 적용
    success->show();    //화면에 success 위젯 출력

    //sleep(3);

   //success->close();


    return "1";
}
