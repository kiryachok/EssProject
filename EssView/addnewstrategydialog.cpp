#include "addnewstrategydialog.h"
#include "ui_addnewstrategydialog.h"

AddNewStrategyDialog::AddNewStrategyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewStrategyDialog)
{
    ui->setupUi(this);
}

AddNewStrategyDialog::~AddNewStrategyDialog()
{
    delete ui;
}

QString AddNewStrategyDialog::getStrategyName()
{
    return this->ui->lineEdit_strategyName->text();
}

QString AddNewStrategyDialog::getStrategyComment()
{
    return this->ui->textEdit_strategyComment->toPlainText();
}
