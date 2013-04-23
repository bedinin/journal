/****************************************************************************
** Meta object code from reading C++ file 'cdirectorygroupname.h'
**
** Created: Sun 7. Apr 21:46:52 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cdirectorygroupname.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cdirectorygroupname.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CDirectoryGroupName[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   21,   20,   20, 0x05,
      90,   80,   20,   20, 0x05,
     154,  137,   20,   20, 0x05,
     208,   20,   20,   20, 0x05,
     229,   20,   20,   20, 0x05,
     266,  137,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
     321,   20,   20,   20, 0x0a,
     347,  344,   20,   20, 0x0a,
     374,   80,   20,   20, 0x0a,
     412,   80,   20,   20, 0x0a,
     453,   80,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CDirectoryGroupName[] = {
    "CDirectoryGroupName\0\0list\0"
    "signalReturnLoadAllDirectory(EListDirectoryGroupName)\0"
    "directory\0signalReturnLoadDirectory(EDirectoryGroupName)\0"
    "result,directory\0"
    "signalReturnAddDirectory(QString,EDirectoryGroupName)\0"
    "signalError(QString)\0"
    "signalReturnDeleteDirectory(QString)\0"
    "signalReturnEditDirectory(QString,EDirectoryGroupName)\0"
    "slotLoadAllDirectory()\0id\0"
    "slotLoadDirectory(QString)\0"
    "slotAddDirectory(EDirectoryGroupName)\0"
    "slotDeleteDirectory(EDirectoryGroupName)\0"
    "slotEditDirectory(EDirectoryGroupName)\0"
};

const QMetaObject CDirectoryGroupName::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CDirectoryGroupName,
      qt_meta_data_CDirectoryGroupName, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CDirectoryGroupName::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CDirectoryGroupName::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CDirectoryGroupName::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CDirectoryGroupName))
        return static_cast<void*>(const_cast< CDirectoryGroupName*>(this));
    return QObject::qt_metacast(_clname);
}

int CDirectoryGroupName::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signalReturnLoadAllDirectory((*reinterpret_cast< EListDirectoryGroupName(*)>(_a[1]))); break;
        case 1: signalReturnLoadDirectory((*reinterpret_cast< EDirectoryGroupName(*)>(_a[1]))); break;
        case 2: signalReturnAddDirectory((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< EDirectoryGroupName(*)>(_a[2]))); break;
        case 3: signalError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: signalReturnDeleteDirectory((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: signalReturnEditDirectory((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< EDirectoryGroupName(*)>(_a[2]))); break;
        case 6: slotLoadAllDirectory(); break;
        case 7: slotLoadDirectory((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: slotAddDirectory((*reinterpret_cast< EDirectoryGroupName(*)>(_a[1]))); break;
        case 9: slotDeleteDirectory((*reinterpret_cast< EDirectoryGroupName(*)>(_a[1]))); break;
        case 10: slotEditDirectory((*reinterpret_cast< EDirectoryGroupName(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void CDirectoryGroupName::signalReturnLoadAllDirectory(EListDirectoryGroupName _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CDirectoryGroupName::signalReturnLoadDirectory(EDirectoryGroupName _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CDirectoryGroupName::signalReturnAddDirectory(QString _t1, EDirectoryGroupName _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CDirectoryGroupName::signalError(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CDirectoryGroupName::signalReturnDeleteDirectory(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CDirectoryGroupName::signalReturnEditDirectory(QString _t1, EDirectoryGroupName _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
