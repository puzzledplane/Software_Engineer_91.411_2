#include "Device.h"


Device::Device(QObject* parent) : QObject(parent)
{
    ;
}


QString Device::getTypeStr() const
{
    return typeStr;
}


void Device::setTypeStr(const QString& typeStr)
{
    this->typeStr = typeStr;
}


QString Device::getIdStr() const
{
    return idStr;
}


void Device::setIdStr(const QString& idStr)
{
    this->idStr = idStr;
}


QString Device::getIpAddressStr()
{
    return ipAddressStr;
}


void Device::setIpAddressStr(const QString& ipAddressStr)
{
    this->ipAddressStr = ipAddressStr;
}


Device::~Device()
{
    ;
}