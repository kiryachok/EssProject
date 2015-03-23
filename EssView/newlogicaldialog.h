#ifndef NEWLOGICALDIALOG_H
#define NEWLOGICALDIALOG_H

#include <QDialog>
#include "../EssController/productioncontroller.h"

namespace Ui {
class NewLogicalDialog;
}

class NewLogicalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewLogicalDialog(QWidget *parent = 0);
    ~NewLogicalDialog();
    void setController(ProductionController *cont);

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

private:
    Ui::NewLogicalDialog *ui;
    ProductionController *controller;
};

#endif // NEWLOGICALDIALOG_H
