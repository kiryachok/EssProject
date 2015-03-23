#include "productioncontroller.h"
#include "../EssView/productiondialog.h"


ProductionController::ProductionController(CProduction *prod)
{
    if (prod == NULL)
    {
        prod = new CProduction();
    }
    production = prod;
    productions = new CArrayProduction();


}

void ProductionController::addExpresion( char type, QString formula, short value)
{
    CExpres *expr = new CExpres();
    expr->m_Formula = formula.toStdString().c_str();
    expr->m_Type = type;
    expr->m_Value = value;
    production->m_ArrayExpression.Add(expr);
}

string ProductionController::getFormula() const
{
    return production->m_Formula;
}

void ProductionController::saveNewProduction(QString name, short type)
{
    production->m_Type = type;
    production->m_NameCon = name.toStdString();
    productions->Add(production);
}

string ProductionController::getName() const
{
    return production->m_NameCon;
}

BYTE ProductionController::getType() const
{
    return production->m_Type;
}

void ProductionController::removeAllExpresions()
{
    production->m_ArrayExpression.RemoveAll();
}

void ProductionController::setFormula(QString formula)
{
    production->m_Formula = formula.toStdString();
}

void ProductionController::setName(QString name)
{
    production->m_NameCon = name.toStdString();
}

void ProductionController::save()
{
    productions->Add(production);
}

void ProductionController::initView(ProductionDialog *window)
{

    connect(window, SIGNAL(importFile(QString)), this, SLOT(saveNewProduction(QString,short)));
}

void ProductionController::setType(short type)
{
    production->m_Type = type;
}

