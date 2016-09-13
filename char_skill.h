#ifndef CHARSKILL_H
#define CHARSKILL_H

#include <QObject>

#include "log.h"

#define SKILL_ITEMS         4
#define SKILL_ITEMS_XPACK   5

class CharSkill : public QObject
{
    Q_OBJECT
private:
    QString name;

    int skillLength;
    QByteArray skillName;
    QString skillName0;     /// full-name
    QString skillName1;
    QString skillName2;
    int skillLevel;

    QByteArray blockBegin;
    QByteArray blockEnd;
    int offsetBegin;
    int offsetEnd;

public:
    CharSkill();
    int getOffsetBegin() const;
    void setOffsetBegin(int value);
    int getOffsetEnd() const;
    void setOffsetEnd(int value);
    int getSkillLevel() const;
    void setSkillLevel(int value);
    int getSkillLength() const;
    void setSkillLength(int value);
    QByteArray getSkillName() const;
    QByteArray getBlockBegin() const;
    QByteArray getBlockEnd() const;
    QString getSkillName0() const;
    void setSkillName0(const QString &value);
    QString getSkillName1() const;
    QString getSkillName2() const;
};

#endif // CHARSKILL_H
