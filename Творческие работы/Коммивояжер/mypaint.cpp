#include "mypaint.h"
#include <QPaintEvent>
#include <QPainter>
#include <QWidget>
#include <QtCore/qmath.h>

QString str;
QStringList lst;
int f, R=320, r=40, ls=25;
double pi=3.1415;
int hText=26, xa=550, ya=400;
double ang=pi/8;
int disp=60;

myPainter::myPainter()
{
    front=QBrush(QColor(106, 209, 208));
    back=QBrush(QColor(227, 240, 254));
    textPen=QPen(QColor(100, 100, 100));
    glFont.setPixelSize(hText);
}

void myPainter::draw(QPainter *painter, QPaintEvent *event)
{
    QString l;
    QByteArray data;
    if (size==0){
        QFile inputFile("D:/Qt2/!projects/kommivoyazher/qw.txt");
        if(inputFile.open(QIODevice::ReadOnly)){
            data = inputFile.readAll();
            str = QString(data);

        }
        inputFile.close();
        lst = str.split(" ");
        int double_size;
        double_size = lst.size()-1;
        size = sqrt(double_size);}
        int p = 0;
        int** matr = new int* [size];
        for (int i = 0; i < size; i++)
        {
            matr[i] = new int[size];
            for (int j = 0; j < size; j++)
            {
                l = lst.at(p+j);
                matr[i][j] = l.toInt();
            }
            p+=6;
        }

        int** matr2 = new int* [size];
        for (int i = 0; i < size; i++)
        {
            matr2[i] = new int[size];
            for (int j = 0; j < size; j++)
            {
               matr2[i][j] = matr[i][j];
            }
        }
    painter->fillRect(event->rect(),back);
    painter->setBrush(front);
    painter->setPen(textPen);
    painter->setFont(glFont);
    textPen.setWidth(4);
    for (int i=0;i<size;i++)
    {
        double a=pi*3/2+pi*2/size*i;
        int xc=cos(a)*R+xa, yc=sin(a)*R+ya;
        int c1=xc-20, c2=yc-hText/2, c3=40, c4=hText;
        QString text; text.setNum(i+1);

        painter->drawEllipse(QRectF(xc-r,yc-r,2*r,2*r));
        painter->drawText(QRect(c1,c2,c3,c4),Qt::AlignCenter,text);
        for (int k=0;k<size;k++){
            if (matr[i][k]!=0) {
                //для ребра
                double a2=pi*3/2+pi*2/size*k;
                double xc2=cos(a2)*R+xa;
                double yc2=sin(a2)*R+ya;
                double l=sqrt((xc2-xc)*(xc2-xc)+(yc2-yc)*(yc2-yc));
                int xl1=(xc2-xc)/l*r+xc;
                int yl1=(yc2-yc)/l*r+yc;
                int xl2=xc2-(xc2-xc)/l*r;
                int yl2=yc2-(yc2-yc)/l*r;
                    painter->drawLine(xl1,yl1,xl2,yl2);
                //для стрелки
                double b;
                 if      (xc2==xl2 && yl2<yc2) b=pi*3/2;
                 else if (yc2==yl2 && xl2<xc2) b=pi;
                 else if (xc2==xl2 && yl2>yc2) b=pi/2;
                 else if (yc2==yl2 && xl2>xc2) b=0;
                 else if (xl2>xc2 && yl2<yc2)  b=atan((yc2-yl2)/(xc2-xl2))+pi*2;
                 else if (xl2<xc2 && yl2<yc2)  b=atan((yc2-yl2)/(xc2-xl2))+pi;
                 else if (xl2<xc2 && yl2>yc2)  b=atan((yc2-yl2)/(xc2-xl2))+pi;
                 else if (xl2>xc2 && yl2>yc2)  b=atan((yc2-yl2)/(xc2-xl2));
                 int xs1=cos(b+ang)*ls+xl2;
                 int ys1=sin(b+ang)*ls+yl2;
                 int xs2=cos(b-ang)*ls+xl2;
                 int ys2=sin(b-ang)*ls+yl2;
                 painter->drawLine(xl2,yl2,xs1,ys1);
                 painter->drawLine(xl2,yl2,xs2,ys2);

                 //для чисел
                 c1=(xl2+xl1)/2-20+qrand()%disp-disp/2;
                 c2=(yl2+yl1)/2-hText/2+qrand()%disp-disp/2;
                 c3=40;
                 c4=hText;
                 if (matr2[i][k]!=0){
                 if (matr2[i][k] != matr2[k][i])text.setNum(matr2[i][k]);
                 if(matr2[i][k]==matr2[k][i]){text.setNum(matr2[i][k]); matr2[k][i]=0;}
                 painter->drawText(QRect(c1,c2,c3,c4),Qt::AlignCenter,text);}
            }
        }
    }

    for (int i = 0; i < size; i++)
            delete[]matr[i];
        delete[]matr;

    for (int i = 0; i < size; i++)
        delete[]matr2[i];
    delete[] matr2;
}

