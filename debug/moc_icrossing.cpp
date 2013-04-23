/****************************************************************************
** Meta object code from reading C++ file 'icrossing.h'
**
** Created: Tue 9. Apr 15:15:27 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../icrossing.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'icrossing.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ICrossing[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   11,   10,   10, 0x05,
      55,   42,   10,   10, 0x05,
      86,   42,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     120,   10,   10,   10, 0x08,
     137,   10,   10,   10, 0x08,
     155,   10,   10,   10, 0x08,
     181,  176,   10,   10, 0x0a,
     215,   10,   10,   10, 0x0a,
     237,  225,   10,   10, 0x0a,
     289,  274,   10,   10, 0x0a,
     333,  329,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ICrossing[] = {
    "ICrossing\0\0pair\0signalLoadCrossing(EPair)\0"
    "pair,to_pair\0signalAddCrossing(EPair,EPair)\0"
    "signalDeleteCrossing(EPair,EPair)\0"
    "slotClearInput()\0slotAddCrossing()\0"
    "slotDeleteCrossing()\0list\0"
    "slotReturnLoadCrossing(EListPair)\0"
    "slotRun()\0result,pair\0"
    "slotReturnAddCrossing(QString,EPair)\0"
    "result,to_pair\0slotReturnDeleteCrossing(QString,EPair)\0"
    "str\0slotError(QString)\0"
};

const QMetaObject ICrossing::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ICrossing,
      qt_meta_data_ICrossing, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ICrossing::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ICrossing::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ICrossing::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ICrossing))
        return static_cast<void*>(const_cast< ICrossing*>(this));
    return QWidget::qt_metacast(_clname);
}

int ICrossing::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signalLoadCrossing((*reinterpret_cast< EPair(*)>(_a[1]))); break;
        case 1: signalAddCrossing((*reinterpret_cast< EPair(*)>(_a[1])),(*reinterpret_cast< EPair(*)>(_a[2]))); break;
        case 2: signalDeleteCrossing((*reinterpret_cast< EPair(*)>(_a[1])),(*reinterpret_cast< EPair(*)>(_a[2]))); break;
        case 3: slotClearInput(); break;
        case 4: slotAddCrossing(); break;
        case 5: slotDeleteCrossing(); break;
        case 6: slotReturnLoadCrossing((*reinterpret_cast< EListPair(*)>(_a[1]))); break;
        case 7: slotRun(); break;
        case 8: slotReturnAddCrossing((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< EPair(*)>(_a[2]))); break;
        case 9: slotReturnDeleteCrossing((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< EPair(*)>(_a[2]))); break;
        case 10: slotError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void ICrossing::signalLoadCrossing(EPair _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ICrossing::signalAddCrossing(EPair _t1, EPair _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ICrossing::signalDeleteCrossing(EPair _t1, EPair _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
