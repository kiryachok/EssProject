#ifndef NEWSTRINGDIALOG_H
#define NEWSTRINGDIALOG_H

#include <QDialog>

namespace Ui {
class NewStringDialog;
}

class NewStringDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewStringDialog(QWidget *parent = 0);
    ~NewStringDialog();

private slots:
    void on_doneButton_clicked();

private:
    Ui::NewStringDialog *ui;
};

#endif // NEWSTRINGDIALOG_H
