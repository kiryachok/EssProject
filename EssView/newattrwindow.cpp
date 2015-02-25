#include "newattrwindow.h"
#include "ui_newattrwindow.h"

NewAttrWindow::NewAttrWindow(QWidget *parent, CKnAttr* attr) :
    QDialog(parent),
    ui(new Ui::NewAttrWindow)
{
    ui->setupUi(this);
    oldAttr = attr;
    if (attr != NULL) {
        ui->comboBoxType->setCurrentIndex(attr->m_Type);
        ui->lineEditFullName->setText(attr->m_FullName.c_str());
        ui->lineEditShortName->setText(attr->m_ShortName.c_str());
        ui->lineEditValue->setText(attr->getValueAsText().c_str());
    }
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

    CKnAttr* attr = make_attr(fullName, shortName, type, value);
    if (attr != NULL) {
        if (oldAttr == NULL) {
            emit itemCreated(attr);
        } else {
            emit itemChanged(oldAttr, attr);
        }
        close();
    }
}
