/****************************************************************************
** Meta object code from reading C++ file 'sqlfunctions.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../KinectShopApp/sqlfunctions.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sqlfunctions.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_sqlfunctions_t {
    QByteArrayData data[25];
    char stringdata[267];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_sqlfunctions_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_sqlfunctions_t qt_meta_stringdata_sqlfunctions = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 12),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 15),
QT_MOC_LITERAL(4, 43, 4),
QT_MOC_LITERAL(5, 48, 13),
QT_MOC_LITERAL(6, 62, 15),
QT_MOC_LITERAL(7, 78, 7),
QT_MOC_LITERAL(8, 86, 9),
QT_MOC_LITERAL(9, 96, 9),
QT_MOC_LITERAL(10, 106, 14),
QT_MOC_LITERAL(11, 121, 8),
QT_MOC_LITERAL(12, 130, 9),
QT_MOC_LITERAL(13, 140, 14),
QT_MOC_LITERAL(14, 155, 12),
QT_MOC_LITERAL(15, 168, 9),
QT_MOC_LITERAL(16, 178, 10),
QT_MOC_LITERAL(17, 189, 12),
QT_MOC_LITERAL(18, 202, 8),
QT_MOC_LITERAL(19, 211, 12),
QT_MOC_LITERAL(20, 224, 6),
QT_MOC_LITERAL(21, 231, 8),
QT_MOC_LITERAL(22, 240, 8),
QT_MOC_LITERAL(23, 249, 5),
QT_MOC_LITERAL(24, 255, 11)
    },
    "sqlfunctions\0purchaseDone\0\0vector<product>\0"
    "cart\0adminLoggedIn\0isAlreadyInCart\0"
    "product\0myProduct\0addToCart\0removeFromCart\0"
    "showCart\0clearCart\0disempowerUser\0"
    "changeAmount\0newAmount\0checkStock\0"
    "checkBalance\0purchase\0registerUser\0"
    "string\0username\0password\0login\0"
    "empowerUser"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_sqlfunctions[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       5,    0,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   93,    2, 0x0a /* Public */,
       9,    1,   96,    2, 0x0a /* Public */,
      10,    1,   99,    2, 0x0a /* Public */,
      11,    0,  102,    2, 0x0a /* Public */,
      12,    0,  103,    2, 0x0a /* Public */,
      13,    0,  104,    2, 0x0a /* Public */,
      14,    2,  105,    2, 0x0a /* Public */,
      16,    0,  110,    2, 0x0a /* Public */,
      17,    0,  111,    2, 0x0a /* Public */,
      18,    0,  112,    2, 0x0a /* Public */,
      19,    2,  113,    2, 0x0a /* Public */,
      23,    2,  118,    2, 0x0a /* Public */,
      24,    0,  123,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    0x80000000 | 7, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    8,   15,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20, 0x80000000 | 20,   21,   22,
    QMetaType::Void, 0x80000000 | 20, 0x80000000 | 20,   21,   22,
    QMetaType::Void,

       0        // eod
};

void sqlfunctions::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        sqlfunctions *_t = static_cast<sqlfunctions *>(_o);
        switch (_id) {
        case 0: _t->purchaseDone((*reinterpret_cast< vector<product>(*)>(_a[1]))); break;
        case 1: _t->adminLoggedIn(); break;
        case 2: { product _r = _t->isAlreadyInCart((*reinterpret_cast< product(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< product*>(_a[0]) = _r; }  break;
        case 3: _t->addToCart((*reinterpret_cast< product(*)>(_a[1]))); break;
        case 4: _t->removeFromCart((*reinterpret_cast< product(*)>(_a[1]))); break;
        case 5: _t->showCart(); break;
        case 6: _t->clearCart(); break;
        case 7: _t->disempowerUser(); break;
        case 8: _t->changeAmount((*reinterpret_cast< product(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: { int _r = _t->checkStock();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 10: { int _r = _t->checkBalance();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 11: _t->purchase(); break;
        case 12: _t->registerUser((*reinterpret_cast< string(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2]))); break;
        case 13: _t->login((*reinterpret_cast< string(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2]))); break;
        case 14: _t->empowerUser(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (sqlfunctions::*_t)(vector<product> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&sqlfunctions::purchaseDone)) {
                *result = 0;
            }
        }
        {
            typedef void (sqlfunctions::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&sqlfunctions::adminLoggedIn)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject sqlfunctions::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_sqlfunctions.data,
      qt_meta_data_sqlfunctions,  qt_static_metacall, 0, 0}
};


const QMetaObject *sqlfunctions::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *sqlfunctions::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_sqlfunctions.stringdata))
        return static_cast<void*>(const_cast< sqlfunctions*>(this));
    return QObject::qt_metacast(_clname);
}

int sqlfunctions::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void sqlfunctions::purchaseDone(vector<product> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void sqlfunctions::adminLoggedIn()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
