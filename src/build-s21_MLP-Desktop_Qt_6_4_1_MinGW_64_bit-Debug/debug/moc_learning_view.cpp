/****************************************************************************
** Meta object code from reading C++ file 'learning_view.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../app/view/learning_view.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'learning_view.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_s21__LearningView_t {
    uint offsetsAndSizes[18];
    char stringdata0[18];
    char stringdata1[23];
    char stringdata2[1];
    char stringdata3[23];
    char stringdata4[24];
    char stringdata5[20];
    char stringdata6[23];
    char stringdata7[22];
    char stringdata8[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_s21__LearningView_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_s21__LearningView_t qt_meta_stringdata_s21__LearningView = {
    {
        QT_MOC_LITERAL(0, 17),  // "s21::LearningView"
        QT_MOC_LITERAL(18, 22),  // "onRandomWeightsToggled"
        QT_MOC_LITERAL(41, 0),  // ""
        QT_MOC_LITERAL(42, 22),  // "onDownloadTrainClicked"
        QT_MOC_LITERAL(65, 23),  // "onDownloadWeightClicked"
        QT_MOC_LITERAL(89, 19),  // "onSaveWeightClicked"
        QT_MOC_LITERAL(109, 22),  // "onStartTrainingClicked"
        QT_MOC_LITERAL(132, 21),  // "onStartTestingClicked"
        QT_MOC_LITERAL(154, 14)   // "onResetClicked"
    },
    "s21::LearningView",
    "onRandomWeightsToggled",
    "",
    "onDownloadTrainClicked",
    "onDownloadWeightClicked",
    "onSaveWeightClicked",
    "onStartTrainingClicked",
    "onStartTestingClicked",
    "onResetClicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_s21__LearningView[] = {

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

Q_CONSTINIT const QMetaObject s21::LearningView::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_s21__LearningView.offsetsAndSizes,
    qt_meta_data_s21__LearningView,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_s21__LearningView_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<LearningView, std::true_type>,
        // method 'onRandomWeightsToggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDownloadTrainClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDownloadWeightClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSaveWeightClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onStartTrainingClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onStartTestingClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onResetClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void s21::LearningView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LearningView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onRandomWeightsToggled(); break;
        case 1: _t->onDownloadTrainClicked(); break;
        case 2: _t->onDownloadWeightClicked(); break;
        case 3: _t->onSaveWeightClicked(); break;
        case 4: _t->onStartTrainingClicked(); break;
        case 5: _t->onStartTestingClicked(); break;
        case 6: _t->onResetClicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *s21::LearningView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *s21::LearningView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_s21__LearningView.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int s21::LearningView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
