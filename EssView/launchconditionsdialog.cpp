#include "launchconditionsdialog.h"
#include "ui_launchconditionsdialog.h"

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
