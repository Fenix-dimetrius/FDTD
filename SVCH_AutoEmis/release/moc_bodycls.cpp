/****************************************************************************
** Meta object code from reading C++ file 'bodycls.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../bodycls.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bodycls.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BodyCls_t {
    QByteArrayData data[11];
    char stringdata0[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BodyCls_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BodyCls_t qt_meta_stringdata_BodyCls = {
    {
QT_MOC_LITERAL(0, 0, 7), // "BodyCls"
QT_MOC_LITERAL(1, 8, 6), // "rePlot"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 8), // "double**"
QT_MOC_LITERAL(4, 25, 7), // "CoordZ1"
QT_MOC_LITERAL(5, 33, 4), // "size"
QT_MOC_LITERAL(6, 38, 2), // "ny"
QT_MOC_LITERAL(7, 41, 8), // "finished"
QT_MOC_LITERAL(8, 50, 5), // "error"
QT_MOC_LITERAL(9, 56, 3), // "err"
QT_MOC_LITERAL(10, 60, 7) // "process"

    },
    "BodyCls\0rePlot\0\0double**\0CoordZ1\0size\0"
    "ny\0finished\0error\0err\0process"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BodyCls[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   34,    2, 0x06 /* Public */,
       7,    0,   41,    2, 0x06 /* Public */,
       8,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void BodyCls::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BodyCls *_t = static_cast<BodyCls *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rePlot((*reinterpret_cast< double**(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->finished(); break;
        case 2: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->process(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BodyCls::*_t)(double * * , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BodyCls::rePlot)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (BodyCls::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BodyCls::finished)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (BodyCls::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BodyCls::error)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject BodyCls::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BodyCls.data,
      qt_meta_data_BodyCls,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BodyCls::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BodyCls::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BodyCls.stringdata0))
        return static_cast<void*>(const_cast< BodyCls*>(this));
    return QObject::qt_metacast(_clname);
}

int BodyCls::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void BodyCls::rePlot(double * * _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BodyCls::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void BodyCls::error(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
