#ifndef ATTRIBUTECONTROLLER_H
#define ATTRIBUTECONTROLLER_H

#include <QtGlobal>
#include "esscontroller_global.h"
#include "../EssModel/objects.h"

class ESSCONTROLLERSHARED_EXPORT AttributeController : public QObject
{
    Q_OBJECT

public:
    AttributeController(CKnAttr* attr = NULL);

    QString getFullName();

    QString getShortName();

    BYTE getType();

    QString getTypeString();

    QString getValue();

    bool setFullName(QString value);

    bool setShortName(QString value);

    bool setType(QString value);

    bool setValue(QString value);

    bool setDefaultValue();

    void acceptChanges();

    ~AttributeController();

signals:
    void updated(CKnAttr* old, CKnAttr* value);
    void created(CKnAttr* value);

private:
    CKnAttr* attr;
    CKnAttr* old;
};

#endif // ATTRIBUTECONTROLLER_H
