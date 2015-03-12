#ifndef ADDNEWSTRATEGYDIALOG_H
#define ADDNEWSTRATEGYDIALOG_H

#include <QDialog>

namespace Ui {
class AddNewStrategyDialog;
}

class AddNewStrategyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewStrategyDialog(QWidget *parent = 0);
    ~AddNewStrategyDialog();

    QString getStrategyName();
    QString getStrategyComment();

private:
    Ui::AddNewStrategyDialog *ui;
};

#endif // ADDNEWSTRATEGYDIALOG_H
