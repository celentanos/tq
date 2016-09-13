#include "char_property_string.h"

QByteArray CharPropertyString::getBaValueOld() const
{
    return baValueOld;
}

void CharPropertyString::setBaValueOld(const QByteArray &value)
{
    baValueOld = value;
}

QByteArray CharPropertyString::getBaValueNew() const
{
    return baValueNew;
}

void CharPropertyString::setBaValueNew(const QByteArray &value)
{
    baValueNew = value;
}

CharPropertyString::CharPropertyString(QByteArray property, QString name, PROP_ACCESS access) : CharProperty (property, name, access)
{
    this->name = "CharPropertyString";
    this->type = PROP_STRING;
}
