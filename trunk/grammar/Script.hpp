#pragma once

#include <string>

class Script
{
public:
	Script();
	virtual ~Script();

	virtual bool execute() = 0;

    const std::string& getSource() const { return source; }
	void setSource(const std::string& source);

protected:
	std::string source;
};
