#ifndef CHARPROPERTY_H
#define CHARPROPERTY_H

#include <QDebug>
#include <QObject>
#include <QString>
#include <QVariant>

#include <limits>

#include "log.h"

class CharProperty : public QObject
{
    Q_OBJECT
public:
    enum PROP_TYPE {
        TYPE_INT,
        TYPE_FLOAT,
        TYPE_NUMBER
    };

    enum PROP_ACCESS {
        PROP_READ,
        PROP_WRITE
    };

protected:
    QString name;
    PROP_TYPE type;
    PROP_ACCESS access;

    QByteArray propertyString;  /// property
    QString propertyName;
    QVariant valOld;            /// value
    QVariant valNew;            /// new value
    double valMin;
    double valMax;
    int valOffset;              /// offset in character-bin-file
    int valid;                  /// exist

public:
    CharProperty(QByteArray propertyString, QString name, CharProperty::PROP_TYPE type);
    CharProperty(QByteArray propertyString, QString name, CharProperty::PROP_TYPE type, double min, double max, CharProperty::PROP_ACCESS access = PROP_WRITE);
    int getValLength() const;
    CharProperty::PROP_ACCESS getAccess() const;
    void clearAll();

    QByteArray getPropertyString() const;
    QString getPropertyName() const;
    QVariant getValOld() const;
    void setValOld(const QVariant &value);
    QVariant getValNew() const;
    void setValNew(const QVariant &value);
    int getValOffset() const;
    void setValOffset(const int &value);
    int getValid() const;
    void setValid(int value);

public slots:
    void slotSetValNew(const QVariant &value);

signals:
    void signalValOldChanged(QString);
    void signalValNewChanged(QString);
    void signalValNewLimit(QString);
};

#endif // CHARPROPERTY_H
