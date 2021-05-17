#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>
#include <QTextStream>
#include <QStringList>
#include <QtMath>
#include <QByteArray>
#include <QFile>
#include <QVector>
#include <QPair>

namespace Ui {
class Graph;
}

class Graph : public QDialog
{
    Q_OBJECT

public:
    explicit Graph(QWidget *parent = nullptr);
    ~Graph();

private:
    Ui::Graph *ui;
    int size;

private slots:
    void print_result();
    void Search(int l, int i);
    void make_matrix();
    //void on_change_clicked();
};

//int* Search_Min(int* line, int n);
//int** Reduct_Matrix(int** oldmatr);
//int** High_Zero(int** oldmatr);

#endif // GRAPH_H
