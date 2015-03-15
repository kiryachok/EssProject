#ifndef PRODUCTIONDIALOG_H
#define PRODUCTIONDIALOG_H

#include <QMainWindow>
#include "../EssController/productioncontroller.h"

namespace Ui {
class ProductionDialog;
}

class ProductionDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProductionDialog(QWidget *parent = 0);
    ~ProductionDialog();

private slots:
    void on_new_logic_pushButton_clicked();

    void on_new_string_pushButton_clicked();

    void on_new_math_pushButton_clicked();

    void on_finish_pushButton_clicked();

private:
    Ui::ProductionDialog *ui;
    ProductionController *controller;

};

#endif // PRODUCTIONDIALOG_H
