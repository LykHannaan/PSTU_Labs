#include "graph.h"
#include "ui_graph.h"
#include <QOpenGLWidget>
#include "myglwidget.h"
#include <QPainter>
#include <QGridLayout>
#include <QPushButton>
#include <QMessageBox>

QStringList list;
QString str1;
QString res,lenght;

bool notall=0;
//int ik,im,w;
int ris=0,mins=10000,leng,s;
double gradus=360;
int matrix[10][10];
bool *was;
int *way, *minway;

Graph::Graph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graph)
{
    ui->setupUi(this);
    setFixedSize ( 1255, 950 );
    myGLWidget *openGLW=new myGLWidget(this);
    QGridLayout *grid=new QGridLayout();
    //QPushButton *btn=new QPushButton();
    grid->addWidget(openGLW,0,0);
    //grid->addWidget(btn,1,0);
    ui->outputGraph->setLayout(grid);
    connect(ui->result_btn, SIGNAL(clicked()), this, SLOT(print_result()));

}

Graph::~Graph()
{
    delete ui;
}
void Graph::make_matrix()
{
    QString l;
     QByteArray data;
     QFile inputFile("D:/Qt2/!projects/kommivoyazher/qw.txt");
     if(inputFile.open(QIODevice::ReadOnly)){
         data = inputFile.readAll();
         str1 = QString(data);
     }
     inputFile.close();
     list = str1.split(" ");
     int double_size;
     double_size = list.size()-1;
     size = sqrt(double_size);
     int p = 0;
     //int matr[size][size];
     for (int i = 0; i < size; i++)
     {
         for (int j = 0; j < size; j++)
         {
             l = list.at(p+j);
             matrix[i][j] = l.toInt();
         }
         p+=6;
     }
}


void Graph::Search(int l, int i){
    leng+=l;
    was[i]=1;
    bool b=0;
    way[s]=i;
    s++;
    for (int e=0;e<size;e++){
        if (!was[e]){
            if (matrix[i][e]) Search(matrix[i][e],e);
            b=1;
        }
    }
    if(!b){
        if (leng<mins){
            mins=leng;
            for (int z=0;z<size;z++) minway[z]=way[z];
        }
    }
    leng-=l;
    s--;
    was[i]=0;
}

void Graph::print_result()
{
    ui->label_3->setText("Кратчайший путь: ");
    ui->label_4->setText("Длина пути: ");

    make_matrix();
    //ui->go->setStyleSheet("color: rgb(0,250,0);background-color: rgb(150,150,150);border: 1px solid rgb(0,250,0);border-radius: 10px;");
    leng=0;
    s=0;
    mins=10000;
    was = new bool [size];
    way = new int [size];
    minway = new int [size];
    for (int i=0;i<size;i++) Search(0,i);
    res = QString::number(minway[0]+1);
    for (int i=1;i<size;i++) res += "->" + QString::number(minway[i]+1);
    if (mins==10000){
        QMessageBox::warning(this,"Предупреждение","Не существует маршрута, позволяющего посетить все города без повторного посещения пройденных дорог и городов.");
    }
    else{
    lenght+= QString::number(mins);
    this->repaint();
    ui->label_1->setText(res);
    ui->label_2->setText(lenght);
    }
    delete[] was;
    delete[] way;
}

