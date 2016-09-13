#include "char_skill.h"

int CharSkill::getOffsetBegin() const
{
    return offsetBegin;
}

void CharSkill::setOffsetBegin(int value)
{
    offsetBegin = value;
}

int CharSkill::getOffsetEnd() const
{
    return offsetEnd;
}

void CharSkill::setOffsetEnd(int value)
{
    offsetEnd = value;
}

int CharSkill::getSkillLevel() const
{
    return skillLevel;
}

void CharSkill::setSkillLevel(int value)
{
    skillLevel = value;
}

int CharSkill::getSkillLength() const
{
    return skillLength;
}

void CharSkill::setSkillLength(int value)
{
    skillLength = value;
}

QByteArray CharSkill::getSkillName() const
{
    return skillName;
}

QByteArray CharSkill::getBlockBegin() const
{
    return blockBegin;
}

QByteArray CharSkill::getBlockEnd() const
{
    return blockEnd;
}

QString CharSkill::getSkillName0() const
{
    return skillName0;
}

void CharSkill::setSkillName0(const QString &value)
{
    skillName0 = value;

    QStringList items = skillName0.split("/");
    if(items.size() < SKILL_ITEMS)
        items = skillName0.split("\\");
    if(items.size() < SKILL_ITEMS) {
        Log::getInstance()->log(Log::FAILURE, name, __FUNCTION__, "to few skill-items!");
        return;
    }
    if(items.size() == SKILL_ITEMS)
        skillName1 = items.at(2);
    else if(items.size() == SKILL_ITEMS_XPACK)
        skillName1 = items.at(3);

    QStringList items2;
    if(items.size() == SKILL_ITEMS)
        items2 = items.at(3).split(".");
    else if(items.size() == SKILL_ITEMS_XPACK)
        items2 = items.at(4).split(".");

    if(items2.size() < 2) {
        Log::getInstance()->log(Log::FAILURE, name, __FUNCTION__, "to few skill-items2!");
        return;
    }
    skillName2 = items2.at(0);
}

QString CharSkill::getSkillName1() const
{
    return skillName1;
}

QString CharSkill::getSkillName2() const
{
    return skillName2;
}

CharSkill::CharSkill()
{
    name = "CharSkill";

    skillName = "skillName";
    blockBegin = "begin_block";
    blockEnd = "end_block";
}
