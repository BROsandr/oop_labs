#include "figure.h"
#include <QDebug>
#include <QMenu>

void Figure::doMenuAction()
{
    deleted = true;
//    emit deleted(this);
}

void Figure::showMenu(QPoint position)
{
    QMenu menu;
    connect(menu.addAction("Удалить"), &QAction::triggered, this, &Figure::doMenuAction);
    menu.exec(position);
}
