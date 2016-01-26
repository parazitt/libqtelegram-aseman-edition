// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#ifndef LQTG_TYPE_UPDATESTYPE
#define LQTG_TYPE_UPDATESTYPE

#include "telegramtypeobject.h"

#include <QMetaType>
#include <QtGlobal>
#include <QList>
#include "chat.h"
#include "messageentity.h"
#include "peer.h"
#include "messagemedia.h"
#include <QString>
#include "update.h"
#include "user.h"

class LIBQTELEGRAMSHARED_EXPORT UpdatesType : public TelegramTypeObject
{
public:
    enum UpdatesTypeType {
        typeUpdatesTooLong = 0xe317af7e,
        typeUpdateShortMessage = 0x13e4deaa,
        typeUpdateShortChatMessage = 0x248afa62,
        typeUpdateShort = 0x78d4dec1,
        typeUpdatesCombined = 0x725b04c3,
        typeUpdates = 0x74ae4240,
        typeUpdateShortSentMessage = 0x11f1331c
    };

    UpdatesType(UpdatesTypeType classType = typeUpdatesTooLong, InboundPkt *in = 0);
    UpdatesType(InboundPkt *in);
    UpdatesType(const Null&);
    virtual ~UpdatesType();

    void setChatId(qint32 chatId);
    qint32 chatId() const;

    void setChats(const QList<Chat> &chats);
    QList<Chat> chats() const;

    void setDate(qint32 date);
    qint32 date() const;

    void setEntities(const QList<MessageEntity> &entities);
    QList<MessageEntity> entities() const;

    void setFlags(qint32 flags);
    qint32 flags() const;

    void setFromId(qint32 fromId);
    qint32 fromId() const;

    void setFwdDate(qint32 fwdDate);
    qint32 fwdDate() const;

    void setFwdFromId(const Peer &fwdFromId);
    Peer fwdFromId() const;

    void setId(qint32 id);
    qint32 id() const;

    void setMedia(const MessageMedia &media);
    MessageMedia media() const;

    void setMediaUnread(bool mediaUnread);
    bool mediaUnread() const;

    void setMentioned(bool mentioned);
    bool mentioned() const;

    void setMessage(const QString &message);
    QString message() const;

    void setOut(bool out);
    bool out() const;

    void setPts(qint32 pts);
    qint32 pts() const;

    void setPtsCount(qint32 ptsCount);
    qint32 ptsCount() const;

    void setReplyToMsgId(qint32 replyToMsgId);
    qint32 replyToMsgId() const;

    void setSeq(qint32 seq);
    qint32 seq() const;

    void setSeqStart(qint32 seqStart);
    qint32 seqStart() const;

    void setUnread(bool unread);
    bool unread() const;

    void setUpdate(const Update &update);
    Update update() const;

    void setUpdates(const QList<Update> &updates);
    QList<Update> updates() const;

    void setUserId(qint32 userId);
    qint32 userId() const;

    void setUsers(const QList<User> &users);
    QList<User> users() const;

    void setViaBotId(qint32 viaBotId);
    qint32 viaBotId() const;

    void setClassType(UpdatesTypeType classType);
    UpdatesTypeType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    bool operator ==(const UpdatesType &b) const;

    bool operator==(bool stt) const { return isNull() != stt; }
    bool operator!=(bool stt) const { return !operator ==(stt); }

private:
    qint32 m_chatId;
    QList<Chat> m_chats;
    qint32 m_date;
    QList<MessageEntity> m_entities;
    qint32 m_flags;
    qint32 m_fromId;
    qint32 m_fwdDate;
    Peer m_fwdFromId;
    qint32 m_id;
    MessageMedia m_media;
    QString m_message;
    qint32 m_pts;
    qint32 m_ptsCount;
    qint32 m_replyToMsgId;
    qint32 m_seq;
    qint32 m_seqStart;
    Update m_update;
    QList<Update> m_updates;
    qint32 m_userId;
    QList<User> m_users;
    qint32 m_viaBotId;
    UpdatesTypeType m_classType;
};

Q_DECLARE_METATYPE(UpdatesType)

#endif // LQTG_TYPE_UPDATESTYPE