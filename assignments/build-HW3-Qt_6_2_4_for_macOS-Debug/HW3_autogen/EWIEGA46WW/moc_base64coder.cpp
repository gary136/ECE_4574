/****************************************************************************
** Meta object code from reading C++ file 'base64coder.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../HW3/base64coder.h"
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'base64coder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Base64Coder_t {
    const uint offsetsAndSize[10];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Base64Coder_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Base64Coder_t qt_meta_stringdata_Base64Coder = {
    {
QT_MOC_LITERAL(0, 11), // "Base64Coder"
QT_MOC_LITERAL(12, 16), // "requestCompleted"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 18), // "handleRestResponse"
QT_MOC_LITERAL(49, 8) // "response"

    },
    "Base64Coder\0requestCompleted\0\0"
    "handleRestResponse\0response"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Base64Coder[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   27,    2, 0x08,    2 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    4,

       0        // eod
};

void Base64Coder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Base64Coder *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->requestCompleted(); break;
        case 1: _t->handleRestResponse((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Base64Coder::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Base64Coder::requestCompleted)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Base64Coder::staticMetaObject = { {
    QMetaObject::SuperData::link<Coder::staticMetaObject>(),
    qt_meta_stringdata_Base64Coder.offsetsAndSize,
    qt_meta_data_Base64Coder,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Base64Coder_t
, QtPrivate::TypeAndForceComplete<Base64Coder, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>


>,
    nullptr
} };


const QMetaObject *Base64Coder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Base64Coder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Base64Coder.stringdata0))
        return static_cast<void*>(this);
    return Coder::qt_metacast(_clname);
}

int Base64Coder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Coder::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Base64Coder::requestCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
