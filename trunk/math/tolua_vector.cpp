/*
** Lua binding: vector
** Generated automatically by tolua++-1.0.92 on Thu May 20 19:34:29 2010.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_vector_open (lua_State* tolua_S);

#include "vector.hpp"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_vector3 (lua_State* tolua_S)
{
 vector3* self = (vector3*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"vector3");
}

/* function: normalized */
#ifndef TOLUA_DISABLE_tolua_vector_normalized00
static int tolua_vector_normalized00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vector3* a = ((const vector3*)  tolua_tousertype(tolua_S,1,0));
  {
   vector3 tolua_ret = (vector3)  normalized(*a);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normalized'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: length */
#ifndef TOLUA_DISABLE_tolua_vector_length00
static int tolua_vector_length00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vector3* v = ((const vector3*)  tolua_tousertype(tolua_S,1,0));
  {
   float tolua_ret = (float)  length(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'length'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: abs */
#ifndef TOLUA_DISABLE_tolua_vector_abs00
static int tolua_vector_abs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vector3* v = ((const vector3*)  tolua_tousertype(tolua_S,1,0));
  {
   vector3 tolua_ret = (vector3)  abs(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'abs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: dot_product */
#ifndef TOLUA_DISABLE_tolua_vector_dot_product00
static int tolua_vector_dot_product00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vector3* a = ((const vector3*)  tolua_tousertype(tolua_S,1,0));
  const vector3* b = ((const vector3*)  tolua_tousertype(tolua_S,2,0));
  {
   float tolua_ret = (float)  dot_product(*a,*b);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dot_product'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: swap */
#ifndef TOLUA_DISABLE_tolua_vector_swap00
static int tolua_vector_swap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  vector3* a = ((vector3*)  tolua_tousertype(tolua_S,1,0));
  vector3* b = ((vector3*)  tolua_tousertype(tolua_S,2,0));
  {
   swap(*a,*b);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'swap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: cross_product */
#ifndef TOLUA_DISABLE_tolua_vector_cross_product00
static int tolua_vector_cross_product00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vector3* a = ((const vector3*)  tolua_tousertype(tolua_S,1,0));
  const vector3* b = ((const vector3*)  tolua_tousertype(tolua_S,2,0));
  {
   vector3 tolua_ret = (vector3)  cross_product(*a,*b);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cross_product'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: triple_product */
#ifndef TOLUA_DISABLE_tolua_vector_triple_product00
static int tolua_vector_triple_product00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vector3* u = ((const vector3*)  tolua_tousertype(tolua_S,1,0));
  const vector3* v = ((const vector3*)  tolua_tousertype(tolua_S,2,0));
  const vector3* w = ((const vector3*)  tolua_tousertype(tolua_S,3,0));
  {
   float tolua_ret = (float)  triple_product(*u,*v,*w);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'triple_product'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: nearly_equals */
#ifndef TOLUA_DISABLE_tolua_vector_nearly_equals00
static int tolua_vector_nearly_equals00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vector3* a = ((const vector3*)  tolua_tousertype(tolua_S,1,0));
  const vector3* b = ((const vector3*)  tolua_tousertype(tolua_S,2,0));
  float r = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  nearly_equals(*a,*b,r);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'nearly_equals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: reflection */
#ifndef TOLUA_DISABLE_tolua_vector_reflection00
static int tolua_vector_reflection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vector3* a = ((const vector3*)  tolua_tousertype(tolua_S,1,0));
  vector3* b = ((vector3*)  tolua_tousertype(tolua_S,2,0));
  {
   vector3 tolua_ret = (vector3)  reflection(*a,*b);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reflection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: max */
#ifndef TOLUA_DISABLE_tolua_vector_max00
static int tolua_vector_max00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vector3* a = ((const vector3*)  tolua_tousertype(tolua_S,1,0));
  {
   float tolua_ret = (float)  max(*a);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'max'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: max_idx */
#ifndef TOLUA_DISABLE_tolua_vector_max_idx00
static int tolua_vector_max_idx00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vector3* a = ((const vector3*)  tolua_tousertype(tolua_S,1,0));
  {
   unsigned int tolua_ret = (unsigned int)  max_idx(*a);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'max_idx'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: min */
#ifndef TOLUA_DISABLE_tolua_vector_min00
static int tolua_vector_min00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vector3* a = ((const vector3*)  tolua_tousertype(tolua_S,1,0));
  {
   float tolua_ret = (float)  min(*a);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'min'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: min_idx */
#ifndef TOLUA_DISABLE_tolua_vector_min_idx00
static int tolua_vector_min_idx00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vector3* a = ((const vector3*)  tolua_tousertype(tolua_S,1,0));
  {
   unsigned int tolua_ret = (unsigned int)  min_idx(*a);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'min_idx'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: abs_max */
#ifndef TOLUA_DISABLE_tolua_vector_abs_max00
static int tolua_vector_abs_max00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vector3* a = ((const vector3*)  tolua_tousertype(tolua_S,1,0));
  {
   float tolua_ret = (float)  abs_max(*a);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'abs_max'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: abs_max_idx */
#ifndef TOLUA_DISABLE_tolua_vector_abs_max_idx00
static int tolua_vector_abs_max_idx00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vector3* a = ((const vector3*)  tolua_tousertype(tolua_S,1,0));
  {
   unsigned int tolua_ret = (unsigned int)  abs_max_idx(*a);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'abs_max_idx'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: abs_min */
#ifndef TOLUA_DISABLE_tolua_vector_abs_min00
static int tolua_vector_abs_min00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vector3* a = ((const vector3*)  tolua_tousertype(tolua_S,1,0));
  {
   float tolua_ret = (float)  abs_min(*a);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'abs_min'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: abs_min_idx */
#ifndef TOLUA_DISABLE_tolua_vector_abs_min_idx00
static int tolua_vector_abs_min_idx00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vector3* a = ((const vector3*)  tolua_tousertype(tolua_S,1,0));
  {
   unsigned int tolua_ret = (unsigned int)  abs_min_idx(*a);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'abs_min_idx'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  vector3 */
#ifndef TOLUA_DISABLE_tolua_vector_vector3_new00
static int tolua_vector_vector3_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   vector3* tolua_ret = (vector3*)  Mtolua_new((vector3)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"vector3");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  vector3 */
#ifndef TOLUA_DISABLE_tolua_vector_vector3_new00_local
static int tolua_vector_vector3_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   vector3* tolua_ret = (vector3*)  Mtolua_new((vector3)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  vector3 */
#ifndef TOLUA_DISABLE_tolua_vector_vector3_new01
static int tolua_vector_vector3_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float inX = ((float)  tolua_tonumber(tolua_S,2,0));
  float inY = ((float)  tolua_tonumber(tolua_S,3,0));
  float inZ = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   vector3* tolua_ret = (vector3*)  Mtolua_new((vector3)(inX,inY,inZ));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"vector3");
  }
 }
 return 1;
tolua_lerror:
 return tolua_vector_vector3_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  vector3 */
#ifndef TOLUA_DISABLE_tolua_vector_vector3_new01_local
static int tolua_vector_vector3_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float inX = ((float)  tolua_tonumber(tolua_S,2,0));
  float inY = ((float)  tolua_tonumber(tolua_S,3,0));
  float inZ = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   vector3* tolua_ret = (vector3*)  Mtolua_new((vector3)(inX,inY,inZ));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_vector_vector3_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  vector3 */
#ifndef TOLUA_DISABLE_tolua_vector_vector3_new02
static int tolua_vector_vector3_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const vector3* v = ((const vector3*)  tolua_tousertype(tolua_S,2,0));
  {
   vector3* tolua_ret = (vector3*)  Mtolua_new((vector3)(*v));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"vector3");
  }
 }
 return 1;
tolua_lerror:
 return tolua_vector_vector3_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  vector3 */
#ifndef TOLUA_DISABLE_tolua_vector_vector3_new02_local
static int tolua_vector_vector3_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const vector3* v = ((const vector3*)  tolua_tousertype(tolua_S,2,0));
  {
   vector3* tolua_ret = (vector3*)  Mtolua_new((vector3)(*v));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_vector_vector3_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator  of class  vector3 */
#ifndef TOLUA_DISABLE_tolua_vector_vector3_operator_00
static int tolua_vector_vector3_operator_00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  vector3* self = (vector3*)  tolua_tousertype(tolua_S,1,0);
  unsigned int i = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator '", NULL);
#endif
  {
   float tolua_ret = (float)  self->operator[] (i);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'operator_'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator  of class  vector3 */
#ifndef TOLUA_DISABLE_tolua_vector_vector3_operator_01
static int tolua_vector_vector3_operator_01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const vector3* self = (const vector3*)  tolua_tousertype(tolua_S,1,0);
  unsigned int i = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator '", NULL);
#endif
  {
   const float tolua_ret = (const float)  self->operator[] (i);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_vector_vector3_operator_00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  vector3 */
#ifndef TOLUA_DISABLE_tolua_vector_vector3__add00
static int tolua_vector_vector3__add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  vector3* self = (vector3*)  tolua_tousertype(tolua_S,1,0);
  vector3* v = ((vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   vector3 tolua_ret = (vector3)  self->operator+(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  vector3 */
#ifndef TOLUA_DISABLE_tolua_vector_vector3__add01
static int tolua_vector_vector3__add01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const vector3* self = (const vector3*)  tolua_tousertype(tolua_S,1,0);
  const vector3* v = ((const vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   vector3 tolua_ret = (vector3)  self->operator+(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_vector_vector3__add00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  vector3 */
#ifndef TOLUA_DISABLE_tolua_vector_vector3__sub00
static int tolua_vector_vector3__sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  vector3* self = (vector3*)  tolua_tousertype(tolua_S,1,0);
  vector3* v = ((vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   vector3 tolua_ret = (vector3)  self->operator-(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  vector3 */
#ifndef TOLUA_DISABLE_tolua_vector_vector3__sub01
static int tolua_vector_vector3__sub01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const vector3* self = (const vector3*)  tolua_tousertype(tolua_S,1,0);
  const vector3* v = ((const vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   vector3 tolua_ret = (vector3)  self->operator-(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_vector_vector3__sub00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  vector3 */
#ifndef TOLUA_DISABLE_tolua_vector_vector3__mul00
static int tolua_vector_vector3__mul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  vector3* self = (vector3*)  tolua_tousertype(tolua_S,1,0);
  float f = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   vector3 tolua_ret = (vector3)  self->operator*(f);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  vector3 */
#ifndef TOLUA_DISABLE_tolua_vector_vector3__div00
static int tolua_vector_vector3__div00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  vector3* self = (vector3*)  tolua_tousertype(tolua_S,1,0);
  float f = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
  {
   vector3 tolua_ret = (vector3)  self->operator/(f);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.div'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  vector3 */
#ifndef TOLUA_DISABLE_tolua_vector_vector3_set00
static int tolua_vector_vector3_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  vector3* self = (vector3*)  tolua_tousertype(tolua_S,1,0);
  float xIn = ((float)  tolua_tonumber(tolua_S,2,0));
  float yIn = ((float)  tolua_tonumber(tolua_S,3,0));
  float zIn = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   self->set(xIn,yIn,zIn);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: length of class  vector3 */
#ifndef TOLUA_DISABLE_tolua_vector_vector3_length00
static int tolua_vector_vector3_length00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vector3* self = (const vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'length'", NULL);
#endif
  {
   float tolua_ret = (float)  self->length();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'length'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: length_sqr of class  vector3 */
#ifndef TOLUA_DISABLE_tolua_vector_vector3_length_sqr00
static int tolua_vector_vector3_length_sqr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vector3* self = (const vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'length_sqr'", NULL);
#endif
  {
   float tolua_ret = (float)  self->length_sqr();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'length_sqr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: is_zero of class  vector3 */
#ifndef TOLUA_DISABLE_tolua_vector_vector3_is_zero00
static int tolua_vector_vector3_is_zero00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vector3* self = (const vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'is_zero'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->is_zero();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'is_zero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  vector3 */
#ifndef TOLUA_DISABLE_tolua_vector_vector3_normalize00
static int tolua_vector_vector3_normalize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  vector3* self = (vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normalize'", NULL);
#endif
  {
   vector3& tolua_ret = (vector3&)  self->normalize();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"vector3");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: reflection of class  vector3 */
#ifndef TOLUA_DISABLE_tolua_vector_vector3_reflection00
static int tolua_vector_vector3_reflection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  vector3* self = (vector3*)  tolua_tousertype(tolua_S,1,0);
  vector3* normal = ((vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reflection'", NULL);
#endif
  {
   vector3& tolua_ret = (vector3&)  self->reflection(*normal);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"vector3");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reflection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: angle of class  vector3 */
#ifndef TOLUA_DISABLE_tolua_vector_vector3_angle00
static int tolua_vector_vector3_angle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  vector3* self = (vector3*)  tolua_tousertype(tolua_S,1,0);
  vector3* v = ((vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'angle'", NULL);
#endif
  {
   float tolua_ret = (float)  self->angle(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'angle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_vector_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_function(tolua_S,"normalized",tolua_vector_normalized00);
  tolua_function(tolua_S,"length",tolua_vector_length00);
  tolua_function(tolua_S,"abs",tolua_vector_abs00);
  tolua_function(tolua_S,"dot_product",tolua_vector_dot_product00);
  tolua_function(tolua_S,"swap",tolua_vector_swap00);
  tolua_function(tolua_S,"cross_product",tolua_vector_cross_product00);
  tolua_function(tolua_S,"triple_product",tolua_vector_triple_product00);
  tolua_function(tolua_S,"nearly_equals",tolua_vector_nearly_equals00);
  tolua_function(tolua_S,"reflection",tolua_vector_reflection00);
  tolua_function(tolua_S,"max",tolua_vector_max00);
  tolua_function(tolua_S,"max_idx",tolua_vector_max_idx00);
  tolua_function(tolua_S,"min",tolua_vector_min00);
  tolua_function(tolua_S,"min_idx",tolua_vector_min_idx00);
  tolua_function(tolua_S,"abs_max",tolua_vector_abs_max00);
  tolua_function(tolua_S,"abs_max_idx",tolua_vector_abs_max_idx00);
  tolua_function(tolua_S,"abs_min",tolua_vector_abs_min00);
  tolua_function(tolua_S,"abs_min_idx",tolua_vector_abs_min_idx00);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"vector3","vector3","",tolua_collect_vector3);
  #else
  tolua_cclass(tolua_S,"vector3","vector3","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"vector3");
   tolua_function(tolua_S,"new",tolua_vector_vector3_new00);
   tolua_function(tolua_S,"new_local",tolua_vector_vector3_new00_local);
   tolua_function(tolua_S,".call",tolua_vector_vector3_new00_local);
   tolua_function(tolua_S,"new",tolua_vector_vector3_new01);
   tolua_function(tolua_S,"new_local",tolua_vector_vector3_new01_local);
   tolua_function(tolua_S,".call",tolua_vector_vector3_new01_local);
   tolua_function(tolua_S,"new",tolua_vector_vector3_new02);
   tolua_function(tolua_S,"new_local",tolua_vector_vector3_new02_local);
   tolua_function(tolua_S,".call",tolua_vector_vector3_new02_local);
   tolua_function(tolua_S,"operator_",tolua_vector_vector3_operator_00);
   tolua_function(tolua_S,"operator_",tolua_vector_vector3_operator_01);
   tolua_function(tolua_S,".add",tolua_vector_vector3__add00);
   tolua_function(tolua_S,".add",tolua_vector_vector3__add01);
   tolua_function(tolua_S,".sub",tolua_vector_vector3__sub00);
   tolua_function(tolua_S,".sub",tolua_vector_vector3__sub01);
   tolua_function(tolua_S,".mul",tolua_vector_vector3__mul00);
   tolua_function(tolua_S,".div",tolua_vector_vector3__div00);
   tolua_function(tolua_S,"set",tolua_vector_vector3_set00);
   tolua_function(tolua_S,"length",tolua_vector_vector3_length00);
   tolua_function(tolua_S,"length_sqr",tolua_vector_vector3_length_sqr00);
   tolua_function(tolua_S,"is_zero",tolua_vector_vector3_is_zero00);
   tolua_function(tolua_S,"normalize",tolua_vector_vector3_normalize00);
   tolua_function(tolua_S,"reflection",tolua_vector_vector3_reflection00);
   tolua_function(tolua_S,"angle",tolua_vector_vector3_angle00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_vector (lua_State* tolua_S) {
 return tolua_vector_open(tolua_S);
};
#endif

