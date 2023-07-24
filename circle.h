#ifndef CIRCLE_H
#define CIRCLE_H
#include <QPainter>


class Circle
{
public:
    Circle(const QPoint &center_);
    bool isInside(const QPoint &point);
    void paint(QPainter *painter, QColor selectColor);
    int getX();
    int getY();
    void setClicked(bool clicked_);
private:
    QPoint center;
    const int radius = 5;
    bool clicked;
};

#endif // CIRCLE_H
