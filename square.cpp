#include "square.h"
#include "assert.h"
#include "QDebug"
#include "qmenu.h"
#include <iostream>

Square::Square(const QPointF &point, qreal length):
    m_point{point},
    m_length{length}
{
}

void Square::draw(QPoint mousePosition, QPainter &painter)
{
    if (contains(mousePosition))
        painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter.drawRect(m_point.x(), m_point.y(), m_length, m_length);
}

bool Square::contains(QPoint p)
{
    QRectF rect { m_point.x(), m_point.y(), m_length, m_length };
    return rect.contains(p);
}

void Square::printInfo()
{
    std::cerr << "Square " << "at " << m_point.x() << ' ' << m_point.y() << " with side length " << m_length << std::endl;
}

void Square::move(QPoint moveVector)
{
    m_point += moveVector;
}

QAction* Square::showMenu(QPoint point)
{
    QMenu *menu = new QMenu;
    QAction *action = new QAction{"Удалить"};
    menu->addAction(action);
    menu->exec(point);
    return action;
}
