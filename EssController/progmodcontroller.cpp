#include "progmodcontroller.h"

ProgModController::ProgModController(CProgMod* progMod)
{
    this->progMod = progMod;
}

QString ProgModController::getComment() {
        return QString::fromStdString(progMod->m_Comment);
}

QString ProgModController::getMenuString() {
        return QString::fromStdString(progMod->m_Menu);
}

QString ProgModController::getLaunchConditions() {
        return QString::fromStdString(progMod->m_Prod.CreateCondition());
}

vector<string> ProgModController::getLaunchParams() {
        return progMod->m_ParamNames;
}

vector<string> ProgModController::getAttrKeys() {
        return progMod->m_AttrNames;
}

int ProgModController::getUndoAbility() {
        return progMod->m_Undo;
}

BYTE ProgModController::getModuleType() {
        return progMod->m_Type;
}

//-------------------------------------------------

void ProgModController::setComment(QString comment) {
        progMod->m_Comment = comment.toStdString();
}

void ProgModController::setMenuString(QString menuString) {
        progMod->m_Menu = menuString.toStdString();
}

void ProgModController::setLaunchConditions(QString prod) {
        progMod->m_Prod.m_Formula = prod.toStdString();
}

void ProgModController::setLaunchParams(vector<string> vector) {
        progMod->m_ParamNames = vector;
}

void ProgModController::setAttrKeys(vector<string> vector) {
        progMod->m_AttrNames = vector;
}

void ProgModController::setUndoAbility(int undo) {
        progMod->m_Undo = undo;
}

void ProgModController::setModuleType(BYTE modType) {
        progMod->m_Type = modType;
}

ProgModController::~ProgModController() {

}
