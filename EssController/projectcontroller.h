#ifndef PROJECTCONTROLLER_H
#define PROJECTCONTROLLER_H

#include <QObject>
#include <QFileDialog>


#include "../EssModel/project.h"
#include "../EssView/mainwindow.h"
#include "cmapstrategiescontroller.h"
#include "mapattributecontroller.h"

#include "esscontroller_global.h"

class ESSCONTROLLERSHARED_EXPORT Projectcontroller : public QObject
{
    Q_OBJECT

private:
    Project *proj;
    MainWindow *mainWindow;
    QString saveName;

    CMapAttributes m_MapAttributes;
    CMapProgModuls m_MapProgModuls;
  //  CMapStrategies m_MapStrategies;
    CMapFrames m_MapFrames;
    CMapStrategiesController *_mapStrategyController;

    MapAttributeController* _mapAttributeController;

public:
    Projectcontroller(QObject *parent = 0);
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
