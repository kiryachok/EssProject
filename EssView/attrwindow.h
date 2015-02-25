#ifndef ATTRWINDOW_H
#define ATTRWINDOW_H

#include "essview_global.h"

#include <QMainWindow>
#include <QListWidgetItem>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

#include "../EssModel/objects.h"
#include "newattrwindow.h"

#include <QDebug>

namespace Ui {
class AttrWindow;
}

class AttrWindow : public QMainWindow
{
    Q_OBJECT

public:
    AttrWindow(QWidget *parent = 0, CMapAttributes* attributes = NULL);

    void updateAttributes();

    ~AttrWindow();

    void addAttribute(CKnAttr* newAttribute);
    void updateAttribute(CKnAttr* attr, CKnAttr *old);
private slots:
    void on_buttonOk_clicked();

    void onItemCreated(CKnAttr* attr);

    void onItemChanged(CKnAttr* old, CKnAttr* value);

    void onImportFile(QString fileName);

    void on_buttonNewAttribute_clicked();

    void on_buttonEditAttribute_clicked();

    void on_listWidgetAttributes_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_buttonDeleteAttribute_clicked();

    void on_buttonCancel_clicked();

    void on_buttonImport_clicked();


signals:
    void attributesChanged(CMapAttributes* data);

private:
    Ui::AttrWindow *ui;

    CMapAttributes* attributes;
};

#endif // ATTRWINDOW_H
