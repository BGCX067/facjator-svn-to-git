#include "Project.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Windows.hpp"
#include "ui/ctext.h"
#include "grammar/Script.hpp"
#include "grammar/Grammar.hpp"

std::string Project::endOfScriptMarker = "/*EOS*/";

Project* Project::get()
{
    static Project singleton;
    return &singleton;
}

Project::Project()
{
    grammar = 0;
    storeActionArgs = false;
    storeActionOutput = true;
    createGrammar("Nowa gramatyka");
}

Project::~Project()
{
    if (grammar)
        delete grammar;
}

bool Project::createGrammar(const std::string& _name)
{
    reset();
    grammar = new Grammar(_name);
	return true;
}

Grammar* Project::getGrammar() const
{
    return grammar;
}

bool Project::save(const std::string& _fileName)
{
    if (grammar)
    {
        if (Windows::scriptEditor->isDirty)
        {
            grammar->getScript()->setSource(Windows::scriptEditor->get_text());
            Windows::scriptEditor->isDirty = false;
        }
        std::ofstream file;
        file.open(_fileName.c_str(), std::ios_base::out | std::ios_base::trunc);
        if (file.is_open())
        {
            file << grammar->getScript()->getSource();
            file << std::endl << Project::endOfScriptMarker << std::endl;
            grammar->serializeParams(file);
            file.close();
            return true;
        }
        else
            std::cout << "B³¹d podczas otwierania pliku '" << _fileName << "'";
    }
	return false;
}

bool Project::load(const std::string& _fileName)
{
    std::string line;
    std::stringstream ss;
    std::ifstream file;
    file.open(_fileName.c_str());
    if (file.is_open())
    {
        createGrammar(_fileName);
        int nOfLine = 0;
        //skrypt gramatyki
        while (!file.eof())
        {
            getline(file, line);
            if (line == Project::endOfScriptMarker)
                break;
            else if (nOfLine > 0)
                ss << std::endl;
            ss << line;
            nOfLine++;
        }
        grammar->deserializeParams(file);
        file.close();
        grammar->getScript()->setSource(ss.str());
        if (Windows::scriptEditor)
        {
            Windows::scriptEditor->set_text(grammar->getScript()->getSource());
            Windows::scriptEditor->isDirty = false;
        }
        return true;
    }
    else
        std::cout << "B³¹d podczas otwierania pliku '" << _fileName << "'";
	return false;
}

void Project::reset()
{
    if (grammar)
        delete grammar;
    grammar = 0;
}
