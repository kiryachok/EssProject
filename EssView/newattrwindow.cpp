#include "newattrwindow.h"
#include "ui_newattrwindow.h"

NewAttrWindow::NewAttrWindow(AttributeController* controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewAttrWindow)
{
    ui->setupUi(this);

    ctrl = controller;

    ui->lineEditFullName->setText(ctrl->getFullName());
    ui->lineEditShortName->setText(ctrl->getShortName());
    ui->comboBoxType->setCurrentIndex(ctrl->getType());
    ui->lineEditValue->setText(ctrl->getValue());
}

NewAttrWindow::~NewAttrWindow()
{
    delete ui;
}

void NewAttrWindow::on_pushButtonCancel_clicked()
{
    this->close();
}

void NewAttrWindow::on_pushButtonOk_clicked()
{
    QString fullName = ui->lineEditFullName->text();
    QString shortName = ui->lineEditShortName->text();
    QString type = ui->comboBoxType->currentText();
    QString value = ui->lineEditValue->text();

    if (ctrl->setFullName(fullName) && ctrl->setShortName(shortName) &&
            ctrl->setType(type) && ctrl->setValue(value)) {
        ctrl->acceptChanges();
        close();
    } else {
        QString title = "";
        QString text = "Wrong value";
        QMessageBox::Icon icon = QMessageBox::Information;
        QMessageBox* message = new QMessageBox(icon, title, text, QMessageBox::Ok, this);
        message->exec();
    }
}
