#ifndef MAPPROGMODULSCONTROLLER_H
#define MAPPROGMODULSCONTROLLER_H

#include <QObject>
#include <QtGlobal>
#include "esscontroller_global.h"
#include "../EssModel/objects.h"

class ESSCONTROLLERSHARED_EXPORT MapProgModulsController : public QObject
{
    Q_OBJECT
public:
    explicit MapProgModulsController(CMapProgModuls* progModuls = new CMapProgModuls);

signals:

public slots:
    void addProgMod(CProgMod* progMod);
    void updateProgMod(CProgMod* progMod);
    void removeProgModByName(QString key);

private:
    CMapProgModuls* progModuls;
};

#endif // MAPPROGMODULSCONTROLLER_H
