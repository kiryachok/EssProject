#ifndef NEWARITHMETICDIALOG_H
#define NEWARITHMETICDIALOG_H

#include <QDialog>

namespace Ui {
class NewArithmeticDialog;
}

class NewArithmeticDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewArithmeticDialog(QWidget *parent = 0);
    ~NewArithmeticDialog();

private slots:
    void on_backButton_clicked();

private:
    Ui::NewArithmeticDialog *ui;
};

#endif // NEWARITHMETICDIALOG_H
