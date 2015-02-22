#ifndef PRMODDIALOG_H
#define PRMODDIALOG_H

#include <QDialog>
#include "essview_global.h"

namespace Ui {
class PrModDialog;
}

class ESSVIEWSHARED_EXPORT PrModDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PrModDialog(QWidget *parent = 0);
    ~PrModDialog();

private slots:
    void on_exitButton_clicked();

    void on_newButton_clicked();

    void on_exportButton_clicked();

    void on_changeButton_clicked();

private:
    Ui::PrModDialog *ui;
};

#endif // PRMODDIALOG_H
