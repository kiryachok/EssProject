#include "mapprogmodulscontroller.h"

MapProgModulsController::MapProgModulsController(CMapProgModuls* progModuls)
{
    this->progModuls = progModuls;
}

void MapProgModulsController::addProgMod(CProgMod* progMod)
{
    CProgMod* mod;
    if (this->progModuls->Lookup(progMod->m_Name, mod))
    {
        this->progModuls->SetAt(progMod->m_Name, progMod);
    }
    else
    {
        this->progModuls->mpr[progMod->m_Name] = progMod;
    }
}

void MapProgModulsController::updateProgMod(CProgMod* progMod)
{
    CProgMod* mod;
    if (this->progModuls->Lookup(progMod->m_Name, mod))
    {
        this->progModuls->SetAt(progMod->m_Name, progMod);
    }
}

void MapProgModulsController::removeProgModByName(QString key)
{
    this->progModuls->mpr.erase(key.toStdString());
}
