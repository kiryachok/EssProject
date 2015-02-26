#ifndef ATTRWINDOW_H
#define ATTRWINDOW_H

#include "essview_global.h"

#include <QMainWindow>
#include <QListWidgetItem>
#include <QFileDialog>
#include <QMessageBox>

#include "essview_global.h"
#include "newattrwindow.h"
#include "../EssController/mapattributecontroller.h"

namespace Ui {
class AttrWindow;
}

class ESSVIEWSHARED_EXPORT AttrWindow : public QMainWindow
{
    Q_OBJECT

public:
    AttrWindow(MapAttributeController* controller, QWidget *parent = 0);

    ~AttrWindow();

private slots:
    void on_buttonOk_clicked();
    void on_buttonCancel_clicked();
    void on_buttonImport_clicked();

    void on_buttonNewAttribute_clicked();
    void on_buttonEditAttribute_clicked();
    void on_buttonDeleteAttribute_clicked();

    void onAttributeCreated(AttributeController* controller);
    void onAttributeUpdated(AttributeController* controller, QString key);
    void onAttributeRemoved();

    void on_listWidgetAttributes_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

private:
    Ui::AttrWindow *ui;

    MapAttributeController* ctrl;
};

#endif // ATTRWINDOW_H
