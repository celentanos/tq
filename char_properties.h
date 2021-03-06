#ifndef CHARPROPERTYLIST_H
#define CHARPROPERTYLIST_H

#include <QList>

#include <limits>

#include "log.h"
#include "char_property.h"

class CharProperties : public QList<CharProperty *>
{
private:
    QString name;

public:
    enum CHAR {
        CHAR_LEVEL,
        CHAR_EXP_POINTS,
        CHAR_MAX_SKILLS,
        CHAR_MONEY,
        CHAR_MODIFIER_POINTS,
        CHAR_SKILL_POINTS,
        CHAR_SACKS,
        CHAR_NUM_OF_DEATHS,
        CHAR_NUMBER
    };

    CharProperties();
    ~CharProperties();

    CharProperty *getProperty(int index);
    CharProperty *getProperty(CharProperties::CHAR index);
};

#endif // CHARPROPERTYLIST_H
