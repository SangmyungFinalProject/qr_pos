#include "qt_test.h"



qt_test::qt_test(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    set_verti_sel_info();
    set_verti_bill_info();
    /*
    QLabel* sel_item_label[10];
    QVBoxLayout *layout = new QVBoxLayout;


    for(int i=0;i<10;i++){
        sel_item_label[i]=new QLabel();
        sel_item_label[i]->setStyleSheet("border: 1px solid black");
        layout->addWidget(sel_item_label[i]);
    }
    //layout->addWidget(sel_item_label[1]);
    ui.sel_item_frame->setLayout(layout);
    */
}

void qt_test::set_verti_sel_info(){
    QLabel* sel_item_label[10];
    QVBoxLayout *layout = new QVBoxLayout;
    for(int i=0;i<10;i++){
        sel_item_label[i]=new QLabel();
        sel_item_label[i]->setStyleSheet("border: 1px solid black");
        layout->addWidget(sel_item_label[i]);
    }

    ui.sel_item_frame->setLayout(layout);
}

void qt_test::set_verti_bill_info(){
    QLabel* bill_label[3];
    QVBoxLayout *layout = new QVBoxLayout;
    bill_label[0]=new QLabel("현재 금액");
    bill_label[1]=new QLabel("할인 금액");
    bill_label[2]=new QLabel("총 금액");
    for(int i=0;i<3;i++){
        bill_label[i]->setStyleSheet("border: 1px solid black");
        layout->addWidget(bill_label[i]);
    }

    ui.bill_frame->setLayout(layout);
}

qt_test::~qt_test()
{

}

void qt_test::on_payment_button_clicked()
{

}
