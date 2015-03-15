#ifndef PRODUCTIONCONTROLLER_H
#define PRODUCTIONCONTROLLER_H

#include "../EssModel/objects.h"

class ProductionController : public QObject
{
    Q_OBJECT

public:
    ProductionController(CProduction *prod );

    void addExpresion (char type, QString formula, short value);
    void removeAllExpresions();
    void setFormula (string formula);
    void setType (BYTE type);
    void setName(string name);
    void save();

    string getName() const;
    BYTE getType() const;
    string getFormula() const;


private:
    CProduction *production;
    CArrayProduction *productions;
};

#endif // PRODUCTIONCONTROLLER_H
