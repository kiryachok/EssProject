#include "launchconditionsdialog.h"
#include "ui_launchconditionsdialog.h"
#include "newlogicaldialog.h"

LaunchConditionsDialog::LaunchConditionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LaunchConditionsDialog)
{
    ui->setupUi(this);
}

LaunchConditionsDialog::~LaunchConditionsDialog()
{
    delete ui;
}

void LaunchConditionsDialog::on_newLogicButton_clicked()
{
    NewLogicalDialog *newLogDialog = new NewLogicalDialog(this);
    newLogDialog->setModal(true);
    newLogDialog->exec();
}
