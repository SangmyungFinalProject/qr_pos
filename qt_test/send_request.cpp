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
int pay_post_Request(){

    QEventLoop eventLoop;   //이벤트 루프 생성

    QNetworkAccessManager mgr;  //NetworkAccessManager 선언
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit())); //연결이 끝나면 종료함수가 실행되도록 connect

    QNetworkRequest req(QUrl("http://wearhouse.azurewebsites.net/pay"));    //결제 서버의 주소 입력
    //req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded"); //requset의 헤더 선언
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //QUrlQuery q;    //쿼리문을 저장할 q 선언
    QJsonObject qJson;

    qJson.insert("crypto", QString::fromStdString(qr_code_str));
    qJson.insert("total_price",TOTAL_PRICE);
    qJson.insert("pos_time",QString::fromStdString(current_time()));

    //q.addQueryItem("number",qp.card_no);    //카드 정보를 q에 넣는다
    //q.addQueryItem("cvc", qp.cvc);  //cvc 정보를 q에 넣는다.
    //q.addQueryItem("price",QString::number(qp.price));  //결제 금액을 q에 넣는다.
    //q.addQueryItem("time",qp.time); //현재 시간을 q에 넣는다.
    //q.addQueryItem("company",qp.company);   //카드 회사 정보를 q에 넣는다.

    //testcode
    /*
    QJsonObject qJson_temp;
    qJson_temp.insert("card_number","5389200003558896");
    qJson_temp.insert("user_id","1");
    qJson_temp.insert("cvc","893");

    qJson.insert("crypo",qJson_temp);
    qJson.insert("total_price",QString::number(qp.price));
    */

    QJsonDocument qJsonDocu(qJson);

    QByteArray data;    //QUrlQuery를 담을 QByteArray 선언

   // data.append(q.query()); //q를 쿼리로써 담고
    data.append(qJsonDocu.toJson(QJsonDocument::Compact));
    //QString qr_data = QString::fromStdString(qr_code_str);
    //data.append(qr_data);
    qDebug(data);
    QNetworkReply *rep = mgr.post(req,data);    //서버로 data를 POST

    eventLoop.exec();
    if (rep->error() == QNetworkReply::NoError) {   //에러가 발생하지 않았다면 성공
        //connection success
        QString pay_status = rep->readLine();   //POST 결과로 오는 정보 읽음
        qDebug() << pay_status;

        //QStringList temp = pay_status.split(",");

        //qDebug() << "Success" <<rep->readAll(); //로그에 리퀘스트 찍고

        delete rep; //리퀘스트 삭제

        //return display_pay_Status_log(0,0);
        return display_pay_status_log(0,pay_status.split(",")[1].toInt()); //서버로 부터 전달 받은 코드를 분석 & 화면에 해당하는 문구 출력
    }
    else {
        //connection fail
        qDebug() << "Failure" <<rep->errorString(); //로그에 실패 띄우고
        delete rep; //리퀘스트 삭제

        //return 6;
        return display_pay_status_log(0,6); //네트워크 연결 에러 문구를 화면에 출력
    }
}

//cancel_post_request(QString cancel_pay_no)    //
//결제 취소할 거래 번호를 api서버로 post             //
int cancel_post_Request(QString cancel_pay_no)
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
        //success connect
        //qDebug() << "Cancel Success" <<rep->readAll(); //로그에 리퀘스트 찍고

        QString cancel_status = rep->readLine();   //POST 결과로 오는 정보 읽음
        qDebug() << cancel_status;

        delete rep; //리퀘스트 삭제

        //return display_success_log();   //화면에 성공 창을 띄운다.
        return display_pay_status_log(1,cancel_status.split(",")[1].toInt()); //서버로 부터 전달 받은 코드를 분석 & 화면에 해당하는 문구 출력
    }
    else {
        //failure connect
        qDebug() << "Failure" <<rep->errorString(); //로그에 실패 띄우고
        delete rep; //리퀘스트 삭제

        //return 6;
        return display_pay_status_log(1,6); //네트워크 연결 에러 문구를 화면에 출력
    }
}

//current_time()                                                                            //
//시스템의 현재시간을 YYYYMMDDHHMMSS의 14자리로 저장, QR코드에 시간 정보 오기 전까지 임시로 사용할 함수//
string current_time()
{
    time_t now;
    //struct tm *tstruct;
    char buf[80];   //시간 값 임시로 저장할 buf 선언
    string time_arr;
    now=time(NULL); //현재 시간 저장
    printf("%ld\n",now);
    sprintf(buf, "%ld000",now);

    return buf;

    /*
    tstruct=localtime(&now);    //시간 구조체에 현재 시간 저장

    //sprintf를 이용해 YYYYMMDDHHMMSS의 형태로 저장
    sprintf(buf, "%04d%02d%02d%02d%02d%02d",tstruct->tm_year+1900, tstruct->tm_mon+1, tstruct->tm_mday, tstruct->tm_hour, tstruct->tm_min, tstruct->tm_sec);
    time_arr = buf; //string으로 buf 값 저장
    cout << "지금 시간은:" << buf << endl;
    return time_arr;    //time_arr 리턴
    */
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

//display_success_log()                  //
//POST 성공시 화면에 표시할 위젯 설정하는 함수//
int display_success_log(){
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


    return 0;
}

//display_pay_status_log(int code)                                       //
//POST 성공시 받아오는 코드를 판단하여 해당 결과를 화면에 표시할 위젯 설정하는 함수//
int display_pay_status_log(int mode, int code){
    QWidget *widget = new QWidget();   //새로운 위젯 선언
    QVBoxLayout *layout = new QVBoxLayout;  //버티컬 레이아웃 선언
    QFont font( "Arial", 50, QFont::Bold); //폰트 설정
    QLabel *label;    //라벨 생성

    switch(code){
    case 0:
        if(mode==0)
            label = new QLabel("결제 완료");
        else
            label = new QLabel("결제 취소 성공");
        break;
    case 1:
        if(mode==0)
            label = new QLabel("결제 실패 (코드: P1)\nQR 코드 정보 미싱");
        else
            label = new QLabel("결제 취소 실패 (코드: C1)\n없는 결제 번호");
        break;
    case 2:
        if(mode==0)
            label = new QLabel("결제 실패 (코드: P2)\n잔액 부족/한도 초과");
        else
            label = new QLabel("결제 취소 실패 (코드: C2)\n이미 취소된 번호");
        break;
    case 3:
        label = new QLabel("결제 실패 (코드: P3)\n카드 유효기간 만료");
        break;
    case 4:
        label = new QLabel("결제 실패 (코드: P4)\nQR 코드 만료");
        break;
    case 5:
        label = new QLabel("결제 실패 (코드: P5)\n등록되지 않은 카드나 카드 정보 오류");
        break;
    case 6:
        label = new QLabel("NetWork Error!\n정보를 서버로 전송 할 수 없습니다!!");
        break;
    default:
        label = new QLabel("Unknown Error!\n관리자에게 연락 요망!!!");
        break;
    }

    label->setFont(font);   //라벨에 폰트 적용
    label->setAlignment(Qt::AlignCenter);//라벨 내의 문자 중앙 정렬

    layout->addWidget(label);   //레이아웃에 라벨 넣고
    widget->setLayout(layout); //success 위젯에 layout 적용
    widget->move(QApplication::desktop()->screen()->rect().center() - widget->rect().center()); //화면 중앙 정렬
    widget->show();    //화면에 success 위젯 출력

    //sleep(3);

   //success->close();


    return code;
}
