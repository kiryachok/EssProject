#ifndef NEWMODDIALOG_H
#define NEWMODDIALOG_H

#include <QDialog>
#include "essview_global.h"

namespace Ui {
class NewModDialog;
}

class ESSVIEWSHARED_EXPORT NewModDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewModDialog(QWidget *parent = 0);
    ~NewModDialog();

private slots:
    void on_closeButton_clicked();

    void on_changeButton_clicked();

private:
    Ui::NewModDialog *ui;
};

#endif // NEWMODDIALOG_H
