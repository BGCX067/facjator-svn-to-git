#pragma once

#include <string>

class Grammar;
class GrammarObject;

class Operation {
public:
	//Aktualnie przeliczana gramatyka
	static Grammar* grammar;

protected:
    static void begin(const std::string _name);
    static void addArgument(const GrammarObject& _arg);
    static void addOutput(const GrammarObject& _out);
    static void end();
};

/*
class logical: public Operation {
public:
    static GrammarObject op_and(GrammarObject& _first, const GrammarObject& _second);
    static GrammarObject op_or(GrammarObject& _first, const GrammarObject& _second);
    static GrammarObject op_diff(GrammarObject& _first, const GrammarObject& _second);
    static GrammarObject op_xor(GrammarObject& _first, const GrammarObject& _second);
};
*/

class params: public Operation { // tolua_export
public:
    //tolua_begin
    static float getParamFloat(char* _name);
    static int getParamInt(char* _name);
    static std::string getParamString(char* _name);
};
// tolua_end
