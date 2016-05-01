#ifndef DISPLAYSTATS_H
#define DISPLAYSTATS_H

#include <QGraphicsTextItem>

class DisplayStats : public QGraphicsTextItem
{
public:
    DisplayStats(int p_ants = -1 , int p_doodlebugs = -1, int p_stepCount = -1, QGraphicsItem * parent = 0); // p_ants and p_doodlebugs are the number of ants and doodlebugs present
    void updateStatsText(int p_ants, int p_doodlebugs, int p_stepCount);
};

#endif // DISPLAYSTATS_H
