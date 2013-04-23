/****************************************************************************
** Meta object code from reading C++ file 'istrafe.h'
**
** Created: Sun 7. Apr 22:29:31 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../istrafe.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'istrafe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_IStrafe[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      43,    8,    8,    8, 0x05,
      61,    8,    8,    8, 0x05,
      83,    8,    8,    8, 0x05,
     108,  104,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
     151,  143,    8,    8, 0x0a,
     184,  179,    8,    8, 0x0a,
     213,  205,    8,    8, 0x0a,
     235,    8,    8,    8, 0x0a,
     252,  245,    8,    8, 0x0a,
     307,    8,    8,    8, 0x0a,
     323,  245,    8,    8, 0x0a,
     356,  354,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_IStrafe[] = {
    "IStrafe\0\0signalGetListDirectoryGroupName()\0"
    "signalGetStrafe()\0signalEditPair(EPair)\0"
    "signalError(QString)\0val\0"
    "signalICrossingConnect(ICrossing*)\0"
    "r,c,val\0slotSetPair(int,int,IPair*)\0"
    "name\0slotSetName(QString)\0row,col\0"
    "slotSetCount(int,int)\0slotRun()\0i_list\0"
    "slotGetListDirectoryGroupName(EListDirectoryGroupName)\0"
    "slotGetStrafe()\0slotReturnGetStrafe(EListPair)\0"
    ",\0slotReturnEditPair(QString,EPair)\0"
};

const QMetaObject IStrafe::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_IStrafe,
      qt_meta_data_IStrafe, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &IStrafe::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *IStrafe::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *IStrafe::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IStrafe))
        return static_cast<void*>(const_cast< IStrafe*>(this));
    return QWidget::qt_metacast(_clname);
}

int IStrafe::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signalGetListDirectoryGroupName(); break;
        case 1: signalGetStrafe(); break;
        case 2: signalEditPair((*reinterpret_cast< EPair(*)>(_a[1]))); break;
        case 3: signalError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: signalICrossingConnect((*reinterpret_cast< ICrossing*(*)>(_a[1]))); break;
        case 5: slotSetPair((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< IPair*(*)>(_a[3]))); break;
        case 6: slotSetName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: slotSetCount((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: slotRun(); break;
        case 9: slotGetListDirectoryGroupName((*reinterpret_cast< EListDirectoryGroupName(*)>(_a[1]))); break;
        case 10: slotGetStrafe(); break;
        case 11: slotReturnGetStrafe((*reinterpret_cast< EListPair(*)>(_a[1]))); break;
        case 12: slotReturnEditPair((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< EPair(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void IStrafe::signalGetListDirectoryGroupName()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void IStrafe::signalGetStrafe()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void IStrafe::signalEditPair(EPair _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void IStrafe::signalError(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void IStrafe::signalICrossingConnect(ICrossing * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
