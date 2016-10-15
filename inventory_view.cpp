#include "inventory_view.h"

InventoryView::InventoryView()
{
    scene = new InventoryScene;
    scene->setSceneRect(0, 0, 320, 240);
    this->setScene(scene);

    cell = new GOCell;

    scene->addItem(cell);
}

InventoryView::~InventoryView()
{
    if(scene)
        delete scene;
//    if(cell)
//        delete cell;
}
