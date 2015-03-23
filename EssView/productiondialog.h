#ifndef PRODUCTIONDIALOG_H
#define PRODUCTIONDIALOG_H

#include <QMainWindow>

namespace Ui {
class ProductionDialog;
}

class ProductionDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProductionDialog(QWidget *parent = 0);
    ~ProductionDialog();

signals:

    void createNewProduction(QString, short);
    void addNewExpression();

private slots:
    void on_new_logic_pushButton_clicked();

    void on_new_string_pushButton_clicked();

    void on_new_math_pushButton_clicked();

    void on_finish_pushButton_clicked();

    void on_ok_pushButton_clicked();

private:
    Ui::ProductionDialog *ui;

};

#endif // PRODUCTIONDIALOG_H
