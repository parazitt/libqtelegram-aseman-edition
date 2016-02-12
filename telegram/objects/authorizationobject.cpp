// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "authorizationobject.h"

AuthorizationObject::AuthorizationObject(const Authorization &core, QObject *parent) :
    TelegramTypeQObject(parent),
    m_core(core)
{
}

AuthorizationObject::AuthorizationObject(QObject *parent) :
    TelegramTypeQObject(parent),
    m_core()
{
}

AuthorizationObject::~AuthorizationObject() {
}

void AuthorizationObject::setApiId(qint32 apiId) {
    if(m_core.apiId() == apiId) return;
    m_core.setApiId(apiId);
    Q_EMIT apiIdChanged();
    Q_EMIT coreChanged();
}

qint32 AuthorizationObject::apiId() const {
    return m_core.apiId();
}

void AuthorizationObject::setAppName(const QString &appName) {
    if(m_core.appName() == appName) return;
    m_core.setAppName(appName);
    Q_EMIT appNameChanged();
    Q_EMIT coreChanged();
}

QString AuthorizationObject::appName() const {
    return m_core.appName();
}

void AuthorizationObject::setAppVersion(const QString &appVersion) {
    if(m_core.appVersion() == appVersion) return;
    m_core.setAppVersion(appVersion);
    Q_EMIT appVersionChanged();
    Q_EMIT coreChanged();
}

QString AuthorizationObject::appVersion() const {
    return m_core.appVersion();
}

void AuthorizationObject::setCountry(const QString &country) {
    if(m_core.country() == country) return;
    m_core.setCountry(country);
    Q_EMIT countryChanged();
    Q_EMIT coreChanged();
}

QString AuthorizationObject::country() const {
    return m_core.country();
}

void AuthorizationObject::setDateActive(qint32 dateActive) {
    if(m_core.dateActive() == dateActive) return;
    m_core.setDateActive(dateActive);
    Q_EMIT dateActiveChanged();
    Q_EMIT coreChanged();
}

qint32 AuthorizationObject::dateActive() const {
    return m_core.dateActive();
}

void AuthorizationObject::setDateCreated(qint32 dateCreated) {
    if(m_core.dateCreated() == dateCreated) return;
    m_core.setDateCreated(dateCreated);
    Q_EMIT dateCreatedChanged();
    Q_EMIT coreChanged();
}

qint32 AuthorizationObject::dateCreated() const {
    return m_core.dateCreated();
}

void AuthorizationObject::setDeviceModel(const QString &deviceModel) {
    if(m_core.deviceModel() == deviceModel) return;
    m_core.setDeviceModel(deviceModel);
    Q_EMIT deviceModelChanged();
    Q_EMIT coreChanged();
}

QString AuthorizationObject::deviceModel() const {
    return m_core.deviceModel();
}

void AuthorizationObject::setFlags(qint32 flags) {
    if(m_core.flags() == flags) return;
    m_core.setFlags(flags);
    Q_EMIT flagsChanged();
    Q_EMIT coreChanged();
}

qint32 AuthorizationObject::flags() const {
    return m_core.flags();
}

void AuthorizationObject::setHash(qint64 hash) {
    if(m_core.hash() == hash) return;
    m_core.setHash(hash);
    Q_EMIT hashChanged();
    Q_EMIT coreChanged();
}

qint64 AuthorizationObject::hash() const {
    return m_core.hash();
}

void AuthorizationObject::setIp(const QString &ip) {
    if(m_core.ip() == ip) return;
    m_core.setIp(ip);
    Q_EMIT ipChanged();
    Q_EMIT coreChanged();
}

QString AuthorizationObject::ip() const {
    return m_core.ip();
}

void AuthorizationObject::setPlatform(const QString &platform) {
    if(m_core.platform() == platform) return;
    m_core.setPlatform(platform);
    Q_EMIT platformChanged();
    Q_EMIT coreChanged();
}

QString AuthorizationObject::platform() const {
    return m_core.platform();
}

void AuthorizationObject::setRegion(const QString &region) {
    if(m_core.region() == region) return;
    m_core.setRegion(region);
    Q_EMIT regionChanged();
    Q_EMIT coreChanged();
}

QString AuthorizationObject::region() const {
    return m_core.region();
}

void AuthorizationObject::setSystemVersion(const QString &systemVersion) {
    if(m_core.systemVersion() == systemVersion) return;
    m_core.setSystemVersion(systemVersion);
    Q_EMIT systemVersionChanged();
    Q_EMIT coreChanged();
}

QString AuthorizationObject::systemVersion() const {
    return m_core.systemVersion();
}

AuthorizationObject &AuthorizationObject::operator =(const Authorization &b) {
    if(m_core == b) return *this;
    m_core = b;

    Q_EMIT apiIdChanged();
    Q_EMIT appNameChanged();
    Q_EMIT appVersionChanged();
    Q_EMIT countryChanged();
    Q_EMIT dateActiveChanged();
    Q_EMIT dateCreatedChanged();
    Q_EMIT deviceModelChanged();
    Q_EMIT flagsChanged();
    Q_EMIT hashChanged();
    Q_EMIT ipChanged();
    Q_EMIT platformChanged();
    Q_EMIT regionChanged();
    Q_EMIT systemVersionChanged();
    Q_EMIT coreChanged();
    return *this;
}

bool AuthorizationObject::operator ==(const Authorization &b) const {
    return m_core == b;
}

void AuthorizationObject::setClassType(quint32 classType) {
    Authorization::AuthorizationType result;
    switch(classType) {
    case TypeAuthorization:
        result = Authorization::typeAuthorization;
        break;
    default:
        result = Authorization::typeAuthorization;
        break;
    }

    if(m_core.classType() == result) return;
    m_core.setClassType(result);
    Q_EMIT classTypeChanged();
    Q_EMIT coreChanged();
}

quint32 AuthorizationObject::classType() const {
    int result;
    switch(static_cast<qint64>(m_core.classType())) {
    case Authorization::typeAuthorization:
        result = TypeAuthorization;
        break;
    default:
        result = TypeAuthorization;
        break;
    }

    return result;
}

void AuthorizationObject::setCore(const Authorization &core) {
    operator =(core);
}

Authorization AuthorizationObject::core() const {
    return m_core;
}
