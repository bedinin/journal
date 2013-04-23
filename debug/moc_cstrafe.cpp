/****************************************************************************
** Meta object code from reading C++ file 'cstrafe.h'
**
** Created: Sun 7. Apr 21:46:50 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cstrafe.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cstrafe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CStrafe[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,    9,    8,    8, 0x05,
      54,    8,    8,    8, 0x05,
      87,   75,    8,    8, 0x05,
     123,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
     142,    8,    8,    8, 0x0a,
     164,  159,    8,    8, 0x0a,
     186,  184,    8,    8, 0x0a,
     222,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CStrafe[] = {
    "CStrafe\0\0listStrafe\0"
    "signalReturnLoadStrafe(EListPair)\0"
    "signalError(QString)\0result,pair\0"
    "signalReturnEditPair(QString,EPair)\0"
    "signalGetOptions()\0slotLoadStrafe()\0"
    "pair\0slotEditPair(EPair)\0,\0"
    "slotReturnOptions(QString,EOptions)\0"
    "slotRun()\0"
};

const QMetaObject CStrafe::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CStrafe,
      qt_meta_data_CStrafe, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CStrafe::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CStrafe::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CStrafe::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CStrafe))
        return static_cast<void*>(const_cast< CStrafe*>(this));
    return QObject::qt_metacast(_clname);
}

int CStrafe::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signalReturnLoadStrafe((*reinterpret_cast< EListPair(*)>(_a[1]))); break;
        case 1: signalError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: signalReturnEditPair((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< EPair(*)>(_a[2]))); break;
        case 3: signalGetOptions(); break;
        case 4: slotLoadStrafe(); break;
        case 5: slotEditPair((*reinterpret_cast< EPair(*)>(_a[1]))); break;
        case 6: slotReturnOptions((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< EOptions(*)>(_a[2]))); break;
        case 7: slotRun(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void CStrafe::signalReturnLoadStrafe(EListPair _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CStrafe::signalError(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CStrafe::signalReturnEditPair(QString _t1, EPair _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CStrafe::signalGetOptions()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
