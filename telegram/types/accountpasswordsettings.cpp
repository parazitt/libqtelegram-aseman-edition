// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "accountpasswordsettings.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"
#include "../coretypes.h"

#include <QDataStream>

AccountPasswordSettings::AccountPasswordSettings(AccountPasswordSettingsClassType classType, InboundPkt *in) :
    m_classType(classType)
{
    if(in) fetch(in);
}

AccountPasswordSettings::AccountPasswordSettings(InboundPkt *in) :
    m_classType(typeAccountPasswordSettings)
{
    fetch(in);
}

AccountPasswordSettings::AccountPasswordSettings(const Null &null) :
    TelegramTypeObject(null),
    m_classType(typeAccountPasswordSettings)
{
}

AccountPasswordSettings::~AccountPasswordSettings() {
}

void AccountPasswordSettings::setEmail(const QString &email) {
    m_email = email;
}

QString AccountPasswordSettings::email() const {
    return m_email;
}

bool AccountPasswordSettings::operator ==(const AccountPasswordSettings &b) const {
    return m_classType == b.m_classType &&
           m_email == b.m_email;
}

void AccountPasswordSettings::setClassType(AccountPasswordSettings::AccountPasswordSettingsClassType classType) {
    m_classType = classType;
}

AccountPasswordSettings::AccountPasswordSettingsClassType AccountPasswordSettings::classType() const {
    return m_classType;
}

bool AccountPasswordSettings::fetch(InboundPkt *in) {
    LQTG_FETCH_LOG;
    int x = in->fetchInt();
    switch(x) {
    case typeAccountPasswordSettings: {
        m_email = in->fetchQString();
        m_classType = static_cast<AccountPasswordSettingsClassType>(x);
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool AccountPasswordSettings::push(OutboundPkt *out) const {
    out->appendInt(m_classType);
    switch(m_classType) {
    case typeAccountPasswordSettings: {
        out->appendQString(m_email);
        return true;
    }
        break;
    
    default:
        return false;
    }
}

QMap<QString, QVariant> AccountPasswordSettings::toMap() const {
    QMap<QString, QVariant> result;
    switch(static_cast<int>(m_classType)) {
    case typeAccountPasswordSettings: {
        result["classType"] = "AccountPasswordSettings::typeAccountPasswordSettings";
        result["email"] = QVariant::fromValue<QString>(email());
        return result;
    }
        break;
    
    default:
        return result;
    }
}

AccountPasswordSettings AccountPasswordSettings::fromMap(const QMap<QString, QVariant> &map) {
    AccountPasswordSettings result;
    if(map.value("classType").toString() == "AccountPasswordSettings::typeAccountPasswordSettings") {
        result.setClassType(typeAccountPasswordSettings);
        result.setEmail( map.value("email").value<QString>() );
        return result;
    }
    return result;
}

QByteArray AccountPasswordSettings::getHash(QCryptographicHash::Algorithm alg) const {
    QByteArray data;
    QDataStream str(&data, QIODevice::WriteOnly);
    str << *this;
    return QCryptographicHash::hash(data, alg);
}

QDataStream &operator<<(QDataStream &stream, const AccountPasswordSettings &item) {
    stream << static_cast<uint>(item.classType());
    switch(item.classType()) {
    case AccountPasswordSettings::typeAccountPasswordSettings:
        stream << item.email();
        break;
    }
    return stream;
}

QDataStream &operator>>(QDataStream &stream, AccountPasswordSettings &item) {
    uint type = 0;
    stream >> type;
    item.setClassType(static_cast<AccountPasswordSettings::AccountPasswordSettingsClassType>(type));
    switch(type) {
    case AccountPasswordSettings::typeAccountPasswordSettings: {
        QString m_email;
        stream >> m_email;
        item.setEmail(m_email);
    }
        break;
    }
    return stream;
}

