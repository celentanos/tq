#ifndef CHARPROPERTY_H
#define CHARPROPERTY_H

#include <QObject>
#include <QString>

#include <limits>

#include "log.h"

class CharProperty : public QObject
{
    Q_OBJECT
public:
    enum PROP_TYPE {
        PROP_INT,
        PROP_STRING,
        PROP_STRING16,
        PROP_NUMBER
    };

    enum PROP_ACCESS {
        PROP_READ,
        PROP_WRITE
    };

protected:
    QString name;
    PROP_TYPE type;
    PROP_ACCESS access;

    QByteArray property;    /// property
    QString propertyName;
    int valOld;             /// value
    int valNew;             /// new value
    int valOffset;          /// offset in character-bin-file
    int valLength;          /// property length in bytes
    int valid;              /// exist

public:
    CharProperty(QByteArray property, QString name, CharProperty::PROP_ACCESS access, int valLength = 4);

    QString getSValueOld() const;
    void setSValueOld(const QString &value);
    QString getSValueNew() const;
    void setSValueNew(const QString &value);

    QByteArray getProperty() const;
    QString getPropertyName() const;
    int getValOld() const;
    void setValOld(const int &value);
    int getValOffset() const;
    void setValOffset(const int &value);
    int getValid() const;
    void setValid(int value);
    int getValLength() const;
    int getValNew() const;
    int setValNew(int value);

    CharProperty::PROP_ACCESS getAccess() const;

public slots:
    void slotSetValue(int value);

signals:
    void signalValOldChanged(QString);
    void signalValNewChanged(int);
};

#endif // CHARPROPERTY_H
