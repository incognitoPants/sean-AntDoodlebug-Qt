#include <QTimer>
#include <QDebug>
#include "PetriDish.h"


PetriDish::PetriDish(QWidget * parent)
{
    qDebug() << "Test: This is the start point";

    int antNum = 100;
    int doodlebugNum = 5;

    // create a scene
    scene = new QGraphicsScene();
    scene -> setSceneRect(0, 0, 800, 600);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    bugGrid.placeAnts(antNum);
    bugGrid.placeDoodlebugs(doodlebugNum);

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            displayPtrs[i][j] = new OrganismRect();
            displayPtrs[i][j] -> setRect(0, 0, 25, 25);
            scene -> addItem(displayPtrs[i][j]);
            displayPtrs[i][j] -> setPos(i * 25 + (3 * (i + 1)), j * 25 + (3 * (j + 1)));
        }
    }

    updateColor();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(stepSlot()));
    timer -> start(30000);
}

void PetriDish::updateColor()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (bugGrid.getBugType(i, j) == 0)
                displayPtrs[i][j] -> setBrush(* new QBrush(Qt::white));
            else if (bugGrid.getBugType(i, j) == 1)
                displayPtrs[i][j] -> setBrush(* new QBrush(Qt::blue));
            else //if (bugGrid.getBugType(i, j) == 2)
                displayPtrs[i][j] -> setBrush(* new QBrush(Qt::red));
        }
    }
}

void PetriDish::stepSlot()
{
    bugGrid.step();
    updateColor();
    qDebug() << "Updated color! (and a step())";
}
