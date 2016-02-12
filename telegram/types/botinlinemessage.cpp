// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "botinlinemessage.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"
#include "../coretypes.h"

BotInlineMessage::BotInlineMessage(BotInlineMessageType classType, InboundPkt *in) :
    m_flags(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

BotInlineMessage::BotInlineMessage(InboundPkt *in) :
    m_flags(0),
    m_classType(typeBotInlineMessageMediaAuto)
{
    fetch(in);
}

BotInlineMessage::BotInlineMessage(const Null &null) :
    TelegramTypeObject(null),
    m_flags(0),
    m_classType(typeBotInlineMessageMediaAuto)
{
}

BotInlineMessage::~BotInlineMessage() {
}

void BotInlineMessage::setCaption(const QString &caption) {
    m_caption = caption;
}

QString BotInlineMessage::caption() const {
    return m_caption;
}

void BotInlineMessage::setEntities(const QList<MessageEntity> &entities) {
    m_entities = entities;
}

QList<MessageEntity> BotInlineMessage::entities() const {
    return m_entities;
}

void BotInlineMessage::setFlags(qint32 flags) {
    m_flags = flags;
}

qint32 BotInlineMessage::flags() const {
    return m_flags;
}

void BotInlineMessage::setMessage(const QString &message) {
    m_message = message;
}

QString BotInlineMessage::message() const {
    return m_message;
}

void BotInlineMessage::setNoWebpage(bool noWebpage) {
    if(noWebpage) m_flags = (m_flags | (1<<0));
    else m_flags = (m_flags & ~(1<<0));
}

bool BotInlineMessage::noWebpage() const {
    return (m_flags & 1<<0);
}

bool BotInlineMessage::operator ==(const BotInlineMessage &b) const {
    return m_classType == b.m_classType &&
           m_caption == b.m_caption &&
           m_entities == b.m_entities &&
           m_flags == b.m_flags &&
           m_message == b.m_message;
}

void BotInlineMessage::setClassType(BotInlineMessage::BotInlineMessageType classType) {
    m_classType = classType;
}

BotInlineMessage::BotInlineMessageType BotInlineMessage::classType() const {
    return m_classType;
}

bool BotInlineMessage::fetch(InboundPkt *in) {
    LQTG_FETCH_LOG;
    int x = in->fetchInt();
    switch(x) {
    case typeBotInlineMessageMediaAuto: {
        m_caption = in->fetchQString();
        m_classType = static_cast<BotInlineMessageType>(x);
        return true;
    }
        break;
    
    case typeBotInlineMessageText: {
        m_flags = in->fetchInt();
        m_message = in->fetchQString();
        if(m_flags & 1<<1) {
            if(in->fetchInt() != (qint32)CoreTypes::typeVector) return false;
            qint32 m_entities_length = in->fetchInt();
            m_entities.clear();
            for (qint32 i = 0; i < m_entities_length; i++) {
                MessageEntity type;
                if(m_flags & 1<<1) {
                type.fetch(in);
            }
                m_entities.append(type);
            }
        }
        m_classType = static_cast<BotInlineMessageType>(x);
        return true;
    }
        break;
    
    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool BotInlineMessage::push(OutboundPkt *out) const {
    out->appendInt(m_classType);
    switch(m_classType) {
    case typeBotInlineMessageMediaAuto: {
        out->appendQString(m_caption);
        return true;
    }
        break;
    
    case typeBotInlineMessageText: {
        out->appendInt(m_flags);
        out->appendQString(m_message);
        out->appendInt(CoreTypes::typeVector);
        out->appendInt(m_entities.count());
        for (qint32 i = 0; i < m_entities.count(); i++) {
            m_entities[i].push(out);
        }
        return true;
    }
        break;
    
    default:
        return false;
    }
}
