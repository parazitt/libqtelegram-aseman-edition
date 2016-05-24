// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "accountprivacyrules.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"
#include "../coretypes.h"

#include <QDataStream>

AccountPrivacyRules::AccountPrivacyRules(AccountPrivacyRulesClassType classType, InboundPkt *in) :
    m_classType(classType)
{
    if(in) fetch(in);
}

AccountPrivacyRules::AccountPrivacyRules(InboundPkt *in) :
    m_classType(typeAccountPrivacyRules)
{
    fetch(in);
}

AccountPrivacyRules::AccountPrivacyRules(const Null &null) :
    TelegramTypeObject(null),
    m_classType(typeAccountPrivacyRules)
{
}

AccountPrivacyRules::~AccountPrivacyRules() {
}

void AccountPrivacyRules::setRules(const QList<PrivacyRule> &rules) {
    m_rules = rules;
}

QList<PrivacyRule> AccountPrivacyRules::rules() const {
    return m_rules;
}

void AccountPrivacyRules::setUsers(const QList<User> &users) {
    m_users = users;
}

QList<User> AccountPrivacyRules::users() const {
    return m_users;
}

bool AccountPrivacyRules::operator ==(const AccountPrivacyRules &b) const {
    return m_classType == b.m_classType &&
           m_rules == b.m_rules &&
           m_users == b.m_users;
}

void AccountPrivacyRules::setClassType(AccountPrivacyRules::AccountPrivacyRulesClassType classType) {
    m_classType = classType;
}

AccountPrivacyRules::AccountPrivacyRulesClassType AccountPrivacyRules::classType() const {
    return m_classType;
}

bool AccountPrivacyRules::fetch(InboundPkt *in) {
    LQTG_FETCH_LOG;
    int x = in->fetchInt();
    switch(x) {
    case typeAccountPrivacyRules: {
        if(in->fetchInt() != (qint32)CoreTypes::typeVector) return false;
        qint32 m_rules_length = in->fetchInt();
        m_rules.clear();
        for (qint32 i = 0; i < m_rules_length; i++) {
            PrivacyRule type;
            type.fetch(in);
            m_rules.append(type);
        }
        if(in->fetchInt() != (qint32)CoreTypes::typeVector) return false;
        qint32 m_users_length = in->fetchInt();
        m_users.clear();
        for (qint32 i = 0; i < m_users_length; i++) {
            User type;
            type.fetch(in);
            m_users.append(type);
        }
        m_classType = static_cast<AccountPrivacyRulesClassType>(x);
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool AccountPrivacyRules::push(OutboundPkt *out) const {
    out->appendInt(m_classType);
    switch(m_classType) {
    case typeAccountPrivacyRules: {
        out->appendInt(CoreTypes::typeVector);
        out->appendInt(m_rules.count());
        for (qint32 i = 0; i < m_rules.count(); i++) {
            m_rules[i].push(out);
        }
        out->appendInt(CoreTypes::typeVector);
        out->appendInt(m_users.count());
        for (qint32 i = 0; i < m_users.count(); i++) {
            m_users[i].push(out);
        }
        return true;
    }
        break;
    
    default:
        return false;
    }
}

QMap<QString, QVariant> AccountPrivacyRules::toMap() const {
    QMap<QString, QVariant> result;
    switch(static_cast<int>(m_classType)) {
    case typeAccountPrivacyRules: {
        result["classType"] = "AccountPrivacyRules::typeAccountPrivacyRules";
        QList<QVariant> _rules;
        Q_FOREACH(const PrivacyRule &m__type, m_rules)
            _rules << m__type.toMap();
        result["rules"] = _rules;
        QList<QVariant> _users;
        Q_FOREACH(const User &m__type, m_users)
            _users << m__type.toMap();
        result["users"] = _users;
        return result;
    }
        break;
    
    default:
        return result;
    }
}

AccountPrivacyRules AccountPrivacyRules::fromMap(const QMap<QString, QVariant> &map) {
    AccountPrivacyRules result;
    if(map.value("classType").toString() == "AccountPrivacyRules::typeAccountPrivacyRules") {
        result.setClassType(typeAccountPrivacyRules);
        QList<QVariant> map_rules = map["rules"].toList();
        QList<PrivacyRule> _rules;
        Q_FOREACH(const QVariant &var, map_rules)
            _rules << PrivacyRule::fromMap(var.toMap());
        result.setRules(_rules);
        QList<QVariant> map_users = map["users"].toList();
        QList<User> _users;
        Q_FOREACH(const QVariant &var, map_users)
            _users << User::fromMap(var.toMap());
        result.setUsers(_users);
        return result;
    }
    return result;
}

QByteArray AccountPrivacyRules::getHash(QCryptographicHash::Algorithm alg) const {
    QByteArray data;
    QDataStream str(&data, QIODevice::WriteOnly);
    str << *this;
    return QCryptographicHash::hash(data, alg);
}

QDataStream &operator<<(QDataStream &stream, const AccountPrivacyRules &item) {
    stream << static_cast<uint>(item.classType());
    switch(item.classType()) {
    case AccountPrivacyRules::typeAccountPrivacyRules:
        stream << item.rules();
        stream << item.users();
        break;
    }
    return stream;
}

QDataStream &operator>>(QDataStream &stream, AccountPrivacyRules &item) {
    uint type = 0;
    stream >> type;
    item.setClassType(static_cast<AccountPrivacyRules::AccountPrivacyRulesClassType>(type));
    switch(type) {
    case AccountPrivacyRules::typeAccountPrivacyRules: {
        QList<PrivacyRule> m_rules;
        stream >> m_rules;
        item.setRules(m_rules);
        QList<User> m_users;
        stream >> m_users;
        item.setUsers(m_users);
    }
        break;
    }
    return stream;
}

