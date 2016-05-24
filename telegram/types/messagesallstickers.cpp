// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "messagesallstickers.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"
#include "../coretypes.h"

#include <QDataStream>

MessagesAllStickers::MessagesAllStickers(MessagesAllStickersClassType classType, InboundPkt *in) :
    m_hash(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

MessagesAllStickers::MessagesAllStickers(InboundPkt *in) :
    m_hash(0),
    m_classType(typeMessagesAllStickersNotModified)
{
    fetch(in);
}

MessagesAllStickers::MessagesAllStickers(const Null &null) :
    TelegramTypeObject(null),
    m_hash(0),
    m_classType(typeMessagesAllStickersNotModified)
{
}

MessagesAllStickers::~MessagesAllStickers() {
}

void MessagesAllStickers::setHash(qint32 hash) {
    m_hash = hash;
}

qint32 MessagesAllStickers::hash() const {
    return m_hash;
}

void MessagesAllStickers::setSets(const QList<StickerSet> &sets) {
    m_sets = sets;
}

QList<StickerSet> MessagesAllStickers::sets() const {
    return m_sets;
}

bool MessagesAllStickers::operator ==(const MessagesAllStickers &b) const {
    return m_classType == b.m_classType &&
           m_hash == b.m_hash &&
           m_sets == b.m_sets;
}

void MessagesAllStickers::setClassType(MessagesAllStickers::MessagesAllStickersClassType classType) {
    m_classType = classType;
}

MessagesAllStickers::MessagesAllStickersClassType MessagesAllStickers::classType() const {
    return m_classType;
}

bool MessagesAllStickers::fetch(InboundPkt *in) {
    LQTG_FETCH_LOG;
    int x = in->fetchInt();
    switch(x) {
    case typeMessagesAllStickersNotModified: {
        m_classType = static_cast<MessagesAllStickersClassType>(x);
        return true;
    }
        break;
    
    case typeMessagesAllStickers: {
        m_hash = in->fetchInt();
        if(in->fetchInt() != (qint32)CoreTypes::typeVector) return false;
        qint32 m_sets_length = in->fetchInt();
        m_sets.clear();
        for (qint32 i = 0; i < m_sets_length; i++) {
            StickerSet type;
            type.fetch(in);
            m_sets.append(type);
        }
        m_classType = static_cast<MessagesAllStickersClassType>(x);
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool MessagesAllStickers::push(OutboundPkt *out) const {
    out->appendInt(m_classType);
    switch(m_classType) {
    case typeMessagesAllStickersNotModified: {
        return true;
    }
        break;
    
    case typeMessagesAllStickers: {
        out->appendInt(m_hash);
        out->appendInt(CoreTypes::typeVector);
        out->appendInt(m_sets.count());
        for (qint32 i = 0; i < m_sets.count(); i++) {
            m_sets[i].push(out);
        }
        return true;
    }
        break;
    
    default:
        return false;
    }
}

QMap<QString, QVariant> MessagesAllStickers::toMap() const {
    QMap<QString, QVariant> result;
    switch(static_cast<int>(m_classType)) {
    case typeMessagesAllStickersNotModified: {
        result["classType"] = "MessagesAllStickers::typeMessagesAllStickersNotModified";
        return result;
    }
        break;
    
    case typeMessagesAllStickers: {
        result["classType"] = "MessagesAllStickers::typeMessagesAllStickers";
        result["hash"] = QVariant::fromValue<qint32>(hash());
        QList<QVariant> _sets;
        Q_FOREACH(const StickerSet &m__type, m_sets)
            _sets << m__type.toMap();
        result["sets"] = _sets;
        return result;
    }
        break;
    
    default:
        return result;
    }
}

MessagesAllStickers MessagesAllStickers::fromMap(const QMap<QString, QVariant> &map) {
    MessagesAllStickers result;
    if(map.value("classType").toString() == "MessagesAllStickers::typeMessagesAllStickersNotModified") {
        result.setClassType(typeMessagesAllStickersNotModified);
        return result;
    }
    if(map.value("classType").toString() == "MessagesAllStickers::typeMessagesAllStickers") {
        result.setClassType(typeMessagesAllStickers);
        result.setHash( map.value("hash").value<qint32>() );
        QList<QVariant> map_sets = map["sets"].toList();
        QList<StickerSet> _sets;
        Q_FOREACH(const QVariant &var, map_sets)
            _sets << StickerSet::fromMap(var.toMap());
        result.setSets(_sets);
        return result;
    }
    return result;
}

QByteArray MessagesAllStickers::getHash(QCryptographicHash::Algorithm alg) const {
    QByteArray data;
    QDataStream str(&data, QIODevice::WriteOnly);
    str << *this;
    return QCryptographicHash::hash(data, alg);
}

QDataStream &operator<<(QDataStream &stream, const MessagesAllStickers &item) {
    stream << static_cast<uint>(item.classType());
    switch(item.classType()) {
    case MessagesAllStickers::typeMessagesAllStickersNotModified:
        
        break;
    case MessagesAllStickers::typeMessagesAllStickers:
        stream << item.hash();
        stream << item.sets();
        break;
    }
    return stream;
}

QDataStream &operator>>(QDataStream &stream, MessagesAllStickers &item) {
    uint type = 0;
    stream >> type;
    item.setClassType(static_cast<MessagesAllStickers::MessagesAllStickersClassType>(type));
    switch(type) {
    case MessagesAllStickers::typeMessagesAllStickersNotModified: {
        
    }
        break;
    case MessagesAllStickers::typeMessagesAllStickers: {
        qint32 m_hash;
        stream >> m_hash;
        item.setHash(m_hash);
        QList<StickerSet> m_sets;
        stream >> m_sets;
        item.setSets(m_sets);
    }
        break;
    }
    return stream;
}

