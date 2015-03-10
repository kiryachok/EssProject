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

    proj->loadFile(fileName.toLocal8Bit().data());
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

    proj->saveFile(saveName.toLocal8Bit().data());
}

void Projectcontroller::handleSaveAs()
{
    QString caption = "Open file";
    QString dir = "";
    QString filter = "*.bk4";
    QString fileName = QFileDialog::getSaveFileName(0, caption, dir, filter);
    saveName = fileName;

    proj->saveFile(saveName.toLocal8Bit().data());
}

void Projectcontroller::handleNew()
{

}
