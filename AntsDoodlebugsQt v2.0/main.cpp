#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QtGui>

#include "PetriDish.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    PetriDish * mainGame = new PetriDish();
    mainGame -> show();

    return a.exec();
}
