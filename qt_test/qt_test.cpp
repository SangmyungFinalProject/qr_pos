#include "qt_test.h"

unsigned int CATEGORY_NO=0; //
unsigned int P_ROW=0;   //현재 표에 어느 row까지 입력되었는지 반영하기 위한 전역 변수
int TOTAL_PRICE=0;  //총 금액을 저장할 전역변수 선언

struct item_list* I_list[3];
extern string qr_code_str;

qt_test::qt_test(QWidget *parent)
    : QMainWindow(parent)
{
    if(!DB_connect()){
        return ;
    }
    ui.setupUi(this);

    set_menu(ui);
    set_table();    //표 세팅
}

//set_menu(Ui::qt_testClass ui)      //
//설명 : 물품의 메인카테고리 셋팅하는 함수//
void qt_test::set_menu(Ui::qt_testClass ui){

   QHBoxLayout *Layout = new QHBoxLayout;   //호라이즌 레이아웃 선언



   //세부 메뉴들을 담을 QWidget 선언
   QWidget *menu1 = new QWidget;
   QWidget *menu2 = new QWidget;
   QWidget *menu3 = new QWidget;

   //세부 메뉴들 초기화
   //put_item(menu1, "/home/pi/Desktop/qt/qt_test/localdb_fruits.txt");
   //put_item(menu2, "/home/pi/Desktop/qt/qt_test/localdb_drinks.txt");
   //put_item(menu3, "/home/pi/Desktop/qt/qt_test/localdb_meals.txt");

   put_item(menu1,1);
   put_item(menu2,2);
   put_item(menu3,3);

   //ui의 item_stackedWidget에 초기화한 세부 메뉴들 등록
   ui.item_stackedWidget->addWidget(menu1);
   ui.item_stackedWidget->addWidget(menu2);
   ui.item_stackedWidget->addWidget(menu3);

   //메인 카테고리 담을 ComboBox 선언 및 초기화
   QComboBox *pageComboBox = new QComboBox;
   pageComboBox->setMinimumSize(200,50);
   pageComboBox->addItem(tr(""));
   pageComboBox->addItem(tr("Fruits"));
   pageComboBox->addItem(tr("Drinks"));
   pageComboBox->addItem(tr("Meals"));

   QVBoxLayout *layout = new QVBoxLayout;   //버티컬 레이아웃 선언
   layout->addWidget(ui.item_stackedWidget);    //ui의 itemstackedWidget을 버티컬 레이아웃에 추가
   Layout->addWidget(pageComboBox);     //Combobox를 호라이즌 레이아웃에 추가
   ui.maincategory_frame->setLayout(Layout);    //maincategory_frame에 호라이즌 레이아웃 추가
   ui.item_frame->setLayout(layout);    //item_frame에 버티컬 레이아웃 추가

   connect(pageComboBox, SIGNAL(activated(int)), ui.item_stackedWidget, SLOT(setCurrentIndex(int)));    //ComboBox의 값이 선택되었을 때 해당하는 서브 메뉴가 뜨도록 connect
}

//put_item(QWidget *Widget, QString location)//
//설명 : 세부 메뉴 초기화 하는 함수              //
void qt_test::put_item(QWidget *Widget,int num){
    QGridLayout *layout = new QGridLayout();    //그리드 레이아웃 선언
    QPushButton *button[25];    //세부 메뉴들 담을 버튼 선언
    //fileio file;    //file class 선언
    item_list LIST[25]; //item_list 구조체 배열 선언

    for(int i =0 ;i<25;i++){    //LIST struct array initailize
        LIST[i].item_name =" "; //" "로 모든 item_name 초기화
    }

    //file.file_io2(LIST, location);  //file_io2 함수에 구조체 배열과 입력받은 주소 넘겨줌
    get_item_info(LIST, num);   //DB에서 물품 정보를 받아온다

    int temp=0; //버튼의 위치를 임시로 저장할 변수 선언
    for(int i=0;i<5;i++){
        for(int j=1;j<6;j++,temp++){
            if(QString::compare(LIST[temp].item_name," ")==0){  //만약 현재 list 배열이 " "로 초기화 되어있다면
                button[temp] = new QPushButton(LIST[temp].item_name);   //해당 값을 넣어줌 -> 버튼에 아무것도 안 보임
            }
            else
                button[temp] = new QPushButton(LIST[temp].item_name+"\n"+QString::number(LIST[temp].price));//메뉴 이름과 메뉴 가격을 버튼에 띄움

            button[temp]->setMinimumSize(10,70);   //버튼크기 지정
            layout->addWidget(button[temp],i,j);    //레이아웃에 버튼 추가
            connect( button[temp], &QPushButton::clicked, [=] { input_item( button[temp] ); } );    //버튼이 눌렸을 때 표에 선택된 값이 들어가도록 connect
        }
    }


    Widget->setLayout(layout);  //입력 받은 위젯에 레이아웃 적용
    I_list[CATEGORY_NO] = LIST; //
    CATEGORY_NO++;

    //connect(*button,SIGNAL(clicked()),this,SLOT(input_item(*button)));
}

