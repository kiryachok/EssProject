#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTextBrowser>

#include "attrwindow.h"
#include "newattrwindow.h"

#include "essview_global.h"
#include "../EssController/mapattributecontroller.h"

namespace Ui {
class MainWindow;
}

class ESSVIEWSHARED_EXPORT MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTableWidget* getMapStrategyTableView();
    QTextBrowser* getCurrentStrategyView();

    void setMapAttributeController(MapAttributeController* ctrl);

signals:
    void openFile();
    void saveFile();
    void saveFileAs();
    void newFile();

    void actionNewStrategy(QString, QString);
    void actionRemoveStrategy();

private slots:
    void on_action_modules_triggered();

    void on_action_attributes_triggered();

    void on_action_open_triggered();

    void on_action_save_as_triggered();

    void on_action_save_triggered();

    void on_action_new_triggered();

    void on_action_productionNew_triggered();

    void on_action_productionRemove_triggered();

private:
    Ui::MainWindow *ui;

    MapAttributeController* attr_ctrl;
};

#endif // MAINWINDOW_H
