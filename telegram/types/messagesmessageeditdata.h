// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#ifndef LQTG_TYPE_MESSAGESMESSAGEEDITDATA
#define LQTG_TYPE_MESSAGESMESSAGEEDITDATA

#include "telegramtypeobject.h"

#include <QMetaType>
#include <QVariant>
#include <QtGlobal>

class LIBQTELEGRAMSHARED_EXPORT MessagesMessageEditData : public TelegramTypeObject
{
public:
    enum MessagesMessageEditDataClassType {
        typeMessagesMessageEditData = 0x26b5dde6
    };

    MessagesMessageEditData(MessagesMessageEditDataClassType classType = typeMessagesMessageEditData, InboundPkt *in = 0);
    MessagesMessageEditData(InboundPkt *in);
    MessagesMessageEditData(const Null&);
    virtual ~MessagesMessageEditData();

    void setCaption(bool caption);
    bool caption() const;

    void setFlags(qint32 flags);
    qint32 flags() const;

    void setClassType(MessagesMessageEditDataClassType classType);
    MessagesMessageEditDataClassType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    QMap<QString, QVariant> toMap() const;
    static MessagesMessageEditData fromMap(const QMap<QString, QVariant> &map);

    bool operator ==(const MessagesMessageEditData &b) const;

    bool operator==(bool stt) const { return isNull() != stt; }
    bool operator!=(bool stt) const { return !operator ==(stt); }

    QByteArray getHash(QCryptographicHash::Algorithm alg = QCryptographicHash::Md5) const;

private:
    qint32 m_flags;
    MessagesMessageEditDataClassType m_classType;
};

Q_DECLARE_METATYPE(MessagesMessageEditData)

QDataStream LIBQTELEGRAMSHARED_EXPORT &operator<<(QDataStream &stream, const MessagesMessageEditData &item);
QDataStream LIBQTELEGRAMSHARED_EXPORT &operator>>(QDataStream &stream, MessagesMessageEditData &item);

#endif // LQTG_TYPE_MESSAGESMESSAGEEDITDATA
