/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "view/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[372];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "on_loginBtn_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 20), // "on_logoutBtn_clicked"
QT_MOC_LITERAL(4, 53, 20), // "on_browseBtn_clicked"
QT_MOC_LITERAL(5, 74, 18), // "on_dashBtn_clicked"
QT_MOC_LITERAL(6, 93, 26), // "on_backScheduleBtn_clicked"
QT_MOC_LITERAL(7, 120, 22), // "on_backDashBtn_clicked"
QT_MOC_LITERAL(8, 143, 18), // "on_bookBtn_clicked"
QT_MOC_LITERAL(9, 162, 22), // "on_waitlistBtn_clicked"
QT_MOC_LITERAL(10, 185, 24), // "on_cancelBookBtn_clicked"
QT_MOC_LITERAL(11, 210, 23), // "on_leaveWaitBtn_clicked"
QT_MOC_LITERAL(12, 234, 21), // "onScheduleRowSelected"
QT_MOC_LITERAL(13, 256, 3), // "row"
QT_MOC_LITERAL(14, 260, 20), // "on_opBookBtn_clicked"
QT_MOC_LITERAL(15, 281, 22), // "on_opCancelBtn_clicked"
QT_MOC_LITERAL(16, 304, 26), // "on_opRemoveWaitBtn_clicked"
QT_MOC_LITERAL(17, 331, 36), // "on_opVendorCombo_currentIndex..."
QT_MOC_LITERAL(18, 368, 3) // "idx"

    },
    "MainWindow\0on_loginBtn_clicked\0\0"
    "on_logoutBtn_clicked\0on_browseBtn_clicked\0"
    "on_dashBtn_clicked\0on_backScheduleBtn_clicked\0"
    "on_backDashBtn_clicked\0on_bookBtn_clicked\0"
    "on_waitlistBtn_clicked\0on_cancelBookBtn_clicked\0"
    "on_leaveWaitBtn_clicked\0onScheduleRowSelected\0"
    "row\0on_opBookBtn_clicked\0"
    "on_opCancelBtn_clicked\0"
    "on_opRemoveWaitBtn_clicked\0"
    "on_opVendorCombo_currentIndexChanged\0"
    "idx"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    1,   99,    2, 0x08 /* Private */,
      14,    0,  102,    2, 0x08 /* Private */,
      15,    0,  103,    2, 0x08 /* Private */,
      16,    0,  104,    2, 0x08 /* Private */,
      17,    1,  105,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_loginBtn_clicked(); break;
        case 1: _t->on_logoutBtn_clicked(); break;
        case 2: _t->on_browseBtn_clicked(); break;
        case 3: _t->on_dashBtn_clicked(); break;
        case 4: _t->on_backScheduleBtn_clicked(); break;
        case 5: _t->on_backDashBtn_clicked(); break;
        case 6: _t->on_bookBtn_clicked(); break;
        case 7: _t->on_waitlistBtn_clicked(); break;
        case 8: _t->on_cancelBookBtn_clicked(); break;
        case 9: _t->on_leaveWaitBtn_clicked(); break;
        case 10: _t->onScheduleRowSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_opBookBtn_clicked(); break;
        case 12: _t->on_opCancelBtn_clicked(); break;
        case 13: _t->on_opRemoveWaitBtn_clicked(); break;
        case 14: _t->on_opVendorCombo_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
