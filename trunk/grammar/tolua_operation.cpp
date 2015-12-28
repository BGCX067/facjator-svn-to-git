/*
** Lua binding: Operation
** Generated automatically by tolua++-1.0.92 on 03/12/11 17:42:22.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Operation_open (lua_State* tolua_S);

#include "Operation.hpp"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Operation");
 tolua_usertype(tolua_S,"params");
}

/* method: getParamFloat of class  params */
#ifndef TOLUA_DISABLE_tolua_Operation_params_getParamFloat00
static int tolua_Operation_params_getParamFloat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"params",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* _name = ((char*)  tolua_tostring(tolua_S,2,0));
  {
   float tolua_ret = (float)  params::getParamFloat(_name);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getParamFloat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getParamInt of class  params */
#ifndef TOLUA_DISABLE_tolua_Operation_params_getParamInt00
static int tolua_Operation_params_getParamInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"params",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* _name = ((char*)  tolua_tostring(tolua_S,2,0));
  {
   int tolua_ret = (int)  params::getParamInt(_name);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getParamInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getParamString of class  params */
#ifndef TOLUA_DISABLE_tolua_Operation_params_getParamString00
static int tolua_Operation_params_getParamString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"params",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* _name = ((char*)  tolua_tostring(tolua_S,2,0));
  {
   std::string tolua_ret = (std::string)  params::getParamString(_name);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getParamString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Operation_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"params","params","Operation",NULL);
  tolua_beginmodule(tolua_S,"params");
   tolua_function(tolua_S,"getParamFloat",tolua_Operation_params_getParamFloat00);
   tolua_function(tolua_S,"getParamInt",tolua_Operation_params_getParamInt00);
   tolua_function(tolua_S,"getParamString",tolua_Operation_params_getParamString00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Operation (lua_State* tolua_S) {
 return tolua_Operation_open(tolua_S);
};
#endif

