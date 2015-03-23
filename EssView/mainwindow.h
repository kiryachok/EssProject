#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTextBrowser>

#include "attrwindow.h"
#include "newattrwindow.h"
#include "productiondialog.h"

#include "essview_global.h"

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

signals:
    void openFile();
    void saveFile();
    void saveFileAs();
    void newFile();

    void actionNewProduction();
    void actionNewStrategy(QString, QString);
    void actionRemoveStrategy();
    void actionAttributes(AttrWindow* window);

private slots:
    void on_action_modules_triggered();

    void on_action_attributes_triggered();

    void on_action_open_triggered();

    void on_action_save_as_triggered();

    void on_action_save_triggered();

    void on_action_new_triggered();

    void on_action_productionNew_triggered();

    void on_action_productionRemove_triggered();

    void on_action_24_triggered();

    void on_action_25_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
