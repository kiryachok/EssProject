#include "attrwindow.h"
#include "ui_attrwindow.h"

AttrWindow::AttrWindow(QWidget *parent, CMapAttributes* attributes) :
    QMainWindow(parent),
    ui(new Ui::AttrWindow)
{
    ui->setupUi(this);

    if (attributes != NULL) {
        this->attributes = attributes->copy();
    } else {
        this->attributes = new CMapAttributes;
    }
}

AttrWindow::~AttrWindow()
{
    delete ui;
}

void AttrWindow::on_buttonOk_clicked()
{
    emit attributesChanged(attributes);
    close();
}


void AttrWindow::on_buttonCancel_clicked()
{
    delete attributes;
    close();
}

void AttrWindow::onItemCreated(CKnAttr* attr) {
    attributes->add(attr);
    addAttribute(attr);
}

void AttrWindow::addAttribute(CKnAttr* newAttribute)
{
    ui->listWidgetAttributes->addItem(newAttribute->text());
    int size = ui->listWidgetAttributes->count();
    ui->listWidgetAttributes->setCurrentRow(size - 1);
    ui->listWidgetAttributes->setFocus();
}

void AttrWindow::onItemChanged(CKnAttr *old, CKnAttr* value) {
    attributes->remove(old);
    attributes->add(value);
    updateAttribute(value, old);
}

void AttrWindow::updateAttribute(CKnAttr* attr, CKnAttr *old)
{
    QList<QListWidgetItem*> found = ui->listWidgetAttributes->findItems(old->text(),
                                                                        Qt::MatchExactly);
    found[0]->setText(attr->text());
    ui->listWidgetAttributes->setFocus();
}

void AttrWindow::on_buttonNewAttribute_clicked()
{
    NewAttrWindow window;
    connect(&window, SIGNAL(itemCreated(CKnAttr*)), this, SLOT(onItemCreated(CKnAttr*)));
    window.exec();
}

void AttrWindow::on_buttonEditAttribute_clicked()
{
    if (ui->listWidgetAttributes->currentRow() < 0) {
        return;
    }
    string key = ui->listWidgetAttributes->currentItem()->text().toStdString();
    CKnAttr* attr = NULL;
    attributes->Lookup(key, attr);
    if (attr != NULL) {
        NewAttrWindow* window = new NewAttrWindow(this, attr);
        connect(window, SIGNAL(itemChanged(CKnAttr*,CKnAttr*)),
                this, SLOT(onItemChanged(CKnAttr*,CKnAttr*)));
        window->exec();
        emit ui->listWidgetAttributes->currentItemChanged(ui->listWidgetAttributes->currentItem(),
                                                          NULL);
    }
}

void AttrWindow::on_listWidgetAttributes_currentItemChanged(QListWidgetItem *current,
                                                          QListWidgetItem *previous)
{
    if (ui->listWidgetAttributes->currentRow() < 0) {
        return;
    }
    string key = current->text().toStdString();
    CKnAttr* attr = NULL;
    attributes->Lookup(key, attr);
    if (attr != NULL) {
        ui->lineEditShortName->setText(attr->m_ShortName.c_str());
        ui->comboBoxType->setCurrentIndex(attr->m_Type);
        ui->lineEditValue->setText(attr->getValueAsText().c_str());
    }
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
        string key = ui->listWidgetAttributes->currentItem()->text().toStdString();
        attributes->removeAt(key);
        ui->listWidgetAttributes->takeItem(ui->listWidgetAttributes->currentRow());
        ui->listWidgetAttributes->setFocus();
    }
}

void AttrWindow::on_buttonImport_clicked()
{
    QString dir = "";
    QString caption = "";
    QString filter = "*.atr";
    QFileDialog dialog(this, caption, dir, filter);
//    connect(&dialog, SIGNAL(fileSelected(QString)), this, SLOT(onImportFile(QString)));
    dialog.exec();
    onImportFile(dialog.selectedFiles()[0]);
}

void AttrWindow::onImportFile(QString fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        return;
    }
    CMapAttributes* importAttrs = new CMapAttributes;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString shortName;
        QString type;
        QString fullName;
        in >> shortName >> type;
        in.skipWhiteSpace();
        fullName = in.readLine().simplified();
        type = type.mid(1, type.length() - 2); //remove parentheses
        CKnAttr* attr = make_attr(fullName, shortName, type);
        if (attr != NULL) {
            importAttrs->add(attr);
        } else {
            delete importAttrs;
            return;
        }
    }
    file.close();
    delete attributes;
    attributes = importAttrs;
    updateAttributes();
}

void AttrWindow::updateAttributes() {
    string key;
    CKnAttr* value = NULL;
    ui->listWidgetAttributes->clear();
    attributes->fromBeginning();
    while (attributes->hasNext()) {
        attributes->GetNextAssoc(key, value);
        addAttribute(value);
    }
}
