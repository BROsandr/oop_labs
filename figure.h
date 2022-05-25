#ifndef FIGURE_H
#define FIGURE_H

#include "qaction.h"
#include <QPainter>
#include <QObject>

class Figure: public QObject
{
    Q_OBJECT

public:

    virtual void draw(QPoint mousePosition, QPainter &painter) = 0;
    virtual bool contains(QPoint p) = 0;
    virtual void printInfo() = 0;
    virtual void move(QPoint moveVector) = 0;
    void showMenu(QPoint position);
    bool deleted { false };

public slots:
    void doMenuAction();
};

#endif // FIGURE_H
