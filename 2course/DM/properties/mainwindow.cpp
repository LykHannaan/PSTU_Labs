#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

QString file_name = "D:/Qt2/!projects/lab2/matr.txt";
QString str;
QStringList lst;
QByteArray dataa;
QString output = "";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize ( 670, 370 );
    setWindowTitle ( " Relationship properties " );
    QFile inputFile(file_name);
    if(inputFile.open(QIODevice::ReadOnly)){
        dataa = inputFile.readAll();
        ui->matrix1->setText(dataa);
        str = QString(dataa);
    }
    inputFile.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::make_matrix()
{
    ui->properties->setText("");
     QString l;

     int p = 0;
     bool **matrix = new bool*[size];
     int count=0;

     for (int i = 0; i < size; i++)
     {
         matrix[i] = new bool [size];
         for (int j = 0; j < size; j++)
         {
             l = lst.at(p+j);
             matrix[i][j] = l.toInt();
             if (matrix[i][j]) count++;
         }
         p+=size;
     }
     bool gd1 = 1, gd0=0;
     int n = (size*(size-1))/2;
     bool *mass = new bool[size];
     bool *X = new bool[n];
     bool *Y = new bool[n];
     bool trans = 1;

     for (int i = 0; i < size; i++)
     {
         mass[i] = matrix[i][i];
         gd1 = gd1 && mass[i];
         gd0 = gd0 || mass[i];
     }
     int k=0, k2=0;
     for (int i = 0; i < size-1; i++)
         for(int j = i+1; j < size; j++){
             X[k] = matrix[i][j];
             k++;}
     int t = 1;
     for (int j = 0; j < size-1; j++){
         for(int i = 1; i < size; i++){
               while(i<t) i++;
               Y[k2] = matrix[i][j];
               k2++;}
         t++;
     }
     QString ref = "рефлексивность", antiref = "антирефлексивность", sym = "симметричность",
             antisym = "антисимметричность", asym = "асимметричность", tr = "транзитивность", con = "связность";

     if (gd1) output = output + ref + "\n";
     if (!gd0) output = output + antiref + "\n";

     bool yes1 = 1, yes = 1, no1 = 1;
     for (int i = 0; i<n; i++){
         qDebug() << X[i] << Y[i];
         if(X[i]==Y[i]) yes1=yes1&&1;
         else yes1=yes1&&0;
         if(X[i]!=Y[i]) no1=no1&&1;
         else no1=no1&&0;
         if(X[i]+Y[i]) yes=yes&&1;
         else yes = yes&&0;
     }
     if(yes1) output = output + sym + "\n";
     if (no1 and !gd0) output = output + asym + "\n";
     else if (no1) output = output + antisym + "\n";
     if(yes) output = output + con + "\n";

     for (int i = 0; i < size; i++) {
         for (int j = 0; j < size; j++) {
             if (i == j) continue;
                        if (!matrix[i][j]) continue;
                        for(int k = 0; k < size; ++k)
                        {
                            if (k == i || k == j) continue;
                            if (matrix[j][k] == 0) continue;
                            if (matrix[i][k] == 0) trans = 0;
                        }
         }
     }
     if(trans) output = output + tr + "\n";
     if (output == "") output = output + "не рефлексивное\nне антирефлексивное\nне симметричное\nне антисимметричное" +
                                           "\nне асимметричное\nне связное\nне транзитивное";
     ui->properties->setText(output);
}

void MainWindow::on_change_btn_clicked()
{
    ui->properties->setText("");
    output = "";
    size = 0;
    QString data1;
    data1 = ui->matrix1->toPlainText();
    QFile changeFile(file_name);
    QTextStream writeStream(&changeFile);
    if(changeFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
           writeStream << data1;
    }
    changeFile.close();
    nWin = new MainWindow;
    nWin->show();
    this->close();
}

void MainWindow::on_prprts_btn_clicked()
{
    QFile inputFile(file_name);
    if (size==0){
    if(inputFile.open(QIODevice::ReadOnly)){
        dataa = inputFile.readAll();
        str = QString(dataa);
    }
    inputFile.close();
    lst = str.split(" ");
    int double_size;
    double_size = lst.size()-1;
    size = sqrt(double_size);}
    if (size*size != lst.size()-1)  {
        QMessageBox::warning(this,"Предупреждение","Введите квадратную матрицу!");
    }
    else make_matrix();
}
