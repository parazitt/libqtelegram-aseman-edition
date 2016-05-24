// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "channelparticipantrole.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"
#include "../coretypes.h"

#include <QDataStream>

ChannelParticipantRole::ChannelParticipantRole(ChannelParticipantRoleClassType classType, InboundPkt *in) :
    m_classType(classType)
{
    if(in) fetch(in);
}

ChannelParticipantRole::ChannelParticipantRole(InboundPkt *in) :
    m_classType(typeChannelRoleEmpty)
{
    fetch(in);
}

ChannelParticipantRole::ChannelParticipantRole(const Null &null) :
    TelegramTypeObject(null),
    m_classType(typeChannelRoleEmpty)
{
}

ChannelParticipantRole::~ChannelParticipantRole() {
}

bool ChannelParticipantRole::operator ==(const ChannelParticipantRole &b) const {
    return m_classType == b.m_classType;
}

void ChannelParticipantRole::setClassType(ChannelParticipantRole::ChannelParticipantRoleClassType classType) {
    m_classType = classType;
}

ChannelParticipantRole::ChannelParticipantRoleClassType ChannelParticipantRole::classType() const {
    return m_classType;
}

bool ChannelParticipantRole::fetch(InboundPkt *in) {
    LQTG_FETCH_LOG;
    int x = in->fetchInt();
    switch(x) {
    case typeChannelRoleEmpty: {
        m_classType = static_cast<ChannelParticipantRoleClassType>(x);
        return true;
    }
        break;
    
    case typeChannelRoleModerator: {
        m_classType = static_cast<ChannelParticipantRoleClassType>(x);
        return true;
    }
        break;
    
    case typeChannelRoleEditor: {
        m_classType = static_cast<ChannelParticipantRoleClassType>(x);
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool ChannelParticipantRole::push(OutboundPkt *out) const {
    out->appendInt(m_classType);
    switch(m_classType) {
    case typeChannelRoleEmpty: {
        return true;
    }
        break;
    
    case typeChannelRoleModerator: {
        return true;
    }
        break;
    
    case typeChannelRoleEditor: {
        return true;
    }
        break;
    
    default:
        return false;
    }
}

QMap<QString, QVariant> ChannelParticipantRole::toMap() const {
    QMap<QString, QVariant> result;
    switch(static_cast<int>(m_classType)) {
    case typeChannelRoleEmpty: {
        result["classType"] = "ChannelParticipantRole::typeChannelRoleEmpty";
        return result;
    }
        break;
    
    case typeChannelRoleModerator: {
        result["classType"] = "ChannelParticipantRole::typeChannelRoleModerator";
        return result;
    }
        break;
    
    case typeChannelRoleEditor: {
        result["classType"] = "ChannelParticipantRole::typeChannelRoleEditor";
        return result;
    }
        break;
    
    default:
        return result;
    }
}

ChannelParticipantRole ChannelParticipantRole::fromMap(const QMap<QString, QVariant> &map) {
    ChannelParticipantRole result;
    if(map.value("classType").toString() == "ChannelParticipantRole::typeChannelRoleEmpty") {
        result.setClassType(typeChannelRoleEmpty);
        return result;
    }
    if(map.value("classType").toString() == "ChannelParticipantRole::typeChannelRoleModerator") {
        result.setClassType(typeChannelRoleModerator);
        return result;
    }
    if(map.value("classType").toString() == "ChannelParticipantRole::typeChannelRoleEditor") {
        result.setClassType(typeChannelRoleEditor);
        return result;
    }
    return result;
}

QByteArray ChannelParticipantRole::getHash(QCryptographicHash::Algorithm alg) const {
    QByteArray data;
    QDataStream str(&data, QIODevice::WriteOnly);
    str << *this;
    return QCryptographicHash::hash(data, alg);
}

QDataStream &operator<<(QDataStream &stream, const ChannelParticipantRole &item) {
    stream << static_cast<uint>(item.classType());
    switch(item.classType()) {
    case ChannelParticipantRole::typeChannelRoleEmpty:
        
        break;
    case ChannelParticipantRole::typeChannelRoleModerator:
        
        break;
    case ChannelParticipantRole::typeChannelRoleEditor:
        
        break;
    }
    return stream;
}

QDataStream &operator>>(QDataStream &stream, ChannelParticipantRole &item) {
    uint type = 0;
    stream >> type;
    item.setClassType(static_cast<ChannelParticipantRole::ChannelParticipantRoleClassType>(type));
    switch(type) {
    case ChannelParticipantRole::typeChannelRoleEmpty: {
        
    }
        break;
    case ChannelParticipantRole::typeChannelRoleModerator: {
        
    }
        break;
    case ChannelParticipantRole::typeChannelRoleEditor: {
        
    }
        break;
    }
    return stream;
}

