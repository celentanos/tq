#include "widget_properties.h"

WidgetProperties::WidgetProperties(CharProperties *properties, QWidget *parent) : QWidget(parent)
{
    for (int i = 0; i < properties->size(); ++i) {
        this->append(new WidgetProperty(this, properties->at(i)));
    }
}
