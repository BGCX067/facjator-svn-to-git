#pragma once

#include <string>
#include <vector>
#include "terminal.hpp"

class ActionLog
{
public:
    ActionLog(std::string _actionName)
    {
        actionName = _actionName;
    }
    ~ActionLog();

	void addArgument(const GrammarObject& _argument);
	inline const std::vector<GrammarObject*> getArguments() const;

	void addOutput(const GrammarObject& _output);
	inline const std::vector<GrammarObject*> getOutput() const;

    inline const std::string& getName() const;

private:
	std::string actionName;
	//Argumenty operacji.
	std::vector<GrammarObject*> arguments;
    //Rezultat wykonania operacji.
	std::vector<GrammarObject*> output;
};
