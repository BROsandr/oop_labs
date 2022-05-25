#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"
#include <array>

class Triangle: public Figure
{
public:
    Triangle(std::array<QPoint, 3> &vertices);
    Triangle(const Triangle &trianlge);
    void draw(QPoint mousePosition, QPainter &painter) override;
    bool contains(QPoint p) override;
    void printInfo() override;
    void move(QPoint moveVector)override;

private:
    std::array<QPoint, 3> m_vertices;
};

#endif // TRIANGLE_H
