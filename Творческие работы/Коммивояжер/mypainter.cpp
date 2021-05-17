#include "mypainter.h"
#include <QPaintEvent>
#include <QPainter>
#include <QWidget>
#include <QtCore/qmath.h>

QString str;
QStringList lst;
int f;
int R=300;        //радиус графа
int r=40;         //радиус узла
double pi=3.1415;
int HeightText=30;
int xa=600;       //отступ от вертикали
int ya=400;       //отступ от горизонтали
double angle=pi/8;//угол раствора стрелки
int ls=25;        //длина кончика стрелки
int disp=60;      //разброс подписей ребер

myPainter::myPainter()
{//127,255,212
    front=QBrush(QColor(106, 209, 208));
    back=QBrush(QColor(227, 240, 254));
    textPen=QPen(QColor(100,100,100));
    glFont.setPixelSize(HeightText);
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
               matr2[i][j] = 0;
            }
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = i+1; j < size; j++)
            {
               matr2[i][j] = matr[i][j];
            }
        }
        for (int i = size-1; i>=0; i--)
        {
            for (int j = 0; j < i-1; j++)
            {
                if(matr[i][j] != matr2[j][i])
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
        double a=pi*3/2+pi*2/size*i; //угол в полярных координатах (узел)
        int xc=cos(a)*R+xa;         //декартовы координата узла
        int yc=sin(a)*R+ya;
        int c1=xc-20;               //координаты текста
        int c2=yc-HeightText/2;
        int c3=40;
        int c4=HeightText;
        QString text; text.setNum(i+1);
        painter->drawEllipse(QRectF(xc-r,yc-r,2*r,2*r));
        painter->drawText(QRect(c1,c2,c3,c4),Qt::AlignCenter,text);
        for (int k=0;k<size;k++)
        {
            if (matr[i][k]!=0)
            {
                //линия
                double a2=pi*3/2+pi*2/size*k;
                double xc2=cos(a2)*R+xa;
                double yc2=sin(a2)*R+ya;
                double l=sqrt((xc2-xc)*(xc2-xc)+(yc2-yc)*(yc2-yc));
                int xl1=(xc2-xc)/l*r+xc;
                int yl1=(yc2-yc)/l*r+yc;
                int xl2=xc2-(xc2-xc)/l*r;
                int yl2=yc2-(yc2-yc)/l*r;
                    painter->drawLine(xl1,yl1,xl2,yl2);
                //стрелка
                double b;
                 if      (xc2==xl2 && yl2<yc2) b=pi*3/2;
                 else if (yc2==yl2 && xl2<xc2) b=pi;
                 else if (xc2==xl2 && yl2>yc2) b=pi/2;
                 else if (yc2==yl2 && xl2>xc2) b=0;
                 else if (xl2>xc2 && yl2<yc2)  b=atan((yc2-yl2)/(xc2-xl2))+pi*2;
                 else if (xl2<xc2 && yl2<yc2)  b=atan((yc2-yl2)/(xc2-xl2))+pi;
                 else if (xl2<xc2 && yl2>yc2)  b=atan((yc2-yl2)/(xc2-xl2))+pi;
                 else if (xl2>xc2 && yl2>yc2)  b=atan((yc2-yl2)/(xc2-xl2));
                 int xs1=cos(b+angle)*ls+xl2;
                 int ys1=sin(b+angle)*ls+yl2;
                 int xs2=cos(b-angle)*ls+xl2;
                 int ys2=sin(b-angle)*ls+yl2;
                 painter->drawLine(xl2,yl2,xs1,ys1);
                 painter->drawLine(xl2,yl2,xs2,ys2);

                 if(matr2[i][k]!=0){
                 //текст
                 c1=(xl2+xl1)/2-20+qrand()%disp-disp/2;
                 c2=(yl2+yl1)/2-HeightText/2+qrand()%disp-disp/2;
                 c3=40;
                 c4=HeightText;
                 text.setNum(matr2[i][k]);
                 painter->drawText(QRect(c1,c2,c3,c4),Qt::AlignCenter,text);
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
