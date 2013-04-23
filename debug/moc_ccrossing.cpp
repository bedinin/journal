/****************************************************************************
** Meta object code from reading C++ file 'ccrossing.h'
**
** Created: Sun 7. Apr 21:46:55 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ccrossing.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ccrossing.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CCrossing[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   11,   10,   10, 0x05,
      58,   10,   10,   10, 0x05,
      91,   79,   10,   10, 0x05,
     130,   79,   10,   10, 0x05,
     172,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     194,  187,   10,   10, 0x0a,
     231,  218,   10,   10, 0x0a,
     260,  218,   10,   10, 0x0a,
     292,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CCrossing[] = {
    "CCrossing\0\0listStrafe\0"
    "signalReturnLoadCrossing(EListPair)\0"
    "signalError(QString)\0result,pair\0"
    "signalReturnAddCrossing(QString,EPair)\0"
    "signalReturnDeleteCrossing(QString,EPair)\0"
    "signalUpdate()\0i_pair\0slotLoadCrossing(EPair)\0"
    "pair,to_pair\0slotAddCrossing(EPair,EPair)\0"
    "slotDeleteCrossing(EPair,EPair)\0"
    "slotRun()\0"
};

const QMetaObject CCrossing::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CCrossing,
      qt_meta_data_CCrossing, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CCrossing::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CCrossing::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CCrossing::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CCrossing))
        return static_cast<void*>(const_cast< CCrossing*>(this));
    return QObject::qt_metacast(_clname);
}

int CCrossing::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signalReturnLoadCrossing((*reinterpret_cast< EListPair(*)>(_a[1]))); break;
        case 1: signalError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: signalReturnAddCrossing((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< EPair(*)>(_a[2]))); break;
        case 3: signalReturnDeleteCrossing((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< EPair(*)>(_a[2]))); break;
        case 4: signalUpdate(); break;
        case 5: slotLoadCrossing((*reinterpret_cast< EPair(*)>(_a[1]))); break;
        case 6: slotAddCrossing((*reinterpret_cast< EPair(*)>(_a[1])),(*reinterpret_cast< EPair(*)>(_a[2]))); break;
        case 7: slotDeleteCrossing((*reinterpret_cast< EPair(*)>(_a[1])),(*reinterpret_cast< EPair(*)>(_a[2]))); break;
        case 8: slotRun(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void CCrossing::signalReturnLoadCrossing(EListPair _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CCrossing::signalError(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CCrossing::signalReturnAddCrossing(QString _t1, EPair _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CCrossing::signalReturnDeleteCrossing(QString _t1, EPair _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CCrossing::signalUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
