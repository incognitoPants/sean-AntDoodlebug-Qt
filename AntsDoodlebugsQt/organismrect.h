#ifndef ORGANISMRECT_H
#define ORGANISMRECT_H

#include <QGraphicsRectItem>
#include <QObject>

class OrganismRect : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    OrganismRect();
};

#endif // ORGANISMRECT_H
