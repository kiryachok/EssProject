#ifndef CHANGEMODDIALOG_H
#define CHANGEMODDIALOG_H

#include <QDialog>
#include "essview_global.h"

namespace Ui {
class ChangeModDialog;
}

class ESSVIEWSHARED_EXPORT ChangeModDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeModDialog(QWidget *parent = 0);
    ~ChangeModDialog();

signals:
    void changedProgModSubmitted();

private slots:
    void on_closeButton_clicked();

    void on_okButton_clicked();

private:
    Ui::ChangeModDialog *ui;
};

#endif // CHANGEMODDIALOG_H
