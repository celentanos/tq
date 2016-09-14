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

#define WIDGET_WEIGHT   100
#define LABEL_HEIGHT    24

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
    explicit WidgetProperty(QWidget *parent, QString name, CharProperty::PROP_ACCESS access);

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
