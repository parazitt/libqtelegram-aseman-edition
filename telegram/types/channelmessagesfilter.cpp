// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "channelmessagesfilter.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"
#include "../coretypes.h"

#include <QDataStream>

ChannelMessagesFilter::ChannelMessagesFilter(ChannelMessagesFilterClassType classType, InboundPkt *in) :
    m_flags(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

ChannelMessagesFilter::ChannelMessagesFilter(InboundPkt *in) :
    m_flags(0),
    m_classType(typeChannelMessagesFilterEmpty)
{
    fetch(in);
}

ChannelMessagesFilter::ChannelMessagesFilter(const Null &null) :
    TelegramTypeObject(null),
    m_flags(0),
    m_classType(typeChannelMessagesFilterEmpty)
{
}

ChannelMessagesFilter::~ChannelMessagesFilter() {
}

void ChannelMessagesFilter::setExcludeNewMessages(bool excludeNewMessages) {
    if(excludeNewMessages) m_flags = (m_flags | (1<<1));
    else m_flags = (m_flags & ~(1<<1));
}

bool ChannelMessagesFilter::excludeNewMessages() const {
    return (m_flags & 1<<1);
}

void ChannelMessagesFilter::setFlags(qint32 flags) {
    m_flags = flags;
}

qint32 ChannelMessagesFilter::flags() const {
    return m_flags;
}

void ChannelMessagesFilter::setImportantOnly(bool importantOnly) {
    if(importantOnly) m_flags = (m_flags | (1<<0));
    else m_flags = (m_flags & ~(1<<0));
}

bool ChannelMessagesFilter::importantOnly() const {
    return (m_flags & 1<<0);
}

void ChannelMessagesFilter::setRanges(const QList<MessageRange> &ranges) {
    m_ranges = ranges;
}

QList<MessageRange> ChannelMessagesFilter::ranges() const {
    return m_ranges;
}

bool ChannelMessagesFilter::operator ==(const ChannelMessagesFilter &b) const {
    return m_classType == b.m_classType &&
           m_flags == b.m_flags &&
           m_ranges == b.m_ranges;
}

void ChannelMessagesFilter::setClassType(ChannelMessagesFilter::ChannelMessagesFilterClassType classType) {
    m_classType = classType;
}

ChannelMessagesFilter::ChannelMessagesFilterClassType ChannelMessagesFilter::classType() const {
    return m_classType;
}

bool ChannelMessagesFilter::fetch(InboundPkt *in) {
    LQTG_FETCH_LOG;
    int x = in->fetchInt();
    switch(x) {
    case typeChannelMessagesFilterEmpty: {
        m_classType = static_cast<ChannelMessagesFilterClassType>(x);
        return true;
    }
        break;
    
    case typeChannelMessagesFilter: {
        m_flags = in->fetchInt();
        if(in->fetchInt() != (qint32)CoreTypes::typeVector) return false;
        qint32 m_ranges_length = in->fetchInt();
        m_ranges.clear();
        for (qint32 i = 0; i < m_ranges_length; i++) {
            MessageRange type;
            type.fetch(in);
            m_ranges.append(type);
        }
        m_classType = static_cast<ChannelMessagesFilterClassType>(x);
        return true;
    }
        break;
    
    case typeChannelMessagesFilterCollapsed: {
        m_classType = static_cast<ChannelMessagesFilterClassType>(x);
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool ChannelMessagesFilter::push(OutboundPkt *out) const {
    out->appendInt(m_classType);
    switch(m_classType) {
    case typeChannelMessagesFilterEmpty: {
        return true;
    }
        break;
    
    case typeChannelMessagesFilter: {
        out->appendInt(m_flags);
        out->appendInt(CoreTypes::typeVector);
        out->appendInt(m_ranges.count());
        for (qint32 i = 0; i < m_ranges.count(); i++) {
            m_ranges[i].push(out);
        }
        return true;
    }
        break;
    
    case typeChannelMessagesFilterCollapsed: {
        return true;
    }
        break;
    
    default:
        return false;
    }
}

QMap<QString, QVariant> ChannelMessagesFilter::toMap() const {
    QMap<QString, QVariant> result;
    switch(static_cast<int>(m_classType)) {
    case typeChannelMessagesFilterEmpty: {
        result["classType"] = "ChannelMessagesFilter::typeChannelMessagesFilterEmpty";
        return result;
    }
        break;
    
    case typeChannelMessagesFilter: {
        result["classType"] = "ChannelMessagesFilter::typeChannelMessagesFilter";
        result["flags"] = QVariant::fromValue<qint32>(flags());
        QList<QVariant> _ranges;
        Q_FOREACH(const MessageRange &m__type, m_ranges)
            _ranges << m__type.toMap();
        result["ranges"] = _ranges;
        return result;
    }
        break;
    
    case typeChannelMessagesFilterCollapsed: {
        result["classType"] = "ChannelMessagesFilter::typeChannelMessagesFilterCollapsed";
        return result;
    }
        break;
    
    default:
        return result;
    }
}

ChannelMessagesFilter ChannelMessagesFilter::fromMap(const QMap<QString, QVariant> &map) {
    ChannelMessagesFilter result;
    if(map.value("classType").toString() == "ChannelMessagesFilter::typeChannelMessagesFilterEmpty") {
        result.setClassType(typeChannelMessagesFilterEmpty);
        return result;
    }
    if(map.value("classType").toString() == "ChannelMessagesFilter::typeChannelMessagesFilter") {
        result.setClassType(typeChannelMessagesFilter);
        result.setImportantOnly( map.value("importantOnly").value<bool>() );
        result.setExcludeNewMessages( map.value("excludeNewMessages").value<bool>() );
        QList<QVariant> map_ranges = map["ranges"].toList();
        QList<MessageRange> _ranges;
        Q_FOREACH(const QVariant &var, map_ranges)
            _ranges << MessageRange::fromMap(var.toMap());
        result.setRanges(_ranges);
        return result;
    }
    if(map.value("classType").toString() == "ChannelMessagesFilter::typeChannelMessagesFilterCollapsed") {
        result.setClassType(typeChannelMessagesFilterCollapsed);
        return result;
    }
    return result;
}

QByteArray ChannelMessagesFilter::getHash(QCryptographicHash::Algorithm alg) const {
    QByteArray data;
    QDataStream str(&data, QIODevice::WriteOnly);
    str << *this;
    return QCryptographicHash::hash(data, alg);
}

QDataStream &operator<<(QDataStream &stream, const ChannelMessagesFilter &item) {
    stream << static_cast<uint>(item.classType());
    switch(item.classType()) {
    case ChannelMessagesFilter::typeChannelMessagesFilterEmpty:
        
        break;
    case ChannelMessagesFilter::typeChannelMessagesFilter:
        stream << item.flags();
        stream << item.ranges();
        break;
    case ChannelMessagesFilter::typeChannelMessagesFilterCollapsed:
        
        break;
    }
    return stream;
}

QDataStream &operator>>(QDataStream &stream, ChannelMessagesFilter &item) {
    uint type = 0;
    stream >> type;
    item.setClassType(static_cast<ChannelMessagesFilter::ChannelMessagesFilterClassType>(type));
    switch(type) {
    case ChannelMessagesFilter::typeChannelMessagesFilterEmpty: {
        
    }
        break;
    case ChannelMessagesFilter::typeChannelMessagesFilter: {
        qint32 m_flags;
        stream >> m_flags;
        item.setFlags(m_flags);
        QList<MessageRange> m_ranges;
        stream >> m_ranges;
        item.setRanges(m_ranges);
    }
        break;
    case ChannelMessagesFilter::typeChannelMessagesFilterCollapsed: {
        
    }
        break;
    }
    return stream;
}

