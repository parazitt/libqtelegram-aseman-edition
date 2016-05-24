// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#ifndef LQTG_TYPE_INPUTCHATPHOTO
#define LQTG_TYPE_INPUTCHATPHOTO

#include "telegramtypeobject.h"

#include <QMetaType>
#include <QVariant>
#include "inputphotocrop.h"
#include "inputfile.h"
#include "inputphoto.h"

class LIBQTELEGRAMSHARED_EXPORT InputChatPhoto : public TelegramTypeObject
{
public:
    enum InputChatPhotoClassType {
        typeInputChatPhotoEmpty = 0x1ca48f57,
        typeInputChatUploadedPhoto = 0x94254732,
        typeInputChatPhoto = 0xb2e1bf08
    };

    InputChatPhoto(InputChatPhotoClassType classType = typeInputChatPhotoEmpty, InboundPkt *in = 0);
    InputChatPhoto(InboundPkt *in);
    InputChatPhoto(const Null&);
    virtual ~InputChatPhoto();

    void setCrop(const InputPhotoCrop &crop);
    InputPhotoCrop crop() const;

    void setFile(const InputFile &file);
    InputFile file() const;

    void setId(const InputPhoto &id);
    InputPhoto id() const;

    void setClassType(InputChatPhotoClassType classType);
    InputChatPhotoClassType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    QMap<QString, QVariant> toMap() const;
    static InputChatPhoto fromMap(const QMap<QString, QVariant> &map);

    bool operator ==(const InputChatPhoto &b) const;

    bool operator==(bool stt) const { return isNull() != stt; }
    bool operator!=(bool stt) const { return !operator ==(stt); }

    QByteArray getHash(QCryptographicHash::Algorithm alg = QCryptographicHash::Md5) const;

private:
    InputPhotoCrop m_crop;
    InputFile m_file;
    InputPhoto m_id;
    InputChatPhotoClassType m_classType;
};

Q_DECLARE_METATYPE(InputChatPhoto)

QDataStream LIBQTELEGRAMSHARED_EXPORT &operator<<(QDataStream &stream, const InputChatPhoto &item);
QDataStream LIBQTELEGRAMSHARED_EXPORT &operator>>(QDataStream &stream, InputChatPhoto &item);

#endif // LQTG_TYPE_INPUTCHATPHOTO
