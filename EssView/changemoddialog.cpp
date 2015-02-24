#include "changemoddialog.h"
#include "ui_changemoddialog.h"

ChangeModDialog::ChangeModDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeModDialog)
{
    ui->setupUi(this);
}

ChangeModDialog::~ChangeModDialog()
{
    delete ui;
}
