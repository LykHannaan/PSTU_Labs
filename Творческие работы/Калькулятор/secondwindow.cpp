#include "secondwindow.h"
#include "ui_secondwindow.h"

QString m;

secondwindow::secondwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);
    setFixedSize ( 1080, 650 );
    setWindowTitle ( " Payments " );
    makeTable(sum, year_percent, date, terms, payment);
}

void secondwindow::recieveData(QString str)
{
    QStringList lst = str.split(" ");
       if (lst.size() > 4) {
           ui->L1->setText(lst.at(0));
           ui->L2->setText(lst.at(1));
           ui->L3->setText(lst.at(2));
           ui->L4->setText(lst.at(3));
           ui->L5->setText(lst.at(4));
       }
}

void secondwindow::what_month()
{
    if (month>12) {month-=12; year++;}
    switch(month){
    case 1: m = " января "; break;
    case 2: m = " февраля "; break;
    case 3: m = " марта "; break;
    case 4: m = " апреля "; break;
    case 5: m = " мая "; break;
    case 6: m = " июня "; break;
    case 7: m = " июля "; break;
    case 8: m = " августа "; break;
    case 9: m = " сентября "; break;
    case 10: m = " октября "; break;
    case 11: m = " ноября "; break;
    case 12: m = " декабря "; break;
    default: break;   
  }
}

void secondwindow::makeTable(double sum, double year_percent, QString date, int terms, double payment)
{
    QStringList lst = date.split(".");
    if (lst.size() > 2)
    {day = lst.at(0).toInt();
    month = lst.at(1).toInt();
    year = lst.at(2).toInt();}

    double m_proc = year_percent/1200;
    double balance = sum, interest_debt = 0, main_debt = 0;

    model = new QStandardItemModel(terms, 4, this); //создание модели для таблицы, terms - кол-во строк, 4 - кол-во столбцов
    model->setHeaderData(0, Qt::Horizontal, "Дата платежа");
    model->setHeaderData(1, Qt::Horizontal, "Остаток по кредиту");
    model->setHeaderData(2, Qt::Horizontal, "Платеж по кредиту");
    model->setHeaderData(3, Qt::Horizontal, "Платеж по процентам");
    ui->tableView->setModel(model);

    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    for(int i = 0; i<4; i++)
    {
       ui->tableView->setColumnWidth(i, this->width()/4);
    }

    QModelIndex index;
    for(int row = 0; row<model->rowCount(); row++){                  //перебирает строки
        for(int col = 0; col<model->columnCount(); col++){                 //перебирает столбцы
            index = model->index(row,col);
            if(col == 0) {
                what_month();
                model->setData(index, QString::number(day) + m + QString::number(year));
                month++;
            }
            if(col == 1) {
                balance-= main_debt;
                model->setData(index, balance);}
            if(col == 2) {
                interest_debt = m_proc*balance;
                model->setData(index, interest_debt);}
            if(col == 3) {
                main_debt = payment-interest_debt;
                model->setData(index, main_debt);}
        }
    }
}

secondwindow::~secondwindow()
{
    delete ui;
}
