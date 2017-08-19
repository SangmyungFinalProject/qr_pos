#ifndef QT_TEST_H
#define QT_TEST_H

#define ROW 10  //표 row 초기화 시 사용
#define COLUMN 3    //표 colum 초기화 시 사용

#include <QMainWindow>
#include "ui_qt_test.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QLayout>
#include <QComboBox>
#include <QTableWidget>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "zbar.h"
#include <iostream>
#include <string>
#include <time.h>
#include <QDebug>
#include <QLineEdit>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QUrlQuery>
#include <unistd.h>
#include <QThread>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

using namespace cv;
using namespace std;
using namespace zbar;


//로컬 파일에서 불러온 세부 물품을 저장할 구조체 선언
struct item_list{
    QString item_name;
    int item_amount;
    int price;
};

//QR Code 값을 저장할 구조체 선언
struct qr_and_price{
    QString card_no;
    QString cvc;
    QString time;
    int price;
    QString company;
};

class qt_test : public QMainWindow
{
    Q_OBJECT

public:
    qt_test(QWidget *parent = 0);
    void set_menu(Ui::qt_testClass ui);
    void put_item(QWidget *Widget, int num);
    void set_table();
    void display_ammount_price();
    void plus_table_qty(int row);
    void minus_table_qty(int row);
    void plus_table_price(int row);
    void minus_table_price(int row);
    ~qt_test();

public slots:
    void on_cancel_deal_button_clicked();

private slots:
    void on_payment_button_clicked();
    //void set_item();
    void on_set_fruit_clicked();
    void input_item(QPushButton *button);
    void on_qty_up_button_pressed();
    void on_qty_down_button_clicked();
    void on_del_item_button_clicked();
    void on_change_qty_button_clicked();
    void on_cancel_pay_button_clicked();

    void set_qty(QWidget *change_qty, QLineEdit *line_edit, int row);
    void transfer_cancel_pay_no(QWidget *cancel_pay, QLineEdit * line_edit);
    bool isTableSelect();

private:
    Ui::qt_testClass ui;
};

class fileio{
public:

    void file_io(item_list *list);
    void file_io2(item_list *list, QString location);
};

int qr_scan();
void getRequest();
QString postRequest();
QString cancel_post_request(QString cancel_pay_no);
string current_time();
void sep_qr_price();
QString dlsplay_success_log();
void save_JSON_format();

bool DB_connect();
void get_item_info(item_list *list, int category_no);

#endif // QT_TEST_H
