/****************************************************************************
** Meta object code from reading C++ file 'qt_test.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qt_test/qt_test.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qt_test.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_qt_test_t {
    QByteArrayData data[22];
    char stringdata[355];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qt_test_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qt_test_t qt_meta_stringdata_qt_test = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 29),
QT_MOC_LITERAL(2, 38, 0),
QT_MOC_LITERAL(3, 39, 25),
QT_MOC_LITERAL(4, 65, 20),
QT_MOC_LITERAL(5, 86, 10),
QT_MOC_LITERAL(6, 97, 12),
QT_MOC_LITERAL(7, 110, 6),
QT_MOC_LITERAL(8, 117, 24),
QT_MOC_LITERAL(9, 142, 26),
QT_MOC_LITERAL(10, 169, 26),
QT_MOC_LITERAL(11, 196, 28),
QT_MOC_LITERAL(12, 225, 28),
QT_MOC_LITERAL(13, 254, 7),
QT_MOC_LITERAL(14, 262, 8),
QT_MOC_LITERAL(15, 271, 10),
QT_MOC_LITERAL(16, 282, 10),
QT_MOC_LITERAL(17, 293, 9),
QT_MOC_LITERAL(18, 303, 3),
QT_MOC_LITERAL(19, 307, 22),
QT_MOC_LITERAL(20, 330, 10),
QT_MOC_LITERAL(21, 341, 13)
    },
    "qt_test\0on_cancel_deal_button_clicked\0"
    "\0on_payment_button_clicked\0"
    "on_set_fruit_clicked\0input_item\0"
    "QPushButton*\0button\0on_qty_up_button_pressed\0"
    "on_qty_down_button_clicked\0"
    "on_del_item_button_clicked\0"
    "on_change_qty_button_clicked\0"
    "on_cancel_pay_button_clicked\0set_qty\0"
    "QWidget*\0change_qty\0QLineEdit*\0line_edit\0"
    "row\0transfer_cancel_pay_no\0cancel_pay\0"
    "isTableSelect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qt_test[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    1,   77,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    3,   85,    2, 0x08 /* Private */,
      19,    2,   92,    2, 0x08 /* Private */,
      21,    0,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 16, QMetaType::Int,   15,   17,   18,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 16,   20,   17,
    QMetaType::Bool,

       0        // eod
};

void qt_test::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        qt_test *_t = static_cast<qt_test *>(_o);
        switch (_id) {
        case 0: _t->on_cancel_deal_button_clicked(); break;
        case 1: _t->on_payment_button_clicked(); break;
        case 2: _t->on_set_fruit_clicked(); break;
        case 3: _t->input_item((*reinterpret_cast< QPushButton*(*)>(_a[1]))); break;
        case 4: _t->on_qty_up_button_pressed(); break;
        case 5: _t->on_qty_down_button_clicked(); break;
        case 6: _t->on_del_item_button_clicked(); break;
        case 7: _t->on_change_qty_button_clicked(); break;
        case 8: _t->on_cancel_pay_button_clicked(); break;
        case 9: _t->set_qty((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QLineEdit*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 10: _t->transfer_cancel_pay_no((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QLineEdit*(*)>(_a[2]))); break;
        case 11: { bool _r = _t->isTableSelect();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QPushButton* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLineEdit* >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLineEdit* >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    }
}

const QMetaObject qt_test::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_qt_test.data,
      qt_meta_data_qt_test,  qt_static_metacall, 0, 0}
};


const QMetaObject *qt_test::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qt_test::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qt_test.stringdata))
        return static_cast<void*>(const_cast< qt_test*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int qt_test::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
