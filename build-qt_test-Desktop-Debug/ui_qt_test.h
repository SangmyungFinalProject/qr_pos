/********************************************************************************
** Form generated from reading UI file 'qt_test.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_TEST_H
#define UI_QT_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qt_testClass
{
public:
    QWidget *centralWidget;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *maincategory_frame;
    QFrame *button_frame;
    QPushButton *payment_button;
    QPushButton *del_item_button;
    QPushButton *cancel_deal_button;
    QPushButton *qty_down_button;
    QPushButton *cancel_pay_button;
    QPushButton *qty_up_button;
    QPushButton *pushButton_7;
    QPushButton *change_qty_button;
    QPushButton *pushButton_9;
    QFrame *bill_frame;
    QLabel *current_price_label;
    QLabel *discount_price_label;
    QLabel *ammount_price_label;
    QLabel *display_current_price;
    QLabel *display_discount_price;
    QLabel *display_ammount_pirce;
    QFrame *title_frame;
    QLabel *label_title;
    QFrame *item_frame;
    QStackedWidget *item_stackedWidget;
    QWidget *stackedWidgetPage1;
    QTableWidget *sel_item_table;

    void setupUi(QMainWindow *qt_testClass)
    {
        if (qt_testClass->objectName().isEmpty())
            qt_testClass->setObjectName(QStringLiteral("qt_testClass"));
        qt_testClass->resize(1280, 720);
        centralWidget = new QWidget(qt_testClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(499, 550, 1201, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 100, 1280, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(500, 0, 3, 720));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(0, 500, 500, 3));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        maincategory_frame = new QFrame(centralWidget);
        maincategory_frame->setObjectName(QStringLiteral("maincategory_frame"));
        maincategory_frame->setGeometry(QRect(500, 0, 780, 100));
        button_frame = new QFrame(centralWidget);
        button_frame->setObjectName(QStringLiteral("button_frame"));
        button_frame->setGeometry(QRect(500, 560, 780, 160));
        button_frame->setFrameShape(QFrame::StyledPanel);
        button_frame->setFrameShadow(QFrame::Raised);
        payment_button = new QPushButton(button_frame);
        payment_button->setObjectName(QStringLiteral("payment_button"));
        payment_button->setGeometry(QRect(620, 0, 160, 160));
        QFont font;
        font.setPointSize(30);
        font.setBold(true);
        font.setUnderline(false);
        font.setWeight(75);
        payment_button->setFont(font);
        del_item_button = new QPushButton(button_frame);
        del_item_button->setObjectName(QStringLiteral("del_item_button"));
        del_item_button->setGeometry(QRect(465, 0, 155, 80));
        QFont font1;
        font1.setPointSize(15);
        del_item_button->setFont(font1);
        cancel_deal_button = new QPushButton(button_frame);
        cancel_deal_button->setObjectName(QStringLiteral("cancel_deal_button"));
        cancel_deal_button->setGeometry(QRect(465, 80, 155, 80));
        cancel_deal_button->setFont(font1);
        qty_down_button = new QPushButton(button_frame);
        qty_down_button->setObjectName(QStringLiteral("qty_down_button"));
        qty_down_button->setGeometry(QRect(310, 0, 155, 80));
        qty_down_button->setFont(font1);
        cancel_pay_button = new QPushButton(button_frame);
        cancel_pay_button->setObjectName(QStringLiteral("cancel_pay_button"));
        cancel_pay_button->setGeometry(QRect(310, 80, 155, 80));
        cancel_pay_button->setFont(font1);
        qty_up_button = new QPushButton(button_frame);
        qty_up_button->setObjectName(QStringLiteral("qty_up_button"));
        qty_up_button->setGeometry(QRect(155, 0, 155, 80));
        qty_up_button->setFont(font1);
        pushButton_7 = new QPushButton(button_frame);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(155, 80, 155, 80));
        change_qty_button = new QPushButton(button_frame);
        change_qty_button->setObjectName(QStringLiteral("change_qty_button"));
        change_qty_button->setGeometry(QRect(0, 0, 155, 80));
        change_qty_button->setFont(font1);
        pushButton_9 = new QPushButton(button_frame);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(0, 80, 155, 80));
        bill_frame = new QFrame(centralWidget);
        bill_frame->setObjectName(QStringLiteral("bill_frame"));
        bill_frame->setGeometry(QRect(0, 500, 500, 220));
        bill_frame->setFrameShape(QFrame::StyledPanel);
        bill_frame->setFrameShadow(QFrame::Raised);
        current_price_label = new QLabel(bill_frame);
        current_price_label->setObjectName(QStringLiteral("current_price_label"));
        current_price_label->setGeometry(QRect(10, 20, 481, 51));
        current_price_label->setStyleSheet(QStringLiteral("border: 1px solid black"));
        discount_price_label = new QLabel(bill_frame);
        discount_price_label->setObjectName(QStringLiteral("discount_price_label"));
        discount_price_label->setGeometry(QRect(10, 90, 481, 51));
        discount_price_label->setStyleSheet(QStringLiteral("border: 1px solid black"));
        ammount_price_label = new QLabel(bill_frame);
        ammount_price_label->setObjectName(QStringLiteral("ammount_price_label"));
        ammount_price_label->setGeometry(QRect(10, 160, 481, 51));
        ammount_price_label->setStyleSheet(QStringLiteral("border: 1px solid black"));
        display_current_price = new QLabel(bill_frame);
        display_current_price->setObjectName(QStringLiteral("display_current_price"));
        display_current_price->setGeometry(QRect(250, 20, 231, 51));
        display_current_price->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        display_discount_price = new QLabel(bill_frame);
        display_discount_price->setObjectName(QStringLiteral("display_discount_price"));
        display_discount_price->setGeometry(QRect(250, 90, 231, 51));
        display_discount_price->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        display_ammount_pirce = new QLabel(bill_frame);
        display_ammount_pirce->setObjectName(QStringLiteral("display_ammount_pirce"));
        display_ammount_pirce->setGeometry(QRect(250, 160, 231, 51));
        display_ammount_pirce->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        title_frame = new QFrame(centralWidget);
        title_frame->setObjectName(QStringLiteral("title_frame"));
        title_frame->setGeometry(QRect(0, 0, 500, 100));
        title_frame->setFrameShape(QFrame::StyledPanel);
        title_frame->setFrameShadow(QFrame::Raised);
        label_title = new QLabel(title_frame);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(0, 0, 501, 101));
        QFont font2;
        font2.setPointSize(35);
        label_title->setFont(font2);
        label_title->setAlignment(Qt::AlignCenter);
        item_frame = new QFrame(centralWidget);
        item_frame->setObjectName(QStringLiteral("item_frame"));
        item_frame->setGeometry(QRect(500, 100, 780, 460));
        item_stackedWidget = new QStackedWidget(item_frame);
        item_stackedWidget->setObjectName(QStringLiteral("item_stackedWidget"));
        item_stackedWidget->setGeometry(QRect(0, 0, 781, 461));
        item_stackedWidget->setFrameShape(QFrame::StyledPanel);
        item_stackedWidget->setFrameShadow(QFrame::Raised);
        stackedWidgetPage1 = new QWidget();
        stackedWidgetPage1->setObjectName(QStringLiteral("stackedWidgetPage1"));
        item_stackedWidget->addWidget(stackedWidgetPage1);
        sel_item_table = new QTableWidget(centralWidget);
        sel_item_table->setObjectName(QStringLiteral("sel_item_table"));
        sel_item_table->setGeometry(QRect(0, 100, 501, 401));
        qt_testClass->setCentralWidget(centralWidget);

        retranslateUi(qt_testClass);

        QMetaObject::connectSlotsByName(qt_testClass);
    } // setupUi

    void retranslateUi(QMainWindow *qt_testClass)
    {
        qt_testClass->setWindowTitle(QApplication::translate("qt_testClass", "qt_test", 0));
        payment_button->setText(QApplication::translate("qt_testClass", "\352\262\260\354\240\234", 0));
        del_item_button->setText(QApplication::translate("qt_testClass", "\354\202\255\354\240\234", 0));
        cancel_deal_button->setText(QApplication::translate("qt_testClass", "\354\264\210\352\270\260\355\231\224", 0));
        qty_down_button->setText(QApplication::translate("qt_testClass", "-", 0));
        cancel_pay_button->setText(QApplication::translate("qt_testClass", "\352\262\260\354\240\234 \354\202\255\354\240\234", 0));
        qty_up_button->setText(QApplication::translate("qt_testClass", "+", 0));
        pushButton_7->setText(QString());
        change_qty_button->setText(QApplication::translate("qt_testClass", "\354\210\230\353\237\211", 0));
        pushButton_9->setText(QString());
        current_price_label->setText(QApplication::translate("qt_testClass", "\355\230\204\354\236\254 \352\270\210\354\225\241", 0));
        discount_price_label->setText(QApplication::translate("qt_testClass", "\355\225\240\354\235\270 \352\270\210\354\225\241", 0));
        ammount_price_label->setText(QApplication::translate("qt_testClass", "\354\264\235 \352\270\210\354\225\241", 0));
        display_current_price->setText(QApplication::translate("qt_testClass", "0", 0));
        display_discount_price->setText(QApplication::translate("qt_testClass", "0", 0));
        display_ammount_pirce->setText(QApplication::translate("qt_testClass", "0", 0));
        label_title->setText(QApplication::translate("qt_testClass", "QR POS SYSTEM", 0));
    } // retranslateUi

};

namespace Ui {
    class qt_testClass: public Ui_qt_testClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_TEST_H
