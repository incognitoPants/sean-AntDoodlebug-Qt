#ifndef ORGANISMRECT_H
#define ORGANISMRECT_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QWidget>

class OrganismRect : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    OrganismRect(QWidget * parent = 0);
};

#endif // ORGANISMRECT_H
