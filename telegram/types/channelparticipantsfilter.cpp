// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "channelparticipantsfilter.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"
#include "../coretypes.h"

#include <QDataStream>

ChannelParticipantsFilter::ChannelParticipantsFilter(ChannelParticipantsFilterClassType classType, InboundPkt *in) :
    m_classType(classType)
{
    if(in) fetch(in);
}

ChannelParticipantsFilter::ChannelParticipantsFilter(InboundPkt *in) :
    m_classType(typeChannelParticipantsRecent)
{
    fetch(in);
}

ChannelParticipantsFilter::ChannelParticipantsFilter(const Null &null) :
    TelegramTypeObject(null),
    m_classType(typeChannelParticipantsRecent)
{
}

ChannelParticipantsFilter::~ChannelParticipantsFilter() {
}

bool ChannelParticipantsFilter::operator ==(const ChannelParticipantsFilter &b) const {
    return m_classType == b.m_classType;
}

void ChannelParticipantsFilter::setClassType(ChannelParticipantsFilter::ChannelParticipantsFilterClassType classType) {
    m_classType = classType;
}

ChannelParticipantsFilter::ChannelParticipantsFilterClassType ChannelParticipantsFilter::classType() const {
    return m_classType;
}

bool ChannelParticipantsFilter::fetch(InboundPkt *in) {
    LQTG_FETCH_LOG;
    int x = in->fetchInt();
    switch(x) {
    case typeChannelParticipantsRecent: {
        m_classType = static_cast<ChannelParticipantsFilterClassType>(x);
        return true;
    }
        break;
    
    case typeChannelParticipantsAdmins: {
        m_classType = static_cast<ChannelParticipantsFilterClassType>(x);
        return true;
    }
        break;
    
    case typeChannelParticipantsKicked: {
        m_classType = static_cast<ChannelParticipantsFilterClassType>(x);
        return true;
    }
        break;
    
    case typeChannelParticipantsBots: {
        m_classType = static_cast<ChannelParticipantsFilterClassType>(x);
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool ChannelParticipantsFilter::push(OutboundPkt *out) const {
    out->appendInt(m_classType);
    switch(m_classType) {
    case typeChannelParticipantsRecent: {
        return true;
    }
        break;
    
    case typeChannelParticipantsAdmins: {
        return true;
    }
        break;
    
    case typeChannelParticipantsKicked: {
        return true;
    }
        break;
    
    case typeChannelParticipantsBots: {
        return true;
    }
        break;
    
    default:
        return false;
    }
}

QMap<QString, QVariant> ChannelParticipantsFilter::toMap() const {
    QMap<QString, QVariant> result;
    switch(static_cast<int>(m_classType)) {
    case typeChannelParticipantsRecent: {
        result["classType"] = "ChannelParticipantsFilter::typeChannelParticipantsRecent";
        return result;
    }
        break;
    
    case typeChannelParticipantsAdmins: {
        result["classType"] = "ChannelParticipantsFilter::typeChannelParticipantsAdmins";
        return result;
    }
        break;
    
    case typeChannelParticipantsKicked: {
        result["classType"] = "ChannelParticipantsFilter::typeChannelParticipantsKicked";
        return result;
    }
        break;
    
    case typeChannelParticipantsBots: {
        result["classType"] = "ChannelParticipantsFilter::typeChannelParticipantsBots";
        return result;
    }
        break;
    
    default:
        return result;
    }
}

ChannelParticipantsFilter ChannelParticipantsFilter::fromMap(const QMap<QString, QVariant> &map) {
    ChannelParticipantsFilter result;
    if(map.value("classType").toString() == "ChannelParticipantsFilter::typeChannelParticipantsRecent") {
        result.setClassType(typeChannelParticipantsRecent);
        return result;
    }
    if(map.value("classType").toString() == "ChannelParticipantsFilter::typeChannelParticipantsAdmins") {
        result.setClassType(typeChannelParticipantsAdmins);
        return result;
    }
    if(map.value("classType").toString() == "ChannelParticipantsFilter::typeChannelParticipantsKicked") {
        result.setClassType(typeChannelParticipantsKicked);
        return result;
    }
    if(map.value("classType").toString() == "ChannelParticipantsFilter::typeChannelParticipantsBots") {
        result.setClassType(typeChannelParticipantsBots);
        return result;
    }
    return result;
}

QByteArray ChannelParticipantsFilter::getHash(QCryptographicHash::Algorithm alg) const {
    QByteArray data;
    QDataStream str(&data, QIODevice::WriteOnly);
    str << *this;
    return QCryptographicHash::hash(data, alg);
}

QDataStream &operator<<(QDataStream &stream, const ChannelParticipantsFilter &item) {
    stream << static_cast<uint>(item.classType());
    switch(item.classType()) {
    case ChannelParticipantsFilter::typeChannelParticipantsRecent:
        
        break;
    case ChannelParticipantsFilter::typeChannelParticipantsAdmins:
        
        break;
    case ChannelParticipantsFilter::typeChannelParticipantsKicked:
        
        break;
    case ChannelParticipantsFilter::typeChannelParticipantsBots:
        
        break;
    }
    return stream;
}

QDataStream &operator>>(QDataStream &stream, ChannelParticipantsFilter &item) {
    uint type = 0;
    stream >> type;
    item.setClassType(static_cast<ChannelParticipantsFilter::ChannelParticipantsFilterClassType>(type));
    switch(type) {
    case ChannelParticipantsFilter::typeChannelParticipantsRecent: {
        
    }
        break;
    case ChannelParticipantsFilter::typeChannelParticipantsAdmins: {
        
    }
        break;
    case ChannelParticipantsFilter::typeChannelParticipantsKicked: {
        
    }
        break;
    case ChannelParticipantsFilter::typeChannelParticipantsBots: {
        
    }
        break;
    }
    return stream;
}

