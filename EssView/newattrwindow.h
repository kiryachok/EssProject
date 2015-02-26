#ifndef NEWATTRWINDOW_H
#define NEWATTRWINDOW_H

#include <QDialog>
#include <QMessageBox>

#include "essview_global.h"
#include "../EssController/attributecontroller.h"

namespace Ui {
class NewAttrWindow;
}

class ESSVIEWSHARED_EXPORT NewAttrWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NewAttrWindow(AttributeController* controller, QWidget *parent = 0);
    ~NewAttrWindow();

private slots:
    void on_pushButtonCancel_clicked();
    void on_pushButtonOk_clicked();

private:
    Ui::NewAttrWindow *ui;
    AttributeController* ctrl;
};

#endif // NEWATTRWINDOW_H
