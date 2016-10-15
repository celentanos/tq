#include "go_cell.h"

GOCell::GOCell()
{

}

QRectF GOCell::boundingRect() const
{
    return QRectF(0, 0, 40, 40);    // Ограничиваем область, в которой лежит цель
}

void GOCell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::gray);
    painter->drawRect(0, 0, 40, 40);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
