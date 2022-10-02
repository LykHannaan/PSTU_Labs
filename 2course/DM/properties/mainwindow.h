#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QStringList>
#include <QByteArray>
#include <QTextStream>
#include <QtCore/qmath.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
     int size = 0;
     MainWindow *nWin;

private slots:
  void make_matrix();
  void on_change_btn_clicked();
  void on_prprts_btn_clicked();
};
#endif // MAINWINDOW_H
