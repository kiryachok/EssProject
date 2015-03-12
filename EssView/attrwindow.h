#ifndef ATTRWINDOW_H
#define ATTRWINDOW_H

#include "essview_global.h"

#include <QMainWindow>
#include <QListWidgetItem>
#include <QFileDialog>
#include <QMessageBox>

#include "essview_global.h"
#include "newattrwindow.h"

namespace Ui {
class AttrWindow;
}

class ESSVIEWSHARED_EXPORT AttrWindow : public QMainWindow
{
    Q_OBJECT

public:
    AttrWindow(QWidget *parent = 0);

    ~AttrWindow();

signals:
    void tryDataChange(QString key, QString fullName, QString shortName,
                       QString type, QString value);
    void remove(QString key);
    void currentItemChanged(QString key);
    void accepted();
    void rejected();
    void importFile(QString fileName);
    void exportFile(QString fileName);

public slots:
    void setCurrentItem(QString fullName, QString shortName, QString type, QString value);
    void dataChecked(QString key, QString fullName, QString shortName,
                     QString type, QString value, bool valid);

public slots:
    void on_buttonOk_clicked();
    void on_buttonCancel_clicked();
    void on_buttonImport_clicked();

    void on_buttonNewAttribute_clicked();
    void on_buttonEditAttribute_clicked();
    void on_buttonDeleteAttribute_clicked();

    void AddAttribute(QString fullName, QString shortName,
                      QString type, QString value);

    void on_listWidgetAttributes_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_buttonExport_clicked();

private:
    Ui::AttrWindow *ui;
    NewAttrWindow* lastNewAttrWindow;
};

#endif // ATTRWINDOW_H