//set_table()   //
//설명 : 표 초기화//
void qt_test::set_table(){
    ui.sel_item_table->horizontalHeader()->setStretchLastSection(true); //표 행을 위젯에 딱 맞춤
    ui.sel_item_table->verticalHeader()->setDefaultSectionSize(38); //섹션 크기 고정
    ui.sel_item_table->verticalHeader()->setStretchLastSection(true);   //표 열을 위젯에 딱 맞춤
    ui.sel_item_table->setRowCount(ROW);    //Row 설정
    ui.sel_item_table->setColumnCount(COLUMN);//Column 설정
    ui.sel_item_table->setColumnWidth(0,300);
    ui.sel_item_table->setColumnWidth(1,50);    //Column 길이 설정

    QStringList headerLabels;   //표의 해더 라벨 설정을 위해 QStringList 선언
    headerLabels << "물품명" << "수량" << "금액";
    //headerLabels << "item" << "Qty" << "price";
    ui.sel_item_table->setHorizontalHeaderLabels(headerLabels); //헤더에 라벨 적용
    ui.sel_item_table->setSelectionBehavior(QAbstractItemView::SelectRows); //셀 선택시 row 전부가 선택되도록 설정

    for(int i=0;i<ROW;i++){
        for(int j=0;j<COLUMN;j++){
            ui.sel_item_table->setItem(i,j,new QTableWidgetItem(" "));  // 표 전체를 " "로 초기화
        }
    }
}

//on_payment_button_clicked()                //
//설명 : 결제버튼이 눌렸을 경우 동작되는 슬롯 함수//
void qt_test::on_payment_button_clicked()
{
    qr_scan();  //QR코드 스캔
    save_JSON_format(); //입력 받은 값을 구조체에 분리
    QString check = postRequest(); //서버로 POST 실행
    if(QString::compare(check,"1") ==0) //포스트 결과 이상이 없다면
        on_cancel_deal_button_clicked();    //거래 초기화 진행

}

// !실수로 Qt Designer 상에서 잘못 생성한 slot이라, 삭제시 오류 발생//
void qt_test::on_set_fruit_clicked()
{

}


//input_item(QPushButton *button)                      //
//설명 : 메뉴 버튼이 눌렸을 때 표에 해당 물품을 넣는 슬롯 함수//
void qt_test::input_item(QPushButton *button){


        QStringList tmpList = button->text().split("\n");   //버튼의 텍스트를 \n를 기준으로 구분하여 임시 배열에 저장

        for(int i=0;i<P_ROW;i++){  //P_ROW만큼 비교
            if(QString::compare(tmpList[0]," ")==0) //만약 메뉴버튼의 텍스트가 " "라면 -> 물품 정보가 없는 버튼이면
              //if(tmpList[0].toInt()==0)
                return ;    //그대로 함수 종료
            else if(QString::compare(ui.sel_item_table->item(i,0)->text(), tmpList[0]) ==0){    //현재 표에 들어간 물품과 지금 누른 버튼을 일일이 비교해서 같은 값이 있으면
                plus_table_qty(i);  //해당 row에 갯수 1 증가
                plus_table_price(i);    //해당 row의 가격 증가
                return ;    //함수 종료
            }
        }
        if(!(P_ROW==10)){   //표에 새롭게 들어가는 물품이라면, P_ROW가 10이 아닐 시
            ui.sel_item_table->item(P_ROW,0)->setText(tmpList[0]);  //현재 row 아래에 물품 이름 넣고
            ui.sel_item_table->item(P_ROW,1)->setText("1"); // 갯수 1 넣고
            ui.sel_item_table->item(P_ROW,2)->setText(tmpList[1]);  // 금액 넣어준 뒤
            P_ROW++;    //1 증가
        }

        display_ammount_price();    // 그 뒤 결과를 표에 반영한다.

        qDebug()<<P_ROW;

}

