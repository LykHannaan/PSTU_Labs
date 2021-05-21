#include "graph.h"
#include "ui_graph.h"
#include <QOpenGLWidget>
#include "paintGraph.h"
#include <QPainter>
#include <QGridLayout>
#include <QPushButton>

QString file_name = "D:/Qt2/!projects/kommivoyazher/qw.txt";
QStringList list;
QString str1;
QString res,sum;
int const n = 6;
int matrix[n][n];  // матрица связей

Graph::Graph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graph)
{
    ui->setupUi(this);
    setFixedSize ( 1194, 1030 );
    setWindowTitle ( " Traveling salesman " );
    myGLWidget *openGLW=new myGLWidget(this);
    QGridLayout *grid=new QGridLayout();
    grid->addWidget(openGLW,0,0);
    ui->outputGraph->setLayout(grid);
    ui->label_1->setText("");
    ui->label_2->setText("");
    ui->label_3->setText("");
    ui->label_4->setText("");
    //ui->label_3->setText("");
    //ui->label_4->setText("");
    connect(ui->result_btn, SIGNAL(clicked()), this, SLOT(print_result()));
    make_matrix();
}

Graph::~Graph()
{
    delete ui;
}
void Graph::make_matrix()
{
     QString l;
     QByteArray data;
     QFile inputFile(file_name);
     if(inputFile.open(QIODevice::ReadOnly)){
         data = inputFile.readAll();
         ui->matrix1->setText(data);
         str1 = QString(data);
     }
     inputFile.close();
     list = str1.split(" ");
     int p = 0;

     for (int i = 0; i < n; i++)
     {
         for (int j = 0; j < n; j++)
         {
             l = list.at(p+j);
             matrix[i][j] = l.toInt();
         }
         p+=6;
     }
}

void Graph::print_result()
{
    int point1, point2;
    point1 = ui->lineEdit->text().toInt();
    point2 = ui->lineEdit_2->text().toInt();
    int d[n];                       // минимальное расстояние
    int v[n];                       // посещенные вершины
    int temp, minindex, min;
    int begin_index = point1 - 1;

    ui->label_1->setText("");
    ui->label_2->setText("");
    ui->label_3->setText("Кратчайший путь: ");
    ui->label_4->setText("Расстояние: ");

    make_matrix();
    //Инициализация вершин и расстояний
    for (int i = 0; i<n; i++)
      {
        d[i] = 10000;
        v[i] = 1;
      }
      d[begin_index] = 0;
      //if (minindex == 10000)  {QMessageBox::warning(this,"Предупреждение","Маршрута не существует!");

      do {
        minindex = 10000;
        min = 10000;
        for (int i = 0; i<n; i++)
        { // Если вершину ещё не обошли и вес меньше min
          if ((v[i] == 1) && (d[i]<min))
          {
            min = d[i];
            minindex = i;
          }
        }
        // Добавляем найденный минимальный вес к текущему весу вершиныи сравниваем с текущим минимальным весом вершины
        if (minindex != 10000)
        {
          for (int i = 0; i<n; i++)
          {
            if (matrix[minindex][i] > 0)
            {
              temp = min + matrix[minindex][i];
              if (temp < d[i])
              {
                d[i] = temp;
              }
            }
          }
          v[minindex] = 0;
        }
      } while (minindex < 10000);

      // Восстановление пути
      int ver[n]; // массив посещенных вершин
      int end = point2 - 1; // индекс конечной вершины
      ver[0] = end + 1;
      int k = 1;
      int weight = d[end]; // вес конечной вершины

      while (end != begin_index) // пока не дошли до начальной вершины
      {
        for (int i = 0; i<n; i++)
          if (matrix[i][end] != 0)
          {
            int temp = weight - matrix[i][end];
            if (temp == d[i])
            {
              weight = temp;
              end = i;
              ver[k] = i + 1;
              k++;
            }
          }
      }
      int s = 0;
      res = QString::number(ver[k-1]);
      for (int i = k - 2; i >= 0; i--)
      {
          res = res + " -> " + QString::number(ver[i]);
          s = d[point2 - 1];
      }
    sum = QString::number(s);
    ui->label_1->setText(res);
    ui->label_2->setText(sum);
}

void Graph::on_change_btn_clicked()
{
    QString data1;
    data1 = ui->matrix1->toPlainText();

    QFile changeFile(file_name);
    QTextStream writeStream(&changeFile);
    if(changeFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
           writeStream << data1;
    }
    changeFile.close();
    nWin = new Graph;
    nWin->show();
    res = "";
    sum = "";
    ui->label_1->setText("");
    ui->label_2->setText("");
    ui->label_3->setText("");
    ui->label_4->setText("");
    this->close();
}
