/****************************************************************************
** Meta object code from reading C++ file 'testing_view.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../app/view/testing_view.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testing_view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_s21__TestingView_t {
    uint offsetsAndSizes[18];
    char stringdata0[17];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[19];
    char stringdata4[20];
    char stringdata5[21];
    char stringdata6[22];
    char stringdata7[15];
    char stringdata8[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_s21__TestingView_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_s21__TestingView_t qt_meta_stringdata_s21__TestingView = {
    {
        QT_MOC_LITERAL(0, 16),  // "s21::TestingView"
        QT_MOC_LITERAL(17, 21),  // "onDownloadTestClicked"
        QT_MOC_LITERAL(39, 0),  // ""
        QT_MOC_LITERAL(40, 18),  // "onStartTestClicked"
        QT_MOC_LITERAL(59, 19),  // "onCleanPaintClicked"
        QT_MOC_LITERAL(79, 20),  // "onDownloadImgClicked"
        QT_MOC_LITERAL(100, 21),  // "onStartTestIMGClicked"
        QT_MOC_LITERAL(122, 14),  // "onResetClicked"
        QT_MOC_LITERAL(137, 19)   // "onExperimentClicked"
    },
    "s21::TestingView",
    "onDownloadTestClicked",
    "",
    "onStartTestClicked",
    "onCleanPaintClicked",
    "onDownloadImgClicked",
    "onStartTestIMGClicked",
    "onResetClicked",
    "onExperimentClicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_s21__TestingView[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    0,   62,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject s21::TestingView::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_s21__TestingView.offsetsAndSizes,
    qt_meta_data_s21__TestingView,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_s21__TestingView_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TestingView, std::true_type>,
        // method 'onDownloadTestClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onStartTestClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCleanPaintClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDownloadImgClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onStartTestIMGClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onResetClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onExperimentClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void s21::TestingView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TestingView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onDownloadTestClicked(); break;
        case 1: _t->onStartTestClicked(); break;
        case 2: _t->onCleanPaintClicked(); break;
        case 3: _t->onDownloadImgClicked(); break;
        case 4: _t->onStartTestIMGClicked(); break;
        case 5: _t->onResetClicked(); break;
        case 6: _t->onExperimentClicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *s21::TestingView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *s21::TestingView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_s21__TestingView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int s21::TestingView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
