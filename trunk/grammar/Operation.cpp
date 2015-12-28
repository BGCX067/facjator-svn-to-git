#include <sstream>
#include "Operation.hpp"
#include "Grammar.hpp"
#include "GrammarOutput.hpp"
#include "ActionLog.hpp"
#include "GrammarParam.hpp"
#include "terminal.hpp"

Grammar* Operation::grammar = 0;

void Operation::begin(const std::string _name)
{
    if (grammar)
        grammar->getOutput()->beginAction(_name);
}

void Operation::addArgument(const GrammarObject& _arg)
{
    if (grammar)
        grammar->getOutput()->getAction()->addArgument(_arg);
}

void Operation::addOutput(const GrammarObject& _out)
{
    if (grammar)
        grammar->getOutput()->getAction()->addOutput(_out);
}

void Operation::end()
{
    if (grammar)
        grammar->getOutput()->endAction();
}

/*
void logical::op_and(GrammarObject& _first, const GrammarObject& _second)
{
    begin("and");
    addArgument(_first);
    addArgument(_second);
    _first.logicOp(_second, OP_AND);
    addOutput(_first);
    end();
}

void logical::op_or(GrammarObject& _first, const GrammarObject& _second)
{
    begin("or");
    addArgument(_first);
    addArgument(_second);
    _first.logicOp(_second, OP_OR);
    addOutput(_first);
    end();
}

void logical::op_diff(GrammarObject& _first, const GrammarObject& _second)
{
    begin("diff");
    addArgument(_first);
    addArgument(_second);
    _first.logicOp(_second, OP_DIFF);
    addOutput(_first);
    end();
}

void logical::op_xor(GrammarObject& _first, const GrammarObject& _second)
{
    begin("xor");
    addArgument(_first);
    addArgument(_second);
    _first.logicOp(_second, OP_XOR);
    addOutput(_first);
    end();
}
*/

float params::getParamFloat(char* _name)
{
    GrammarParam* param = grammar->getParam(_name);
    if (param && param->getType() == GPT_FLOAT)
    {
        return param->getValue().valueFloat;
    }
    std::stringstream ss;
    ss << "Could not find variable '" << _name << "'";
    throw std::exception(ss.str().c_str());
}

int params::getParamInt(char* _name)
{
    GrammarParam* param = grammar->getParam(_name);
    if (param && param->getType() == GPT_INT)
    {
        return param->getValue().valueInt;
    }
    std::stringstream ss;
    ss << "Could not find variable '" << _name << "'";
    throw std::exception(ss.str().c_str());
}

std::string params::getParamString(char* _name)
{
    GrammarParam* param = grammar->getParam(_name);
    if (param && param->getType() == GPT_STRING)
    {
        return param->getValue().valueString->c_str();
    }
    std::stringstream ss;
    ss << "Could not find variable '" << _name << "'";
    throw std::exception(ss.str().c_str());
}
