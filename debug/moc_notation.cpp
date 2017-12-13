/****************************************************************************
** Meta object code from reading C++ file 'notation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../notation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'notation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Notation_t {
    QByteArrayData data[17];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Notation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Notation_t qt_meta_stringdata_Notation = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Notation"
QT_MOC_LITERAL(1, 9, 16), // "noteScaleChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "scale"
QT_MOC_LITERAL(4, 33, 12), // "setNoteScale"
QT_MOC_LITERAL(5, 46, 9), // "noteScale"
QT_MOC_LITERAL(6, 56, 4), // "Clef"
QT_MOC_LITERAL(7, 61, 11), // "TrebleClef*"
QT_MOC_LITERAL(8, 73, 9), // "MusicNote"
QT_MOC_LITERAL(9, 83, 11), // "NoteUnknown"
QT_MOC_LITERAL(10, 95, 5), // "NoteC"
QT_MOC_LITERAL(11, 101, 5), // "NoteD"
QT_MOC_LITERAL(12, 107, 5), // "NoteE"
QT_MOC_LITERAL(13, 113, 5), // "NoteF"
QT_MOC_LITERAL(14, 119, 5), // "NoteG"
QT_MOC_LITERAL(15, 125, 5), // "NoteA"
QT_MOC_LITERAL(16, 131, 5) // "NoteB"

    },
    "Notation\0noteScaleChanged\0\0scale\0"
    "setNoteScale\0noteScale\0Clef\0TrebleClef*\0"
    "MusicNote\0NoteUnknown\0NoteC\0NoteD\0"
    "NoteE\0NoteF\0NoteG\0NoteA\0NoteB"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Notation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       2,   30, // properties
       1,   38, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QReal,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QReal,    3,

 // properties: name, type, flags
       5, QMetaType::QReal, 0x00495103,
       6, 0x80000000 | 7, 0x0009510b,

 // properties: notify_signal_id
       0,
       0,

 // enums: name, flags, count, data
       8, 0x0,    8,   42,

 // enum data: key, value
       9, uint(Notation::NoteUnknown),
      10, uint(Notation::NoteC),
      11, uint(Notation::NoteD),
      12, uint(Notation::NoteE),
      13, uint(Notation::NoteF),
      14, uint(Notation::NoteG),
      15, uint(Notation::NoteA),
      16, uint(Notation::NoteB),

       0        // eod
};

void Notation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Notation *_t = static_cast<Notation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->noteScaleChanged((*reinterpret_cast< const qreal(*)>(_a[1]))); break;
        case 1: _t->setNoteScale((*reinterpret_cast< const qreal(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Notation::*_t)(const qreal & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Notation::noteScaleChanged)) {
                *result = 0;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TrebleClef* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Notation *_t = static_cast<Notation *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->noteScale(); break;
        case 1: *reinterpret_cast< TrebleClef**>(_v) = _t->noteClef(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Notation *_t = static_cast<Notation *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setNoteScale(*reinterpret_cast< qreal*>(_v)); break;
        case 1: _t->setClef(*reinterpret_cast< TrebleClef**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject Notation::staticMetaObject = {
    { &QQuickPaintedItem::staticMetaObject, qt_meta_stringdata_Notation.data,
      qt_meta_data_Notation,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Notation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Notation::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Notation.stringdata0))
        return static_cast<void*>(const_cast< Notation*>(this));
    return QQuickPaintedItem::qt_metacast(_clname);
}

int Notation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickPaintedItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Notation::noteScaleChanged(const qreal & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
