#include <QTimer>
#include <QRect>
#include <QApplication>
#include <QDesktopWidget>

#include "PetriDish.h"
#include "displaystats.h"

PetriDish::PetriDish(QWidget * parent)
    : QGraphicsView(parent)
{
    QRect deskResolution = QApplication::desktop()->screenGeometry(); // gets the resolution of the desktop screen

    // the number of pixels is defined by the height of the screen
    const int rectPixelSize = 32 * (deskResolution.height() / 1080); // The size of each rectangle
    const int rectGridSpacing = 0 * (deskResolution.height() / 1080); // The space between the rectangles

    const int view_width = rectPixelSize * 20;
    const int view_height = rectPixelSize * 20 + (rectPixelSize * 1.2 * deskResolution.height() / 1080);

    int antNum = 100;
    int doodlebugNum = 5;
    int timeDelay = 250;

    // create a scene
    scene = new QGraphicsScene();
    scene -> setSceneRect(0, 0, view_width, view_height);
    setScene(scene);

    // set QGraphicsView parameters
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(view_width, view_height);

    bugGrid.placeAnts(antNum);
    bugGrid.placeDoodlebugs(doodlebugNum);

    // creates and adds the text to the scene
    stats = new DisplayStats(antNum, doodlebugNum, 0);
    scene -> addItem(stats);
    stats -> setPos(view_width / 16, rectPixelSize * 20 + 7); // 7 is the distance from the bottom of the grid

    for (int i = 0; i < 20; i++) // Creates the OrganismRect() instancs and puts them in the scene at the correct location
    {
        for (int j = 0; j < 20; j++)
        {
            displayPtrs[i][j] = new OrganismRect(this); // sets this PetriDish object as the parent, too
            displayPtrs[i][j] -> setRect(0, 0, rectPixelSize, rectPixelSize);
            scene -> addItem(displayPtrs[i][j]);
            displayPtrs[i][j] -> setPos(i * rectPixelSize + (rectGridSpacing * (i + 1)), j * rectPixelSize + (rectGridSpacing * (j + 1)));
        }
    }

    updateColor();

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(stepSlot()));
    timer -> start(timeDelay);
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
            else // if (bugGrid.getBugType(i, j) == 2)
                displayPtrs[i][j] -> setBrush(* new QBrush(Qt::red));
        }
    }
}

// anything that needs to be looped
void PetriDish::stepSlot()
{
    bugGrid.step();
    updateColor();
    stats -> updateStatsText(bugGrid.numAnts(), bugGrid.numDoodlebugs(), bugGrid.getStepCount());

    // TODO: add check here to see if the sim is over, and if so kill the timer.
}
