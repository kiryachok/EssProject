#ifndef NEWLOGICALDIALOG_H
#define NEWLOGICALDIALOG_H

#include <QDialog>

namespace Ui {
class NewLogicalDialog;
}

class NewLogicalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewLogicalDialog(QWidget *parent = 0);
    ~NewLogicalDialog();

private:
    Ui::NewLogicalDialog *ui;
};

#endif // NEWLOGICALDIALOG_H
