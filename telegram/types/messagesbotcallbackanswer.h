// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#ifndef LQTG_TYPE_MESSAGESBOTCALLBACKANSWER
#define LQTG_TYPE_MESSAGESBOTCALLBACKANSWER

#include "telegramtypeobject.h"

#include <QMetaType>
#include <QVariant>
#include <QtGlobal>
#include <QString>

class LIBQTELEGRAMSHARED_EXPORT MessagesBotCallbackAnswer : public TelegramTypeObject
{
public:
    enum MessagesBotCallbackAnswerClassType {
        typeMessagesBotCallbackAnswer = 0x1264f1c6
    };

    MessagesBotCallbackAnswer(MessagesBotCallbackAnswerClassType classType = typeMessagesBotCallbackAnswer, InboundPkt *in = 0);
    MessagesBotCallbackAnswer(InboundPkt *in);
    MessagesBotCallbackAnswer(const Null&);
    virtual ~MessagesBotCallbackAnswer();

    void setAlert(bool alert);
    bool alert() const;

    void setFlags(qint32 flags);
    qint32 flags() const;

    void setMessage(const QString &message);
    QString message() const;

    void setClassType(MessagesBotCallbackAnswerClassType classType);
    MessagesBotCallbackAnswerClassType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    QMap<QString, QVariant> toMap() const;
    static MessagesBotCallbackAnswer fromMap(const QMap<QString, QVariant> &map);

    bool operator ==(const MessagesBotCallbackAnswer &b) const;

    bool operator==(bool stt) const { return isNull() != stt; }
    bool operator!=(bool stt) const { return !operator ==(stt); }

    QByteArray getHash(QCryptographicHash::Algorithm alg = QCryptographicHash::Md5) const;

private:
    qint32 m_flags;
    QString m_message;
    MessagesBotCallbackAnswerClassType m_classType;
};

Q_DECLARE_METATYPE(MessagesBotCallbackAnswer)

QDataStream LIBQTELEGRAMSHARED_EXPORT &operator<<(QDataStream &stream, const MessagesBotCallbackAnswer &item);
QDataStream LIBQTELEGRAMSHARED_EXPORT &operator>>(QDataStream &stream, MessagesBotCallbackAnswer &item);

#endif // LQTG_TYPE_MESSAGESBOTCALLBACKANSWER
