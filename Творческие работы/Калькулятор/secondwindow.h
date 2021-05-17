#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <QStandardItemModel>
#include <QStringList>

namespace Ui {
class secondwindow;
}

class secondwindow : public QDialog
{
    Q_OBJECT

public:
    explicit secondwindow(QWidget *parent = nullptr);
    ~secondwindow();

private:
    Ui::secondwindow *ui;
    QStandardItemModel *model;

    double sum = 0.0;
    double year_percent = 0.0;
    QString date;
    int terms = 0;
    double payment = 0.0;
    int day, month, year;

private slots:
    void recieveData(QString str);
    void what_month();
    void makeTable(double sum, double year_percent, QString date, int terms, double payment);

};

#endif // SECONDWINDOW_H
