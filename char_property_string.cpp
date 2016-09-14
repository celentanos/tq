#include "char_property_string.h"

QByteArray CharPropertyString::getBaValOld() const
{
    return baValOld;
}

void CharPropertyString::setBaValOld(const QByteArray &value)
{
    baValOld = value;
}

QByteArray CharPropertyString::getBaValNew() const
{
    return baValNew;
}

void CharPropertyString::setBaValNew(const QByteArray &value)
{
    baValNew = value;
}

CharPropertyString::CharPropertyString(QByteArray property, QString name, PROP_ACCESS access) : CharProperty (property, name, access)
{
    this->name = "CharPropertyString";
    this->type = PROP_STRING;
}
