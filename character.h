#ifndef CHERACTER_H
#define CHERACTER_H

#include <QDataStream>
#include <QIODevice>

#include "char_properties.h"
#include "char_skills.h"

#define SKILLS_PER_LEVEL    3

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

    template<typename T>
    static int getValFromLittle(const QByteArray &ba) {
        QDataStream ds(ba);
        ds.setByteOrder(QDataStream::LittleEndian);
        T i;
        ds >> i;
        return i;
    }

    template<typename T>
    static QByteArray getBaLittleFromVal(T val) {
        QByteArray ba;
        ba.reserve(sizeof (T));
        QDataStream ds(&ba, QIODevice::ReadWrite);
        ds.setByteOrder(QDataStream::LittleEndian);
        ds << val;
        return ba;
    }

    void clearAll();
    void resetSkills();
    void parseProperties();
    void parseSkills();

    CharProperties *getProperties() const;
    CharSkills *getSkills() const;
    QByteArray *getCharacter() const;
};

#endif // CHERACTER_H
