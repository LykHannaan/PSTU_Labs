#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>
#include <QTextStream>
#include <QStringList>
#include <QtMath>
#include <QByteArray>
#include <QFile>
#include <QMessageBox>

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
    Graph *nWin;

private slots:
    void print_result();
    //void Search(int l, int i);
    void make_matrix();
    void on_change_btn_clicked();
};


#endif // GRAPH_H
