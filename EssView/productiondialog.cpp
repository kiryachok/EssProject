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
    controller = new ProductionController();
}

ProductionDialog::~ProductionDialog()
{
    delete ui;
}

void ProductionDialog::on_new_logic_pushButton_clicked()
{
    NewLogicalDialog *dialog = new NewLogicalDialog(this);
    dialog->setController(controller);
    dialog->show();
}

void ProductionDialog::on_new_string_pushButton_clicked()
{
    NewStringProductionDialog *dialog = new NewStringProductionDialog(this);
    dialog->setController(controller);
    dialog->show();
}

void ProductionDialog::on_new_math_pushButton_clicked()
{
    NewArithmeticDialog *dialog = new NewArithmeticDialog(this);
    dialog->show();
}


void ProductionDialog::on_finish_pushButton_clicked()
{
    controller->setFormula("");
    controller->setName("strategy");
    controller->setType(1);
}
