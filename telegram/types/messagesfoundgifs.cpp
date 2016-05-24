// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "messagesfoundgifs.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"
#include "../coretypes.h"

#include <QDataStream>

MessagesFoundGifs::MessagesFoundGifs(MessagesFoundGifsClassType classType, InboundPkt *in) :
    m_nextOffset(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

MessagesFoundGifs::MessagesFoundGifs(InboundPkt *in) :
    m_nextOffset(0),
    m_classType(typeMessagesFoundGifs)
{
    fetch(in);
}

MessagesFoundGifs::MessagesFoundGifs(const Null &null) :
    TelegramTypeObject(null),
    m_nextOffset(0),
    m_classType(typeMessagesFoundGifs)
{
}

MessagesFoundGifs::~MessagesFoundGifs() {
}

void MessagesFoundGifs::setNextOffset(qint32 nextOffset) {
    m_nextOffset = nextOffset;
}

qint32 MessagesFoundGifs::nextOffset() const {
    return m_nextOffset;
}

void MessagesFoundGifs::setResults(const QList<FoundGif> &results) {
    m_results = results;
}

QList<FoundGif> MessagesFoundGifs::results() const {
    return m_results;
}

bool MessagesFoundGifs::operator ==(const MessagesFoundGifs &b) const {
    return m_classType == b.m_classType &&
           m_nextOffset == b.m_nextOffset &&
           m_results == b.m_results;
}

void MessagesFoundGifs::setClassType(MessagesFoundGifs::MessagesFoundGifsClassType classType) {
    m_classType = classType;
}

MessagesFoundGifs::MessagesFoundGifsClassType MessagesFoundGifs::classType() const {
    return m_classType;
}

bool MessagesFoundGifs::fetch(InboundPkt *in) {
    LQTG_FETCH_LOG;
    int x = in->fetchInt();
    switch(x) {
    case typeMessagesFoundGifs: {
        m_nextOffset = in->fetchInt();
        if(in->fetchInt() != (qint32)CoreTypes::typeVector) return false;
        qint32 m_results_length = in->fetchInt();
        m_results.clear();
        for (qint32 i = 0; i < m_results_length; i++) {
            FoundGif type;
            type.fetch(in);
            m_results.append(type);
        }
        m_classType = static_cast<MessagesFoundGifsClassType>(x);
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool MessagesFoundGifs::push(OutboundPkt *out) const {
    out->appendInt(m_classType);
    switch(m_classType) {
    case typeMessagesFoundGifs: {
        out->appendInt(m_nextOffset);
        out->appendInt(CoreTypes::typeVector);
        out->appendInt(m_results.count());
        for (qint32 i = 0; i < m_results.count(); i++) {
            m_results[i].push(out);
        }
        return true;
    }
        break;
    
    default:
        return false;
    }
}

QMap<QString, QVariant> MessagesFoundGifs::toMap() const {
    QMap<QString, QVariant> result;
    switch(static_cast<int>(m_classType)) {
    case typeMessagesFoundGifs: {
        result["classType"] = "MessagesFoundGifs::typeMessagesFoundGifs";
        result["nextOffset"] = QVariant::fromValue<qint32>(nextOffset());
        QList<QVariant> _results;
        Q_FOREACH(const FoundGif &m__type, m_results)
            _results << m__type.toMap();
        result["results"] = _results;
        return result;
    }
        break;
    
    default:
        return result;
    }
}

MessagesFoundGifs MessagesFoundGifs::fromMap(const QMap<QString, QVariant> &map) {
    MessagesFoundGifs result;
    if(map.value("classType").toString() == "MessagesFoundGifs::typeMessagesFoundGifs") {
        result.setClassType(typeMessagesFoundGifs);
        result.setNextOffset( map.value("nextOffset").value<qint32>() );
        QList<QVariant> map_results = map["results"].toList();
        QList<FoundGif> _results;
        Q_FOREACH(const QVariant &var, map_results)
            _results << FoundGif::fromMap(var.toMap());
        result.setResults(_results);
        return result;
    }
    return result;
}

QByteArray MessagesFoundGifs::getHash(QCryptographicHash::Algorithm alg) const {
    QByteArray data;
    QDataStream str(&data, QIODevice::WriteOnly);
    str << *this;
    return QCryptographicHash::hash(data, alg);
}

QDataStream &operator<<(QDataStream &stream, const MessagesFoundGifs &item) {
    stream << static_cast<uint>(item.classType());
    switch(item.classType()) {
    case MessagesFoundGifs::typeMessagesFoundGifs:
        stream << item.nextOffset();
        stream << item.results();
        break;
    }
    return stream;
}

QDataStream &operator>>(QDataStream &stream, MessagesFoundGifs &item) {
    uint type = 0;
    stream >> type;
    item.setClassType(static_cast<MessagesFoundGifs::MessagesFoundGifsClassType>(type));
    switch(type) {
    case MessagesFoundGifs::typeMessagesFoundGifs: {
        qint32 m_next_offset;
        stream >> m_next_offset;
        item.setNextOffset(m_next_offset);
        QList<FoundGif> m_results;
        stream >> m_results;
        item.setResults(m_results);
    }
        break;
    }
    return stream;
}

