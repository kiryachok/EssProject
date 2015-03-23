#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "prmoddialog.h"
#include "addnewstrategydialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget_Products->resizeColumnsToContents();
    ui->tableWidget_Strategy->resizeColumnsToContents();

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
    AttrWindow* window = new AttrWindow(this);
    emit actionAttributes(window);
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

QTableWidget* MainWindow::getMapStrategyTableView()
{
    return this->ui->tableWidget_Strategy;
}

QTextBrowser* MainWindow::getCurrentStrategyView()
{
    return this->ui->textBrowser;
}

void MainWindow::on_action_productionNew_triggered()
{
    AddNewStrategyDialog *addStartegyDialogue = new AddNewStrategyDialog(this);
    if (QDialog::Accepted == addStartegyDialogue->exec()) {
        emit this->actionNewStrategy(addStartegyDialogue->getStrategyName(), addStartegyDialogue->getStrategyComment());
    }
    delete addStartegyDialogue;
}

void MainWindow::on_action_productionRemove_triggered()
{
    emit this->actionRemoveStrategy();
}

void MainWindow::on_action_24_triggered()
{
   ProductionDialog *prodDialog = new ProductionDialog(this);

   prodDialog->show();
}

void MainWindow::on_action_25_triggered()
{
   ProductionDialog *prodDialog = new ProductionDialog(this);
    prodDialog->show();
}
