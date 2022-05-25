#include "circle.h"
#include <math.h>
#include <iostream>
#include <QMenu>

Circle::Circle(const QPointF &center, qreal radius):
    m_center{center},
    m_radius{radius}
{
}

Circle::Circle(const Circle &circle)
{
    m_center = circle.m_center;
    m_radius = circle.m_radius;
}


void Circle::draw(QPoint mousePosition, QPainter &painter)
{
    if (contains(mousePosition))
        painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter.drawEllipse(m_center, m_radius, m_radius);
}

bool Circle::contains(QPoint p)
{
    QPointF subtract { p - m_center };
    QPointF absSubtract { abs(subtract.x()), abs(subtract.y()) };
    return absSubtract.x() < m_radius && absSubtract.y() < m_radius;
}

void Circle::printInfo()
{
    std::cerr << "Circle " << "at " << m_center.x() << ' ' << m_center.y() << " with radius " << m_radius << std::endl;
}

void Circle::move(QPoint moveVector)
{
    m_center += moveVector;
}
