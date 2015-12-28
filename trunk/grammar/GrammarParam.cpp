#include <sstream>
#include "GrammarParam.hpp"

void GrammarParam::setName(const std::string& _name)
{
    name = _name;
    dirtyString = true;
}

void GrammarParam::setValue(GrammarParamValue _value)
{
    value = _value;
    dirtyString = true;
}

const std::string& GrammarParam::toString()
{
    if (dirtyString)
    {
        std::stringstream ss;
        ss << getName() << ": ";
        if (type == GPT_STRING)
            ss << *value.valueString << " (STRING)";
        else if (type == GPT_FLOAT)
            ss << value.valueFloat << " (FLOAT)";
        else if (type == GPT_INT)
            ss << value.valueInt << " (INT)";
        toStringStr = ss.str();
        dirtyString = false;
    }
    return toStringStr;
}