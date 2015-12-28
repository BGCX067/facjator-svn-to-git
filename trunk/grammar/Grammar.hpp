#pragma once

#include <string>
#include <vector>
#include "IGrammarEventListener.hpp"

class IGrammarEventListener;
class Script;
class GrammarOutput;
class GrammarParam;

class Grammar
{
public:
    typedef std::vector<IGrammarEventListener*> EventListeners;
    typedef std::vector<GrammarParam*> GrammarParameters;

    Grammar(const std::string& _name);
	virtual ~Grammar();

    //Przetwarza gramatykê zdefiniowan¹ przez skrypt.
	bool execute();

    GrammarOutput* getOutput() const { return grammarOutput; }
    Script* getScript() const { return script; }

    //Zarz¹dzanie parametrami gramatyki.
	bool addParam(const std::string& _name, float _value);
	bool addParam(const std::string& _name, int _value);
	bool addParam(const std::string& _name, const std::string& _value);
    void removeParam(const std::string& _name);
    void removeAllParams();
    GrammarParam* getParam(const std::string& _name) const;
    bool updateParamName(const std::string& _oldName, const std::string& _newName);
    const GrammarParameters& getParams() const { return grammarParams; }
    void serializeParams(std::ostream& stream) const;
    void deserializeParams(std::istream& stream);

    //Obs³uga zdarzeñ.
	void addEventListener(IGrammarEventListener* _listener);
	void removeEventListener(IGrammarEventListener* _listener);

private:
    void sendEvent(GrammarEvent _event, void* data);

	std::string name;
	EventListeners eventListeners;
    GrammarParameters grammarParams;
    GrammarOutput* grammarOutput;
    Script* script;
};
