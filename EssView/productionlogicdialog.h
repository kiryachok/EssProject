#ifndef PRODUCTIONLOGICDIALOG_H
#define PRODUCTIONLOGICDIALOG_H

#include <QDialog>

namespace Ui {
class ProductionLogicDialog;
}

class ProductionLogicDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProductionLogicDialog(QWidget *parent = 0);
    ~ProductionLogicDialog();

private:
    Ui::ProductionLogicDialog *ui;
};

#endif // PRODUCTIONLOGICDIALOG_H
