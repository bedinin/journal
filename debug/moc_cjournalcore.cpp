/****************************************************************************
** Meta object code from reading C++ file 'cjournalcore.h'
**
** Created: Sun 7. Apr 22:36:20 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cjournalcore.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cjournalcore.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CJournalCore[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      39,   13,   13,   13, 0x05,
      65,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
     125,   85,   13,   13, 0x0a,
     181,   13,   13,   13, 0x0a,
     204,   13,   13,   13, 0x0a,
     233,   13,   13,   13, 0x0a,
     251,   13,   13,   13, 0x0a,
     279,  277,   13,   13, 0x0a,
     319,  315,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CJournalCore[] = {
    "CJournalCore\0\0signalShowError(QString)\0"
    "signalErrorMysql(QString)\0signalLoadOptions()\0"
    "DatabaseName,UserName,HostName,Password\0"
    "slotCreateMysqlConnect(QString,QString,QString,QString)\0"
    "slotShowError(QString)\0"
    "slotShowDirectoryGroupName()\0"
    "slotShowIFacade()\0slotShowIDetailedStrafe()\0"
    ",\0slotReturnOptions(QString,EOptions)\0"
    "val\0slotICrossingConnect(ICrossing*)\0"
};

const QMetaObject CJournalCore::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CJournalCore,
      qt_meta_data_CJournalCore, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CJournalCore::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CJournalCore::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CJournalCore::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CJournalCore))
        return static_cast<void*>(const_cast< CJournalCore*>(this));
    return QObject::qt_metacast(_clname);
}

int CJournalCore::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signalShowError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: signalErrorMysql((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: signalLoadOptions(); break;
        case 3: slotCreateMysqlConnect((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 4: slotShowError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: slotShowDirectoryGroupName(); break;
        case 6: slotShowIFacade(); break;
        case 7: slotShowIDetailedStrafe(); break;
        case 8: slotReturnOptions((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< EOptions(*)>(_a[2]))); break;
        case 9: slotICrossingConnect((*reinterpret_cast< ICrossing*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void CJournalCore::signalShowError(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CJournalCore::signalErrorMysql(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CJournalCore::signalLoadOptions()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
