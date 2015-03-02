#include "attributecontroller.h"

AttributeController::AttributeController(CKnAttr* attr)
{
    this->attr = new CKnAttr();
    this->old = attr;
    if (old != NULL) {
        *this->attr = *attr;
    }
}

QString AttributeController::getFullName() {
    return QString(attr->m_FullName.c_str());
}

QString AttributeController::getShortName() {
    return QString(attr->m_ShortName.c_str());
}

BYTE AttributeController::getType() {
    return attr->m_Type;
}

QString AttributeController::getTypeString() {
    return attr->getTypeString().c_str();
}

QString AttributeController::getValue() {
    return QString(attr->getValueAsText().c_str());
}

bool AttributeController::setFullName(QString value) {
    return attr->setFullName(value.toStdString());
}

bool AttributeController::setShortName(QString value) {
    return attr->setShortName(value.toStdString());
}

bool AttributeController::setType(QString value) {
    return attr->setType(value.toStdString());
}

bool AttributeController::setValue(QString value) {
    return attr->setValue(value.toStdString());
}

bool AttributeController::setDefaultValue() {
    attr->setDefaultValue();
    return true;
}

void AttributeController::acceptChanges() {
    if (old == NULL) {
        emit created(attr);
    } else {
        emit updated(old, attr);
    }
}

AttributeController::~AttributeController()
{

}

