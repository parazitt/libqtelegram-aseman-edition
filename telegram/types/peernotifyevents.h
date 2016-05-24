// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#ifndef LQTG_TYPE_PEERNOTIFYEVENTS
#define LQTG_TYPE_PEERNOTIFYEVENTS

#include "telegramtypeobject.h"

#include <QMetaType>
#include <QVariant>

class LIBQTELEGRAMSHARED_EXPORT PeerNotifyEvents : public TelegramTypeObject
{
public:
    enum PeerNotifyEventsClassType {
        typePeerNotifyEventsEmpty = 0xadd53cb3,
        typePeerNotifyEventsAll = 0x6d1ded88
    };

    PeerNotifyEvents(PeerNotifyEventsClassType classType = typePeerNotifyEventsEmpty, InboundPkt *in = 0);
    PeerNotifyEvents(InboundPkt *in);
    PeerNotifyEvents(const Null&);
    virtual ~PeerNotifyEvents();

    void setClassType(PeerNotifyEventsClassType classType);
    PeerNotifyEventsClassType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    QMap<QString, QVariant> toMap() const;
    static PeerNotifyEvents fromMap(const QMap<QString, QVariant> &map);

    bool operator ==(const PeerNotifyEvents &b) const;

    bool operator==(bool stt) const { return isNull() != stt; }
    bool operator!=(bool stt) const { return !operator ==(stt); }

    QByteArray getHash(QCryptographicHash::Algorithm alg = QCryptographicHash::Md5) const;

private:
    PeerNotifyEventsClassType m_classType;
};

Q_DECLARE_METATYPE(PeerNotifyEvents)

QDataStream LIBQTELEGRAMSHARED_EXPORT &operator<<(QDataStream &stream, const PeerNotifyEvents &item);
QDataStream LIBQTELEGRAMSHARED_EXPORT &operator>>(QDataStream &stream, PeerNotifyEvents &item);

#endif // LQTG_TYPE_PEERNOTIFYEVENTS
