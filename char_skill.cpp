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

QByteArray CharSkill::getSkillNameString() const
{
    return skillNameString;
}

QByteArray CharSkill::getBlockBeginString() const
{
    return blockBeginString;
}

QByteArray CharSkill::getBlockEndString() const
{
    return blockEndString;
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
    skillName1 = items.at(items.size() - 2);            // vorletzter

    QStringList items2;
    items2 = items.at(items.size() - 1).split(".");     // letzter

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

QByteArray CharSkill::getSkillLevelString() const
{
    return skillLevelString;
}

CharSkill::CharSkill()
{
    name = "CharSkill";

    skillNameString = "skillName";
    skillLevelString = "skillLevel";
    blockBeginString = "begin_block";
    blockEndString = "end_block";
}
