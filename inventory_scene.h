#ifndef INVENTORYSCENE_H
#define INVENTORYSCENE_H

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>

#include "go_cell.h"

class InventoryScene : public QGraphicsScene
{
    Q_OBJECT
public:
    InventoryScene();

signals:
    void signalCursorCoordinate(QPointF point);

private:
    bool bounding;  /// wenn ein Item gefangen und verschoben wird, sollen die Grenzen geprüft werden

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // INVENTORYSCENE_H
