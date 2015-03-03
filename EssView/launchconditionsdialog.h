#ifndef LAUNCHCONDITIONSDIALOG_H
#define LAUNCHCONDITIONSDIALOG_H

#include <QDialog>
#include "essview_global.h"

namespace Ui {
class LaunchConditionsDialog;
}

class ESSVIEWSHARED_EXPORT LaunchConditionsDialog : public QDialog {
    Q_OBJECT

public:
    explicit LaunchConditionsDialog(QWidget *parent = 0);
    ~LaunchConditionsDialog();

private slots:
    void on_newLogicButton_clicked();

private:
    Ui::LaunchConditionsDialog *ui;
};

#endif // LAUNCHCONDITIONSDIALOG_H
