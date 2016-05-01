#include <QGraphicsTextItem>
#include <QFont>

#include "DisplayStats.h"

DisplayStats::DisplayStats(int p_ants, int p_doodlebugs, int p_stepCount, QGraphicsItem * parent)
    :   QGraphicsTextItem(parent)
{
    setPlainText(QString("Ants Remaining: " + QString::number(p_ants) + "\nDoodlebugs Remaining: " + QString::number(p_doodlebugs)
                         + QString("\nTurn: " + QString::number(p_stepCount))));
    setDefaultTextColor(Qt::black);

    setFont(QFont("times", 10)); // Times New Roman
}

void DisplayStats::updateStatsText(int p_ants, int p_doodlebugs, int p_stepCount)
{
    setPlainText(QString("Ants Remaining: " + QString::number(p_ants) + "\nDoodlebugs Remaining: " + QString::number(p_doodlebugs)
                         + QString("\nTurn: " + QString::number(p_stepCount))));
}
