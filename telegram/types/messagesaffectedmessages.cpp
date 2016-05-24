// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "messagesaffectedmessages.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"
#include "../coretypes.h"

#include <QDataStream>

MessagesAffectedMessages::MessagesAffectedMessages(MessagesAffectedMessagesClassType classType, InboundPkt *in) :
    m_pts(0),
    m_ptsCount(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

MessagesAffectedMessages::MessagesAffectedMessages(InboundPkt *in) :
    m_pts(0),
    m_ptsCount(0),
    m_classType(typeMessagesAffectedMessages)
{
    fetch(in);
}

MessagesAffectedMessages::MessagesAffectedMessages(const Null &null) :
    TelegramTypeObject(null),
    m_pts(0),
    m_ptsCount(0),
    m_classType(typeMessagesAffectedMessages)
{
}

MessagesAffectedMessages::~MessagesAffectedMessages() {
}

void MessagesAffectedMessages::setPts(qint32 pts) {
    m_pts = pts;
}

qint32 MessagesAffectedMessages::pts() const {
    return m_pts;
}

void MessagesAffectedMessages::setPtsCount(qint32 ptsCount) {
    m_ptsCount = ptsCount;
}

qint32 MessagesAffectedMessages::ptsCount() const {
    return m_ptsCount;
}

bool MessagesAffectedMessages::operator ==(const MessagesAffectedMessages &b) const {
    return m_classType == b.m_classType &&
           m_pts == b.m_pts &&
           m_ptsCount == b.m_ptsCount;
}

void MessagesAffectedMessages::setClassType(MessagesAffectedMessages::MessagesAffectedMessagesClassType classType) {
    m_classType = classType;
}

MessagesAffectedMessages::MessagesAffectedMessagesClassType MessagesAffectedMessages::classType() const {
    return m_classType;
}

bool MessagesAffectedMessages::fetch(InboundPkt *in) {
    LQTG_FETCH_LOG;
    int x = in->fetchInt();
    switch(x) {
    case typeMessagesAffectedMessages: {
        m_pts = in->fetchInt();
        m_ptsCount = in->fetchInt();
        m_classType = static_cast<MessagesAffectedMessagesClassType>(x);
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool MessagesAffectedMessages::push(OutboundPkt *out) const {
    out->appendInt(m_classType);
    switch(m_classType) {
    case typeMessagesAffectedMessages: {
        out->appendInt(m_pts);
        out->appendInt(m_ptsCount);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

QMap<QString, QVariant> MessagesAffectedMessages::toMap() const {
    QMap<QString, QVariant> result;
    switch(static_cast<int>(m_classType)) {
    case typeMessagesAffectedMessages: {
        result["classType"] = "MessagesAffectedMessages::typeMessagesAffectedMessages";
        result["pts"] = QVariant::fromValue<qint32>(pts());
        result["ptsCount"] = QVariant::fromValue<qint32>(ptsCount());
        return result;
    }
        break;
    
    default:
        return result;
    }
}

MessagesAffectedMessages MessagesAffectedMessages::fromMap(const QMap<QString, QVariant> &map) {
    MessagesAffectedMessages result;
    if(map.value("classType").toString() == "MessagesAffectedMessages::typeMessagesAffectedMessages") {
        result.setClassType(typeMessagesAffectedMessages);
        result.setPts( map.value("pts").value<qint32>() );
        result.setPtsCount( map.value("ptsCount").value<qint32>() );
        return result;
    }
    return result;
}

QByteArray MessagesAffectedMessages::getHash(QCryptographicHash::Algorithm alg) const {
    QByteArray data;
    QDataStream str(&data, QIODevice::WriteOnly);
    str << *this;
    return QCryptographicHash::hash(data, alg);
}

QDataStream &operator<<(QDataStream &stream, const MessagesAffectedMessages &item) {
    stream << static_cast<uint>(item.classType());
    switch(item.classType()) {
    case MessagesAffectedMessages::typeMessagesAffectedMessages:
        stream << item.pts();
        stream << item.ptsCount();
        break;
    }
    return stream;
}

QDataStream &operator>>(QDataStream &stream, MessagesAffectedMessages &item) {
    uint type = 0;
    stream >> type;
    item.setClassType(static_cast<MessagesAffectedMessages::MessagesAffectedMessagesClassType>(type));
    switch(type) {
    case MessagesAffectedMessages::typeMessagesAffectedMessages: {
        qint32 m_pts;
        stream >> m_pts;
        item.setPts(m_pts);
        qint32 m_pts_count;
        stream >> m_pts_count;
        item.setPtsCount(m_pts_count);
    }
        break;
    }
    return stream;
}

