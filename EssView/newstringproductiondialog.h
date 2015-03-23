#ifndef NEWSTRINGPRODUCTIONDIALOG_H
#define NEWSTRINGPRODUCTIONDIALOG_H

#include <QDialog>
#include "../EssController/productioncontroller.h"
namespace Ui {
class NewStringProductionDialog;
}

class NewStringProductionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewStringProductionDialog(QWidget *parent = 0);
    ~NewStringProductionDialog();
private slots:
    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::NewStringProductionDialog *ui;
};

#endif // NEWSTRINGPRODUCTIONDIALOG_H
