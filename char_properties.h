#ifndef CHARPROPERTYLIST_H
#define CHARPROPERTYLIST_H

#include <QList>

#include "log.h"
#include "char_property.h"
#include "char_property_string.h"

class CharProperties : public QList<CharProperty *>
{
private:
    QString name;

public:
    enum CHAR {
        CHAR_PLAYER_LEVEL,
        CHAR_MAX_SKILLS,
        CHAR_MONEY,
        CHAR_MODIFIER_POINTS,
        CHAR_SKILL_POINTS,
        CHAR_NUM_OF_DEATHS,
        CHAR_NUMBER
    };

    CharProperties();
    ~CharProperties();

    CharProperty *getProperty(int index);
    CharProperty *getProperty(CharProperties::CHAR index);
};

#endif // CHARPROPERTYLIST_H
