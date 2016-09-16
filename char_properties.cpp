#include "char_properties.h"

CharProperties::CharProperties()
{
    name = "CharProperties";

//    this->append(new CharPropertyString("playerCharacterClass", 4));
//    this->append(new CharPropertyString("myPlayerName", 4));
    this->append(new CharProperty("charLevel", "character level", CharProperty::TYPE_INT, 0, 1000));
    this->append(new CharProperty("experiencePoints", "experience points", CharProperty::TYPE_INT, 0, std::numeric_limits<int>::max()));
    this->append(new CharProperty("max", "all skills", CharProperty::TYPE_INT));
    this->append(new CharProperty("money", "money", CharProperty::TYPE_INT, 0, std::numeric_limits<int>::max()));
    this->append(new CharProperty("modifierPoints", "modifier points", CharProperty::TYPE_INT, 0, std::numeric_limits<int>::max()));
    this->append(new CharProperty("skillPoints", "skill points", CharProperty::TYPE_INT, 0, std::numeric_limits<int>::max()));
    this->append(new CharProperty("numberOfSacks", "inventaty sacks", CharProperty::TYPE_INT, 1, 4));
    this->append(new CharProperty("numberOfDeaths", "number of deaths", CharProperty::TYPE_INT, 0, std::numeric_limits<int>::max()));
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
