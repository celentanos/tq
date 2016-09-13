#ifndef CHARSKILLS_H
#define CHARSKILLS_H

#include <QList>

#include "char_skill.h"

class CharSkills : public QList<CharSkill *>
{
public:
    CharSkills();
    ~CharSkills();
};

#endif // CHARSKILLS_H
