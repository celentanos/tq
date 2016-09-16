#include "character.h"

int Character::getIntFromLittle(const QByteArray &ba)
{
    QDataStream ds(ba);
    ds.setByteOrder(QDataStream::LittleEndian);
    int i;
    ds >> i;
    return i;
}

QByteArray Character::getBaLittleFromInt(int val)
{
    QByteArray ba;
    ba.reserve(4);
    QDataStream ds(&ba, QIODevice::ReadWrite);
    ds.setByteOrder(QDataStream::LittleEndian);
    ds << val;
    return ba;
}

void Character::clearAll()
{
    for (int i = 0; i < properties->size(); ++i) {
        properties->at(i)->setValOld(0);
        properties->at(i)->setValNew(0);
        properties->at(i)->setValOffset(0);
        properties->at(i)->setValid(0);
    }
    qDeleteAll(skills->begin(), skills->end());
    skills->clear();
}

CharProperties *Character::getProperties() const
{
    return properties;
}

CharSkills *Character::getSkills() const
{
    return skills;
}

void Character::resetSkills()
{
    if(skills->size() == 0) {
        Log::getInstance()->log(Log::INFO, name, __FUNCTION__, "no skills found!");
        return;
    }
    int skillNumber = 0;
    int skillPoints = 0;
    for (int i = 0; i < skills->size(); ++i) {
        if(skillList.contains(skills->at(i)->getSkillName1().toLower())) {
            character->remove(skills->at(i)->getOffsetBegin(),
                              skills->at(i)->getOffsetEnd() - skills->at(i)->getOffsetBegin());
            skillPoints += skills->at(i)->getSkillLevel();
            skillNumber++;
        }
    }
    if(skillNumber == 0) {
        Log::getInstance()->log(Log::INFO, name, __FUNCTION__, "no resetable skills found!");
        return;
    }
    clearAll();
    parseProperties();
    parseSkills();

    properties->at(CharProperties::CHAR_MAX_SKILLS)->setValNew(
        properties->at(CharProperties::CHAR_MAX_SKILLS)->getValOld() - skillNumber);

    properties->at(CharProperties::CHAR_SKILL_POINTS)->setValNew(skillPoints);
}

void Character::parseProperties()
{
    for (int i = 0; i < properties->size(); ++i) {
        int pos = character->indexOf(properties->getProperty(i)->getProperty());
        if(pos < 0) {
            Log::getInstance()->log(Log::FAILURE, name, __FUNCTION__, "no property: " + properties->getProperty(i)->getProperty() + " found!");
            return;
        }
        properties->getProperty(i)->setValOffset(pos + properties->getProperty(i)->getProperty().size());
        properties->getProperty(i)->setValid(true);
        properties->getProperty(i)->setValOld(getIntFromLittle(character->mid(
                properties->getProperty(i)->getValOffset(),
                properties->getProperty(i)->getValLength())));
    }
}

void Character::parseSkills()
{
    int posBegin = 0;
    for(int i = 0; i < properties->getProperty(CharProperties::CHAR_MAX_SKILLS)->getValOld(); ++i) {
        CharSkill *skill = new CharSkill;
        int posEnd = 0;
        int posBegin2 = 0;
        while(1) {
            posBegin = character->indexOf(skill->getBlockBeginString(), posBegin);
            if(posBegin == -1) {
                delete skill;
                break;
            }
            posEnd = character->indexOf(skill->getBlockEndString(), posBegin);
            posBegin2 = character->indexOf(skill->getBlockBeginString(), posBegin + 1);
            if (posBegin2 != -1 && posBegin2 < posEnd) {
                posBegin++;
                continue;
            }
            // skillName -------------------------------------------------------
            int skillNameOffset = character->indexOf(skill->getSkillNameString(), posBegin);
            if(skillNameOffset > posEnd) {
                posBegin++;
                continue;
            } else if(skillNameOffset == -1) {
                Log::getInstance()->log(Log::FAILURE, name, __FUNCTION__, "no skillName found!");
                return;
            }
            int skillNameLength = getIntFromLittle(character->mid(
                    skillNameOffset + skill->getSkillNameString().size(),
                    INT_LENGTH));
            skill->setSkillName0(character->mid(
                                     skillNameOffset + skill->getSkillNameString().size() + INT_LENGTH,
                                     skillNameLength));
            // skillLevel ------------------------------------------------------
            int skillLevelOffset = character->indexOf(skill->getSkillLevelString(), posBegin);
            if(skillLevelOffset > posEnd) {
                Log::getInstance()->log(Log::FAILURE, name, __FUNCTION__, "no skillLevel found!");
                return;
            }
            skill->setSkillLevel(getIntFromLittle(character->mid(
                    skillLevelOffset + skill->getSkillLevelString().size(),
                    INT_LENGTH)));
            // offsets ---------------------------------------------------------
            skill->setOffsetBegin(posBegin - INT_LENGTH);
            skill->setOffsetEnd(posEnd + INT_LENGTH);

            skills->append(skill);
            posBegin++;
            break;
        }
    }
}

QByteArray *Character::getCharacter() const
{
    return character;
}

Character::Character()
{
    name = "Character";
    character = new QByteArray;
    properties = new CharProperties;
    skills = new CharSkills;

    skillList << "defensive"
              << "dream"
              << "earth"
              << "hunting"
              << "nature"
              << "spirit"
              << "stealth"
              << "storm"
              << "warfare";
}

Character::~Character()
{
    if(character)
        delete character;
    if(properties)
        delete properties;
    if(skills)
        delete skills;
}
