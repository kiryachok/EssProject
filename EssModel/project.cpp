#include "project.h"

Project::Project()
{
    m_MapAttributes = CMapAttributes();
    m_MapFrames = CMapFrames();
    m_MapProgModuls = CMapProgModuls();
    m_MapStrategies = CMapStrategies();
}

Project::~Project()
{

}

bool Project::saveFile(char* fileName)
{
    CArch *arh = new CArch(fileName, 0);

    CKnAttr* pKnAttr= new CKnAttr();
    m_MapAttributes.add(pKnAttr);
    m_MapAttributes.Serialize(*arh);
    m_MapFrames.Serialize(*arh);
    m_MapProgModuls.Serialize(*arh);
    m_MapStrategies.Serialize(*arh);

    return true;
}

bool Project::loadFile(char *fileName)
{
    CArch *arh = new CArch(fileName, 1);
    m_MapAttributes.Serialize(*arh);
    m_MapFrames.Serialize(*arh);
    m_MapProgModuls.Serialize(*arh);
    m_MapStrategies.Serialize(*arh);

    return true;
}
