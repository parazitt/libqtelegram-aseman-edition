// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "messageschatfull.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"
#include "../coretypes.h"

#include <QDataStream>

MessagesChatFull::MessagesChatFull(MessagesChatFullClassType classType, InboundPkt *in) :
    m_classType(classType)
{
    if(in) fetch(in);
}

MessagesChatFull::MessagesChatFull(InboundPkt *in) :
    m_classType(typeMessagesChatFull)
{
    fetch(in);
}

MessagesChatFull::MessagesChatFull(const Null &null) :
    TelegramTypeObject(null),
    m_classType(typeMessagesChatFull)
{
}

MessagesChatFull::~MessagesChatFull() {
}

void MessagesChatFull::setChats(const QList<Chat> &chats) {
    m_chats = chats;
}

QList<Chat> MessagesChatFull::chats() const {
    return m_chats;
}

void MessagesChatFull::setFullChat(const ChatFull &fullChat) {
    m_fullChat = fullChat;
}

ChatFull MessagesChatFull::fullChat() const {
    return m_fullChat;
}

void MessagesChatFull::setUsers(const QList<User> &users) {
    m_users = users;
}

QList<User> MessagesChatFull::users() const {
    return m_users;
}

bool MessagesChatFull::operator ==(const MessagesChatFull &b) const {
    return m_classType == b.m_classType &&
           m_chats == b.m_chats &&
           m_fullChat == b.m_fullChat &&
           m_users == b.m_users;
}

void MessagesChatFull::setClassType(MessagesChatFull::MessagesChatFullClassType classType) {
    m_classType = classType;
}

MessagesChatFull::MessagesChatFullClassType MessagesChatFull::classType() const {
    return m_classType;
}

bool MessagesChatFull::fetch(InboundPkt *in) {
    LQTG_FETCH_LOG;
    int x = in->fetchInt();
    switch(x) {
    case typeMessagesChatFull: {
        m_fullChat.fetch(in);
        if(in->fetchInt() != (qint32)CoreTypes::typeVector) return false;
        qint32 m_chats_length = in->fetchInt();
        m_chats.clear();
        for (qint32 i = 0; i < m_chats_length; i++) {
            Chat type;
            type.fetch(in);
            m_chats.append(type);
        }
        if(in->fetchInt() != (qint32)CoreTypes::typeVector) return false;
        qint32 m_users_length = in->fetchInt();
        m_users.clear();
        for (qint32 i = 0; i < m_users_length; i++) {
            User type;
            type.fetch(in);
            m_users.append(type);
        }
        m_classType = static_cast<MessagesChatFullClassType>(x);
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool MessagesChatFull::push(OutboundPkt *out) const {
    out->appendInt(m_classType);
    switch(m_classType) {
    case typeMessagesChatFull: {
        m_fullChat.push(out);
        out->appendInt(CoreTypes::typeVector);
        out->appendInt(m_chats.count());
        for (qint32 i = 0; i < m_chats.count(); i++) {
            m_chats[i].push(out);
        }
        out->appendInt(CoreTypes::typeVector);
        out->appendInt(m_users.count());
        for (qint32 i = 0; i < m_users.count(); i++) {
            m_users[i].push(out);
        }
        return true;
    }
        break;
    
    default:
        return false;
    }
}

QMap<QString, QVariant> MessagesChatFull::toMap() const {
    QMap<QString, QVariant> result;
    switch(static_cast<int>(m_classType)) {
    case typeMessagesChatFull: {
        result["classType"] = "MessagesChatFull::typeMessagesChatFull";
        result["fullChat"] = m_fullChat.toMap();
        QList<QVariant> _chats;
        Q_FOREACH(const Chat &m__type, m_chats)
            _chats << m__type.toMap();
        result["chats"] = _chats;
        QList<QVariant> _users;
        Q_FOREACH(const User &m__type, m_users)
            _users << m__type.toMap();
        result["users"] = _users;
        return result;
    }
        break;
    
    default:
        return result;
    }
}

MessagesChatFull MessagesChatFull::fromMap(const QMap<QString, QVariant> &map) {
    MessagesChatFull result;
    if(map.value("classType").toString() == "MessagesChatFull::typeMessagesChatFull") {
        result.setClassType(typeMessagesChatFull);
        result.setFullChat( ChatFull::fromMap(map.value("fullChat").toMap()) );
        QList<QVariant> map_chats = map["chats"].toList();
        QList<Chat> _chats;
        Q_FOREACH(const QVariant &var, map_chats)
            _chats << Chat::fromMap(var.toMap());
        result.setChats(_chats);
        QList<QVariant> map_users = map["users"].toList();
        QList<User> _users;
        Q_FOREACH(const QVariant &var, map_users)
            _users << User::fromMap(var.toMap());
        result.setUsers(_users);
        return result;
    }
    return result;
}

QByteArray MessagesChatFull::getHash(QCryptographicHash::Algorithm alg) const {
    QByteArray data;
    QDataStream str(&data, QIODevice::WriteOnly);
    str << *this;
    return QCryptographicHash::hash(data, alg);
}

QDataStream &operator<<(QDataStream &stream, const MessagesChatFull &item) {
    stream << static_cast<uint>(item.classType());
    switch(item.classType()) {
    case MessagesChatFull::typeMessagesChatFull:
        stream << item.fullChat();
        stream << item.chats();
        stream << item.users();
        break;
    }
    return stream;
}

QDataStream &operator>>(QDataStream &stream, MessagesChatFull &item) {
    uint type = 0;
    stream >> type;
    item.setClassType(static_cast<MessagesChatFull::MessagesChatFullClassType>(type));
    switch(type) {
    case MessagesChatFull::typeMessagesChatFull: {
        ChatFull m_full_chat;
        stream >> m_full_chat;
        item.setFullChat(m_full_chat);
        QList<Chat> m_chats;
        stream >> m_chats;
        item.setChats(m_chats);
        QList<User> m_users;
        stream >> m_users;
        item.setUsers(m_users);
    }
        break;
    }
    return stream;
}

