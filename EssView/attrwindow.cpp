#include "attrwindow.h"
#include "ui_attrwindow.h"

AttrWindow::AttrWindow(MapAttributeController* controller, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AttrWindow)
{
    ui->setupUi(this);

    ctrl = controller;

    connect(ctrl, SIGNAL(attributeCreated(AttributeController*)),
            this, SLOT(onAttributeCreated(AttributeController*)));
    connect(ctrl, SIGNAL(attributeUpdated(AttributeController*,QString)),
            this, SLOT(onAttributeUpdated(AttributeController*,QString)));
    connect(ctrl, SIGNAL(attributeRemoved(QString)),
            this, SLOT(onAttributeRemoved()));

    ctrl->refresh();
}

void AttrWindow::on_buttonOk_clicked()
{
    ctrl->acceptChanges();
    close();
}

void AttrWindow::on_buttonCancel_clicked()
{
    ctrl->discardChanges();
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
        ctrl->loadFile(dialog.selectedFiles()[0]);
    }
}

void AttrWindow::on_buttonExport_clicked()
{
    QString caption = "Save file";
    QString dir = "";
    QString filter = "*.atr";
    QString fileName = QFileDialog::getSaveFileName(this, caption, dir, filter);
    ctrl->saveFile(fileName);
}

void AttrWindow::on_buttonNewAttribute_clicked()
{
    AttributeController* controller = ctrl->getAttributeController();
    NewAttrWindow* window = new NewAttrWindow(controller, this);
    window->exec();
}

void AttrWindow::on_buttonEditAttribute_clicked()
{
    if (ui->listWidgetAttributes->currentRow() < 0) {
        return;
    }
    QString key = ui->listWidgetAttributes->currentItem()->text();
    AttributeController* controller = ctrl->getAttributeController(key);
    NewAttrWindow* window = new NewAttrWindow(controller, this);
    window->exec();
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
        ctrl->remove(ui->listWidgetAttributes->currentItem()->text());
    }
}

void AttrWindow::onAttributeCreated(AttributeController *controller) {
    ui->listWidgetAttributes->addItem(controller->getFullName());
    int size = ui->listWidgetAttributes->count();
    ui->listWidgetAttributes->setCurrentRow(size - 1);
    ui->listWidgetAttributes->setFocus();
}

void AttrWindow::onAttributeUpdated(AttributeController *controller, QString key) {
    QList<QListWidgetItem*> found = ui->listWidgetAttributes->findItems(key, Qt::MatchExactly);
    found[0]->setText(controller->getFullName());
    emit ui->listWidgetAttributes->currentItemChanged(found[0], NULL);
    ui->listWidgetAttributes->setFocus();
}

void AttrWindow::onAttributeRemoved() {
    ui->listWidgetAttributes->takeItem(ui->listWidgetAttributes->currentRow());
    ui->listWidgetAttributes->setFocus();
}

void AttrWindow::on_listWidgetAttributes_currentItemChanged(QListWidgetItem *current,
                                                          QListWidgetItem *previous)
{
    if (ui->listWidgetAttributes->currentRow() < 0) {
        ui->lineEditShortName->setText("");
        ui->comboBoxType->setCurrentIndex(-1);
        ui->lineEditValue->setText("");
    } else {
        AttributeController* controller = ctrl->getAttributeController(current->text());
        ui->lineEditShortName->setText(controller->getShortName());
        ui->comboBoxType->setCurrentIndex(controller->getType());
        ui->lineEditValue->setText(controller->getValue());
    }
}

AttrWindow::~AttrWindow()
{
    delete ui;
}
