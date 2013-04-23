/****************************************************************************
** Meta object code from reading C++ file 'coptions.h'
**
** Created: Sun 7. Apr 21:46:53 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../coptions.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'coptions.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_COptions[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      33,   31,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      71,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_COptions[] = {
    "COptions\0\0signalError(QString)\0,\0"
    "signalReturnOptions(QString,EOptions)\0"
    "slotLoadOptions()\0"
};

const QMetaObject COptions::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_COptions,
      qt_meta_data_COptions, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &COptions::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *COptions::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *COptions::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_COptions))
        return static_cast<void*>(const_cast< COptions*>(this));
    return QObject::qt_metacast(_clname);
}

int COptions::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signalError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: signalReturnOptions((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< EOptions(*)>(_a[2]))); break;
        case 2: slotLoadOptions(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void COptions::signalError(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void COptions::signalReturnOptions(QString _t1, EOptions _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
