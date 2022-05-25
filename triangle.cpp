#include "triangle.h"
#include "qdebug.h"
#include "qmenu.h"
#include <iostream>

Triangle::Triangle(std::array<QPoint, 3> &vertices):
    m_vertices{vertices}
{
}

Triangle::Triangle(const Triangle &trianlge)
{
    m_vertices = trianlge.m_vertices;
}

void Triangle::draw(QPoint mousePosition, QPainter &painter)
{

    QPolygon polygon;   // Using Polygon class, to draw the triangle
    // We put the coordinates of points in the polygonal model
    for(auto &el: m_vertices)
        polygon << el;
    if (contains(mousePosition))
        painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter.drawPolygon(polygon);  // Draw a triangle on a polygonal model
}

bool Triangle::contains(QPoint p)
{
    QPolygon polygon;   // Using Polygon class, to draw the triangle
    // We put the coordinates of points in the polygonal model
    for(auto &el: m_vertices)
        polygon << el;
    return polygon.containsPoint(p, Qt::OddEvenFill);
}

void Triangle::printInfo()
{
    std::cerr << "Triangle " << "vertices:\n"
          << m_vertices.at(0).x() << ' ' << m_vertices.at(0).y() << std::endl
          << m_vertices.at(1).x() << ' ' << m_vertices.at(1).y() << std::endl
          << m_vertices.at(2).x() << ' ' << m_vertices.at(2).y() << std::endl;
}

void Triangle::move(QPoint moveVector)
{
    for (auto &el: m_vertices)
        el += moveVector;
}
