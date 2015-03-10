#ifndef PROJECTCONTROLLER_H
#define PROJECTCONTROLLER_H

#include <QObject>
#include <QFileDialog>


#include "../EssModel/project.h"
#include "../EssView/mainwindow.h"

#include "esscontroller_global.h"

class ESSCONTROLLERSHARED_EXPORT Projectcontroller : public QObject
{
    Q_OBJECT

private:
    Project *proj;
    MainWindow *mainWindow;
    QString saveName;
public:
    Projectcontroller();
    ~Projectcontroller();

    void initView(MainWindow *window);
    bool saveFile(char* fileName);
    bool loadFile(char* fileName);

private slots:
    void handleOpen();
    void handleSave();
    void handleSaveAs();
    void handleNew();
};

#endif // PROJECTCONTROLLER_H
