// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "inputgeopoint.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"
#include "../coretypes.h"

#include <QDataStream>

InputGeoPoint::InputGeoPoint(InputGeoPointClassType classType, InboundPkt *in) :
    m_lat(0),
    m_longValue(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

InputGeoPoint::InputGeoPoint(InboundPkt *in) :
    m_lat(0),
    m_longValue(0),
    m_classType(typeInputGeoPointEmpty)
{
    fetch(in);
}

InputGeoPoint::InputGeoPoint(const Null &null) :
    TelegramTypeObject(null),
    m_lat(0),
    m_longValue(0),
    m_classType(typeInputGeoPointEmpty)
{
}

InputGeoPoint::~InputGeoPoint() {
}

void InputGeoPoint::setLat(qreal lat) {
    m_lat = lat;
}

qreal InputGeoPoint::lat() const {
    return m_lat;
}

void InputGeoPoint::setLongValue(qreal longValue) {
    m_longValue = longValue;
}

qreal InputGeoPoint::longValue() const {
    return m_longValue;
}

bool InputGeoPoint::operator ==(const InputGeoPoint &b) const {
    return m_classType == b.m_classType &&
           m_lat == b.m_lat &&
           m_longValue == b.m_longValue;
}

void InputGeoPoint::setClassType(InputGeoPoint::InputGeoPointClassType classType) {
    m_classType = classType;
}

InputGeoPoint::InputGeoPointClassType InputGeoPoint::classType() const {
    return m_classType;
}

bool InputGeoPoint::fetch(InboundPkt *in) {
    LQTG_FETCH_LOG;
    int x = in->fetchInt();
    switch(x) {
    case typeInputGeoPointEmpty: {
        m_classType = static_cast<InputGeoPointClassType>(x);
        return true;
    }
        break;
    
    case typeInputGeoPoint: {
        m_lat = in->fetchDouble();
        m_longValue = in->fetchDouble();
        m_classType = static_cast<InputGeoPointClassType>(x);
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool InputGeoPoint::push(OutboundPkt *out) const {
    out->appendInt(m_classType);
    switch(m_classType) {
    case typeInputGeoPointEmpty: {
        return true;
    }
        break;
    
    case typeInputGeoPoint: {
        out->appendDouble(m_lat);
        out->appendDouble(m_longValue);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

QMap<QString, QVariant> InputGeoPoint::toMap() const {
    QMap<QString, QVariant> result;
    switch(static_cast<int>(m_classType)) {
    case typeInputGeoPointEmpty: {
        result["classType"] = "InputGeoPoint::typeInputGeoPointEmpty";
        return result;
    }
        break;
    
    case typeInputGeoPoint: {
        result["classType"] = "InputGeoPoint::typeInputGeoPoint";
        result["lat"] = QVariant::fromValue<qreal>(lat());
        result["longValue"] = QVariant::fromValue<qreal>(longValue());
        return result;
    }
        break;
    
    default:
        return result;
    }
}

InputGeoPoint InputGeoPoint::fromMap(const QMap<QString, QVariant> &map) {
    InputGeoPoint result;
    if(map.value("classType").toString() == "InputGeoPoint::typeInputGeoPointEmpty") {
        result.setClassType(typeInputGeoPointEmpty);
        return result;
    }
    if(map.value("classType").toString() == "InputGeoPoint::typeInputGeoPoint") {
        result.setClassType(typeInputGeoPoint);
        result.setLat( map.value("lat").value<qreal>() );
        result.setLongValue( map.value("longValue").value<qreal>() );
        return result;
    }
    return result;
}

QByteArray InputGeoPoint::getHash(QCryptographicHash::Algorithm alg) const {
    QByteArray data;
    QDataStream str(&data, QIODevice::WriteOnly);
    str << *this;
    return QCryptographicHash::hash(data, alg);
}

QDataStream &operator<<(QDataStream &stream, const InputGeoPoint &item) {
    stream << static_cast<uint>(item.classType());
    switch(item.classType()) {
    case InputGeoPoint::typeInputGeoPointEmpty:
        
        break;
    case InputGeoPoint::typeInputGeoPoint:
        stream << item.lat();
        stream << item.longValue();
        break;
    }
    return stream;
}

QDataStream &operator>>(QDataStream &stream, InputGeoPoint &item) {
    uint type = 0;
    stream >> type;
    item.setClassType(static_cast<InputGeoPoint::InputGeoPointClassType>(type));
    switch(type) {
    case InputGeoPoint::typeInputGeoPointEmpty: {
        
    }
        break;
    case InputGeoPoint::typeInputGeoPoint: {
        qreal m_lat;
        stream >> m_lat;
        item.setLat(m_lat);
        qreal m_longValue;
        stream >> m_longValue;
        item.setLongValue(m_longValue);
    }
        break;
    }
    return stream;
}

