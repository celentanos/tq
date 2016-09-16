#include "widget_property.h"

QLabel *WidgetProperty::getValOld() const
{
    return valOld;
}

QLineEdit *WidgetProperty::getValNew() const
{
    return valNew;
}

void WidgetProperty::slotSetValueIntern()
{
    if(valNew->text() == valOld->text())
        valNew->setStyleSheet(LE_BLUE);
    else
        valNew->setStyleSheet(LE_GREEN);
    emit signalSetValue(valNew->text());
}

void WidgetProperty::slotEditedValueIntern()
{
    valNew->setStyleSheet(LE_CYAN);
}

void WidgetProperty::slotSetValue(QString val)
{
    valNew->setText(val);
    if(val == valOld->text())
        valNew->setStyleSheet(LE_BLUE);
    else
        valNew->setStyleSheet(LE_GREEN);
}

void WidgetProperty::slotSetValueLimit(QString val)
{
    valNew->setText(val);
    valNew->setStyleSheet(LE_YELLOW);
}

WidgetProperty::WidgetProperty(QWidget *parent, CharProperty *property) : QWidget(parent)
{
    this->name = "WidgetProperty";
    this->hbox = new QHBoxLayout;
    this->pName = new QLabel;
    this->valOld = new QLabel;
    this->valNew = new QLineEdit;

    this->hbox->addStretch(-1);
    this->hbox->addWidget(this->pName);
    this->hbox->addWidget(this->valOld);
    this->hbox->addWidget(this->valNew);

    this->hbox->setMargin(1);
    this->hbox->setAlignment(this->hbox, Qt::AlignRight);

    this->pName->setText(property->getPropertyName());
    this->pName->setAlignment(Qt::AlignRight);
    this->pName->setMaximumHeight(LABEL_HEIGHT);
    if(property->getPropertyString() == "numberOfSacks")
        this->pName->setStyleSheet("QLabel { color: rgb(255, 0, 0) }");

    this->valOld->setText("-");
    this->valOld->setMinimumWidth(WIDGET_WEIGHT);
    this->valOld->setMaximumHeight(LABEL_HEIGHT);
    this->valOld->setFrameShape(QFrame::Panel);
    this->valOld->setFrameShadow(QFrame::Sunken);
    this->valOld->setAlignment(Qt::AlignRight);
    this->valOld->setStyleSheet("QLabel { background: rgb(220, 220, 220) }");

    this->valNew->setMaximumWidth(WIDGET_WEIGHT);
    this->valNew->setAlignment(Qt::AlignRight);
    this->valNew->setStyleSheet(LE_BLUE);
    if(property->getPropertyString() == "numberOfSacks")
        this->valNew->setToolTip("WARNING! You items will be deleted! At first: save this by handler!");

    if(property->getAccess() == CharProperty::PROP_READ) {
        this->valNew->setEnabled(false);
        valNew->setStyleSheet(LE_RED);
    }

    this->setLayout(this->hbox);

    connect(this->valNew, &QLineEdit::returnPressed, this, &WidgetProperty::slotSetValueIntern);
    connect(this->valNew, &QLineEdit::textEdited, this, &WidgetProperty::slotEditedValueIntern);
}
