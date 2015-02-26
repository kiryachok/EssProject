#ifndef MAPATTRIBUTECONTROLLER_H
#define MAPATTRIBUTECONTROLLER_H

#include <QtGlobal>
#include <QFile>
#include <QTextStream>
#include "../EssModel/objects.h"
#include "attributecontroller.h"

class MapAttributeController : public QObject
{
    Q_OBJECT

public:
    MapAttributeController(CMapAttributes* attributes = new CMapAttributes);

    AttributeController* getAttributeController(QString key = QString());

    void acceptChanges();

    void discardChanges();

    void loadFile(QString fileName);

    void refresh();

    ~MapAttributeController();

public slots:

    void add(CKnAttr* value);

    void update(CKnAttr* old, CKnAttr* value);

    void remove(QString key);

signals:

    void attributeCreated(AttributeController*);

    void attributeUpdated(AttributeController*, QString);

    void attributeRemoved(QString);

private:
    CMapAttributes* attributes;

    CMapAttributes* old;
};

#endif // MAPATTRIBUTECONTROLLER_H
