#include "mapattributecontroller.h"

MapAttributeController::MapAttributeController(CMapAttributes* attributes)
{
    this->old = attributes;
    this->attributes = this->old->copy();
}

void MapAttributeController::add(CKnAttr *value) {
    attributes->add(value);
    emit attributeCreated(new AttributeController(value));
}

void MapAttributeController::remove(QString key) {
    attributes->removeAt(key.toStdString());
    emit attributeRemoved(key);
}

void MapAttributeController::update(CKnAttr *old, CKnAttr *value) {
    attributes->update(old, value);
    AttributeController controller(old);
    emit attributeUpdated(new AttributeController(value), controller.getFullName());
}

AttributeController* MapAttributeController::getAttributeController(QString key) {
    AttributeController* ctrl;
    CKnAttr* value = NULL;
    string k = key.toStdString();
    attributes->Lookup(k, value);
    if (value == NULL) {
        ctrl = new AttributeController();
        connect(ctrl, SIGNAL(created(CKnAttr*)), this, SLOT(add(CKnAttr*)));
    } else {
        ctrl = new AttributeController(value);
        connect(ctrl, SIGNAL(updated(CKnAttr*,CKnAttr*)), this, SLOT(update(CKnAttr*,CKnAttr*)));
    }
    return ctrl;
}

void MapAttributeController::acceptChanges() {
    delete old;
    old = attributes->copy();
}

void MapAttributeController::discardChanges() {
    delete attributes;
    attributes = old->copy();
}

void MapAttributeController::loadFile(QString fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        return;
    }
    attributes->RemoveAll();
    QTextStream in(&file);
    while (!in.atEnd()) {
        AttributeController* ctrl = getAttributeController();
        QString shortName;
        QString type;
        QString fullName;
        in >> shortName >> type;
        in.skipWhiteSpace();
        fullName = in.readLine().simplified();
        type = type.mid(1, type.length() - 2); //remove parentheses
        if (ctrl->setFullName(fullName) && ctrl->setShortName(shortName) &&
                ctrl->setType(type) && ctrl->setDefaultValue()) {
            ctrl->acceptChanges();
        } else {
            break;
        }
    }
    file.close();
}

void MapAttributeController::saveFile(QString fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        return;
    }
    QTextStream in(&file);
    string key;
    CKnAttr* attr = NULL;
    attributes->begin();
    while (attributes->hasNext()) {
        attributes->GetNextAssoc(key, attr);
        AttributeController* controller = getAttributeController(key.c_str());
        in << controller->getShortName()
           << " (" << controller->getTypeString() << ")\n"
           << controller->getFullName() << "\n\n";
    }
    file.close();
}

void MapAttributeController::refresh() {
    string key;
    CKnAttr* value = NULL;
    attributes->begin();
    while (attributes->hasNext()) {
        attributes->GetNextAssoc(key, value);
        emit this->attributeCreated(new AttributeController(value));
    }
}

MapAttributeController::~MapAttributeController()
{

}

