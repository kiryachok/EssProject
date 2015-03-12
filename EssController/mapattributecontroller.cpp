#include "mapattributecontroller.h"

MapAttributeController::MapAttributeController(CMapAttributes* attributes)
{
    this->old = attributes;
    this->attributes = this->old->copy();
}

void MapAttributeController::InitView(MainWindow *window) {
    connect(window, SIGNAL(actionAttributes(AttrWindow*)), this, SLOT(setAttributesWindow(AttrWindow*)));
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
            window->AddAttribute(ctrl->getFullName(), ctrl->getShortName(),
                                 ctrl->getTypeString(), ctrl->getValue());
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
        AttributeController* ctrl =  new AttributeController(value);
        window->AddAttribute(ctrl->getFullName(), ctrl->getShortName(),
                             ctrl->getTypeString(), ctrl->getValue());
    }
}

void MapAttributeController::setAttributesWindow(AttrWindow *window) {
    this->window = window;
    refresh();
    connect(window, SIGNAL(importFile(QString)), this, SLOT(loadFile(QString)));
    connect(window, SIGNAL(exportFile(QString)), this, SLOT(saveFile(QString)));
    connect(window, SIGNAL(accepted()), this, SLOT(acceptChanges()));
    connect(window, SIGNAL(rejected()), this, SLOT(discardChanges()));
    connect(window, SIGNAL(currentItemChanged(QString)), this, SLOT(setCurrentItem(QString)));
    connect(window, SIGNAL(remove(QString)), this, SLOT(remove(QString)));
    connect(window, SIGNAL(tryDataChange(QString,QString,QString,QString,QString)),
            this, SLOT(tryDataChange(QString,QString,QString,QString,QString)));
    connect(window, SIGNAL(remove(QString)), this, SLOT(remove(QString)));
}

void MapAttributeController::setCurrentItem(QString key) {
    AttributeController* ctrl = getAttributeController(key);
    window->setCurrentItem(ctrl->getFullName(), ctrl->getShortName(),
                           ctrl->getTypeString(), ctrl->getValue());
}

void MapAttributeController::tryDataChange(QString key, QString fullName, QString shortName,
                                           QString type, QString value) {
    AttributeController* ctrl = getAttributeController(key);
    bool valid = ctrl->setFullName(fullName) && ctrl->setShortName(shortName) &&
                 ctrl->setType(type) && ctrl->setValue(value);
    if (valid) {
        ctrl->acceptChanges();
    }
    window->dataChecked(key, fullName, shortName, type, value, valid);
}

MapAttributeController::~MapAttributeController()
{

}

