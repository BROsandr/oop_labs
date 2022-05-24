#ifndef FIGURE_H
#define FIGURE_H

#include "qaction.h"
#include <QPainter>

class Figure
{
public:
    virtual void draw(QPoint mousePosition, QPainter &painter) = 0;
    virtual bool contains(QPoint p) = 0;
    virtual void printInfo() = 0;
    virtual void move(QPoint moveVector) = 0;
    virtual QAction* showMenu(QPoint point) = 0;
};

#endif // FIGURE_H
