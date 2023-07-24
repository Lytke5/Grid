#include "circle.h"

Circle::Circle(const QPoint &center_)
{
    center = center_;
    clicked = false;
}

bool Circle::isInside(const QPoint &point)
{
    int katheten = pow(point.x() - getX(),2) +
                   pow(point.y() - getY(),2);

    int hypothenuse = sqrt(katheten);

    if(hypothenuse <= radius)
    return true;

    return false;
}

void Circle::paint(QPainter *painter, QColor selectColor)
{
    if(clicked)
    {
        painter->setBrush(selectColor);
        setClicked(false);
    }
    painter->drawEllipse(center, radius, radius);
    painter->setBrush(Qt::black);
}

int Circle::getX()
{
    return center.x();
}

int Circle::getY()
{
    return center.y();
}

void Circle::setClicked(bool clicked_)
{
    clicked = clicked_;
}
