#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <vector>
#include <QtGui>
#include <ctime>

#include "organismrect.h"
#include "Grid.h"
#include "PetriDish.h"

#define MAINTEST 2
#if MAINTEST == 1

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    int antNum = 100;
    int doodlebugNum = 5;

    srand(static_cast<int>(time(0)));

    Grid bugGrid;
    OrganismRect *displayPtrs[20][20];

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    bugGrid.placeAnts(antNum);
    bugGrid.placeDoodlebugs(doodlebugNum);

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            displayPtrs[i][j] = new OrganismRect();
            displayPtrs[i][j] -> setRect(0, 0, 25, 25);
            scene -> addItem(displayPtrs[i][j]);

            if (bugGrid.getBugType(i, j) == 0)
                displayPtrs[i][j] -> setBrush(* new QBrush(Qt::white));
            else if (bugGrid.getBugType(i, j) == 1)
                displayPtrs[i][j] -> setBrush(* new QBrush(Qt::blue));
            else //if (bugGrid.getBugType(i, j) == 2)
                displayPtrs[i][j] -> setBrush(* new QBrush(Qt::red));

            displayPtrs[i][j] -> setPos(i * 25 + (3 * (i + 1)), j * 25 + (3 * (j + 1)));
        }
    }

    // create a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // show the view
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);



    /*QTimer * timer = new QTimer();
    for (int i = 0; i < 20; i++)
    {
        QObject::connect(timer, SIGNAL(timeout()), , SLOT(step()));
        timer->start(4000);
    }*/

    return a.exec();
}

#elif MAINTEST == 2

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    PetriDish * mainGame = new PetriDish();
    mainGame -> show();

    return a.exec();
}
#endif
