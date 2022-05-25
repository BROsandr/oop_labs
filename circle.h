#ifndef CIRCLE_H
#define CIRCLE_H


#include "figure.h"

class Circle: public Figure
{
public:
    Circle(const QPointF &center, qreal radius);
    Circle(const Circle &circle);
    void draw(QPoint mousePosition, QPainter &painter) override;
    bool contains(QPoint p) override;
    void printInfo() override;
    void move(QPoint moveVector)override;

private:
    QPointF m_center{-1, -1};
    qreal m_radius = -1;
};

#endif // CIRCLE_H
