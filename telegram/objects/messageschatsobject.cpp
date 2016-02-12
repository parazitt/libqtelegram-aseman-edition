// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "messageschatsobject.h"

MessagesChatsObject::MessagesChatsObject(const MessagesChats &core, QObject *parent) :
    TelegramTypeQObject(parent),
    m_core(core)
{
}

MessagesChatsObject::MessagesChatsObject(QObject *parent) :
    TelegramTypeQObject(parent),
    m_core()
{
}

MessagesChatsObject::~MessagesChatsObject() {
}

void MessagesChatsObject::setChats(const QList<Chat> &chats) {
    if(m_core.chats() == chats) return;
    m_core.setChats(chats);
    Q_EMIT chatsChanged();
    Q_EMIT coreChanged();
}

QList<Chat> MessagesChatsObject::chats() const {
    return m_core.chats();
}

MessagesChatsObject &MessagesChatsObject::operator =(const MessagesChats &b) {
    if(m_core == b) return *this;
    m_core = b;

    Q_EMIT chatsChanged();
    Q_EMIT coreChanged();
    return *this;
}

bool MessagesChatsObject::operator ==(const MessagesChats &b) const {
    return m_core == b;
}

void MessagesChatsObject::setClassType(quint32 classType) {
    MessagesChats::MessagesChatsType result;
    switch(classType) {
    case TypeMessagesChats:
        result = MessagesChats::typeMessagesChats;
        break;
    default:
        result = MessagesChats::typeMessagesChats;
        break;
    }

    if(m_core.classType() == result) return;
    m_core.setClassType(result);
    Q_EMIT classTypeChanged();
    Q_EMIT coreChanged();
}

quint32 MessagesChatsObject::classType() const {
    int result;
    switch(static_cast<qint64>(m_core.classType())) {
    case MessagesChats::typeMessagesChats:
        result = TypeMessagesChats;
        break;
    default:
        result = TypeMessagesChats;
        break;
    }

    return result;
}

void MessagesChatsObject::setCore(const MessagesChats &core) {
    operator =(core);
}

MessagesChats MessagesChatsObject::core() const {
    return m_core;
}
