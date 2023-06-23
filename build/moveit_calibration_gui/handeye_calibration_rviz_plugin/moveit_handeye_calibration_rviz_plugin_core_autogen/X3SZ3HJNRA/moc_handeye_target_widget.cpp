/****************************************************************************
** Meta object code from reading C++ file 'handeye_target_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/Perception/moveit_calibration/moveit_calibration_gui/handeye_calibration_rviz_plugin/include/moveit/handeye_calibration_rviz_plugin/handeye_target_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'handeye_target_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_moveit_rviz_plugin__RosTopicComboBox_t {
    QByteArrayData data[1];
    char stringdata0[37];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_moveit_rviz_plugin__RosTopicComboBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_moveit_rviz_plugin__RosTopicComboBox_t qt_meta_stringdata_moveit_rviz_plugin__RosTopicComboBox = {
    {
QT_MOC_LITERAL(0, 0, 36) // "moveit_rviz_plugin::RosTopicC..."

    },
    "moveit_rviz_plugin::RosTopicComboBox"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_moveit_rviz_plugin__RosTopicComboBox[] = {

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

void moveit_rviz_plugin::RosTopicComboBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject moveit_rviz_plugin::RosTopicComboBox::staticMetaObject = { {
    &QComboBox::staticMetaObject,
    qt_meta_stringdata_moveit_rviz_plugin__RosTopicComboBox.data,
    qt_meta_data_moveit_rviz_plugin__RosTopicComboBox,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *moveit_rviz_plugin::RosTopicComboBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *moveit_rviz_plugin::RosTopicComboBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_moveit_rviz_plugin__RosTopicComboBox.stringdata0))
        return static_cast<void*>(this);
    return QComboBox::qt_metacast(_clname);
}

int moveit_rviz_plugin::RosTopicComboBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_moveit_rviz_plugin__TargetTabWidget_t {
    QByteArrayData data[18];
    char stringdata0[317];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_moveit_rviz_plugin__TargetTabWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_moveit_rviz_plugin__TargetTabWidget_t qt_meta_stringdata_moveit_rviz_plugin__TargetTabWidget = {
    {
QT_MOC_LITERAL(0, 0, 35), // "moveit_rviz_plugin::TargetTab..."
QT_MOC_LITERAL(1, 36, 17), // "cameraInfoChanged"
QT_MOC_LITERAL(2, 54, 0), // ""
QT_MOC_LITERAL(3, 55, 23), // "sensor_msgs::CameraInfo"
QT_MOC_LITERAL(4, 79, 3), // "msg"
QT_MOC_LITERAL(5, 83, 19), // "opticalFrameChanged"
QT_MOC_LITERAL(6, 103, 11), // "std::string"
QT_MOC_LITERAL(7, 115, 8), // "frame_id"
QT_MOC_LITERAL(8, 124, 25), // "targetTypeComboboxChanged"
QT_MOC_LITERAL(9, 150, 4), // "text"
QT_MOC_LITERAL(10, 155, 29), // "loadInputWidgetsForTargetType"
QT_MOC_LITERAL(11, 185, 11), // "plugin_name"
QT_MOC_LITERAL(12, 197, 27), // "createTargetImageBtnClicked"
QT_MOC_LITERAL(13, 225, 7), // "clicked"
QT_MOC_LITERAL(14, 233, 25), // "saveTargetImageBtnClicked"
QT_MOC_LITERAL(15, 259, 25), // "imageTopicComboboxChanged"
QT_MOC_LITERAL(16, 285, 5), // "topic"
QT_MOC_LITERAL(17, 291, 25) // "cameraInfoComboBoxChanged"

    },
    "moveit_rviz_plugin::TargetTabWidget\0"
    "cameraInfoChanged\0\0sensor_msgs::CameraInfo\0"
    "msg\0opticalFrameChanged\0std::string\0"
    "frame_id\0targetTypeComboboxChanged\0"
    "text\0loadInputWidgetsForTargetType\0"
    "plugin_name\0createTargetImageBtnClicked\0"
    "clicked\0saveTargetImageBtnClicked\0"
    "imageTopicComboboxChanged\0topic\0"
    "cameraInfoComboBoxChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_moveit_rviz_plugin__TargetTabWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   60,    2, 0x08 /* Private */,
      10,    1,   63,    2, 0x08 /* Private */,
      12,    1,   66,    2, 0x08 /* Private */,
      14,    1,   69,    2, 0x08 /* Private */,
      15,    1,   72,    2, 0x08 /* Private */,
      17,    1,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Bool, 0x80000000 | 6,   11,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   16,

       0        // eod
};

void moveit_rviz_plugin::TargetTabWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TargetTabWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cameraInfoChanged((*reinterpret_cast< sensor_msgs::CameraInfo(*)>(_a[1]))); break;
        case 1: _t->opticalFrameChanged((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 2: _t->targetTypeComboboxChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: { bool _r = _t->loadInputWidgetsForTargetType((*reinterpret_cast< const std::string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->createTargetImageBtnClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->saveTargetImageBtnClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->imageTopicComboboxChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->cameraInfoComboBoxChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< sensor_msgs::CameraInfo >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< std::string >(); break;
            }
            break;
        case 3:
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
            using _t = void (TargetTabWidget::*)(sensor_msgs::CameraInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TargetTabWidget::cameraInfoChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TargetTabWidget::*)(const std::string & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TargetTabWidget::opticalFrameChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject moveit_rviz_plugin::TargetTabWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_moveit_rviz_plugin__TargetTabWidget.data,
    qt_meta_data_moveit_rviz_plugin__TargetTabWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *moveit_rviz_plugin::TargetTabWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *moveit_rviz_plugin::TargetTabWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_moveit_rviz_plugin__TargetTabWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int moveit_rviz_plugin::TargetTabWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void moveit_rviz_plugin::TargetTabWidget::cameraInfoChanged(sensor_msgs::CameraInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void moveit_rviz_plugin::TargetTabWidget::opticalFrameChanged(const std::string & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
