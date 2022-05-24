#include "widget.h"
#include "ui_widget.h"
#include "circle.h"
#include "triangle.h"
#include "square.h"
#include "QDebug"
#include <QMouseEvent>
#include <array>
#include <QAction>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    setMouseTracking(true);
    ui->setupUi(this);

    figures.clear();
    std::array<QPoint, 3> tri{QPoint{70, 70}, QPoint{150, 150}, QPoint{70, 50}};
    figures.push_back(std::make_unique<Circle>(Circle{QPoint{50, 50}, 20}));
    figures.push_back(std::make_unique<Triangle>(Triangle{tri}));
    figures.push_back(std::make_unique<Square>(Square{QPoint{200, 200}, 200}));
}

Widget::~Widget()
{
    delete ui;
}

/* Метод, в котором происходит рисование
 * */
void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this); // Создаём объект отрисовщика
    // Устанавливаем кисть абриса
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));

    for(auto &el: figures)
    {
        el->draw(mousePosition, painter);
        painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (mousePosition != QPoint { -1, -1 } && (event->buttons() & Qt::LeftButton))
        if (movedFigure)
            movedFigure->move(event->pos() - mousePosition);
    update();
    mousePosition = event->pos();
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    for (auto &el: figures)
        if(el->contains(event->pos()))
                el->printInfo();
    if (event->buttons() & Qt::LeftButton)
        for (auto &el: figures)
            if(el->contains(event->pos()))
                movedFigure = el.get();
    if (event->buttons() & Qt::RightButton)
        for (auto &el: figures)
            if(el->contains(event->pos())){
                QAction *action { el->showMenu(mapToGlobal(event->pos())) };
                connect(action, &QAction::triggered, this, &Widget::doMenuAction);
//                QAction *p = nullptr;
//                p->trigger();
            }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    movedFigure = nullptr;
}

void Widget::doMenuAction()
{
    assert(0 && "in do menu");
    qDebug() << 'g';
}
