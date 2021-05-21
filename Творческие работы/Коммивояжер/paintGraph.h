#ifndef PAINTGRAPH_H
#define PAINTGRAPH_H
#include "mypaint.h"
#include <QOpenGLWidget>

class myGLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    myGLWidget( QWidget *parent);
//public slots:
    //void redraw();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    myPainter *mypainter;
};

#endif // PAINTGRAPH_H
