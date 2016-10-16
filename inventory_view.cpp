#include "inventory_view.h"

InventoryView::InventoryView()
{
    scene = new InventoryScene;
    this->setScene(scene);
    this->setFixedSize(CELLS_X * CELL_H + 2, CELLS_Y * CELL_H + 2);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    this->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(0, 0, CELLS_X * CELL_H, CELLS_Y * CELL_H);

    cell = new GOCell;

    for (int i = 0; i < CELLS_Y + 1; ++i)
        scene->addLine(0, i * CELL_H, CELLS_X * CELL_H, i * CELL_H);
    for (int i = 0; i < CELLS_X + 1; ++i)
        scene->addLine(i * CELL_H, 0, i * CELL_H, CELLS_Y * CELL_H);

    scene->addItem(cell);
}

InventoryView::~InventoryView()
{
    if(scene)
        delete scene;
//    if(cell)
//        delete cell;
}
