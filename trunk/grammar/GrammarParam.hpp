#pragma once

#include <string>

//Typ wartosci przechowywanej w parametrze.
enum GrammarParamType { GPT_STRING = 0, GPT_INT = 1, GPT_FLOAT = 2 };

//Warto�� parametru
union GrammarParamValue
{
	std::string* valueString;
	int valueInt;
	float valueFloat;
};

//Parametr gramatyki, kt�rego warto�� mo�e zmieni� u�ytkownik.
//Ka�dy parametr posiada nazw�, typ przechowywanej warto�ci oraz warto��.
class GrammarParam
{
public:
    GrammarParam(const std::string& _name, GrammarParamType _type, GrammarParamValue _value)
    {
        name = _name;
        type = _type;
        value = _value;
        dirtyString = true;
    }

    const std::string& getName() const { return name; }
    void setName(const std::string& _name);

    GrammarParamType getType() const { return type; }

    const GrammarParamValue& getValue() const { return value; }
    void setValue(GrammarParamValue _value);

    const std::string& toString();

private:
    std::string name;
	GrammarParamType type;
    GrammarParamValue value;
    bool dirtyString;
    std::string toStringStr;
};
