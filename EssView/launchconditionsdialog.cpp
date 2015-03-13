#include "launchconditionsdialog.h"
#include "ui_launchconditionsdialog.h"
#include "newlogicaldialog.h"
#include "newarithmeticdialog.h"
#include "newstringdialog.h"

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

void LaunchConditionsDialog::on_newArithmeticButton_clicked()
{
    NewArithmeticDialog *newArDialog = new NewArithmeticDialog(this);
    newArDialog->setModal(true);
    newArDialog->exec();
}

void LaunchConditionsDialog::on_newStringButton_clicked()
{
    NewStringDialog *newStrDialog = new NewStringDialog(this);
    newStrDialog->setModal(true);
    newStrDialog->exec();
}
