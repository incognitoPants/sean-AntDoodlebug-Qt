#ifndef PETRIDISH_H
#define PETRIDISH_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Grid.h"
#include "organismrect.h"

class PetriDish : public QGraphicsView
{
public:
    PetriDish(QWidget * parent = 0);

    QGraphicsScene * scene;
    Grid bugGrid;
    OrganismRect *displayPtrs[20][20];

    void updateColor();

public slots:
    void stepSlot();
};

#endif // PETRIDISH_H
