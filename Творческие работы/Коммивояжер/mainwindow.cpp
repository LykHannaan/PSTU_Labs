#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle ( " Traveling salesman " );
    setFixedSize ( 400, 250 );
    window = new Dialog();
    window_graph = new Graph();
    connect(ui->input_btn, SIGNAL(clicked()), this, SLOT(onButtonSend()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_createGraph_btn_clicked()
{
    window_graph->setModal(true);
    window_graph->exec();
}

void MainWindow::on_input_btn_clicked()
{
    QString file1_name = "D:/Qt2/!projects/kommivoyazher/qw.txt";
    QString file2_name = "D:/Qt2/!projects/kommivoyazher/qww.txt";
    QFile inputFile(file1_name);
    QTextStream writeStream(&inputFile);

    if(!QFile(file1_name).exists()) QMessageBox::warning(this,"Предупреждение","Файл не найден!");
    else{
        if(QFile(file2_name).exists()) QFile::remove(file2_name);
        QFile::copy(file1_name, file2_name);
    }

    if(inputFile.open(QIODevice::WriteOnly | QIODevice::Text))writeStream << "";
    inputFile.close();
    window->setModal(true);
    window->exec();
}



