#ifndef CHARPROPERTYSTRING_H
#define CHARPROPERTYSTRING_H

#include "char_property.h"

class CharPropertyString : public CharProperty
{
private:
    QByteArray baValueOld;
    QByteArray baValueNew;

public:
    CharPropertyString(QByteArray property, QString name, CharProperty::PROP_ACCESS access);

    QByteArray getBaValueOld() const;
    void setBaValueOld(const QByteArray &value);
    QByteArray getBaValueNew() const;
    void setBaValueNew(const QByteArray &value);
};

#endif // CHARPROPERTYSTRING_H
