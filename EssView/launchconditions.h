#ifndef LAUNCHCONDITIONS_H
#define LAUNCHCONDITIONS_H

#include <QDialog>
#include "essview_global.h"

namespace Ui {
class LaunchConditions;
}

class ESSVIEWSHARED_EXPORT LaunchConditions : public QDialog {
    Q_OBJECT

public:
    explicit LaunchConditions(QWidget *parent = 0);
    ~LaunchConditions();

private:
    Ui::LaunchConditions *ui;
};

#endif // LAUNCHCONDITIONS_H
