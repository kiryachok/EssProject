#include "newlogicaldialog.h"
#include "ui_newlogicaldialog.h"
#include "../EssController/productioncontroller.h"
NewLogicalDialog::NewLogicalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewLogicalDialog)
{
    ui->setupUi(this);

}

NewLogicalDialog::~NewLogicalDialog()
{
    delete ui;
}

void NewLogicalDialog::setController(ProductionController *cont)
{
    controller = cont;
}

void NewLogicalDialog::on_pushButton_7_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + '(');
}

void NewLogicalDialog::on_pushButton_8_clicked()
{

    ui->lineEdit->setText(ui->lineEdit->text() + ')');
}

void NewLogicalDialog::on_pushButton_clicked()
{

    ui->lineEdit->setText(ui->lineEdit->text() + '~');
}

void NewLogicalDialog::on_pushButton_2_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + '&');
}

void NewLogicalDialog::on_pushButton_3_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + '|');
}

void NewLogicalDialog::on_pushButton_4_clicked()
{

    ui->lineEdit->setText(ui->lineEdit->text() + '^');
}

void NewLogicalDialog::on_pushButton_5_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "->");
}

void NewLogicalDialog::on_pushButton_6_clicked()
{

    ui->lineEdit->setText(ui->lineEdit->text() + '=');
}

void NewLogicalDialog::on_pushButton_10_clicked()
{

    ui->lineEdit->setText("");
}

void NewLogicalDialog::on_pushButton_12_clicked()
{
    controller->addExpresion(0, ui->lineEdit->text(),1);
}
