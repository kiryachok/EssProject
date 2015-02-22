#include "newmoddialog.h"
#include "ui_newmoddialog.h"

NewModDialog::NewModDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewModDialog)
{
    ui->setupUi(this);
}

NewModDialog::~NewModDialog()
{
    delete ui;
}

void NewModDialog::on_closeButton_clicked()
{
    close();
}
