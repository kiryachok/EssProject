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

signals:
    void newProgModSubmitted();

private slots:
    void on_changeButton_clicked();
    void on_exitButton_clicked();

    void on_okButton_clicked();

private:
    Ui::NewModDialog *ui;
};

#endif // NEWMODDIALOG_H
