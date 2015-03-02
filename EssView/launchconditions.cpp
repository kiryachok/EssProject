#include "launchconditions.h"
#include "ui_launchconditions.h"

LaunchConditions::LaunchConditions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LaunchConditions)
{
    ui->setupUi(this);
}

LaunchConditions::~LaunchConditions()
{
    delete ui;
}