//on_qty_up_button_pressed()                                 //
//설명 : +버튼 누를 시 해당 row의 갯수와 금액을 증가시키는 slot 함수//
void qt_test::on_qty_up_button_pressed()
{
    if (isTableSelect() == false) {
        return;
    }

    int row = ui.sel_item_table->currentRow();  //현재 선택된 row 저장
    QString str= ui.sel_item_table->item(row, 0)->text();   //그 row의 물품명도 저장

    if(QString::compare(str," ")==0){   //지금 선택된 row의 물품명이 " " -> 아무것도 들어가지 않은 상태일 경우
        qDebug("nope"); //로그 찍고
        return ;    //바로 종료
    }
    else{
        qDebug(str.toLatin1()); //해당 물품명 로그 찍고
        plus_table_qty(row);    //해당 row에 갯수 1증가
        plus_table_price(row);  //해당 row에 가격 증가
    }

    display_ammount_price();    //그 뒤 결과를 반영한다.
}


//on_qty_down_button_clicked()                               //
//설명 : -버튼 누를 시 해당 row의 갯수와 금액을 감소시키는 slot 함수//
void qt_test::on_qty_down_button_clicked()
{
    if (isTableSelect() == false) {
        return;
    }

    int row = ui.sel_item_table->currentRow();  //현재 선택된 row 저장
    QString str = ui.sel_item_table->item(row, 0)->text();  //그 row의 물품명 저장
    int Qty = ui.sel_item_table->item(row, 1)->text().toInt();  //그 row의 갯수 저장

    if(QString::compare(str," ")==0){   //지금 선택된 row의 물품명이 " " -> 아무것도 들어가지 않은 상태일 경우
        qDebug("nope"); //로그 찍고
        return ;    //바로 종료
    }
    else if(Qty==1){    //만약 현재 갯수가 1개라면
            ui.sel_item_table->removeRow(row);  //해당 row를 지우고
            P_ROW--;    //P_ROW 1 감소
            ui.sel_item_table->setRowCount(ROW);    //표의 row count를 다시 초기화

            for(int i=0;i<COLUMN;i++){
                ui.sel_item_table->setItem(ROW-1,i,new QTableWidgetItem(" "));  // 새로 추가된 행을 " "로 초기화
            }
    }
    else{
        qDebug(str.toLatin1()); //해당 물품명 로그 찍고
        minus_table_qty(row);   //해당 row에 갯수 1감소
        minus_table_price(row); //해당 row에 가격 감소
    }

    display_ammount_price();    //그 뒤 결과를 반영한다.
}

//on_del_item_button_clicked()          //
//설명 : 삭제 버튼 누를 시 해당 row를 지운다.//
void qt_test::on_del_item_button_clicked()
{
    if (isTableSelect() == false) {
        return;
    }

    int row = ui.sel_item_table->currentRow();  //현재 선택된 row 저장
    QString str = ui.sel_item_table->item(row, 0)->text();  //그 row의 물품명 저장

    if(QString::compare(str," ")==0){   //지금 선택된 row의 물품명이 " " -> 아무것도 들어가지 않은 상태일 경우
        qDebug("nope"); //로그 찍고
        return ;    //바로 종료
    }
    else{
        ui.sel_item_table->removeRow(row);  //해당 row 지우고
        P_ROW--;    //P_ROW 1 감소
        ui.sel_item_table->setRowCount(ROW);    //표의 row count를 다시 초기화

        for(int i=0;i<COLUMN;i++){
            ui.sel_item_table->setItem(ROW-1,i,new QTableWidgetItem(" "));  // 새로 추가된 행을 " "로 초기화
        }
    }

    display_ammount_price(); // 그 뒤 결과를 반영한다.
}

