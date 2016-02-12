// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "inputaudioobject.h"

InputAudioObject::InputAudioObject(const InputAudio &core, QObject *parent) :
    TelegramTypeQObject(parent),
    m_core(core)
{
}

InputAudioObject::InputAudioObject(QObject *parent) :
    TelegramTypeQObject(parent),
    m_core()
{
}

InputAudioObject::~InputAudioObject() {
}

void InputAudioObject::setAccessHash(qint64 accessHash) {
    if(m_core.accessHash() == accessHash) return;
    m_core.setAccessHash(accessHash);
    Q_EMIT accessHashChanged();
    Q_EMIT coreChanged();
}

qint64 InputAudioObject::accessHash() const {
    return m_core.accessHash();
}

void InputAudioObject::setId(qint64 id) {
    if(m_core.id() == id) return;
    m_core.setId(id);
    Q_EMIT idChanged();
    Q_EMIT coreChanged();
}

qint64 InputAudioObject::id() const {
    return m_core.id();
}

InputAudioObject &InputAudioObject::operator =(const InputAudio &b) {
    if(m_core == b) return *this;
    m_core = b;

    Q_EMIT accessHashChanged();
    Q_EMIT idChanged();
    Q_EMIT coreChanged();
    return *this;
}

bool InputAudioObject::operator ==(const InputAudio &b) const {
    return m_core == b;
}

void InputAudioObject::setClassType(quint32 classType) {
    InputAudio::InputAudioType result;
    switch(classType) {
    case TypeInputAudioEmpty:
        result = InputAudio::typeInputAudioEmpty;
        break;
    case TypeInputAudio:
        result = InputAudio::typeInputAudio;
        break;
    default:
        result = InputAudio::typeInputAudioEmpty;
        break;
    }

    if(m_core.classType() == result) return;
    m_core.setClassType(result);
    Q_EMIT classTypeChanged();
    Q_EMIT coreChanged();
}

quint32 InputAudioObject::classType() const {
    int result;
    switch(static_cast<qint64>(m_core.classType())) {
    case InputAudio::typeInputAudioEmpty:
        result = TypeInputAudioEmpty;
        break;
    case InputAudio::typeInputAudio:
        result = TypeInputAudio;
        break;
    default:
        result = TypeInputAudioEmpty;
        break;
    }

    return result;
}

void InputAudioObject::setCore(const InputAudio &core) {
    operator =(core);
}

InputAudio InputAudioObject::core() const {
    return m_core;
}
