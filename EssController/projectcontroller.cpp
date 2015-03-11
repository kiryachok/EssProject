#include "projectcontroller.h"


Projectcontroller::Projectcontroller(QObject *parent)
    : QObject(parent)
{
    proj = new Project();

    this->_mapStrategyController = new CMapStrategiesController(this);
}

Projectcontroller::~Projectcontroller()
{

}

bool Projectcontroller::loadFile(char *fileName)
{
    return proj->loadFile(fileName);
}

bool Projectcontroller::saveFile(char *fileName)
{
    return proj->saveFile(fileName);
}

void Projectcontroller::initView(MainWindow *window)
{
    mainWindow = window;
    
    if (NULL != mainWindow) {
        connect(mainWindow, SIGNAL(openFile()), this, SLOT(handleOpen()));
        connect(mainWindow, SIGNAL(saveFile()), this, SLOT(handleSave()));
        connect(mainWindow, SIGNAL(saveFileAs()), this, SLOT(handleSaveAs()));
        connect(mainWindow, SIGNAL(newFile()), this, SLOT(handleNew()));
    }
}

//void Projectcontroller::handleAtata()
//{
//    proj->loadFile(fileName);
//}

void Projectcontroller::handleOpen()
{
    QString caption = "Open file";
    QString dir = "";
    QString filter = "*.bk4";
    QString fileName = QFileDialog::getOpenFileName(0, caption, dir, filter);


    CArch *arh = new CArch(saveName.toLocal8Bit().data(), 0);

    m_MapAttributes.Serialize(*arh);
    m_MapFrames.Serialize(*arh);
    m_MapProgModuls.Serialize(*arh);
    _mapStrategyController->Serialize(*arh);
}

void Projectcontroller::handleSave()
{

    if(saveName.isEmpty())
    {
        QString caption = "Open file";
        QString dir = "";
        QString filter = "*.bk4";
        QString fileName = QFileDialog::getSaveFileName(0, caption, dir, filter);
        fileName.append(".bk4");
        saveName = fileName;
    }

    CArch *arh = new CArch(saveName.toLocal8Bit().data(), 0);


    m_MapAttributes.Serialize(*arh);
    m_MapFrames.Serialize(*arh);
    m_MapProgModuls.Serialize(*arh);
    _mapStrategyController->Serialize(*arh);

}

void Projectcontroller::handleSaveAs()
{
    QString caption = "Open file";
    QString dir = "";
    QString filter = "*.bk4";
    QString fileName = QFileDialog::getSaveFileName(0, caption, dir, filter);
    saveName = fileName;

    CArch *arh = new CArch(saveName.toLocal8Bit().data(), 0);


    m_MapAttributes.Serialize(*arh);
    m_MapFrames.Serialize(*arh);
    m_MapProgModuls.Serialize(*arh);
    _mapStrategyController->Serialize(*arh);
}

void Projectcontroller::handleNew()
{

}
