#ifndef GOCELL_H
#define GOCELL_H

#include <QGraphicsItem>
#include <QGraphicsObject>
#include <QPainter>

class GOCell : public QGraphicsObject
{
    Q_OBJECT
public:
    GOCell();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // GOCELL_H