//on_cancel_deal_button_clicked()              //
//설명 : 초기화 버튼 누를 시 표의 모든 내용을 지운다.//
void qt_test::on_cancel_deal_button_clicked()
{
    ui.sel_item_table->clear(); //표 전부를 지우고
    set_table();    //표를 다시 초기화
    P_ROW=0;    //P_ROW 0으로 변경

    display_ammount_price();    //그 뒤 결과를 반영한다.
}


//on_change_qty_button_clicked()                //
//설명 : 변경 버튼 누를 시 해당 row의 갯수를 변경한다.//
void qt_test::on_change_qty_button_clicked()
{
    if (isTableSelect() == false) {
        return;
    }

    int row = ui.sel_item_table->currentRow();  //현재 선택된 row 저장
    QString str= ui.sel_item_table->item(row, 0)->text();   //그 row의 물품명 저장

    if(QString::compare(str," ")==0){   //지금 선택된 row의 물품명이 " " -> 아무것도 들어가지 않은 상태일 경우
        qDebug("nope"); //로그 찍고
        return ;    //바로 종료
    }
    else{
        qDebug(str.toLatin1()); //로그 찍고
        QWidget *change_qty = new QWidget(); //변경 값을 입력받을 위젯을 선언
        QVBoxLayout *layout = new QVBoxLayout;  //버티컬 레이아웃 선언
        QLabel *label = new QLabel("change the Qty");   //라벨 선언 후 텍스트 설정
        QLineEdit *line_edit = new QLineEdit(); //변경 값 입력받을 line_edit 선언
        QPushButton *button = new QPushButton("&set");  //입력 끝나고 누를 버튼 선언

        line_edit->setValidator(new QIntValidator(0, 100, this));

        //레이아웃에 라벨, 라인에딧, 버튼 순으로 담기
        layout->addWidget(label);
        layout->addWidget(line_edit);
        layout->addWidget(button);

        change_qty->setLayout(layout);  //change_qty 위젯에 레이아웃 반영

        change_qty->show(); //화면에 change_qty 표시


        //connect(button, SIGNAL(clicked()), this, SLOT(set_qty()));
        connect(button, &QPushButton::clicked, [=]{set_qty(change_qty, line_edit, row);});  //버튼이 눌렸을 때 해당 row의 값을 변경 할 슬롯 함수로 connect

    }
}


void qt_test::on_cancel_pay_button_clicked()
{
    QWidget *cancel_pay = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout;
    QLabel *label = new QLabel("Input pay No.");
    QLineEdit *line_edit = new QLineEdit();
    QPushButton *button = new QPushButton("OK");

    line_edit->setValidator(new QIntValidator(0, 100, this));

    layout->addWidget(label);
    layout->addWidget(line_edit);
    layout->addWidget(button);

    cancel_pay->setLayout(layout);

    cancel_pay->show();

    connect(button, &QPushButton::clicked, [=]{transfer_cancel_pay_no(cancel_pay, line_edit);});

}

//set_qty(QWidget *change_qty, QLineEdit *line_edit, int row)//
//설명 : 변경 값을 받은 뒤 실제로 표에 반영하는 슬롯함수           //
void qt_test::set_qty(QWidget *change_qty, QLineEdit *line_edit, int row){

    int price = ui.sel_item_table->item(row,2)->text().toInt(); //현재 선택된 row의 금액 저장
    int qty = ui.sel_item_table->item(row,1)->text().toInt();   //현재 선택된 row의 갯수 저장

    price = (price/qty)*line_edit->text().toInt();  //1개당 금액을 구해 현재 입력받은 변경값을 곱하여 price에 저장

    ui.sel_item_table->item(row,1)->setText(line_edit->text()); //현재 선택된 row의 갯수를 라인에딧으로 입력받은 값으로 변경
    ui.sel_item_table->item(row,2)->setText(QString::number(price));    //현재 선택된 row의 금액을 price로 변경

    display_ammount_price();    //결과 반영
    qDebug("input item in table finished");
    change_qty->close();    //change_gty 위젯 닫기

}
//transfer_cancel_pay_no(QWidget *cancel_pay, QLineEdit * line_edit)//
//input the pay_id and call cancel_post_request() func              //
void qt_test::transfer_cancel_pay_no(QWidget *cancel_pay, QLineEdit * line_edit)
{
    qDebug("Enter pay no. checker");
    QString cancel_pay_no = line_edit->text();
    cancel_pay->close();
    qDebug("input finish");

    cancel_post_request(cancel_pay_no);
}

