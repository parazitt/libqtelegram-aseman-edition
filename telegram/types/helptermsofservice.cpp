// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "helptermsofservice.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"
#include "../coretypes.h"

#include <QDataStream>

HelpTermsOfService::HelpTermsOfService(HelpTermsOfServiceClassType classType, InboundPkt *in) :
    m_classType(classType)
{
    if(in) fetch(in);
}

HelpTermsOfService::HelpTermsOfService(InboundPkt *in) :
    m_classType(typeHelpTermsOfService)
{
    fetch(in);
}

HelpTermsOfService::HelpTermsOfService(const Null &null) :
    TelegramTypeObject(null),
    m_classType(typeHelpTermsOfService)
{
}

HelpTermsOfService::~HelpTermsOfService() {
}

void HelpTermsOfService::setText(const QString &text) {
    m_text = text;
}

QString HelpTermsOfService::text() const {
    return m_text;
}

bool HelpTermsOfService::operator ==(const HelpTermsOfService &b) const {
    return m_classType == b.m_classType &&
           m_text == b.m_text;
}

void HelpTermsOfService::setClassType(HelpTermsOfService::HelpTermsOfServiceClassType classType) {
    m_classType = classType;
}

HelpTermsOfService::HelpTermsOfServiceClassType HelpTermsOfService::classType() const {
    return m_classType;
}

bool HelpTermsOfService::fetch(InboundPkt *in) {
    LQTG_FETCH_LOG;
    int x = in->fetchInt();
    switch(x) {
    case typeHelpTermsOfService: {
        m_text = in->fetchQString();
        m_classType = static_cast<HelpTermsOfServiceClassType>(x);
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool HelpTermsOfService::push(OutboundPkt *out) const {
    out->appendInt(m_classType);
    switch(m_classType) {
    case typeHelpTermsOfService: {
        out->appendQString(m_text);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

QMap<QString, QVariant> HelpTermsOfService::toMap() const {
    QMap<QString, QVariant> result;
    switch(static_cast<int>(m_classType)) {
    case typeHelpTermsOfService: {
        result["classType"] = "HelpTermsOfService::typeHelpTermsOfService";
        result["text"] = QVariant::fromValue<QString>(text());
        return result;
    }
        break;
    
    default:
        return result;
    }
}

HelpTermsOfService HelpTermsOfService::fromMap(const QMap<QString, QVariant> &map) {
    HelpTermsOfService result;
    if(map.value("classType").toString() == "HelpTermsOfService::typeHelpTermsOfService") {
        result.setClassType(typeHelpTermsOfService);
        result.setText( map.value("text").value<QString>() );
        return result;
    }
    return result;
}

QByteArray HelpTermsOfService::getHash(QCryptographicHash::Algorithm alg) const {
    QByteArray data;
    QDataStream str(&data, QIODevice::WriteOnly);
    str << *this;
    return QCryptographicHash::hash(data, alg);
}

QDataStream &operator<<(QDataStream &stream, const HelpTermsOfService &item) {
    stream << static_cast<uint>(item.classType());
    switch(item.classType()) {
    case HelpTermsOfService::typeHelpTermsOfService:
        stream << item.text();
        break;
    }
    return stream;
}

QDataStream &operator>>(QDataStream &stream, HelpTermsOfService &item) {
    uint type = 0;
    stream >> type;
    item.setClassType(static_cast<HelpTermsOfService::HelpTermsOfServiceClassType>(type));
    switch(type) {
    case HelpTermsOfService::typeHelpTermsOfService: {
        QString m_text;
        stream >> m_text;
        item.setText(m_text);
    }
        break;
    }
    return stream;
}

