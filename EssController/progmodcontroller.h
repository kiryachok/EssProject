#ifndef PROGMODCONTROLLER_H
#define PROGMODCONTROLLER_H

#include <QObject>
#include <QtGlobal>
#include "esscontroller_global.h"
#include "../EssModel/objects.h"

class ESSCONTROLLERSHARED_EXPORT ProgModController : public QObject
{
    Q_OBJECT
public:
    explicit ProgModController(CProgMod* progMod = 0);

    QString getComment();

    QString getMenuString();

    QString getLaunchConditions();

    vector<string> getLaunchParams();

    vector<string> getAttrKeys();

    int getUndoAbility();

    BYTE getModuleType();

//--------------------------
    void setComment(QString comment);

    void setMenuString(QString menuString);

    void setLaunchConditions(QString prod);

    void setLaunchParams(vector<string> vector);

    void setAttrKeys(vector<string> vector);

    void setUndoAbility(int undo);

    void setModuleType(BYTE modType);

    ~ProgModController();

signals:

public slots:

private:
    CProgMod* progMod;
};

#endif // PROGMODCONTROLLER_H
