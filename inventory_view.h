#ifndef INVENTORYVIEW_H
#define INVENTORYVIEW_H

#include <QGraphicsView>

#include "inventory_scene.h"
#include "go_cell.h"

class InventoryView : public QGraphicsView
{
    Q_OBJECT
public:
    InventoryView();
    ~InventoryView();

private:
    InventoryScene *scene;
    GOCell *cell;

};

#endif // INVENTORYVIEW_H
