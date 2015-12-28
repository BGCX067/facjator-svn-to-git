#pragma once

#include "ActionLog.hpp"

class GrammarOutput
{
public:
	GrammarOutput();
	virtual ~GrammarOutput();

	void beginAction(const std::string& name);
	bool endAction();
	ActionLog* getAction();

private:
	GrammarObject* finalTerminal;
	//Lista akcji zarejestrowanych podczas ewaluacji gramatyki.
	std::list<ActionLog*> actions;

};
