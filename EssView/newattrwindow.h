#ifndef NEWATTRWINDOW_H
#define NEWATTRWINDOW_H

#include <QDialog>
#include <QMessageBox>

#include "essview_global.h"

namespace Ui {
class NewAttrWindow;
}

class ESSVIEWSHARED_EXPORT NewAttrWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NewAttrWindow(QWidget *parent = 0);
    void initView(QString fullName = QString(), QString shortName = QString(),
                  QString type = QString(), QString value = QString());
    ~NewAttrWindow();

signals:
    void tryDataChange(QString key, QString fullName, QString shortName,
                       QString type, QString value);

public slots:
    void dataChecked(bool valid);


private slots:
    void on_pushButtonCancel_clicked();
    void on_pushButtonOk_clicked();

private:
    Ui::NewAttrWindow *ui;

    QString key;
};

#endif // NEWATTRWINDOW_H
