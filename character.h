#ifndef CHERACTER_H
#define CHERACTER_H

#include <QDataStream>
#include <QIODevice>

#include "char_properties.h"
#include "char_skills.h"

class Character
{
private:
    QString name;
    QByteArray *character;
    CharProperties *properties;
    CharSkills *skills;
    QStringList skillList;

public:
    Character();
    ~Character();

    static int getIntFromLittle(const QByteArray &ba);
    static QByteArray getBaLittleFromInt(int val);

    void clearAll();
    void resetSkills();
    void parseProperties();
    void parseSkills();

    CharProperties *getProperties() const;
    CharSkills *getSkills() const;
    QByteArray *getCharacter() const;
};

#endif // CHERACTER_H
