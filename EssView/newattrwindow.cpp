#include "newattrwindow.h"
#include "ui_newattrwindow.h"

NewAttrWindow::NewAttrWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewAttrWindow)
{
    ui->setupUi(this);
}

void NewAttrWindow::initView(QString fullName, QString shortName, QString type, QString value) {
    key = fullName;
    ui->lineEditFullName->setText(fullName);
    ui->lineEditShortName->setText(shortName);
    ui->comboBoxType->setCurrentText(type);
    ui->lineEditValue->setText(value);
}

void NewAttrWindow::on_pushButtonCancel_clicked()
{
    close();
}

void NewAttrWindow::on_pushButtonOk_clicked()
{
    QString fullName = ui->lineEditFullName->text();
    QString shortName = ui->lineEditShortName->text();
    QString type = ui->comboBoxType->currentText();
    QString value = ui->lineEditValue->text();

    emit tryDataChange(key, fullName, shortName, type, value);
}

void NewAttrWindow::dataChecked(bool valid) {
    if (valid) {
        close();
    } else {
        QString title = "";
        QString text = "Wrong value";
        QMessageBox::Icon icon = QMessageBox::Information;
        QMessageBox* message = new QMessageBox(icon, title, text, QMessageBox::Ok, this);
        message->exec();
    }
}

NewAttrWindow::~NewAttrWindow()
{
    delete ui;
}
