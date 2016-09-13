#ifndef WIDGETPROPERTY_H
#define WIDGETPROPERTY_H

#include <QDebug>
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "log.h"
#include "char_property.h"

class WidgetProperty : public QWidget
{
    Q_OBJECT
private:
    QString name;

    QHBoxLayout *hbox;
    QLabel *pName;
    QLabel *valOld;
    QLineEdit *valNew;

public:
    explicit WidgetProperty(QWidget *parent, QString pName, CharProperty::PROP_ACCESS access);

    QLabel *getValOld() const;

    QLineEdit *getValNew() const;

    QPushButton *getButSet() const;

signals:
    void signalSetValue(int);

public slots:
    void slotSetValueIntern();
    void slotSetValue(int val);
};

#endif // WIDGETPROPERTY_H