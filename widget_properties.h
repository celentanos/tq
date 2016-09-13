#ifndef WIDGETPROPERTIES_H
#define WIDGETPROPERTIES_H

#include <QWidget>
#include <QList>

#include "widget_property.h"
#include "char_properties.h"

class WidgetProperties : public QWidget, public QList<WidgetProperty *>
{
    Q_OBJECT
public:
    explicit WidgetProperties(CharProperties *properties, QWidget *parent = 0);

signals:

public slots:
};

#endif // WIDGETPROPERTIES_H
