#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QAbstractButton>
#include <QValidator>
#include <QMessageBox>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void onButtonSend();
    void btnPress();

    void on_cancel_btn_clicked();
    void on_ok_btn_clicked();

private:
    Ui::Dialog *ui;

    QIntValidator m_intValidator;
    QIntValidator m_intValidator2;
    int way;
};

#endif // DIALOG_H
