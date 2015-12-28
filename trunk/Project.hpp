#pragma once

#include <string>

class Grammar;

class Project
{
private:
	Project();

public:
    static Project* get();

	virtual ~Project();

	bool createGrammar(const std::string& _name);
	Grammar* getGrammar() const;

	bool save(const std::string& _fileName);
	bool load(const std::string& _fileName);

	void reset();

    bool storeActionArgs;
    bool storeActionOutput;

    std::string projectFile;

private:
	//std::vector<Grammar> grammars;
    Grammar* grammar;
    static std::string endOfScriptMarker;
};
