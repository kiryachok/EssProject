#ifndef CMAPSTRATEGIESCONTROLLER_H
#define CMAPSTRATEGIESCONTROLLER_H

#include <QObject>
#include <QTableWidget>
#include <QTextBrowser>

#include "objects.h"
#include "esscontroller_global.h"

class ESSCONTROLLERSHARED_EXPORT CMapStrategiesController : public QObject
{
    Q_OBJECT

private:
    QTableWidget *_tableView;
    QTextBrowser *_textBrowser;
    CStrategy *_curentStrategy;
    CMapStrategies *_mapStrategys;

    QHash<QString, int> _columnIndex;

public:
    explicit CMapStrategiesController(QObject *parent = 0);
    ~CMapStrategiesController();

    void InitView(QTableWidget *tableView = NULL, QTextBrowser *textView = NULL);
    void Serialize(CArch&);
    CStrategy* getCurrentStrategy();

signals:
    void curentStrategyChanged(CStrategy*);
    void curentMapChanged();

private slots:
    void handleMapDataChanged();
    void handleSelectionChanged();
    void handleCurrentStrategyChanged();

public slots:
    void handleAddStrategy(QString, QString);
    void handleRemoveStrategy();

};

#endif // CMAPSTRATEGIESCONTROLLER_H
