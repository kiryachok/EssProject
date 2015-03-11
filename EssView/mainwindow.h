#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

    void setMapAttributeController(MapAttributeController* ctrl);

signals:
    void openFile();
    void saveFile();
    void saveFileAs();
    void newFile();

private slots:
    void on_action_modules_triggered();

    void on_action_attributes_triggered();

    void on_action_open_triggered();

    void on_action_save_as_triggered();

    void on_action_save_triggered();

    void on_action_new_triggered();

private:
    Ui::MainWindow *ui;

    MapAttributeController* attr_ctrl;
};

#endif // MAINWINDOW_H
