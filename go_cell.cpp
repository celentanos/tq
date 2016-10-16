#include "go_cell.h"

GOCell::GOCell()
{

}

QRectF GOCell::boundingRect() const
{
    return QRectF(0, 0, CELL_W, CELL_H);    // Ограничиваем область, в которой лежит цель
}

void GOCell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::gray);
    painter->drawRect(0, 0, CELL_W, CELL_H);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void GOCell::slotCoordinate(QPointF point)
{
    this->setX(point.x() - this->boundingRect().width() / 2);
    this->setY(point.y() - this->boundingRect().height() / 2);
}
