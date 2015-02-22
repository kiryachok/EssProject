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
