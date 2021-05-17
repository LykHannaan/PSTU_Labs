#include "myproject.h"
#include "ui_myproject.h"
#include <QPixmap>

double pl, k, sum_total, overpay;

MyProject::MyProject(QWidget *parent):QMainWindow(parent),
    ui(new Ui::MyProject), m_doubleValidator(0, 1000000000, 2, this),
    m_doubleValidator2(0, 100, 1, this), m_intValidator(0, 100, this)
{
    ui->setupUi(this);
    setFixedSize ( 1070, 560 );
    setWindowTitle ( " Credit Calculator " );
    setImg1();
    window = new secondwindow();
    connect(ui->click_table, SIGNAL(clicked()), this, SLOT(onButtonSend()));
    connect(this, SIGNAL(sendData(QString)), window, SLOT(recieveData(QString)));
    connect(this, SIGNAL(sendVariables(double, double, QString, int, double)),
            window, SLOT(makeTable(double, double, QString, int, double)));

    this->setWindowFlags(Qt::WindowContextHelpButtonHint | Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint);

    m_doubleValidator.setNotation(QDoubleValidator::StandardNotation);
    m_doubleValidator2.setNotation(QDoubleValidator::StandardNotation);
      ui->credit_sum->setValidator(&m_doubleValidator);
      ui->credit_terms->setValidator(&m_intValidator);
      ui->percent->setValidator(&m_doubleValidator2);
}

MyProject::~MyProject()
{
    delete ui;
}

void MyProject::setImg1()
{
    ui->label_10->setText("Введите значения!");
    QPixmap myPixmap( ":resources/img/S11.png" );
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(myPixmap.scaled(w, h, Qt::KeepAspectRatio));
}
void MyProject::setImg2()
{
    ui->label_10->setText("Готово!");
    QPixmap myPixmap( ":resources/img/S222.png" );
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(myPixmap.scaled(w, h, Qt::KeepAspectRatio));
}

void MyProject::variables()
{
    sum = ui->credit_sum->text().toDouble();
    terms = ui->credit_terms->text().toInt();
    year_percent = ui->percent->text().toDouble();
    date =  ui->day->text() + "." + ui->month->text() + "." + ui->year->text();
}

void MyProject::Calculator()
{
    variables();
    double m_proc = year_percent/1200;
    k = (m_proc*pow((1+m_proc),terms))/(pow((1+m_proc),terms)-1);
    pl = sum * k;
    sum_total = pl * terms;
    overpay = sum_total - sum;
}

void MyProject::onButtonSend()
{
    variables();
    emit sendData(date + " " + ui->credit_terms->text() + " "
                 + ui->credit_sum->text()+ " " + ui->percent->text() + " " + ui->payment->text());
        double m_proc = year_percent/1200;
        k = (m_proc*pow((1+m_proc),terms))/(pow((1+m_proc),terms)-1);
        pl = sum * k;
    emit sendVariables(sum, year_percent, date, terms, pl);
}

void MyProject::on_click_table_clicked()
{
    variables();
    if((sum>0)and(terms>0)and(year_percent>0)) window->show();
}

void MyProject::on_clickCalc_clicked()
{
    Calculator();
    if((sum>0)and(terms>0)and(year_percent>0))
    {ui->label_11->setText(QString::number(sum_total, 'f', 2));
    ui->payment->setText(QString::number(pl, 'f', 2)); setImg2();
    ui->pereplata->setText(QString::number(overpay, 'f', 2)); setImg2();}
    else {ui->label_11->setText("-");
    ui->payment->setText("-");
    ui->pereplata->setText("-");
    setImg1();}
}

void MyProject::on_slotClear_clicked()
{
    window->close();
    setImg1();
    ui->credit_sum->setText("");
    ui->credit_terms->setText("");
    ui->percent->setText("");
    ui->payment->setText("");
    ui->label_11->setText("");
    ui->pereplata->setText("");
}

