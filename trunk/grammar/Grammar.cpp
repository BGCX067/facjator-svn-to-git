#include <algorithm>
#include <sstream>
#include "Grammar.hpp"
#include "GrammarParam.hpp"
#include "GrammarOutput.hpp"
#include "LuaScript.hpp"
#include "Operation.hpp"

Grammar::Grammar(const std::string& _name)
{
    name = _name;
    grammarOutput = 0;
    script = new LuaScript();
}

Grammar::~Grammar()
{
    if (script)
        delete script;
    script = 0;
    if (grammarOutput)
        delete grammarOutput;
    grammarOutput = 0;
}

bool Grammar::execute()
{
    Operation::grammar = this;
    if (grammarOutput)
        delete grammarOutput;
    grammarOutput = new GrammarOutput();
	return script->execute();
}

bool Grammar::addParam(const std::string& _name, float _value)
{
	if (getParam(_name) != 0 || _name.length() == 0)
        return false;
    GrammarParamValue pvalue;
    pvalue.valueFloat = _value;
    GrammarParam* param = new GrammarParam(_name, GPT_FLOAT, pvalue);
    grammarParams.push_back(param);
    return true;
}

bool Grammar::addParam(const std::string& _name, int _value)
{
	if (getParam(_name) != 0 || _name.length() == 0)
        return false;
    GrammarParamValue pvalue;
    pvalue.valueInt = _value;
    GrammarParam* param = new GrammarParam(_name, GPT_INT, pvalue);
    grammarParams.push_back(param);
    return true;
}

bool Grammar::addParam(const std::string& _name, const std::string& _value)
{
	if (getParam(_name) != 0 || _name.length() == 0)
        return false;
    GrammarParamValue pvalue;
    pvalue.valueString = new std::string(_value);
    GrammarParam* param = new GrammarParam(_name, GPT_STRING, pvalue);
    grammarParams.push_back(param);
    return true;
}

void Grammar::removeParam(const std::string& _name)
{
    for (GrammarParameters::iterator it = grammarParams.begin();
        it != grammarParams.end(); it++)
    {
        if ((*it)->getName() == _name)
        {
            delete *it;
            grammarParams.erase(it);
            return;
        }
    }
}

void Grammar::removeAllParams()
{
    for (GrammarParameters::iterator it = grammarParams.begin();
        it != grammarParams.end(); it++)
    {
        delete *it;
    }
    grammarParams.clear();
}

GrammarParam* Grammar::getParam(const std::string& _name) const
{
    for (GrammarParameters::const_iterator it = grammarParams.begin();
        it != grammarParams.end(); it++)
    {
        if ((*it)->getName() == _name)
            return *it;
    }
    return 0;
}

bool Grammar::updateParamName(const std::string& _oldName, const std::string& _newName)
{
    if (_oldName == _newName)
        return true;
    GrammarParam* param = 0;
    if (getParam(_newName) != 0 || (param = getParam(_oldName)) == 0)
        return false;
    param->setName(_newName);
    return true;
}

void Grammar::serializeParams(std::ostream& stream) const
{
    for (GrammarParameters::const_iterator it = grammarParams.begin();
        it != grammarParams.end(); it++)
    {
        stream << (*it)->getName() << ";";
        stream << (int)(*it)->getType() << ";";
        if ((*it)->getType() == GPT_STRING)
            stream << (*it)->getValue().valueString;
        else if ((*it)->getType() == GPT_FLOAT)
            stream << (*it)->getValue().valueFloat;
        else// if ((*it)->getType() == GPT_INT)
            stream << (*it)->getValue().valueInt;
        stream << std::endl;
    }
}

void Grammar::deserializeParams(std::istream& stream)
{
    std::string line;
    while (!stream.eof())
    {
        getline(stream, line);
        if (line.length() == 0)
            continue;
        std::string::size_type id1, id2;
        id1 = line.find(";");
        if (id1 == std::string::npos)
            continue;
        id2 = line.find(";", id1+1);
        if (id2 == std::string::npos)
            continue;

        std::string name = line.substr(0, id1);
        std::string type = line.substr(id1+1, id2-id1-1);
        std::string value = line.substr(id2+1);
        if (type == "0")
        {
            addParam(name, value);
        }
        else if (type == "1")
        {
            addParam(name, atoi(value.c_str()));
        }
        else if (type == "2")
        {
            addParam(name, (float)atof(value.c_str()));
        }
        else
        {
            std::cout << "import warning: unknown type of parameter '" << name << "', skipping\n";
            continue;
        }
    }
}

void Grammar::addEventListener(IGrammarEventListener* _listener)
{
    EventListeners::iterator it = std::find(eventListeners.begin(),
        eventListeners.end(), _listener);
    if (it == eventListeners.end())
        eventListeners.push_back(_listener);
}

void Grammar::removeEventListener(IGrammarEventListener* _listener)
{
    EventListeners::iterator it = std::find(eventListeners.begin(),
        eventListeners.end(), _listener);
    if (it != eventListeners.end())
        eventListeners.erase(it);
}

void Grammar::sendEvent(GrammarEvent _event, void* data)
{
    for (EventListeners::iterator it = eventListeners.begin();
        it != eventListeners.end(); it++)
        (*it)->handle(_event, data);
}
