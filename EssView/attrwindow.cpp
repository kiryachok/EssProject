#include "attrwindow.h"
#include "ui_attrwindow.h"

AttrWindow::AttrWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AttrWindow)
{
    ui->setupUi(this);
}

void AttrWindow::on_buttonOk_clicked()
{
    emit accepted();
    close();
}

void AttrWindow::on_buttonCancel_clicked()
{
    emit rejected();
    close();
}

void AttrWindow::on_buttonImport_clicked()
{
    QString dir = "";
    QString caption = "";
    QString filter = "*.atr";
    QFileDialog dialog(this, caption, dir, filter);
    dialog.exec();
    ui->listWidgetAttributes->clear();
    QStringList files = dialog.selectedFiles();
    if (!files.empty()) {
        emit importFile(dialog.selectedFiles()[0]);
    }
}

void AttrWindow::on_buttonExport_clicked()
{
    QString caption = "Save file";
    QString dir = "";
    QString filter = "*.atr";
    QString fileName = QFileDialog::getSaveFileName(this, caption, dir, filter);
    emit exportFile(fileName);
}

void AttrWindow::on_buttonNewAttribute_clicked()
{
    lastNewAttrWindow = new NewAttrWindow(this);
    lastNewAttrWindow->initView();
    connect(lastNewAttrWindow, SIGNAL(tryDataChange(QString,QString,QString,QString,QString)),
            this, SIGNAL(tryDataChange(QString,QString,QString,QString,QString)));
    lastNewAttrWindow->exec();
    ui->listWidgetAttributes->setFocus();
}

void AttrWindow::on_buttonEditAttribute_clicked()
{
    if (ui->listWidgetAttributes->currentRow() < 0) {
        return;
    }
    QString fullName = ui->listWidgetAttributes->currentItem()->text();
    QString shortName = ui->lineEditShortName->text();
    QString type = ui->comboBoxType->currentText();
    QString value = ui->lineEditValue->text();
    lastNewAttrWindow = new NewAttrWindow(this);
    lastNewAttrWindow->initView(fullName, shortName, type, value);
    connect(lastNewAttrWindow, SIGNAL(tryDataChange(QString,QString,QString,QString,QString)),
            this, SIGNAL(tryDataChange(QString,QString,QString,QString,QString)));
    lastNewAttrWindow->exec();
    ui->listWidgetAttributes->setFocus();
}

void AttrWindow::on_buttonDeleteAttribute_clicked()
{
    if (ui->listWidgetAttributes->currentRow() < 0) {
        return;
    }
    QString title = "Delete attribute";
    QString text = "Do you want to delete attribute?";
    QMessageBox::Icon icon = QMessageBox::Question;
    QMessageBox* message = new QMessageBox(icon, title, text,
                                           QMessageBox::Yes | QMessageBox::No, this);
    int answer = message->exec();
    if (answer == QMessageBox::Yes) {
        emit remove(ui->listWidgetAttributes->currentItem()->text());
        ui->listWidgetAttributes->takeItem(ui->listWidgetAttributes->currentRow());
    }
    ui->listWidgetAttributes->setFocus();
}

void AttrWindow::AddAttribute(QString fullName, QString shortName, QString type, QString value) {
    ui->listWidgetAttributes->addItem(fullName);
    ui->lineEditShortName->setText(shortName);
    ui->comboBoxType->setCurrentText(type);
    ui->lineEditValue->setText(value);
}

void AttrWindow::dataChecked(QString key, QString fullName, QString shortName,
                             QString type, QString value, bool valid) {
    if (lastNewAttrWindow != 0) {
        lastNewAttrWindow->dataChecked(valid);
        if (valid) {
            if (key == "") {
                AddAttribute(fullName, shortName, type, value);
            } else {
                setCurrentItem(fullName, shortName, type, value);
            }
        }
    }
}

void AttrWindow::on_listWidgetAttributes_currentItemChanged(QListWidgetItem *current,
                                                          QListWidgetItem */*previous*/)
{
    if (ui->listWidgetAttributes->currentRow() < 0) {
        ui->lineEditShortName->setText("");
        ui->comboBoxType->setCurrentIndex(-1);
        ui->lineEditValue->setText("");
    } else {
        emit currentItemChanged(ui->listWidgetAttributes->currentItem()->text());
    }
}

void AttrWindow::setCurrentItem(QString fullName, QString shortName, QString type, QString value) {
    ui->listWidgetAttributes->currentItem()->setText(fullName);
    ui->lineEditShortName->setText(shortName);
    ui->comboBoxType->setCurrentText(type);
    ui->lineEditValue->setText(value);
}

AttrWindow::~AttrWindow()
{
    delete ui;
}
