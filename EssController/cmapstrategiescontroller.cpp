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
    this->_textBrowser = NULL;
    this->_curentStrategy = NULL;

    this->_mapStrategys = new CMapStrategies();

    connect(this, SIGNAL(curentMapChanged()),
            this, SLOT(handleMapDataChanged()));
    connect(this, SIGNAL(curentStrategyChanged(CStrategy*)),
            this, SLOT(handleCurrentStrategyChanged()));
}

CMapStrategiesController::~CMapStrategiesController()
{
    delete this->_mapStrategys;
}

void CMapStrategiesController::InitView(QTableWidget *tableView, QTextBrowser *textView)
{
    this->_tableView = tableView;
    this->_textBrowser = textView;

    if (NULL == this->_tableView) {
        return;
    }

    this->_tableView->clear();
    this->_tableView->verticalHeader()->hide();
    this->_tableView->horizontalHeader()->setStretchLastSection(true);
    this->_tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->_tableView->setSelectionMode(QAbstractItemView::SingleSelection);

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

    if (this->_tableView->selectedItems().size() == 0) {
        this->_curentStrategy = NULL;
        emit this->curentStrategyChanged(this->_curentStrategy);
        return;
    }

    int rowIndex = this->_tableView->selectedItems()[0]->row();
    QTableWidgetItem *strategyItem = this->_tableView->item(rowIndex, this->_columnIndex[COLUMN_NAME_STRATEGY]);
    QString strategyName = strategyItem->text();

    if (this->_mapStrategys->mst.count(strategyName.toStdString()) != 0) {
        this->_curentStrategy = this->_mapStrategys->mst[strategyName.toStdString()];
        emit this->curentStrategyChanged(this->_curentStrategy);
    }
}

void CMapStrategiesController::handleCurrentStrategyChanged()
{
    if (NULL == this->_textBrowser) {
        return;
    }

    if (NULL == this->_curentStrategy) {
        this->_textBrowser->clear();
    } else {
        this->_textBrowser->append(QString("Число продукций - ") +
                                   QString::number(this->_curentStrategy->m_ArrayProduction.apr.size()));
        this->_textBrowser->append(QString::fromStdString(this->_curentStrategy->m_Comment));
    }
}

CStrategy* CMapStrategiesController::getCurrentStrategy()
{
    return this->_curentStrategy;
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

        countItem->setFlags(countItem->flags() & ~Qt::ItemIsEditable);
        strategyItem->setFlags(strategyItem->flags() & ~Qt::ItemIsEditable);

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
    if (NULL == this->_curentStrategy) {
        return;
    }

    string strategyName = this->_curentStrategy->m_Name;
    if (this->_mapStrategys->mst.count(strategyName) != 0) {
        this->_mapStrategys->mst.erase(strategyName);
        this->_curentStrategy = NULL;
        emit this->curentStrategyChanged(this->_curentStrategy);
        emit this->curentMapChanged();
    }
}
