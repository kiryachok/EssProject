#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
