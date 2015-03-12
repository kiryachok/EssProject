#ifndef CMAPSTRATEGIESCONTROLLER_H
#define CMAPSTRATEGIESCONTROLLER_H

#include <QObject>
#include <QTableWidget>

#include "objects.h"
#include "esscontroller_global.h"

class ESSCONTROLLERSHARED_EXPORT CMapStrategiesController : public QObject
{
    Q_OBJECT

private:
    QTableWidget *_tableView;
    CStrategy *_curentStrategy;
    CMapStrategies *_mapStrategys;

    QHash<QString, int> _columnIndex;

public:
    explicit CMapStrategiesController(QObject *parent = 0);
    ~CMapStrategiesController();

    void InitView(QTableWidget*);

    void Serialize(CArch&);

signals:
    void curentStrategyChanged();
    void curentMapChanged();

private slots:
    void handleMapDataChanged();
    void handleSelectionChanged();

public slots:
    void handleAddStrategy(QString, QString);
    void handleRemoveStrategy();

};

#endif // CMAPSTRATEGIESCONTROLLER_H
