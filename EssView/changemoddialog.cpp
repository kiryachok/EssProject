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

void ChangeModDialog::on_closeButton_clicked()
{
    close();
}

void ChangeModDialog::on_okButton_clicked()
{
    emit changedProgModSubmitted();
    close();
}
