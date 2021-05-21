#include "dialog.h"
#include "ui_dialog.h"
#include <QFile>
#include <QTextStream>

int k=1,t=1;

QString file1_name = "D:/Qt2/!projects/kommivoyazher/qw.txt";
QString file2_name = "D:/Qt2/!projects/kommivoyazher/qww.txt";

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog), m_intValidator(0, 100, this)
{
    ui->setupUi(this);
    setFixedSize ( 600, 250 );
    setWindowTitle ( " Traveling salesman " );
    setWindowFlags(Qt::Window |  Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    ui->onward_btn->setShortcut(Qt::Key_Return);
    ui->ok_btn->setEnabled(false);
    ui->label_3->setText("Введите вес ребра 1-2:");
    ui->weightG->setValidator(&m_intValidator);
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
        if ((k<=6)and(t<=6))
        {
           if((k==1)and(t==1)){writeStream << "0 "; t++;}
           way = ui->weightG->text().toInt();
           writeStream << QString::number(way)<< " ";
           ui->weightG->setText(""); t++;
           if(t<=6){
               if (k==t) {writeStream << "0 "; t++;}
               if(t<=6) ui->label_3->setText("Введите длину пути " + QString::number(k) + "-" + QString::number(t) + ":");
           }
           if(t>6){k++; t=1;
                writeStream << Qt::endl;
             if (k<=6)ui->label_3->setText("Введите длину пути " + QString::number(k) + "-" + QString::number(t) + ":");}
        }
        if (k>6) {
            ui->ok_btn->setEnabled(true);
            ui->weightG->setEnabled(false);
            ui->onward_btn->setEnabled(false);
            ui->label_2->setText("Все значения введены!");}
    }
    inputFile.close();
}

void Dialog::btnPress()
{
    ui->weightG->setText("");
    ui->label_2->setText("");
    ui->label_3->setText("");
    ui->weightG->setEnabled(true);
    ui->onward_btn->setEnabled(true);
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
