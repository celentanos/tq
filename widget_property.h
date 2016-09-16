#ifndef WIDGETPROPERTY_H
#define WIDGETPROPERTY_H

#include <QDebug>
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVariant>

#include "log.h"
#include "char_property.h"

#define WIDGET_WEIGHT   100
#define LABEL_HEIGHT    24
#define LE_RED          "QLineEdit { background: rgb(255, 200, 200) }"
#define LE_GREEN        "QLineEdit { background: rgb(200, 255, 200) }"
#define LE_BLUE         "QLineEdit { background: rgb(220, 220, 255) }"
#define LE_CYAN         "QLineEdit { background: rgb(200, 255, 255) }"
#define LE_YELLOW       "QLineEdit { background: rgb(255, 255, 200) }"

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
    explicit WidgetProperty(QWidget *parent, CharProperty *property);

    QLabel *getValOld() const;

    QLineEdit *getValNew() const;

    QPushButton *getButSet() const;

signals:
    void signalSetValue(QVariant);

public slots:
    void slotSetValueIntern();
    void slotEditedValueIntern();
    void slotSetValue(QString val);
    void slotSetValueLimit(QString val);
};

#endif // WIDGETPROPERTY_H
