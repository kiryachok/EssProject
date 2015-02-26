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

private slots:
    void on_action_modules_triggered();

    void on_action_attributes_triggered();

private:
    Ui::MainWindow *ui;

    MapAttributeController attr_ctrl;
};

#endif // MAINWINDOW_H
