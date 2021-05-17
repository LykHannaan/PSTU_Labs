#ifndef MYPROJECT_H
#define MYPROJECT_H

#include <QMainWindow>
#include "secondwindow.h"
#include <QtMath>
#include <QStringList>
#include <QValidator>

QT_BEGIN_NAMESPACE
namespace Ui { class MyProject; }
QT_END_NAMESPACE

class MyProject : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyProject(QWidget *parent = nullptr);
    ~MyProject();

signals:
    void sendData(QString str);
    void sendVariables(double sum, double year_percent, QString date, int terms, double payment);

private slots:
    void onButtonSend();
    void Calculator();
    void on_clickCalc_clicked();
    void on_slotClear_clicked();
    void on_click_table_clicked();
    void setImg1();
    void setImg2();
    void variables();


private:
    Ui::MyProject *ui;
    secondwindow *window;
    QDoubleValidator m_doubleValidator;
    QDoubleValidator m_doubleValidator2;
    QIntValidator m_intValidator;

    double sum = 0.0;
    double year_percent = 0.0;
    QString date;
    int terms = 0;
};

#endif // MYPROJECT_H
