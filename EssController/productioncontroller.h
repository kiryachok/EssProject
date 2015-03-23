#ifndef PRODUCTIONCONTROLLER_H
#define PRODUCTIONCONTROLLER_H

#include "../EssModel/objects.h"
#include "../EssView/productiondialog.h"

class ProductionController : public QObject
{
    Q_OBJECT

public:
    ProductionController(CProduction *prod );

    void addExpresion (char type, QString formula, short value);
    void removeAllExpresions();
    void setFormula (QString formula);
    void setType (short type);
    void setName(QString name);
    void save();
    void initView(ProductionDialog *window);
    string getName() const;
    BYTE getType() const;
    string getFormula() const;

private slots:
    void saveNewProduction(QString name, short type);

private:
    CProduction *production;
    CArrayProduction *productions;
};

#endif // PRODUCTIONCONTROLLER_H
