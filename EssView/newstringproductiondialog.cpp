#include "newstringproductiondialog.h"
#include "ui_newstringproductiondialog.h"

NewStringProductionDialog::NewStringProductionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewStringProductionDialog)
{
    ui->setupUi(this);
}

NewStringProductionDialog::~NewStringProductionDialog()
{
    delete ui;
}


void NewStringProductionDialog::on_pushButton_12_clicked()
{
   ui->lineEdit->setText(ui->lineEdit->text() + "=");
}

void NewStringProductionDialog::on_pushButton_13_clicked()
{

   ui->lineEdit->setText(ui->lineEdit->text() + "#");
}

void NewStringProductionDialog::on_pushButton_4_clicked()
{

   ui->lineEdit->setText(ui->lineEdit->text() + "+");
}

void NewStringProductionDialog::on_pushButton_6_clicked()
{

   ui->lineEdit->setText(ui->lineEdit->text() + "\"");
}

void NewStringProductionDialog::on_pushButton_clicked()
{

   ui->lineEdit->setText(ui->lineEdit->text() + "have");
}


void NewStringProductionDialog::on_pushButton_3_clicked()
{

   ui->lineEdit->setText(ui->lineEdit->text() + "not have");
}

void NewStringProductionDialog::on_pushButton_2_clicked()
{
   ui->lineEdit->setText(ui->lineEdit->text() + "exist");
}

void NewStringProductionDialog::on_pushButton_5_clicked()
{
   ui->lineEdit->setText(ui->lineEdit->text() + "not exist");
}

void NewStringProductionDialog::on_pushButton_8_clicked()
{
    this->close();
}

void NewStringProductionDialog::on_pushButton_11_clicked()
{
    this->close();
}

void NewStringProductionDialog::on_pushButton_9_clicked()
{
    ui->lineEdit->setText("");
}
