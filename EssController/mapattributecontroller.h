#ifndef MAPATTRIBUTECONTROLLER_H
#define MAPATTRIBUTECONTROLLER_H

#include <QtGlobal>
#include <QFile>
#include <QTextStream>
#include "../EssModel/objects.h"
#include "esscontroller_global.h"
#include "attributecontroller.h"
#include "../EssView/mainwindow.h"

class ESSCONTROLLERSHARED_EXPORT MapAttributeController : public QObject
{
    Q_OBJECT

public:
    MapAttributeController(CMapAttributes* attributes = new CMapAttributes);

    AttributeController* getAttributeController(QString key = QString());

    void refresh();

    void InitView(MainWindow* window);

    ~MapAttributeController();

private slots:

    void acceptChanges();

    void discardChanges();

    void add(CKnAttr* value);

    void update(CKnAttr* old, CKnAttr* value);

    void remove(QString key);

    void setAttributesWindow(AttrWindow* window);

    void loadFile(QString fileName);

    void saveFile(QString fileName);

    void setCurrentItem(QString key);

    void tryDataChange(QString key, QString fullName, QString shortName,
                       QString type, QString value);
signals:

    void attributeCreated(AttributeController*);

    void attributeUpdated(AttributeController*, QString);

    void attributeRemoved(QString);

private:
    CMapAttributes* attributes;

    CMapAttributes* old;

    AttrWindow* window;
};

#endif // MAPATTRIBUTECONTROLLER_H
