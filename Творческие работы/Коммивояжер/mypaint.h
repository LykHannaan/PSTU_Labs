#ifndef MYPAINT_H
#define MYPAINT_H

#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>

class myPainter
{
public:
    myPainter();
public:
    void draw(QPainter *painter, QPaintEvent *event);
    QBrush front;
private:
    QBrush back;
    QFont glFont;
    QPen textPen;
    int size = 0;
};

#endif //MYPAINT_H
