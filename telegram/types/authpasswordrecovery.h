// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#ifndef LQTG_TYPE_AUTHPASSWORDRECOVERY
#define LQTG_TYPE_AUTHPASSWORDRECOVERY

#include "telegramtypeobject.h"

#include <QMetaType>
#include <QVariant>
#include <QString>

class LIBQTELEGRAMSHARED_EXPORT AuthPasswordRecovery : public TelegramTypeObject
{
public:
    enum AuthPasswordRecoveryClassType {
        typeAuthPasswordRecovery = 0x137948a5
    };

    AuthPasswordRecovery(AuthPasswordRecoveryClassType classType = typeAuthPasswordRecovery, InboundPkt *in = 0);
    AuthPasswordRecovery(InboundPkt *in);
    AuthPasswordRecovery(const Null&);
    virtual ~AuthPasswordRecovery();

    void setEmailPattern(const QString &emailPattern);
    QString emailPattern() const;

    void setClassType(AuthPasswordRecoveryClassType classType);
    AuthPasswordRecoveryClassType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    QMap<QString, QVariant> toMap() const;
    static AuthPasswordRecovery fromMap(const QMap<QString, QVariant> &map);

    bool operator ==(const AuthPasswordRecovery &b) const;

    bool operator==(bool stt) const { return isNull() != stt; }
    bool operator!=(bool stt) const { return !operator ==(stt); }

    QByteArray getHash(QCryptographicHash::Algorithm alg = QCryptographicHash::Md5) const;

private:
    QString m_emailPattern;
    AuthPasswordRecoveryClassType m_classType;
};

Q_DECLARE_METATYPE(AuthPasswordRecovery)

QDataStream LIBQTELEGRAMSHARED_EXPORT &operator<<(QDataStream &stream, const AuthPasswordRecovery &item);
QDataStream LIBQTELEGRAMSHARED_EXPORT &operator>>(QDataStream &stream, AuthPasswordRecovery &item);

#endif // LQTG_TYPE_AUTHPASSWORDRECOVERY
