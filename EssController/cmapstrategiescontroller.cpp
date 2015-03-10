#include "cmapstrategiescontroller.h"

#include <QHeaderView>
#include <QTableWidgetItem>

#define COLUMN_NAME_COUNTER     QString("Counter")
#define COLUMN_NAME_STRATEGY    QString("Strategy")

#define COLUMN_TEXT_COUNTER     QString("№")
#define COLUMN_TEXT_STRATEGY    QString("С т р а т е г и и")

CMapStrategiesController::CMapStrategiesController(QObject *parent) :
    QObject(parent)
{
    this->_tableView = NULL;
    this->_curentStrategy = NULL;
    this->_mapStrategys = NULL;

    connect(this, SIGNAL(curentMapChanged()),
            this, SLOT(handleMapDataChanged()));
}

void CMapStrategiesController::InitView(QTableWidget *view)
{
    this->_tableView = view;

    if (NULL == this->_tableView) {
        return;
    }

    QStringList headerList;
    headerList.append(COLUMN_TEXT_COUNTER);
    headerList.append(COLUMN_TEXT_STRATEGY);

    this->_columnIndex.clear();
    this->_columnIndex.insert(COLUMN_NAME_COUNTER, this->_columnIndex.size());
    this->_columnIndex.insert(COLUMN_NAME_STRATEGY, this->_columnIndex.size());

    this->_tableView->clear();
    this->_tableView->setColumnCount(this->_columnIndex.size());
    this->_tableView->setHorizontalHeaderLabels(headerList);

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
    this->_tableView->clear();

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
}
