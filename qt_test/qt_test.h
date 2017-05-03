#ifndef QT_TEST_H
#define QT_TEST_H

#include <QMainWindow>
#include "ui_qt_test.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QLayout>

class qt_test : public QMainWindow
{
    Q_OBJECT

public:
    qt_test(QWidget *parent = 0);
    void set_verti_sel_info();
    void set_verti_bill_info();
    ~qt_test();

private slots:
    void on_payment_button_clicked();

private:
    Ui::qt_testClass ui;
};

class fileio{
public:
    void file_io();
};


#endif // QT_TEST_H
