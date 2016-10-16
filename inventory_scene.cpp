#include "inventory_scene.h"

InventoryScene::InventoryScene()
{

}

void InventoryScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(bounding) {
        // проверяем границы инвентаря (что бы Item не выходил за его предел)
        if((event->scenePos().x() > this->sceneRect().x() && event->scenePos().x() < this->sceneRect().x() + this->sceneRect().width()) &&
           (event->scenePos().y() > this->sceneRect().y() && event->scenePos().y() < this->sceneRect().y() + this->sceneRect().height()))
            emit signalCursorCoordinate(event->scenePos());
    }
}

void InventoryScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QTransform trans;
    for (int i = 0; i < this->items().size(); ++i) {
        QGraphicsItem *item;
        if((item = this->itemAt(event->scenePos(), trans))) {

//            QCursor::setPos(static_cast<int>(event->screenPos().x() + item->boundingRect().width() / 2),
//                            static_cast<int>(event->screenPos().y() + item->boundingRect().height() / 2));

//            item->setX(QCursor::pos().x() - item->boundingRect().width() / 2);
//            item->setY(QCursor::pos().y() - item->boundingRect().height() / 2);
            bounding = true;
            GOCell *cell = dynamic_cast<GOCell *>(item);
            if(cell)
                connect(this, &InventoryScene::signalCursorCoordinate,
                        dynamic_cast<GOCell *>(item), &GOCell::slotCoordinate);
        }
    }
    Q_UNUSED(event);
}

void InventoryScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QTransform trans;
    for (int i = 0; i < this->items().size(); ++i) {
        QGraphicsItem *item;
        if((item = this->itemAt(event->scenePos(), trans))) {
            bounding = false;
            GOCell *cell = dynamic_cast<GOCell *>(item);
            if(cell)
                disconnect(this, &InventoryScene::signalCursorCoordinate,
                           dynamic_cast<GOCell *>(item), &GOCell::slotCoordinate);
            else
                qDebug() << "wrong GO";

            item->setX(((static_cast<int>(item->scenePos().x()) + CELL_H / 2) / CELL_H)*CELL_H);
            item->setY(((static_cast<int>(item->scenePos().y()) + CELL_H / 2) / CELL_H)*CELL_H);
        }
    }
    Q_UNUSED(event);
}
