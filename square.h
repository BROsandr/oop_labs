#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

class Square: public Figure
{
public:
    Square(const QPointF &point, qreal length);
    Square(const Square &square);
    void draw(QPoint mousePosition, QPainter &painter) override;
    bool contains(QPoint p) override;
    void printInfo() override;
    void move(QPoint moveVector)override;

private:
    QPointF m_point{-1, -1};
    qreal m_length = -1;
};

#endif // SQUARE_H
