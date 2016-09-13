#include "char_properties.h"

CharProperties::CharProperties()
{
    name = "CharProperties";

//    this->append(new CharPropertyString("playerCharacterClass", 4));
//    this->append(new CharPropertyString("myPlayerName", 4));
    this->append(new CharProperty("playerLevel", "player level", CharProperty::PROP_WRITE));
    this->append(new CharProperty("max", "all skills", CharProperty::PROP_READ));
    this->append(new CharProperty("money", "money", CharProperty::PROP_WRITE));
    this->append(new CharProperty("modifierPoints", "modifier points", CharProperty::PROP_WRITE));
    this->append(new CharProperty("skillPoints", "skill points", CharProperty::PROP_WRITE));
    this->append(new CharProperty("numberOfDeaths", "number of deaths", CharProperty::PROP_WRITE));
}

CharProperties::~CharProperties()
{
    if(this->size() > 0) {
        qDeleteAll(this->begin(), this->end());
        this->clear();
    }
}

CharProperty *CharProperties::getProperty(int index)
{
    if(index > this->size() - 1) {
        Log::getInstance()->log(Log::FAILURE, name, __FUNCTION__, "wrong index!");
        return 0;
    }
    return this->operator[](index);
}

CharProperty *CharProperties::getProperty(CharProperties::CHAR index)
{
    if(index > this->size() - 1) {
        Log::getInstance()->log(Log::FAILURE, name, __FUNCTION__, "wrong index!");
        return 0;
    }
    return this->operator[](index);
}
