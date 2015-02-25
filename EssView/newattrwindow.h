#ifndef NEWATTRWINDOW_H
#define NEWATTRWINDOW_H

#include <QDialog>
#include <../EssModel/objects.h>

namespace Ui {
class NewAttrWindow;
}

class NewAttrWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NewAttrWindow(QWidget *parent = 0, CKnAttr* attr = NULL);
    ~NewAttrWindow();

private slots:
    void on_pushButtonCancel_clicked();

    void on_pushButtonOk_clicked();

signals:
    void itemCreated(CKnAttr* attr);
    void itemChanged(CKnAttr* old, CKnAttr* attr);

private:
    Ui::NewAttrWindow *ui;
    CKnAttr* oldAttr;
};

#endif // NEWATTRWINDOW_H
