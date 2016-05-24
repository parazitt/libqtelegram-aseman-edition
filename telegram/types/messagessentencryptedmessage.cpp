// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "messagessentencryptedmessage.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"
#include "../coretypes.h"

#include <QDataStream>

MessagesSentEncryptedMessage::MessagesSentEncryptedMessage(MessagesSentEncryptedMessageClassType classType, InboundPkt *in) :
    m_date(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

MessagesSentEncryptedMessage::MessagesSentEncryptedMessage(InboundPkt *in) :
    m_date(0),
    m_classType(typeMessagesSentEncryptedMessage)
{
    fetch(in);
}

MessagesSentEncryptedMessage::MessagesSentEncryptedMessage(const Null &null) :
    TelegramTypeObject(null),
    m_date(0),
    m_classType(typeMessagesSentEncryptedMessage)
{
}

MessagesSentEncryptedMessage::~MessagesSentEncryptedMessage() {
}

void MessagesSentEncryptedMessage::setDate(qint32 date) {
    m_date = date;
}

qint32 MessagesSentEncryptedMessage::date() const {
    return m_date;
}

void MessagesSentEncryptedMessage::setFile(const EncryptedFile &file) {
    m_file = file;
}

EncryptedFile MessagesSentEncryptedMessage::file() const {
    return m_file;
}

bool MessagesSentEncryptedMessage::operator ==(const MessagesSentEncryptedMessage &b) const {
    return m_classType == b.m_classType &&
           m_date == b.m_date &&
           m_file == b.m_file;
}

void MessagesSentEncryptedMessage::setClassType(MessagesSentEncryptedMessage::MessagesSentEncryptedMessageClassType classType) {
    m_classType = classType;
}

MessagesSentEncryptedMessage::MessagesSentEncryptedMessageClassType MessagesSentEncryptedMessage::classType() const {
    return m_classType;
}

bool MessagesSentEncryptedMessage::fetch(InboundPkt *in) {
    LQTG_FETCH_LOG;
    int x = in->fetchInt();
    switch(x) {
    case typeMessagesSentEncryptedMessage: {
        m_date = in->fetchInt();
        m_classType = static_cast<MessagesSentEncryptedMessageClassType>(x);
        return true;
    }
        break;
    
    case typeMessagesSentEncryptedFile: {
        m_date = in->fetchInt();
        m_file.fetch(in);
        m_classType = static_cast<MessagesSentEncryptedMessageClassType>(x);
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool MessagesSentEncryptedMessage::push(OutboundPkt *out) const {
    out->appendInt(m_classType);
    switch(m_classType) {
    case typeMessagesSentEncryptedMessage: {
        out->appendInt(m_date);
        return true;
    }
        break;
    
    case typeMessagesSentEncryptedFile: {
        out->appendInt(m_date);
        m_file.push(out);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

QMap<QString, QVariant> MessagesSentEncryptedMessage::toMap() const {
    QMap<QString, QVariant> result;
    switch(static_cast<int>(m_classType)) {
    case typeMessagesSentEncryptedMessage: {
        result["classType"] = "MessagesSentEncryptedMessage::typeMessagesSentEncryptedMessage";
        result["date"] = QVariant::fromValue<qint32>(date());
        return result;
    }
        break;
    
    case typeMessagesSentEncryptedFile: {
        result["classType"] = "MessagesSentEncryptedMessage::typeMessagesSentEncryptedFile";
        result["date"] = QVariant::fromValue<qint32>(date());
        result["file"] = m_file.toMap();
        return result;
    }
        break;
    
    default:
        return result;
    }
}

MessagesSentEncryptedMessage MessagesSentEncryptedMessage::fromMap(const QMap<QString, QVariant> &map) {
    MessagesSentEncryptedMessage result;
    if(map.value("classType").toString() == "MessagesSentEncryptedMessage::typeMessagesSentEncryptedMessage") {
        result.setClassType(typeMessagesSentEncryptedMessage);
        result.setDate( map.value("date").value<qint32>() );
        return result;
    }
    if(map.value("classType").toString() == "MessagesSentEncryptedMessage::typeMessagesSentEncryptedFile") {
        result.setClassType(typeMessagesSentEncryptedFile);
        result.setDate( map.value("date").value<qint32>() );
        result.setFile( EncryptedFile::fromMap(map.value("file").toMap()) );
        return result;
    }
    return result;
}

QByteArray MessagesSentEncryptedMessage::getHash(QCryptographicHash::Algorithm alg) const {
    QByteArray data;
    QDataStream str(&data, QIODevice::WriteOnly);
    str << *this;
    return QCryptographicHash::hash(data, alg);
}

QDataStream &operator<<(QDataStream &stream, const MessagesSentEncryptedMessage &item) {
    stream << static_cast<uint>(item.classType());
    switch(item.classType()) {
    case MessagesSentEncryptedMessage::typeMessagesSentEncryptedMessage:
        stream << item.date();
        break;
    case MessagesSentEncryptedMessage::typeMessagesSentEncryptedFile:
        stream << item.date();
        stream << item.file();
        break;
    }
    return stream;
}

QDataStream &operator>>(QDataStream &stream, MessagesSentEncryptedMessage &item) {
    uint type = 0;
    stream >> type;
    item.setClassType(static_cast<MessagesSentEncryptedMessage::MessagesSentEncryptedMessageClassType>(type));
    switch(type) {
    case MessagesSentEncryptedMessage::typeMessagesSentEncryptedMessage: {
        qint32 m_date;
        stream >> m_date;
        item.setDate(m_date);
    }
        break;
    case MessagesSentEncryptedMessage::typeMessagesSentEncryptedFile: {
        qint32 m_date;
        stream >> m_date;
        item.setDate(m_date);
        EncryptedFile m_file;
        stream >> m_file;
        item.setFile(m_file);
    }
        break;
    }
    return stream;
}

