// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#ifndef LQTG_TYPE_WALLPAPER
#define LQTG_TYPE_WALLPAPER

#include "telegramtypeobject.h"

#include <QMetaType>
#include <QVariant>
#include <QtGlobal>
#include <QList>
#include "photosize.h"
#include <QString>

class LIBQTELEGRAMSHARED_EXPORT WallPaper : public TelegramTypeObject
{
public:
    enum WallPaperClassType {
        typeWallPaper = 0xccb03657,
        typeWallPaperSolid = 0x63117f24
    };

    WallPaper(WallPaperClassType classType = typeWallPaper, InboundPkt *in = 0);
    WallPaper(InboundPkt *in);
    WallPaper(const Null&);
    virtual ~WallPaper();

    void setBgColor(qint32 bgColor);
    qint32 bgColor() const;

    void setColor(qint32 color);
    qint32 color() const;

    void setId(qint32 id);
    qint32 id() const;

    void setSizes(const QList<PhotoSize> &sizes);
    QList<PhotoSize> sizes() const;

    void setTitle(const QString &title);
    QString title() const;

    void setClassType(WallPaperClassType classType);
    WallPaperClassType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    QMap<QString, QVariant> toMap() const;
    static WallPaper fromMap(const QMap<QString, QVariant> &map);

    bool operator ==(const WallPaper &b) const;

    bool operator==(bool stt) const { return isNull() != stt; }
    bool operator!=(bool stt) const { return !operator ==(stt); }

    QByteArray getHash(QCryptographicHash::Algorithm alg = QCryptographicHash::Md5) const;

private:
    qint32 m_bgColor;
    qint32 m_color;
    qint32 m_id;
    QList<PhotoSize> m_sizes;
    QString m_title;
    WallPaperClassType m_classType;
};

Q_DECLARE_METATYPE(WallPaper)

QDataStream LIBQTELEGRAMSHARED_EXPORT &operator<<(QDataStream &stream, const WallPaper &item);
QDataStream LIBQTELEGRAMSHARED_EXPORT &operator>>(QDataStream &stream, WallPaper &item);

#endif // LQTG_TYPE_WALLPAPER
