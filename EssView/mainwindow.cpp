#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "prmoddialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget_Frames->resizeColumnsToContents();
    ui->tableWidget_Products->resizeColumnsToContents();
    ui->tableWidget_Strategy->resizeColumnsToContents();
    ui->tableWidget_SlotsByFrame->resizeColumnsToContents();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_modules_triggered()
{
    PrModDialog *PrMod = new PrModDialog(this);
    PrMod->setModal(true);
    PrMod->exec();
}

void MainWindow::on_action_attributes_triggered()
{
    AttrWindow* window = new AttrWindow(&attr_ctrl, this);
    window->show();
}

//void MainWindow::on_action_2_triggered()
//{
//    emit this->atata();
//}

void MainWindow::on_action_open_triggered()
{
    emit this->openFile();
}

void MainWindow::on_action_save_as_triggered()
{
    emit this->saveFileAs();
}

void MainWindow::on_action_save_triggered()
{
    emit this->saveFile();
}

void MainWindow::on_action_new_triggered()
{
    emit this->newFile();
}
