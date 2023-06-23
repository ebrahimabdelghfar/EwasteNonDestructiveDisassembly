/****************************************************************************
** Meta object code from reading C++ file 'handeye_context_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "include/moveit/handeye_calibration_rviz_plugin/handeye_context_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'handeye_context_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_moveit_rviz_plugin__TFFrameNameComboBox_t {
    QByteArrayData data[1];
    char stringdata0[40];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_moveit_rviz_plugin__TFFrameNameComboBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_moveit_rviz_plugin__TFFrameNameComboBox_t qt_meta_stringdata_moveit_rviz_plugin__TFFrameNameComboBox = {
    {
QT_MOC_LITERAL(0, 0, 39) // "moveit_rviz_plugin::TFFrameNa..."

    },
    "moveit_rviz_plugin::TFFrameNameComboBox"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_moveit_rviz_plugin__TFFrameNameComboBox[] = {

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

void moveit_rviz_plugin::TFFrameNameComboBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject moveit_rviz_plugin::TFFrameNameComboBox::staticMetaObject = { {
    &QComboBox::staticMetaObject,
    qt_meta_stringdata_moveit_rviz_plugin__TFFrameNameComboBox.data,
    qt_meta_data_moveit_rviz_plugin__TFFrameNameComboBox,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *moveit_rviz_plugin::TFFrameNameComboBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *moveit_rviz_plugin::TFFrameNameComboBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_moveit_rviz_plugin__TFFrameNameComboBox.stringdata0))
        return static_cast<void*>(this);
    return QComboBox::qt_metacast(_clname);
}

int moveit_rviz_plugin::TFFrameNameComboBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_moveit_rviz_plugin__SliderWidget_t {
    QByteArrayData data[6];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_moveit_rviz_plugin__SliderWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_moveit_rviz_plugin__SliderWidget_t qt_meta_stringdata_moveit_rviz_plugin__SliderWidget = {
    {
QT_MOC_LITERAL(0, 0, 32), // "moveit_rviz_plugin::SliderWidget"
QT_MOC_LITERAL(1, 33, 12), // "valueChanged"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 5), // "value"
QT_MOC_LITERAL(4, 53, 11), // "changeValue"
QT_MOC_LITERAL(5, 65, 12) // "changeSlider"

    },
    "moveit_rviz_plugin::SliderWidget\0"
    "valueChanged\0\0value\0changeValue\0"
    "changeSlider"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_moveit_rviz_plugin__SliderWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   32,    2, 0x08 /* Private */,
       5,    0,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void moveit_rviz_plugin::SliderWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SliderWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->changeValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changeSlider(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SliderWidget::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SliderWidget::valueChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject moveit_rviz_plugin::SliderWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_moveit_rviz_plugin__SliderWidget.data,
    qt_meta_data_moveit_rviz_plugin__SliderWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *moveit_rviz_plugin::SliderWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *moveit_rviz_plugin::SliderWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_moveit_rviz_plugin__SliderWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int moveit_rviz_plugin::SliderWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void moveit_rviz_plugin::SliderWidget::valueChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_moveit_rviz_plugin__ContextTabWidget_t {
    QByteArrayData data[24];
    char stringdata0[313];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_moveit_rviz_plugin__ContextTabWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_moveit_rviz_plugin__ContextTabWidget_t qt_meta_stringdata_moveit_rviz_plugin__ContextTabWidget = {
    {
QT_MOC_LITERAL(0, 0, 36), // "moveit_rviz_plugin::ContextTa..."
QT_MOC_LITERAL(1, 37, 22), // "sensorMountTypeChanged"
QT_MOC_LITERAL(2, 60, 0), // ""
QT_MOC_LITERAL(3, 61, 5), // "index"
QT_MOC_LITERAL(4, 67, 16), // "frameNameChanged"
QT_MOC_LITERAL(5, 84, 33), // "std::map<std::string,std::str..."
QT_MOC_LITERAL(6, 118, 5), // "names"
QT_MOC_LITERAL(7, 124, 13), // "setCameraInfo"
QT_MOC_LITERAL(8, 138, 23), // "sensor_msgs::CameraInfo"
QT_MOC_LITERAL(9, 162, 11), // "camera_info"
QT_MOC_LITERAL(10, 174, 15), // "setOpticalFrame"
QT_MOC_LITERAL(11, 190, 11), // "std::string"
QT_MOC_LITERAL(12, 202, 8), // "frame_id"
QT_MOC_LITERAL(13, 211, 16), // "updateCameraPose"
QT_MOC_LITERAL(14, 228, 2), // "tx"
QT_MOC_LITERAL(15, 231, 2), // "ty"
QT_MOC_LITERAL(16, 234, 2), // "tz"
QT_MOC_LITERAL(17, 237, 2), // "rx"
QT_MOC_LITERAL(18, 240, 2), // "ry"
QT_MOC_LITERAL(19, 243, 2), // "rz"
QT_MOC_LITERAL(20, 246, 21), // "updateSensorMountType"
QT_MOC_LITERAL(21, 268, 15), // "updateFrameName"
QT_MOC_LITERAL(22, 284, 22), // "updateCameraMarkerPose"
QT_MOC_LITERAL(23, 307, 5) // "value"

    },
    "moveit_rviz_plugin::ContextTabWidget\0"
    "sensorMountTypeChanged\0\0index\0"
    "frameNameChanged\0std::map<std::string,std::string>\0"
    "names\0setCameraInfo\0sensor_msgs::CameraInfo\0"
    "camera_info\0setOpticalFrame\0std::string\0"
    "frame_id\0updateCameraPose\0tx\0ty\0tz\0"
    "rx\0ry\0rz\0updateSensorMountType\0"
    "updateFrameName\0updateCameraMarkerPose\0"
    "value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_moveit_rviz_plugin__ContextTabWidget[] = {

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
       4,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   60,    2, 0x0a /* Public */,
      10,    1,   63,    2, 0x0a /* Public */,
      13,    6,   66,    2, 0x0a /* Public */,
      20,    1,   79,    2, 0x08 /* Private */,
      21,    1,   82,    2, 0x08 /* Private */,
      22,    1,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,   14,   15,   16,   17,   18,   19,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Double,   23,

       0        // eod
};

void moveit_rviz_plugin::ContextTabWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ContextTabWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sensorMountTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->frameNameChanged((*reinterpret_cast< std::map<std::string,std::string>(*)>(_a[1]))); break;
        case 2: _t->setCameraInfo((*reinterpret_cast< sensor_msgs::CameraInfo(*)>(_a[1]))); break;
        case 3: _t->setOpticalFrame((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 4: _t->updateCameraPose((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6]))); break;
        case 5: _t->updateSensorMountType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->updateFrameName((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->updateCameraMarkerPose((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< sensor_msgs::CameraInfo >(); break;
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
            using _t = void (ContextTabWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ContextTabWidget::sensorMountTypeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ContextTabWidget::*)(std::map<std::string,std::string> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ContextTabWidget::frameNameChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject moveit_rviz_plugin::ContextTabWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_moveit_rviz_plugin__ContextTabWidget.data,
    qt_meta_data_moveit_rviz_plugin__ContextTabWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *moveit_rviz_plugin::ContextTabWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *moveit_rviz_plugin::ContextTabWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_moveit_rviz_plugin__ContextTabWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int moveit_rviz_plugin::ContextTabWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void moveit_rviz_plugin::ContextTabWidget::sensorMountTypeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void moveit_rviz_plugin::ContextTabWidget::frameNameChanged(std::map<std::string,std::string> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
