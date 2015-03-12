#include "cmapstrategiescontroller.h"

#include <QHeaderView>
#include <QTableWidgetItem>
#include <QDebug>

#define COLUMN_NAME_COUNTER     QString("Counter")
#define COLUMN_NAME_STRATEGY    QString("Strategy")

#define COLUMN_TEXT_COUNTER     QString("№")
#define COLUMN_TEXT_STRATEGY    QString("С т р а т е г и и")

CMapStrategiesController::CMapStrategiesController(QObject *parent) :
    QObject(parent)
{
    this->_tableView = NULL;
    this->_curentStrategy = NULL;

    this->_mapStrategys = new CMapStrategies();

    connect(this, SIGNAL(curentMapChanged()),
            this, SLOT(handleMapDataChanged()));
}

CMapStrategiesController::~CMapStrategiesController()
{
    delete this->_mapStrategys;
}

void CMapStrategiesController::InitView(QTableWidget *view)
{
    this->_tableView = view;
    this->_tableView->clear();
    this->_tableView->verticalHeader()->hide();
    this->_tableView->horizontalHeader()->setStretchLastSection(true);

    if (NULL == this->_tableView) {
        return;
    }

    QStringList headerList;
    headerList.append(COLUMN_TEXT_COUNTER);
    headerList.append(COLUMN_TEXT_STRATEGY);

    this->_columnIndex.clear();
    this->_columnIndex.insert(COLUMN_NAME_COUNTER, this->_columnIndex.size());
    this->_columnIndex.insert(COLUMN_NAME_STRATEGY, this->_columnIndex.size());

    this->_tableView->setColumnCount(this->_columnIndex.size());
    this->_tableView->setHorizontalHeaderLabels(headerList);
    this->_tableView->resizeColumnsToContents();

    connect(this->_tableView, SIGNAL(itemSelectionChanged()),
            this, SLOT(handleSelectionChanged()));
}

void CMapStrategiesController::handleSelectionChanged()
{
    if (NULL == this->_tableView) {
        return;
    }

    //this->_tableView->currentRow();
}

void CMapStrategiesController::Serialize(CArch &arch)
{
    this->_mapStrategys->Serialize(arch);
    emit this->curentMapChanged();
}

void CMapStrategiesController::handleMapDataChanged()
{
    this->_tableView->clearContents();
    this->_tableView->setRowCount(0);

    for (unsigned int i = 0; i < this->_mapStrategys->mst.size(); ++i) {
        CStrategy *strategy = this->_mapStrategys->GetStrategy(i);
        if (NULL == strategy) {
            continue;
        }

        this->_tableView->setRowCount(this->_tableView->rowCount() + 1);

        QTableWidgetItem *countItem = new QTableWidgetItem(QString::number(this->_tableView->rowCount()));
        QTableWidgetItem *strategyItem = new QTableWidgetItem(QString::fromStdString(strategy->m_Name));

        this->_tableView->setItem(this->_tableView->rowCount() - 1, this->_columnIndex[COLUMN_NAME_COUNTER], countItem);
        this->_tableView->setItem(this->_tableView->rowCount() - 1, this->_columnIndex[COLUMN_NAME_STRATEGY], strategyItem);
    }
    this->_tableView->resizeColumnsToContents();
    this->_tableView->horizontalHeader()->setStretchLastSection(true);
}

void CMapStrategiesController::handleAddStrategy(QString name, QString comment)
{
    CStrategy *strategy = new CStrategy();
    strategy->m_Name = name.toStdString();
    strategy->m_Comment = comment.toStdString();

    this->_mapStrategys->SetAt(name.toStdString(), strategy);
    emit this->curentMapChanged();
}

void CMapStrategiesController::handleRemoveStrategy()
{

}
