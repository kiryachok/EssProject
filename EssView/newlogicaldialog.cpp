#include "newlogicaldialog.h"
#include "ui_newlogicaldialog.h"

NewLogicalDialog::NewLogicalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewLogicalDialog)
{
    ui->setupUi(this);
}

NewLogicalDialog::~NewLogicalDialog()
{
    delete ui;
}
