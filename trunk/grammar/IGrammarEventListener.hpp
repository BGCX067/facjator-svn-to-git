#pragma once

enum GrammarEvent { GRAMMAR_EVALUATED, LOG_ACTION_ADDED };

class IGrammarEventListener
{
public:
	virtual void handle(GrammarEvent _type, void* data) = 0;
};
