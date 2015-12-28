#include "ActionLog.hpp"
#include "../Project.hpp"

ActionLog::~ActionLog()
{
    std::vector<GrammarObject*>::iterator it;
    for (it = arguments.begin(); it != arguments.end(); it++)
        delete (*it);
    arguments.clear();
    for (it = output.begin(); it != output.end(); it++)
        delete (*it);
    output.clear();
}

void ActionLog::addArgument(const GrammarObject& _argument)
{
    if (Project::get()->storeActionArgs)
    {
//        GrammarObject* tmp = new GrammarObject(_argument);
//        if (tmp != 0)
//            arguments.push_back(tmp);
    }
}

const std::vector<GrammarObject*> ActionLog::getArguments() const
{
    return arguments;
}

void ActionLog::addOutput(const GrammarObject& _output)
{
    if (Project::get()->storeActionOutput)
    {
//        GrammarObject* tmp = new GrammarObject(_output);
//        if (tmp != 0)
//            output.push_back(tmp);
    }
}

const std::vector<GrammarObject*> ActionLog::getOutput() const
{
    return output;
}

const std::string& ActionLog::getName() const
{
    return actionName;
}
