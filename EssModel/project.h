#ifndef PROJECT_H
#define PROJECT_H
#include "QFile"
#include "QString"
#include "QDataStream"
#include "QSaveFile"
#include "objects.h"
#include "archive.h"

class Project
{
public:
    Project();
    ~Project();
    bool saveFile(char* fileName);
    bool loadFile(char* fileName);
private:
    CMapAttributes m_MapAttributes;
    CMapProgModuls m_MapProgModuls;
    CMapStrategies m_MapStrategies;
    CMapFrames m_MapFrames;
//    CArrayMenuESS m_ArrayMenu;
    QString   m_Repository;


    //---------------------------------------
        int m_ActStrategy;
        int m_ActProd;
    //---------------------------------------
        int m_ActFrame;
        int m_ActSlot;
        QString   m_ActModul;

};

#endif // PROJECT_H
