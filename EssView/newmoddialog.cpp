#include "newmoddialog.h"
#include "ui_newmoddialog.h"
#include "launchconditionsdialog.h"

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

void NewModDialog::on_changeButton_clicked()
{
    LaunchConditionsDialog *launchCondDialog = new LaunchConditionsDialog(this);
    launchCondDialog->setModal(true);
    launchCondDialog->exec();
}

void NewModDialog::on_exitButton_clicked()
{
     close();
}

void NewModDialog::on_okButton_clicked()
{
    emit newProgModSubmitted();
}
