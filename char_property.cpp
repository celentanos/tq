#include "char_property.h"

CharProperty::CharProperty(QByteArray propertyString, QString name, CharProperty::PROP_TYPE type)
{
    this->name = "CharProperty";

    this->propertyString = propertyString;
    this->propertyName = name;
    this->type = type;
    this->access = PROP_READ;

    this->valOld = 0;
    this->valNew = 0;
    this->valMin = 0;
    this->valMax = 0;
    this->valOffset = 0;
    this->valid = false;
}

CharProperty::CharProperty(QByteArray propertyString, QString name, PROP_TYPE type, double min, double max, CharProperty::PROP_ACCESS access)
{
    this->name = "CharProperty";

    this->propertyString = propertyString;
    this->propertyName = name;
    this->type = type;
    this->access = access;

    this->valOld = 0;
    this->valNew = 0;
    this->valMin = min;
    this->valMax = max;
    this->valOffset = 0;
    this->valid = false;
}

int CharProperty::getValLength() const
{
    switch (type) {
    case TYPE_INT:
    case TYPE_FLOAT:
        return 4;
    default:
        Log::getInstance()->log(Log::ERROR, name, __FUNCTION__, "wrong case-type!");
        return 0;
    }
}

CharProperty::PROP_ACCESS CharProperty::getAccess() const
{
    return access;
}

void CharProperty::clearAll()
{
    valOld = 0;
    valNew = 0;
    valOffset = 0;
    valid = false;
}

QByteArray CharProperty::getPropertyString() const
{
    return propertyString;
}

QString CharProperty::getPropertyName() const
{
    return propertyName;
}

QVariant CharProperty::getValOld() const
{
    return valOld;
}

void CharProperty::setValOld(const QVariant &value)
{
    valOld = value;
    emit signalValOldChanged(value.toString());
    setValNew(valOld);
}

QVariant CharProperty::getValNew() const
{
    return valNew;
}

void CharProperty::setValNew(const QVariant &value)
{
    bool b = false;
    switch (type) {
    case TYPE_INT:
        value.toString().toInt(&b);
        break;
    case TYPE_FLOAT:
        value.toString().toFloat(&b);
        break;
    default:
        Log::getInstance()->log(Log::FAILURE, name, __FUNCTION__, "missing value-type!");
        return;
    }
    if(!b) {
        emit signalValNewChanged(valOld.toString());
        Log::getInstance()->log(Log::FAILURE, name, __FUNCTION__, "value cannot be converted!");
        return;
    }
    if(valMin != 0.0 || valMax != 0.0) {
        if(value.toDouble() < valMin) {
            emit signalValNewLimit(QString::number(valMin));
            Log::getInstance()->log(Log::FAILURE, name, __FUNCTION__, propertyString + ": reach min-value!");
            return;
        }
        if(value.toDouble() > valMax) {
            emit signalValNewLimit(QString::number(valMax));
            Log::getInstance()->log(Log::FAILURE, name, __FUNCTION__, propertyString + ": reach max-value!");
            return;
        }
    }
    valNew = value;
    emit signalValNewChanged(valNew.toString());
    return;
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

void CharProperty::slotSetValNew(const QVariant &value)
{
    setValNew(value);
}
