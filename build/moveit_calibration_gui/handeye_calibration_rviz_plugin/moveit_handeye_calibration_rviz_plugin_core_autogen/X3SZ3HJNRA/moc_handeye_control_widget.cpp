/****************************************************************************
** Meta object code from reading C++ file 'handeye_control_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "include/moveit/handeye_calibration_rviz_plugin/handeye_control_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'handeye_control_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_moveit_rviz_plugin__ProgressBarWidget_t {
    QByteArrayData data[1];
    char stringdata0[38];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_moveit_rviz_plugin__ProgressBarWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_moveit_rviz_plugin__ProgressBarWidget_t qt_meta_stringdata_moveit_rviz_plugin__ProgressBarWidget = {
    {
QT_MOC_LITERAL(0, 0, 37) // "moveit_rviz_plugin::ProgressB..."

    },
    "moveit_rviz_plugin::ProgressBarWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_moveit_rviz_plugin__ProgressBarWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void moveit_rviz_plugin::ProgressBarWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject moveit_rviz_plugin::ProgressBarWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_moveit_rviz_plugin__ProgressBarWidget.data,
    qt_meta_data_moveit_rviz_plugin__ProgressBarWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *moveit_rviz_plugin::ProgressBarWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *moveit_rviz_plugin::ProgressBarWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_moveit_rviz_plugin__ProgressBarWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int moveit_rviz_plugin::ProgressBarWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_moveit_rviz_plugin__ControlTabWidget_t {
    QByteArrayData data[34];
    char stringdata0[527];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_moveit_rviz_plugin__ControlTabWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_moveit_rviz_plugin__ControlTabWidget_t qt_meta_stringdata_moveit_rviz_plugin__ControlTabWidget = {
    {
QT_MOC_LITERAL(0, 0, 36), // "moveit_rviz_plugin::ControlTa..."
QT_MOC_LITERAL(1, 37, 16), // "sensorPoseUpdate"
QT_MOC_LITERAL(2, 54, 0), // ""
QT_MOC_LITERAL(3, 55, 1), // "x"
QT_MOC_LITERAL(4, 57, 1), // "y"
QT_MOC_LITERAL(5, 59, 1), // "z"
QT_MOC_LITERAL(6, 61, 2), // "rx"
QT_MOC_LITERAL(7, 64, 2), // "ry"
QT_MOC_LITERAL(8, 67, 2), // "rz"
QT_MOC_LITERAL(9, 70, 21), // "UpdateSensorMountType"
QT_MOC_LITERAL(10, 92, 5), // "index"
QT_MOC_LITERAL(11, 98, 16), // "updateFrameNames"
QT_MOC_LITERAL(12, 115, 33), // "std::map<std::string,std::str..."
QT_MOC_LITERAL(13, 149, 5), // "names"
QT_MOC_LITERAL(14, 155, 20), // "takeSampleBtnClicked"
QT_MOC_LITERAL(15, 176, 7), // "clicked"
QT_MOC_LITERAL(16, 184, 22), // "clearSamplesBtnClicked"
QT_MOC_LITERAL(17, 207, 15), // "solveBtnClicked"
QT_MOC_LITERAL(18, 223, 24), // "saveCameraPoseBtnClicked"
QT_MOC_LITERAL(19, 248, 21), // "loadSamplesBtnClicked"
QT_MOC_LITERAL(20, 270, 21), // "saveSamplesBtnClicked"
QT_MOC_LITERAL(21, 292, 24), // "planningGroupNameChanged"
QT_MOC_LITERAL(22, 317, 4), // "text"
QT_MOC_LITERAL(23, 322, 12), // "setGroupName"
QT_MOC_LITERAL(24, 335, 11), // "std::string"
QT_MOC_LITERAL(25, 347, 10), // "group_name"
QT_MOC_LITERAL(26, 358, 29), // "planningGroupNamespaceChanged"
QT_MOC_LITERAL(27, 388, 24), // "saveJointStateBtnClicked"
QT_MOC_LITERAL(28, 413, 24), // "loadJointStateBtnClicked"
QT_MOC_LITERAL(29, 438, 18), // "autoPlanBtnClicked"
QT_MOC_LITERAL(30, 457, 21), // "autoExecuteBtnClicked"
QT_MOC_LITERAL(31, 479, 18), // "autoSkipBtnClicked"
QT_MOC_LITERAL(32, 498, 12), // "planFinished"
QT_MOC_LITERAL(33, 511, 15) // "executeFinished"

    },
    "moveit_rviz_plugin::ControlTabWidget\0"
    "sensorPoseUpdate\0\0x\0y\0z\0rx\0ry\0rz\0"
    "UpdateSensorMountType\0index\0"
    "updateFrameNames\0std::map<std::string,std::string>\0"
    "names\0takeSampleBtnClicked\0clicked\0"
    "clearSamplesBtnClicked\0solveBtnClicked\0"
    "saveCameraPoseBtnClicked\0loadSamplesBtnClicked\0"
    "saveSamplesBtnClicked\0planningGroupNameChanged\0"
    "text\0setGroupName\0std::string\0group_name\0"
    "planningGroupNamespaceChanged\0"
    "saveJointStateBtnClicked\0"
    "loadJointStateBtnClicked\0autoPlanBtnClicked\0"
    "autoExecuteBtnClicked\0autoSkipBtnClicked\0"
    "planFinished\0executeFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_moveit_rviz_plugin__ControlTabWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    6,  109,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,  122,    2, 0x0a /* Public */,
      11,    1,  125,    2, 0x0a /* Public */,
      14,    1,  128,    2, 0x08 /* Private */,
      16,    1,  131,    2, 0x08 /* Private */,
      17,    1,  134,    2, 0x08 /* Private */,
      18,    1,  137,    2, 0x08 /* Private */,
      19,    1,  140,    2, 0x08 /* Private */,
      20,    1,  143,    2, 0x08 /* Private */,
      21,    1,  146,    2, 0x08 /* Private */,
      23,    1,  149,    2, 0x08 /* Private */,
      26,    0,  152,    2, 0x08 /* Private */,
      27,    1,  153,    2, 0x08 /* Private */,
      28,    1,  156,    2, 0x08 /* Private */,
      29,    1,  159,    2, 0x08 /* Private */,
      30,    1,  162,    2, 0x08 /* Private */,
      31,    1,  165,    2, 0x08 /* Private */,
      32,    0,  168,    2, 0x08 /* Private */,
      33,    0,  169,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    3,    4,    5,    6,    7,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void moveit_rviz_plugin::ControlTabWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ControlTabWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sensorPoseUpdate((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6]))); break;
        case 1: _t->UpdateSensorMountType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->updateFrameNames((*reinterpret_cast< std::map<std::string,std::string>(*)>(_a[1]))); break;
        case 3: _t->takeSampleBtnClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->clearSamplesBtnClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->solveBtnClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->saveCameraPoseBtnClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->loadSamplesBtnClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->saveSamplesBtnClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->planningGroupNameChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->setGroupName((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 11: _t->planningGroupNamespaceChanged(); break;
        case 12: _t->saveJointStateBtnClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->loadJointStateBtnClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->autoPlanBtnClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->autoExecuteBtnClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->autoSkipBtnClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->planFinished(); break;
        case 18: _t->executeFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< std::string >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ControlTabWidget::*)(double , double , double , double , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControlTabWidget::sensorPoseUpdate)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject moveit_rviz_plugin::ControlTabWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_moveit_rviz_plugin__ControlTabWidget.data,
    qt_meta_data_moveit_rviz_plugin__ControlTabWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *moveit_rviz_plugin::ControlTabWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *moveit_rviz_plugin::ControlTabWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_moveit_rviz_plugin__ControlTabWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int moveit_rviz_plugin::ControlTabWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void moveit_rviz_plugin::ControlTabWidget::sensorPoseUpdate(double _t1, double _t2, double _t3, double _t4, double _t5, double _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
