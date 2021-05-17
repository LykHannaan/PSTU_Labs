#include "dialog.h"
#include "ui_dialog.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

int k=1,t=1;

QString file1_name = "D:/Qt2/!projects/kommivoyazher/qw.txt";
QString file2_name = "D:/Qt2/!projects/kommivoyazher/qww.txt";

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog), m_intValidator(0, 9, this), m_intValidator2(0, 100, this)
{
    ui->setupUi(this);
    setFixedSize ( 600, 250 );
    setWindowFlags(Qt::Window |  Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    ui->weightG->setEnabled(false);
    ui->onward_btn->setEnabled(false);
    ui->ok_btn->setEnabled(false);
    ui->weightG->setValidator(&m_intValidator2);
    ui->size->setValidator(&m_intValidator);
    connect(ui->pushButton, SIGNAL(pressed()), this, SLOT(buttonPressed()));
    connect(ui->onward_btn, SIGNAL(clicked()), this, SLOT(onButtonSend()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::onButtonSend()
{
    QFile inputFile(file1_name);
    QTextStream writeStream(&inputFile);
   if(inputFile.open(QIODevice::Append | QIODevice::Text))
   {
        if ((k<=n)and(t<=n))
        {
           if((k==1)and(t==1)){writeStream << "0 "; t++;}
           way = ui->weightG->text().toInt();
           writeStream << QString::number(way)<< " ";
           ui->weightG->setText(""); t++;
           if(t<=n){
               if (k==t) {writeStream << "0 "; t++;}
               if(t<=n) ui->label_3->setText("Введите длину пути " + QString::number(k) + "-" + QString::number(t) + ":");
           }
           if(t>n){k++; t=1;
                writeStream << Qt::endl;
             if (k<=n)ui->label_3->setText("Введите длину пути " + QString::number(k) + "-" + QString::number(t) + ":");}
        }
        if (k>n) {
            ui->ok_btn->setEnabled(true);
            ui->weightG->setEnabled(false);
            ui->label_2->setText("Все значения введены!");}
    }
    inputFile.close();
}

void Dialog::buttonPressed()
{
    n = ui->size->text().toInt();
    if (n<3)QMessageBox::warning(this,"Предупреждение","Количество городов должно иметь значение не менее 3! ");
    else {ui->label_3->setText("Введите длину пути 1-2:");
    ui->weightG->setEnabled(true);
    ui->onward_btn->setEnabled(true);
    ui->size->setEnabled(false);
    ui->pushButton->setEnabled(false);}
}

void Dialog::btnPress()
{
    ui->size->setText("");
    ui->weightG->setText("");
    ui->label_2->setText("");
    ui->label_3->setText("");
    ui->size->setEnabled(true);
    ui->pushButton->setEnabled(true);
    ui->weightG->setEnabled(false);
    ui->onward_btn->setEnabled(false);
    k=1; t=1;
}

void Dialog::on_cancel_btn_clicked()
{
    btnPress();
    if(!QFile(file2_name).exists()) QMessageBox::warning(this,"Предупреждение","Файл не найден!");
    else{
        if(QFile(file1_name).exists()) QFile::remove(file1_name);
        QFile::copy(file2_name, file1_name);
    }
     this->close();
}

void Dialog::on_ok_btn_clicked()
{
    btnPress();
    this->close();
}
