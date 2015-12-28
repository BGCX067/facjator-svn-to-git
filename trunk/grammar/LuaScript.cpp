#include <iostream>
extern "C"
{
#include <lualib.h>
#include <tolua++.h>
}
#include "../math/tolua_vector.hpp"
#include "tolua_terminal.hpp"
#include "tolua_operation.hpp"
#include "LuaScript.hpp"

LuaScript::LuaScript()
{
    startLua();
}

LuaScript::~LuaScript()
{
    shutdownLua();
}

bool LuaScript::execute()
{
    if (!initOk)
        return false;

    int status = luaL_dostring(luaState, source.c_str());
    std::string s;
    if (status)
    {
        s = lua_tostring(luaState, -1);
        std::cout << s << std::endl;
    }

    return status == 0;
}

bool LuaScript::startLua()
{
    luaState = lua_open();
    tolua_open(luaState);

    luaL_openlibs(luaState);
    tolua_vector_open(luaState);
    tolua_terminal_open(luaState);
    tolua_Operation_open(luaState);

    initOk = true;
    return true;
}

bool LuaScript::shutdownLua()
{
    if (initOk)
        lua_close(luaState);
    initOk = false;
    return true;
}
