#include "project.h"

Project::Project()
{

}

Project::~Project()
{

}

bool Project::saveFile(char* fileName)
{
    CArch *arh = new CArch(fileName, 1);
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