//display_ammount_price()                            //
//설명 : 금액 표시 라벨에 표에 있는 물품 총 금액을 반영한다.//
void qt_test::display_ammount_price(){
    int ammount_price = 0;  //총 금액을 저장할 변수 선언

    for(int i=0;i<P_ROW;i++){   //P_ROW까지
        ammount_price += ui.sel_item_table->item(i,2)->text().toInt();  //표에 있는 모든 금액 더해서 ammount_price에 저장
    }
    ui.display_current_price->setText(QString::number(ammount_price));  //현재 금액 라벨에 ammount price 표시
    ui.display_discount_price->setText(QString::number(0)); //현재 별도로 할인 관련 알고리즘이 없으므로 0으로
    ui.display_ammount_pirce->setText(QString::number(ammount_price));  //총 금액 라벨에 ammount price 표시

    TOTAL_PRICE = ammount_price;    //총 금액을 전역 변수에 저장
}



//plus_table_qty(int row)         //
//설명 : 현재 선택된 row의 물품 갯수 1증가//
void qt_test::plus_table_qty(int row){
    int tmp = ui.sel_item_table->item(row,1)->text().toInt() + 1;
    ui.sel_item_table->item(row,1)->setText(QString::number(tmp));
}

//minus_table_qty(int row)        //
//설명 : 현재 선택된 row의 물품 갯수 1감소//
void qt_test::minus_table_qty(int row){
    int tmp = ui.sel_item_table->item(row,1)->text().toInt() - 1;
    ui.sel_item_table->item(row,1)->setText(QString::number(tmp));
}

//plus_table_price(int row)      //
//설명 : 현재 선택된 row의 가격 증가//
void qt_test::plus_table_price(int row){
    int sum = ui.sel_item_table->item(row,2)->text().toInt();   //현재 선택된 row의 금액을 저장
    int qty = ui.sel_item_table->item(row,1)->text().toInt();   //현재 선택된 row의 갯수 저장
    sum += sum/(qty-1); //현재의 sum에 1개 단가를 더한다, 1을 빼는 이유는, 이 함수 수행전 plus_table_qty가 수행되기 때문
    ui.sel_item_table->item(row,2)->setText(QString::number(sum));  //현재 row에 sum 반영
    display_ammount_price();    //그 뒤 결과를 반영한다.
}

//minus_table_price(int row)     //
//설명 : 현재 선택된 row의 가격 감소//
void qt_test::minus_table_price(int row){
    int sum = ui.sel_item_table->item(row,2)->text().toInt();   //현재 선택된 row의 금액을 저장
    int qty = ui.sel_item_table->item(row,1)->text().toInt();   //현재 선택된 row의 갯수 저장
    sum -= sum/(qty+1); //현재의 sum에 1개 단가를 더한다, 1을 더하는는 이유는, 이 함수 수행전 minus_table_qty가 수행되기 때문
    ui.sel_item_table->item(row,2)->setText(QString::number(sum));  //현재 row에 sum 반영
    display_ammount_price();    //그 뒤 결과를 반영한다.
}

//isTableSelect()//
//is table selected??//
bool qt_test::isTableSelect()
{
    return ui.sel_item_table->currentItem() > 0;
}

bool qt_test::isTableFull()
{
    return P_ROW == 10;
}
qt_test::~qt_test()
{
    //free(I_list[0]);
    //free(I_list[1]);
    //free(I_list[2]);
}


