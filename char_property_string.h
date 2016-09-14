#ifndef CHARPROPERTYSTRING_H
#define CHARPROPERTYSTRING_H

#include "char_property.h"

class CharPropertyString : public CharProperty
{
private:
    QByteArray baValOld;
    QByteArray baValNew;

public:
    CharPropertyString(QByteArray property, QString name, CharProperty::PROP_ACCESS access);

    QByteArray getBaValOld() const;
    void setBaValOld(const QByteArray &value);
    QByteArray getBaValNew() const;
    void setBaValNew(const QByteArray &value);
};

#endif // CHARPROPERTYSTRING_H
