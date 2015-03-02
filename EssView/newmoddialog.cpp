#include "newmoddialog.h"
#include "ui_newmoddialog.h"
#include "launchconditions.h"

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

void NewModDialog::on_changeButton_clicked()
{
    LaunchConditions *launchCond = new LaunchConditions(this);
    launchCond->setModal(true);
    launchCond->exec();
}
