#include "newstringdialog.h"
#include "ui_newstringdialog.h"

NewStringDialog::NewStringDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewStringDialog)
{
    ui->setupUi(this);
}

NewStringDialog::~NewStringDialog()
{
    delete ui;
}

void NewStringDialog::on_doneButton_clicked()
{
    close();
}
