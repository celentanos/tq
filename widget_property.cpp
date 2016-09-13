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
    bool b;
    valNew->text().toInt(&b);
    if(!b) {
        valNew->setStyleSheet("QLineEdit { background: rgb(255, 220, 220) }");
        valNew->setText("overflow!");
        Log::getInstance()->log(Log::FAILURE, name, __FUNCTION__, "int-convert failed!");
        return;
    }
    if(valNew->text() == valOld->text())
        valNew->setStyleSheet("QLineEdit { background: rgb(240, 240, 255) }");
    else
        valNew->setStyleSheet("QLineEdit { background: rgb(240, 255, 240) }");
    emit signalSetValue(valNew->text().toInt(&b));
}

void WidgetProperty::slotSetValue(int val)
{
    valNew->setText(QString::number(val));
    if(QString::number(val) == valOld->text())
        valNew->setStyleSheet("QLineEdit { background: rgb(240, 240, 255) }");
    else
        valNew->setStyleSheet("QLineEdit { background: rgb(240, 255, 240) }");
}

WidgetProperty::WidgetProperty(QWidget *parent, QString name, CharProperty::PROP_ACCESS access) : QWidget(parent)
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

    this->pName->setText(name);
    this->pName->setAlignment(Qt::AlignRight);
    this->valOld->setText("-");
    this->valOld->setMinimumWidth(100);
    this->valOld->setFrameShape(QFrame::Panel);
    this->valOld->setFrameShadow(QFrame::Sunken);
    this->valOld->setAlignment(Qt::AlignRight);
    this->valNew->setMaximumWidth(100);
    this->valNew->setAlignment(Qt::AlignRight);
    valNew->setStyleSheet("QLineEdit { background: rgb(240, 240, 255) }");

    if(access == CharProperty::PROP_READ) {
        this->valNew->setEnabled(false);
        valNew->setStyleSheet("QLineEdit { background: rgb(255, 240, 240) }");
    }

    this->setLayout(this->hbox);

    connect(this->valNew, &QLineEdit::textEdited, this, &WidgetProperty::slotSetValueIntern);
}
