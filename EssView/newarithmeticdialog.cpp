#include "newarithmeticdialog.h"
#include "ui_newarithmeticdialog.h"

NewArithmeticDialog::NewArithmeticDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewArithmeticDialog)
{
    ui->setupUi(this);
}

NewArithmeticDialog::~NewArithmeticDialog()
{
    delete ui;
}

void NewArithmeticDialog::on_backButton_clicked()
{
    close();
}
