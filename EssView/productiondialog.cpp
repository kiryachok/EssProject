#include "productiondialog.h"
#include "ui_productiondialog.h"
#include "newlogicaldialog.h"
#include "newstringproductiondialog.h"
#include "newarithmeticdialog.h"

ProductionDialog::ProductionDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProductionDialog)
{
    ui->setupUi(this);
}

ProductionDialog::~ProductionDialog()
{
    delete ui;
}

void ProductionDialog::on_new_logic_pushButton_clicked()
{
    NewLogicalDialog *dialog = new NewLogicalDialog(this);
    if (QDialog::Accepted == dialog->exec()){
        emit addNewExpression();
    }
    delete dialog;
}

void ProductionDialog::on_new_string_pushButton_clicked()
{
    NewStringProductionDialog *dialog = new NewStringProductionDialog(this);
    if (QDialog::Accepted == dialog->exec()){
        emit addNewExpression();
    }
    delete dialog;
}

void ProductionDialog::on_new_math_pushButton_clicked()
{
    NewArithmeticDialog *dialog = new NewArithmeticDialog(this);

    if (QDialog::Accepted == dialog->exec()){
        emit addNewExpression();
    }
    delete dialog;
}


void ProductionDialog::on_finish_pushButton_clicked()
{
   emit this->createNewProduction("strategy",1);
   this->close();
}

void ProductionDialog::on_ok_pushButton_clicked()
{
   this->close();
}
