#include "inventory_view.h"

InventoryView::InventoryView()
{
    scene = new InventoryScene;
    this->setScene(scene);
    this->setFixedSize(322, 242);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    this->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(0, 0, 320, 240);

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
