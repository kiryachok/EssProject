#include "productioncontroller.h"



ProductionController::ProductionController(CProduction *prod)
{
    if (prod == NULL)
    {
        prod = new CProduction();
    }
    production = prod;
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

void ProductionController::setFormula(string formula)
{
    production->m_Formula = formula;
}

void ProductionController::setName(string name)
{
    production->m_NameCon = name;
}

void ProductionController::save()
{
    productions->Add(production);
}

void ProductionController::setType(BYTE type)
{
    production->m_Type = type;
}

