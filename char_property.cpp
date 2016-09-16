#include "char_property.h"

CharProperty::CharProperty(QByteArray property, QString name, CharProperty::PROP_ACCESS access, int valLength)
{
    this->name = "CharProperty";
    this->type = PROP_INT;
    this->access = access;

    this->property = property;
    this->propertyName = name;
    this->valLength = valLength;
    this->valOld = 0;
    this->valOffset = 0;
    this->valid = false;
}

QByteArray CharProperty::getProperty() const
{
    return property;
}

int CharProperty::getValOld() const
{
    return valOld;
}

void CharProperty::setValOld(const int &value)
{
    valOld = value;
    emit signalValOldChanged(QString::number(value));
    setValNew(valOld);
}

int CharProperty::getValOffset() const
{
    return valOffset;
}

void CharProperty::setValOffset(const int &value)
{
    valOffset = value;
}

int CharProperty::getValid() const
{
    return valid;
}

void CharProperty::setValid(int value)
{
    valid = value;
}

int CharProperty::getValLength() const
{
    return valLength;
}

int CharProperty::getValNew() const
{
    return valNew;
}

int CharProperty::setValNew(int value)
{
    if(value > std::numeric_limits<int>::max()) {
        Log::getInstance()->log(Log::FAILURE, name, __FUNCTION__, "maxint value!");
        return -1;
    }
    valNew = value;
    emit signalValNewChanged(valNew);
    return 0;
}

void CharProperty::slotSetValue(int value)
{
    valNew = value;
}

QString CharProperty::getPropertyName() const
{
    return propertyName;
}

CharProperty::PROP_ACCESS CharProperty::getAccess() const
{
    return access;
}

QString CharProperty::getSValueOld() const
{
    Log::getInstance()->log(Log::FAILURE, name, __FUNCTION__, "polymorph-function!");
    return "";
}

void CharProperty::setSValueOld(const QString &value)
{
    Log::getInstance()->log(Log::FAILURE, name, __FUNCTION__, "polymorph-function!");
    (void)value;
}

QString CharProperty::getSValueNew() const
{
    Log::getInstance()->log(Log::FAILURE, name, __FUNCTION__, "polymorph-function!");
    return "";
}

void CharProperty::setSValueNew(const QString &value)
{
    Log::getInstance()->log(Log::FAILURE, name, __FUNCTION__, "polymorph-function!");
    (void)value;
}
