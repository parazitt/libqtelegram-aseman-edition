// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#ifndef LQTG_TYPE_TOPPEERCATEGORYPEERS
#define LQTG_TYPE_TOPPEERCATEGORYPEERS

#include "telegramtypeobject.h"

#include <QMetaType>
#include <QVariant>
#include "toppeercategory.h"
#include <QtGlobal>
#include <QList>
#include "toppeer.h"

class LIBQTELEGRAMSHARED_EXPORT TopPeerCategoryPeers : public TelegramTypeObject
{
public:
    enum TopPeerCategoryPeersClassType {
        typeTopPeerCategoryPeers = 0xfb834291
    };

    TopPeerCategoryPeers(TopPeerCategoryPeersClassType classType = typeTopPeerCategoryPeers, InboundPkt *in = 0);
    TopPeerCategoryPeers(InboundPkt *in);
    TopPeerCategoryPeers(const Null&);
    virtual ~TopPeerCategoryPeers();

    void setCategory(const TopPeerCategory &category);
    TopPeerCategory category() const;

    void setCount(qint32 count);
    qint32 count() const;

    void setPeers(const QList<TopPeer> &peers);
    QList<TopPeer> peers() const;

    void setClassType(TopPeerCategoryPeersClassType classType);
    TopPeerCategoryPeersClassType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    QMap<QString, QVariant> toMap() const;
    static TopPeerCategoryPeers fromMap(const QMap<QString, QVariant> &map);

    bool operator ==(const TopPeerCategoryPeers &b) const;

    bool operator==(bool stt) const { return isNull() != stt; }
    bool operator!=(bool stt) const { return !operator ==(stt); }

    QByteArray getHash(QCryptographicHash::Algorithm alg = QCryptographicHash::Md5) const;

private:
    TopPeerCategory m_category;
    qint32 m_count;
    QList<TopPeer> m_peers;
    TopPeerCategoryPeersClassType m_classType;
};

Q_DECLARE_METATYPE(TopPeerCategoryPeers)

QDataStream LIBQTELEGRAMSHARED_EXPORT &operator<<(QDataStream &stream, const TopPeerCategoryPeers &item);
QDataStream LIBQTELEGRAMSHARED_EXPORT &operator>>(QDataStream &stream, TopPeerCategoryPeers &item);

#endif // LQTG_TYPE_TOPPEERCATEGORYPEERS
