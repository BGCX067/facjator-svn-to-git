#pragma once

extern "C"
{
#include <lua.h>
}
#include "Script.hpp"

class LuaScript : public Script
{
public:
	LuaScript();
	virtual ~LuaScript();

	virtual bool execute();

private:
    bool startLua();
    bool shutdownLua();

    lua_State* luaState;
    bool initOk;
};
