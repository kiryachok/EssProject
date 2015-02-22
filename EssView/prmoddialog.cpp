#include "prmoddialog.h"
#include "ui_prmoddialog.h"
#include "newmoddialog.h"
#include "changemoddialog.h"
#include <QFileDialog>
#include <QString>
#include <QStandardPaths>

QString f_qt;

PrModDialog::PrModDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrModDialog)
{
    ui->setupUi(this);
}

PrModDialog::~PrModDialog()
{
    delete ui;
}

void PrModDialog::on_exitButton_clicked()
{
    close();
}

void PrModDialog::on_newButton_clicked()
{
    NewModDialog *newModDialog = new NewModDialog(this);
    newModDialog->setModal(true);
    newModDialog->exec();
}

void PrModDialog::on_exportButton_clicked()
{
    QString filename;
    const QString dir = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    filename =  QFileDialog::getSaveFileName(this, "Сохранить как", dir, ".prg");
}

void PrModDialog::on_changeButton_clicked()
{
    ChangeModDialog *changeDialog = new ChangeModDialog(this);
    changeDialog->setModal(true);
    changeDialog->exec();
}
