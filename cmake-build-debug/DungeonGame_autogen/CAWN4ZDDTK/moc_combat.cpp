/****************************************************************************
** Meta object code from reading C++ file 'combat.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../source/combat.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'combat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN11CombatLogicE_t {};
} // unnamed namespace

template <> constexpr inline auto CombatLogic::qt_create_metaobjectdata<qt_meta_tag_ZN11CombatLogicE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "CombatLogic",
        "playerhealthChanged",
        "",
        "newhp",
        "Character*",
        "target",
        "enemyhealthChanged",
        "combatEnded",
        "playerWon",
        "enablePlayerInput",
        "enabled",
        "updateAbilityUI",
        "currentActor",
        "isPlayerTurn",
        "handleAbility",
        "index",
        "caster"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'playerhealthChanged'
        QtMocHelpers::SignalData<void(int, Character *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 }, { 0x80000000 | 4, 5 },
        }}),
        // Signal 'enemyhealthChanged'
        QtMocHelpers::SignalData<void(int, Character *)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 }, { 0x80000000 | 4, 5 },
        }}),
        // Signal 'combatEnded'
        QtMocHelpers::SignalData<void(bool)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 8 },
        }}),
        // Signal 'enablePlayerInput'
        QtMocHelpers::SignalData<void(bool)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 10 },
        }}),
        // Signal 'updateAbilityUI'
        QtMocHelpers::SignalData<void(Character *, bool)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 4, 12 }, { QMetaType::Bool, 13 },
        }}),
        // Slot 'handleAbility'
        QtMocHelpers::SlotData<void(int, Character *)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 15 }, { 0x80000000 | 4, 16 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<CombatLogic, qt_meta_tag_ZN11CombatLogicE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject CombatLogic::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11CombatLogicE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11CombatLogicE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11CombatLogicE_t>.metaTypes,
    nullptr
} };

void CombatLogic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<CombatLogic *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->playerhealthChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Character*>>(_a[2]))); break;
        case 1: _t->enemyhealthChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Character*>>(_a[2]))); break;
        case 2: _t->combatEnded((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->enablePlayerInput((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->updateAbilityUI((*reinterpret_cast< std::add_pointer_t<Character*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 5: _t->handleAbility((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Character*>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (CombatLogic::*)(int , Character * )>(_a, &CombatLogic::playerhealthChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (CombatLogic::*)(int , Character * )>(_a, &CombatLogic::enemyhealthChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (CombatLogic::*)(bool )>(_a, &CombatLogic::combatEnded, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (CombatLogic::*)(bool )>(_a, &CombatLogic::enablePlayerInput, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (CombatLogic::*)(Character * , bool )>(_a, &CombatLogic::updateAbilityUI, 4))
            return;
    }
}

const QMetaObject *CombatLogic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CombatLogic::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11CombatLogicE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CombatLogic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void CombatLogic::playerhealthChanged(int _t1, Character * _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void CombatLogic::enemyhealthChanged(int _t1, Character * _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}

// SIGNAL 2
void CombatLogic::combatEnded(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void CombatLogic::enablePlayerInput(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void CombatLogic::updateAbilityUI(Character * _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1, _t2);
}
QT_WARNING_POP
