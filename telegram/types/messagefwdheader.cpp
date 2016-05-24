// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "messagefwdheader.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"
#include "../coretypes.h"

#include <QDataStream>

MessageFwdHeader::MessageFwdHeader(MessageFwdHeaderClassType classType, InboundPkt *in) :
    m_channelId(0),
    m_channelPost(0),
    m_date(0),
    m_flags(0),
    m_fromId(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

MessageFwdHeader::MessageFwdHeader(InboundPkt *in) :
    m_channelId(0),
    m_channelPost(0),
    m_date(0),
    m_flags(0),
    m_fromId(0),
    m_classType(typeMessageFwdHeader)
{
    fetch(in);
}

MessageFwdHeader::MessageFwdHeader(const Null &null) :
    TelegramTypeObject(null),
    m_channelId(0),
    m_channelPost(0),
    m_date(0),
    m_flags(0),
    m_fromId(0),
    m_classType(typeMessageFwdHeader)
{
}

MessageFwdHeader::~MessageFwdHeader() {
}

void MessageFwdHeader::setChannelId(qint32 channelId) {
    m_channelId = channelId;
}

qint32 MessageFwdHeader::channelId() const {
    return m_channelId;
}

void MessageFwdHeader::setChannelPost(qint32 channelPost) {
    m_channelPost = channelPost;
}

qint32 MessageFwdHeader::channelPost() const {
    return m_channelPost;
}

void MessageFwdHeader::setDate(qint32 date) {
    m_date = date;
}

qint32 MessageFwdHeader::date() const {
    return m_date;
}

void MessageFwdHeader::setFlags(qint32 flags) {
    m_flags = flags;
}

qint32 MessageFwdHeader::flags() const {
    return m_flags;
}

void MessageFwdHeader::setFromId(qint32 fromId) {
    m_fromId = fromId;
}

qint32 MessageFwdHeader::fromId() const {
    return m_fromId;
}

bool MessageFwdHeader::operator ==(const MessageFwdHeader &b) const {
    return m_classType == b.m_classType &&
           m_channelId == b.m_channelId &&
           m_channelPost == b.m_channelPost &&
           m_date == b.m_date &&
           m_flags == b.m_flags &&
           m_fromId == b.m_fromId;
}

void MessageFwdHeader::setClassType(MessageFwdHeader::MessageFwdHeaderClassType classType) {
    m_classType = classType;
}

MessageFwdHeader::MessageFwdHeaderClassType MessageFwdHeader::classType() const {
    return m_classType;
}

bool MessageFwdHeader::fetch(InboundPkt *in) {
    LQTG_FETCH_LOG;
    int x = in->fetchInt();
    switch(x) {
    case typeMessageFwdHeader: {
        m_flags = in->fetchInt();
        if(m_flags & 1<<0) {
            m_fromId = in->fetchInt();
        }
        m_date = in->fetchInt();
        if(m_flags & 1<<1) {
            m_channelId = in->fetchInt();
        }
        if(m_flags & 1<<2) {
            m_channelPost = in->fetchInt();
        }
        m_classType = static_cast<MessageFwdHeaderClassType>(x);
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool MessageFwdHeader::push(OutboundPkt *out) const {
    out->appendInt(m_classType);
    switch(m_classType) {
    case typeMessageFwdHeader: {
        out->appendInt(m_flags);
        out->appendInt(m_fromId);
        out->appendInt(m_date);
        out->appendInt(m_channelId);
        out->appendInt(m_channelPost);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

QMap<QString, QVariant> MessageFwdHeader::toMap() const {
    QMap<QString, QVariant> result;
    switch(static_cast<int>(m_classType)) {
    case typeMessageFwdHeader: {
        result["classType"] = "MessageFwdHeader::typeMessageFwdHeader";
        result["flags"] = QVariant::fromValue<qint32>(flags());
        result["fromId"] = QVariant::fromValue<qint32>(fromId());
        result["date"] = QVariant::fromValue<qint32>(date());
        result["channelId"] = QVariant::fromValue<qint32>(channelId());
        result["channelPost"] = QVariant::fromValue<qint32>(channelPost());
        return result;
    }
        break;
    
    default:
        return result;
    }
}

MessageFwdHeader MessageFwdHeader::fromMap(const QMap<QString, QVariant> &map) {
    MessageFwdHeader result;
    if(map.value("classType").toString() == "MessageFwdHeader::typeMessageFwdHeader") {
        result.setClassType(typeMessageFwdHeader);
        result.setFromId( map.value("fromId").value<qint32>() );
        result.setDate( map.value("date").value<qint32>() );
        result.setChannelId( map.value("channelId").value<qint32>() );
        result.setChannelPost( map.value("channelPost").value<qint32>() );
        return result;
    }
    return result;
}

QByteArray MessageFwdHeader::getHash(QCryptographicHash::Algorithm alg) const {
    QByteArray data;
    QDataStream str(&data, QIODevice::WriteOnly);
    str << *this;
    return QCryptographicHash::hash(data, alg);
}

QDataStream &operator<<(QDataStream &stream, const MessageFwdHeader &item) {
    stream << static_cast<uint>(item.classType());
    switch(item.classType()) {
    case MessageFwdHeader::typeMessageFwdHeader:
        stream << item.flags();
        stream << item.fromId();
        stream << item.date();
        stream << item.channelId();
        stream << item.channelPost();
        break;
    }
    return stream;
}

QDataStream &operator>>(QDataStream &stream, MessageFwdHeader &item) {
    uint type = 0;
    stream >> type;
    item.setClassType(static_cast<MessageFwdHeader::MessageFwdHeaderClassType>(type));
    switch(type) {
    case MessageFwdHeader::typeMessageFwdHeader: {
        qint32 m_flags;
        stream >> m_flags;
        item.setFlags(m_flags);
        qint32 m_from_id;
        stream >> m_from_id;
        item.setFromId(m_from_id);
        qint32 m_date;
        stream >> m_date;
        item.setDate(m_date);
        qint32 m_channel_id;
        stream >> m_channel_id;
        item.setChannelId(m_channel_id);
        qint32 m_channel_post;
        stream >> m_channel_post;
        item.setChannelPost(m_channel_post);
    }
        break;
    }
    return stream;
}

