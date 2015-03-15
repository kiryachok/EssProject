#include "productionlogicdialog.h"
#include "ui_productionlogicdialog.h"

ProductionLogicDialog::ProductionLogicDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProductionLogicDialog)
{
    ui->setupUi(this);
}

ProductionLogicDialog::~ProductionLogicDialog()
{
    delete ui;
}
