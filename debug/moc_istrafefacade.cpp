/****************************************************************************
** Meta object code from reading C++ file 'istrafefacade.h'
**
** Created: Fri 5. Apr 07:33:01 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../istrafefacade.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'istrafefacade.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_IStrafeFacade[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      49,   14,   14,   14, 0x05,
      67,   14,   14,   14, 0x05,
      89,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     110,   14,   14,   14, 0x08,
     129,  127,   14,   14, 0x08,
     176,   14,   14,   14, 0x0a,
     194,  186,   14,   14, 0x0a,
     223,  216,   14,   14, 0x0a,
     278,   14,   14,   14, 0x0a,
     294,  216,   14,   14, 0x0a,
     325,  127,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_IStrafeFacade[] = {
    "IStrafeFacade\0\0signalGetListDirectoryGroupName()\0"
    "signalGetStrafe()\0signalEditPair(EPair)\0"
    "signalError(QString)\0slotSelectMenu()\0"
    ",\0slotSelectItems(QItemSelection,QItemSelection)\0"
    "slotRun()\0row,col\0slotSetCount(int,int)\0"
    "i_list\0slotGetListDirectoryGroupName(EListDirectoryGroupName)\0"
    "slotGetStrafe()\0slotReturnGetStrafe(EListPair)\0"
    "slotReturnEditPair(QString,EPair)\0"
};

const QMetaObject IStrafeFacade::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_IStrafeFacade,
      qt_meta_data_IStrafeFacade, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &IStrafeFacade::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *IStrafeFacade::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *IStrafeFacade::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IStrafeFacade))
        return static_cast<void*>(const_cast< IStrafeFacade*>(this));
    return QWidget::qt_metacast(_clname);
}

int IStrafeFacade::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        case 4: slotSelectMenu(); break;
        case 5: slotSelectItems((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        case 6: slotRun(); break;
        case 7: slotSetCount((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: slotGetListDirectoryGroupName((*reinterpret_cast< EListDirectoryGroupName(*)>(_a[1]))); break;
        case 9: slotGetStrafe(); break;
        case 10: slotReturnGetStrafe((*reinterpret_cast< EListPair(*)>(_a[1]))); break;
        case 11: slotReturnEditPair((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< EPair(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void IStrafeFacade::signalGetListDirectoryGroupName()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void IStrafeFacade::signalGetStrafe()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void IStrafeFacade::signalEditPair(EPair _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void IStrafeFacade::signalError(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
