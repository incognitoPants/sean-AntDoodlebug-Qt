#ifndef PETRIDISH_H
#define PETRIDISH_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QObject>

#include "Grid.h"
#include "organismrect.h"
#include "DisplayStats.h"

class PetriDish : public QGraphicsView
{
    Q_OBJECT
public:
    PetriDish(QWidget *parent = 0); // p_ants and p_doodlebugs are the number of ants and doodlebugs present

    void updateColor();

    QGraphicsScene *scene;
    DisplayStats * stats;
    Grid bugGrid;
    OrganismRect *displayPtrs[20][20];

public slots:
    void stepSlot(); // could probably be a private slot
};

#endif // PETRIDISH_H
