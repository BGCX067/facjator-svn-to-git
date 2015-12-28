/*
** Lua binding: terminal
** Generated automatically by tolua++-1.0.92 on 10/01/11 21:35:49.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_terminal_open (lua_State* tolua_S);

#include "terminal.hpp"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_And (lua_State* tolua_S)
{
 And* self = (And*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Plane (lua_State* tolua_S)
{
 Plane* self = (Plane*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Cone (lua_State* tolua_S)
{
 Cone* self = (Cone*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_PlaneProp (lua_State* tolua_S)
{
 PlaneProp* self = (PlaneProp*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Mirror (lua_State* tolua_S)
{
 Mirror* self = (Mirror*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Torus (lua_State* tolua_S)
{
 Torus* self = (Torus*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Cylinder (lua_State* tolua_S)
{
 Cylinder* self = (Cylinder*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Sphere (lua_State* tolua_S)
{
 Sphere* self = (Sphere*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Cube (lua_State* tolua_S)
{
 Cube* self = (Cube*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Or (lua_State* tolua_S)
{
 Or* self = (Or*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Diff (lua_State* tolua_S)
{
 Diff* self = (Diff*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Coscos (lua_State* tolua_S)
{
 Coscos* self = (Coscos*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Xor (lua_State* tolua_S)
{
 Xor* self = (Xor*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_GrammarObject (lua_State* tolua_S)
{
 GrammarObject* self = (GrammarObject*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"And");
 tolua_usertype(tolua_S,"Plane");
 tolua_usertype(tolua_S,"Cone");
 tolua_usertype(tolua_S,"PlaneProp");
 tolua_usertype(tolua_S,"Mirror");
 tolua_usertype(tolua_S,"Torus");
 tolua_usertype(tolua_S,"Cylinder");
 tolua_usertype(tolua_S,"Sphere");
 tolua_usertype(tolua_S,"Cube");
 tolua_usertype(tolua_S,"Or");
 tolua_usertype(tolua_S,"Diff");
 tolua_usertype(tolua_S,"Coscos");
 tolua_usertype(tolua_S,"Xor");
 tolua_usertype(tolua_S,"GrammarObject");
}

/* method: new of class  GrammarObject */
#ifndef TOLUA_DISABLE_tolua_terminal_GrammarObject_new00
static int tolua_terminal_GrammarObject_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GrammarObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GrammarObject* tolua_ret = (GrammarObject*)  Mtolua_new((GrammarObject)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GrammarObject");
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

/* method: new_local of class  GrammarObject */
#ifndef TOLUA_DISABLE_tolua_terminal_GrammarObject_new00_local
static int tolua_terminal_GrammarObject_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GrammarObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GrammarObject* tolua_ret = (GrammarObject*)  Mtolua_new((GrammarObject)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GrammarObject");
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

/* method: delete of class  GrammarObject */
#ifndef TOLUA_DISABLE_tolua_terminal_GrammarObject_delete00
static int tolua_terminal_GrammarObject_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GrammarObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GrammarObject* self = (GrammarObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  GrammarObject */
#ifndef TOLUA_DISABLE_tolua_terminal_GrammarObject_scale00
static int tolua_terminal_GrammarObject_scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GrammarObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GrammarObject* self = (GrammarObject*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   self->scale(x,y,z);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: translate of class  GrammarObject */
#ifndef TOLUA_DISABLE_tolua_terminal_GrammarObject_translate00
static int tolua_terminal_GrammarObject_translate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GrammarObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GrammarObject* self = (GrammarObject*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translate'", NULL);
#endif
  {
   self->translate(x,y,z);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'translate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotate of class  GrammarObject */
#ifndef TOLUA_DISABLE_tolua_terminal_GrammarObject_rotate00
static int tolua_terminal_GrammarObject_rotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GrammarObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GrammarObject* self = (GrammarObject*)  tolua_tousertype(tolua_S,1,0);
  float p = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float r = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotate'", NULL);
#endif
  {
   self->rotate(p,y,r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateDeg of class  GrammarObject */
#ifndef TOLUA_DISABLE_tolua_terminal_GrammarObject_rotateDeg00
static int tolua_terminal_GrammarObject_rotateDeg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GrammarObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GrammarObject* self = (GrammarObject*)  tolua_tousertype(tolua_S,1,0);
  float p = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float r = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateDeg'", NULL);
#endif
  {
   self->rotateDeg(p,y,r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateDeg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_terminal_Sphere_new00
static int tolua_terminal_Sphere_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Sphere",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Sphere* tolua_ret = (Sphere*)  Mtolua_new((Sphere)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sphere");
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

/* method: new_local of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_terminal_Sphere_new00_local
static int tolua_terminal_Sphere_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Sphere",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Sphere* tolua_ret = (Sphere*)  Mtolua_new((Sphere)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sphere");
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

/* method: delete of class  Sphere */
#ifndef TOLUA_DISABLE_tolua_terminal_Sphere_delete00
static int tolua_terminal_Sphere_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sphere",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sphere* self = (Sphere*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Cylinder */
#ifndef TOLUA_DISABLE_tolua_terminal_Cylinder_new00
static int tolua_terminal_Cylinder_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Cylinder",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Cylinder* tolua_ret = (Cylinder*)  Mtolua_new((Cylinder)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Cylinder");
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

/* method: new_local of class  Cylinder */
#ifndef TOLUA_DISABLE_tolua_terminal_Cylinder_new00_local
static int tolua_terminal_Cylinder_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Cylinder",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Cylinder* tolua_ret = (Cylinder*)  Mtolua_new((Cylinder)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Cylinder");
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

/* method: delete of class  Cylinder */
#ifndef TOLUA_DISABLE_tolua_terminal_Cylinder_delete00
static int tolua_terminal_Cylinder_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Cylinder",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Cylinder* self = (Cylinder*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Cube */
#ifndef TOLUA_DISABLE_tolua_terminal_Cube_new00
static int tolua_terminal_Cube_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Cube",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Cube* tolua_ret = (Cube*)  Mtolua_new((Cube)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Cube");
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

/* method: new_local of class  Cube */
#ifndef TOLUA_DISABLE_tolua_terminal_Cube_new00_local
static int tolua_terminal_Cube_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Cube",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Cube* tolua_ret = (Cube*)  Mtolua_new((Cube)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Cube");
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

/* method: delete of class  Cube */
#ifndef TOLUA_DISABLE_tolua_terminal_Cube_delete00
static int tolua_terminal_Cube_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Cube",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Cube* self = (Cube*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Cone */
#ifndef TOLUA_DISABLE_tolua_terminal_Cone_new00
static int tolua_terminal_Cone_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Cone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Cone* tolua_ret = (Cone*)  Mtolua_new((Cone)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Cone");
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

/* method: new_local of class  Cone */
#ifndef TOLUA_DISABLE_tolua_terminal_Cone_new00_local
static int tolua_terminal_Cone_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Cone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Cone* tolua_ret = (Cone*)  Mtolua_new((Cone)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Cone");
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

/* method: delete of class  Cone */
#ifndef TOLUA_DISABLE_tolua_terminal_Cone_delete00
static int tolua_terminal_Cone_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Cone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Cone* self = (Cone*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Torus */
#ifndef TOLUA_DISABLE_tolua_terminal_Torus_new00
static int tolua_terminal_Torus_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Torus",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Torus* tolua_ret = (Torus*)  Mtolua_new((Torus)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Torus");
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

/* method: new_local of class  Torus */
#ifndef TOLUA_DISABLE_tolua_terminal_Torus_new00_local
static int tolua_terminal_Torus_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Torus",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Torus* tolua_ret = (Torus*)  Mtolua_new((Torus)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Torus");
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

/* method: new of class  Torus */
#ifndef TOLUA_DISABLE_tolua_terminal_Torus_new01
static int tolua_terminal_Torus_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Torus",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float _R = ((float)  tolua_tonumber(tolua_S,2,0));
  float _r = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Torus* tolua_ret = (Torus*)  Mtolua_new((Torus)(_R,_r));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Torus");
  }
 }
 return 1;
tolua_lerror:
 return tolua_terminal_Torus_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Torus */
#ifndef TOLUA_DISABLE_tolua_terminal_Torus_new01_local
static int tolua_terminal_Torus_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Torus",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float _R = ((float)  tolua_tonumber(tolua_S,2,0));
  float _r = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Torus* tolua_ret = (Torus*)  Mtolua_new((Torus)(_R,_r));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Torus");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_terminal_Torus_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Torus */
#ifndef TOLUA_DISABLE_tolua_terminal_Torus_delete00
static int tolua_terminal_Torus_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Torus",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Torus* self = (Torus*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Coscos */
#ifndef TOLUA_DISABLE_tolua_terminal_Coscos_new00
static int tolua_terminal_Coscos_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Coscos",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Coscos* tolua_ret = (Coscos*)  Mtolua_new((Coscos)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Coscos");
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

/* method: new_local of class  Coscos */
#ifndef TOLUA_DISABLE_tolua_terminal_Coscos_new00_local
static int tolua_terminal_Coscos_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Coscos",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Coscos* tolua_ret = (Coscos*)  Mtolua_new((Coscos)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Coscos");
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

/* method: delete of class  Coscos */
#ifndef TOLUA_DISABLE_tolua_terminal_Coscos_delete00
static int tolua_terminal_Coscos_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Coscos",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Coscos* self = (Coscos*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  And */
#ifndef TOLUA_DISABLE_tolua_terminal_And_new00
static int tolua_terminal_And_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"And",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GrammarObject* t1 = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  GrammarObject* t2 = ((GrammarObject*)  tolua_tousertype(tolua_S,3,0));
  {
   And* tolua_ret = (And*)  Mtolua_new((And)(*t1,*t2));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"And");
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

/* method: new_local of class  And */
#ifndef TOLUA_DISABLE_tolua_terminal_And_new00_local
static int tolua_terminal_And_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"And",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GrammarObject* t1 = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  GrammarObject* t2 = ((GrammarObject*)  tolua_tousertype(tolua_S,3,0));
  {
   And* tolua_ret = (And*)  Mtolua_new((And)(*t1,*t2));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"And");
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

/* method: new of class  And */
#ifndef TOLUA_DISABLE_tolua_terminal_And_new01
static int tolua_terminal_And_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"And",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GrammarObject* t1 = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  GrammarObject* t2 = ((GrammarObject*)  tolua_tousertype(tolua_S,3,0));
  GrammarObject* t3 = ((GrammarObject*)  tolua_tousertype(tolua_S,4,0));
  {
   And* tolua_ret = (And*)  Mtolua_new((And)(*t1,*t2,*t3));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"And");
  }
 }
 return 1;
tolua_lerror:
 return tolua_terminal_And_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  And */
#ifndef TOLUA_DISABLE_tolua_terminal_And_new01_local
static int tolua_terminal_And_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"And",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GrammarObject* t1 = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  GrammarObject* t2 = ((GrammarObject*)  tolua_tousertype(tolua_S,3,0));
  GrammarObject* t3 = ((GrammarObject*)  tolua_tousertype(tolua_S,4,0));
  {
   And* tolua_ret = (And*)  Mtolua_new((And)(*t1,*t2,*t3));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"And");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_terminal_And_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  And */
#ifndef TOLUA_DISABLE_tolua_terminal_And_new02
static int tolua_terminal_And_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"And",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GrammarObject* t1 = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  GrammarObject* t2 = ((GrammarObject*)  tolua_tousertype(tolua_S,3,0));
  GrammarObject* t3 = ((GrammarObject*)  tolua_tousertype(tolua_S,4,0));
  GrammarObject* t4 = ((GrammarObject*)  tolua_tousertype(tolua_S,5,0));
  {
   And* tolua_ret = (And*)  Mtolua_new((And)(*t1,*t2,*t3,*t4));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"And");
  }
 }
 return 1;
tolua_lerror:
 return tolua_terminal_And_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  And */
#ifndef TOLUA_DISABLE_tolua_terminal_And_new02_local
static int tolua_terminal_And_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"And",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GrammarObject* t1 = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  GrammarObject* t2 = ((GrammarObject*)  tolua_tousertype(tolua_S,3,0));
  GrammarObject* t3 = ((GrammarObject*)  tolua_tousertype(tolua_S,4,0));
  GrammarObject* t4 = ((GrammarObject*)  tolua_tousertype(tolua_S,5,0));
  {
   And* tolua_ret = (And*)  Mtolua_new((And)(*t1,*t2,*t3,*t4));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"And");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_terminal_And_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  And */
#ifndef TOLUA_DISABLE_tolua_terminal_And_new03
static int tolua_terminal_And_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"And",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GrammarObject* t1 = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  GrammarObject* t2 = ((GrammarObject*)  tolua_tousertype(tolua_S,3,0));
  GrammarObject* t3 = ((GrammarObject*)  tolua_tousertype(tolua_S,4,0));
  GrammarObject* t4 = ((GrammarObject*)  tolua_tousertype(tolua_S,5,0));
  GrammarObject* t5 = ((GrammarObject*)  tolua_tousertype(tolua_S,6,0));
  {
   And* tolua_ret = (And*)  Mtolua_new((And)(*t1,*t2,*t3,*t4,*t5));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"And");
  }
 }
 return 1;
tolua_lerror:
 return tolua_terminal_And_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  And */
#ifndef TOLUA_DISABLE_tolua_terminal_And_new03_local
static int tolua_terminal_And_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"And",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GrammarObject* t1 = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  GrammarObject* t2 = ((GrammarObject*)  tolua_tousertype(tolua_S,3,0));
  GrammarObject* t3 = ((GrammarObject*)  tolua_tousertype(tolua_S,4,0));
  GrammarObject* t4 = ((GrammarObject*)  tolua_tousertype(tolua_S,5,0));
  GrammarObject* t5 = ((GrammarObject*)  tolua_tousertype(tolua_S,6,0));
  {
   And* tolua_ret = (And*)  Mtolua_new((And)(*t1,*t2,*t3,*t4,*t5));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"And");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_terminal_And_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  And */
#ifndef TOLUA_DISABLE_tolua_terminal_And_delete00
static int tolua_terminal_And_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"And",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  And* self = (And*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Or */
#ifndef TOLUA_DISABLE_tolua_terminal_Or_new00
static int tolua_terminal_Or_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Or",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GrammarObject* t1 = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  GrammarObject* t2 = ((GrammarObject*)  tolua_tousertype(tolua_S,3,0));
  {
   Or* tolua_ret = (Or*)  Mtolua_new((Or)(*t1,*t2));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Or");
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

/* method: new_local of class  Or */
#ifndef TOLUA_DISABLE_tolua_terminal_Or_new00_local
static int tolua_terminal_Or_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Or",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GrammarObject* t1 = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  GrammarObject* t2 = ((GrammarObject*)  tolua_tousertype(tolua_S,3,0));
  {
   Or* tolua_ret = (Or*)  Mtolua_new((Or)(*t1,*t2));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Or");
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

/* method: new of class  Or */
#ifndef TOLUA_DISABLE_tolua_terminal_Or_new01
static int tolua_terminal_Or_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Or",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GrammarObject* t1 = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  GrammarObject* t2 = ((GrammarObject*)  tolua_tousertype(tolua_S,3,0));
  GrammarObject* t3 = ((GrammarObject*)  tolua_tousertype(tolua_S,4,0));
  {
   Or* tolua_ret = (Or*)  Mtolua_new((Or)(*t1,*t2,*t3));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Or");
  }
 }
 return 1;
tolua_lerror:
 return tolua_terminal_Or_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Or */
#ifndef TOLUA_DISABLE_tolua_terminal_Or_new01_local
static int tolua_terminal_Or_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Or",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GrammarObject* t1 = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  GrammarObject* t2 = ((GrammarObject*)  tolua_tousertype(tolua_S,3,0));
  GrammarObject* t3 = ((GrammarObject*)  tolua_tousertype(tolua_S,4,0));
  {
   Or* tolua_ret = (Or*)  Mtolua_new((Or)(*t1,*t2,*t3));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Or");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_terminal_Or_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Or */
#ifndef TOLUA_DISABLE_tolua_terminal_Or_new02
static int tolua_terminal_Or_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Or",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GrammarObject* t1 = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  GrammarObject* t2 = ((GrammarObject*)  tolua_tousertype(tolua_S,3,0));
  GrammarObject* t3 = ((GrammarObject*)  tolua_tousertype(tolua_S,4,0));
  GrammarObject* t4 = ((GrammarObject*)  tolua_tousertype(tolua_S,5,0));
  {
   Or* tolua_ret = (Or*)  Mtolua_new((Or)(*t1,*t2,*t3,*t4));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Or");
  }
 }
 return 1;
tolua_lerror:
 return tolua_terminal_Or_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Or */
#ifndef TOLUA_DISABLE_tolua_terminal_Or_new02_local
static int tolua_terminal_Or_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Or",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GrammarObject* t1 = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  GrammarObject* t2 = ((GrammarObject*)  tolua_tousertype(tolua_S,3,0));
  GrammarObject* t3 = ((GrammarObject*)  tolua_tousertype(tolua_S,4,0));
  GrammarObject* t4 = ((GrammarObject*)  tolua_tousertype(tolua_S,5,0));
  {
   Or* tolua_ret = (Or*)  Mtolua_new((Or)(*t1,*t2,*t3,*t4));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Or");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_terminal_Or_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Or */
#ifndef TOLUA_DISABLE_tolua_terminal_Or_new03
static int tolua_terminal_Or_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Or",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GrammarObject* t1 = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  GrammarObject* t2 = ((GrammarObject*)  tolua_tousertype(tolua_S,3,0));
  GrammarObject* t3 = ((GrammarObject*)  tolua_tousertype(tolua_S,4,0));
  GrammarObject* t4 = ((GrammarObject*)  tolua_tousertype(tolua_S,5,0));
  GrammarObject* t5 = ((GrammarObject*)  tolua_tousertype(tolua_S,6,0));
  {
   Or* tolua_ret = (Or*)  Mtolua_new((Or)(*t1,*t2,*t3,*t4,*t5));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Or");
  }
 }
 return 1;
tolua_lerror:
 return tolua_terminal_Or_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Or */
#ifndef TOLUA_DISABLE_tolua_terminal_Or_new03_local
static int tolua_terminal_Or_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Or",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GrammarObject* t1 = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  GrammarObject* t2 = ((GrammarObject*)  tolua_tousertype(tolua_S,3,0));
  GrammarObject* t3 = ((GrammarObject*)  tolua_tousertype(tolua_S,4,0));
  GrammarObject* t4 = ((GrammarObject*)  tolua_tousertype(tolua_S,5,0));
  GrammarObject* t5 = ((GrammarObject*)  tolua_tousertype(tolua_S,6,0));
  {
   Or* tolua_ret = (Or*)  Mtolua_new((Or)(*t1,*t2,*t3,*t4,*t5));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Or");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_terminal_Or_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Or */
#ifndef TOLUA_DISABLE_tolua_terminal_Or_delete00
static int tolua_terminal_Or_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Or",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Or* self = (Or*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Diff */
#ifndef TOLUA_DISABLE_tolua_terminal_Diff_new00
static int tolua_terminal_Diff_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Diff",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GrammarObject* t1 = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  GrammarObject* t2 = ((GrammarObject*)  tolua_tousertype(tolua_S,3,0));
  {
   Diff* tolua_ret = (Diff*)  Mtolua_new((Diff)(*t1,*t2));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Diff");
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

/* method: new_local of class  Diff */
#ifndef TOLUA_DISABLE_tolua_terminal_Diff_new00_local
static int tolua_terminal_Diff_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Diff",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GrammarObject* t1 = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  GrammarObject* t2 = ((GrammarObject*)  tolua_tousertype(tolua_S,3,0));
  {
   Diff* tolua_ret = (Diff*)  Mtolua_new((Diff)(*t1,*t2));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Diff");
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

/* method: new of class  Diff */
#ifndef TOLUA_DISABLE_tolua_terminal_Diff_new01
static int tolua_terminal_Diff_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Diff",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GrammarObject* t1 = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  GrammarObject* t2 = ((GrammarObject*)  tolua_tousertype(tolua_S,3,0));
  GrammarObject* t3 = ((GrammarObject*)  tolua_tousertype(tolua_S,4,0));
  {
   Diff* tolua_ret = (Diff*)  Mtolua_new((Diff)(*t1,*t2,*t3));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Diff");
  }
 }
 return 1;
tolua_lerror:
 return tolua_terminal_Diff_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Diff */
#ifndef TOLUA_DISABLE_tolua_terminal_Diff_new01_local
static int tolua_terminal_Diff_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Diff",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GrammarObject* t1 = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  GrammarObject* t2 = ((GrammarObject*)  tolua_tousertype(tolua_S,3,0));
  GrammarObject* t3 = ((GrammarObject*)  tolua_tousertype(tolua_S,4,0));
  {
   Diff* tolua_ret = (Diff*)  Mtolua_new((Diff)(*t1,*t2,*t3));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Diff");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_terminal_Diff_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Diff */
#ifndef TOLUA_DISABLE_tolua_terminal_Diff_new02
static int tolua_terminal_Diff_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Diff",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GrammarObject* t1 = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  GrammarObject* t2 = ((GrammarObject*)  tolua_tousertype(tolua_S,3,0));
  GrammarObject* t3 = ((GrammarObject*)  tolua_tousertype(tolua_S,4,0));
  GrammarObject* t4 = ((GrammarObject*)  tolua_tousertype(tolua_S,5,0));
  {
   Diff* tolua_ret = (Diff*)  Mtolua_new((Diff)(*t1,*t2,*t3,*t4));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Diff");
  }
 }
 return 1;
tolua_lerror:
 return tolua_terminal_Diff_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Diff */
#ifndef TOLUA_DISABLE_tolua_terminal_Diff_new02_local
static int tolua_terminal_Diff_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Diff",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GrammarObject* t1 = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  GrammarObject* t2 = ((GrammarObject*)  tolua_tousertype(tolua_S,3,0));
  GrammarObject* t3 = ((GrammarObject*)  tolua_tousertype(tolua_S,4,0));
  GrammarObject* t4 = ((GrammarObject*)  tolua_tousertype(tolua_S,5,0));
  {
   Diff* tolua_ret = (Diff*)  Mtolua_new((Diff)(*t1,*t2,*t3,*t4));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Diff");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_terminal_Diff_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Diff */
#ifndef TOLUA_DISABLE_tolua_terminal_Diff_new03
static int tolua_terminal_Diff_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Diff",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GrammarObject* t1 = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  GrammarObject* t2 = ((GrammarObject*)  tolua_tousertype(tolua_S,3,0));
  GrammarObject* t3 = ((GrammarObject*)  tolua_tousertype(tolua_S,4,0));
  GrammarObject* t4 = ((GrammarObject*)  tolua_tousertype(tolua_S,5,0));
  GrammarObject* t5 = ((GrammarObject*)  tolua_tousertype(tolua_S,6,0));
  {
   Diff* tolua_ret = (Diff*)  Mtolua_new((Diff)(*t1,*t2,*t3,*t4,*t5));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Diff");
  }
 }
 return 1;
tolua_lerror:
 return tolua_terminal_Diff_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Diff */
#ifndef TOLUA_DISABLE_tolua_terminal_Diff_new03_local
static int tolua_terminal_Diff_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Diff",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GrammarObject* t1 = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  GrammarObject* t2 = ((GrammarObject*)  tolua_tousertype(tolua_S,3,0));
  GrammarObject* t3 = ((GrammarObject*)  tolua_tousertype(tolua_S,4,0));
  GrammarObject* t4 = ((GrammarObject*)  tolua_tousertype(tolua_S,5,0));
  GrammarObject* t5 = ((GrammarObject*)  tolua_tousertype(tolua_S,6,0));
  {
   Diff* tolua_ret = (Diff*)  Mtolua_new((Diff)(*t1,*t2,*t3,*t4,*t5));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Diff");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_terminal_Diff_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Diff */
#ifndef TOLUA_DISABLE_tolua_terminal_Diff_delete00
static int tolua_terminal_Diff_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Diff",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Diff* self = (Diff*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Xor */
#ifndef TOLUA_DISABLE_tolua_terminal_Xor_new00
static int tolua_terminal_Xor_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Xor",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GrammarObject* f = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  GrammarObject* s = ((GrammarObject*)  tolua_tousertype(tolua_S,3,0));
  {
   Xor* tolua_ret = (Xor*)  Mtolua_new((Xor)(*f,*s));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Xor");
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

/* method: new_local of class  Xor */
#ifndef TOLUA_DISABLE_tolua_terminal_Xor_new00_local
static int tolua_terminal_Xor_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Xor",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GrammarObject* f = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  GrammarObject* s = ((GrammarObject*)  tolua_tousertype(tolua_S,3,0));
  {
   Xor* tolua_ret = (Xor*)  Mtolua_new((Xor)(*f,*s));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Xor");
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

/* method: delete of class  Xor */
#ifndef TOLUA_DISABLE_tolua_terminal_Xor_delete00
static int tolua_terminal_Xor_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Xor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Xor* self = (Xor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Mirror */
#ifndef TOLUA_DISABLE_tolua_terminal_Mirror_new00
static int tolua_terminal_Mirror_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mirror",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GrammarObject* t = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  char type = ((char)  tolua_tonumber(tolua_S,3,0));
  {
   Mirror* tolua_ret = (Mirror*)  Mtolua_new((Mirror)(*t,type));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Mirror");
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

/* method: new_local of class  Mirror */
#ifndef TOLUA_DISABLE_tolua_terminal_Mirror_new00_local
static int tolua_terminal_Mirror_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mirror",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GrammarObject* t = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  char type = ((char)  tolua_tonumber(tolua_S,3,0));
  {
   Mirror* tolua_ret = (Mirror*)  Mtolua_new((Mirror)(*t,type));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Mirror");
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

/* method: delete of class  Mirror */
#ifndef TOLUA_DISABLE_tolua_terminal_Mirror_delete00
static int tolua_terminal_Mirror_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mirror",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mirror* self = (Mirror*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Plane */
#ifndef TOLUA_DISABLE_tolua_terminal_Plane_new00
static int tolua_terminal_Plane_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Plane",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Plane* tolua_ret = (Plane*)  Mtolua_new((Plane)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Plane");
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

/* method: new_local of class  Plane */
#ifndef TOLUA_DISABLE_tolua_terminal_Plane_new00_local
static int tolua_terminal_Plane_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Plane",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Plane* tolua_ret = (Plane*)  Mtolua_new((Plane)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Plane");
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

/* method: delete of class  Plane */
#ifndef TOLUA_DISABLE_tolua_terminal_Plane_delete00
static int tolua_terminal_Plane_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Plane",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Plane* self = (Plane*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  PlaneProp */
#ifndef TOLUA_DISABLE_tolua_terminal_PlaneProp_new00
static int tolua_terminal_PlaneProp_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"PlaneProp",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float _max = ((float)  tolua_tonumber(tolua_S,2,0));
  float _power = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   PlaneProp* tolua_ret = (PlaneProp*)  Mtolua_new((PlaneProp)(_max,_power));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"PlaneProp");
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

/* method: new_local of class  PlaneProp */
#ifndef TOLUA_DISABLE_tolua_terminal_PlaneProp_new00_local
static int tolua_terminal_PlaneProp_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"PlaneProp",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float _max = ((float)  tolua_tonumber(tolua_S,2,0));
  float _power = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   PlaneProp* tolua_ret = (PlaneProp*)  Mtolua_new((PlaneProp)(_max,_power));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"PlaneProp");
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

/* method: new of class  PlaneProp */
#ifndef TOLUA_DISABLE_tolua_terminal_PlaneProp_new01
static int tolua_terminal_PlaneProp_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"PlaneProp",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GrammarObject* t1 = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  float _max = ((float)  tolua_tonumber(tolua_S,3,0));
  float _power = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   PlaneProp* tolua_ret = (PlaneProp*)  Mtolua_new((PlaneProp)(*t1,_max,_power));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"PlaneProp");
  }
 }
 return 1;
tolua_lerror:
 return tolua_terminal_PlaneProp_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  PlaneProp */
#ifndef TOLUA_DISABLE_tolua_terminal_PlaneProp_new01_local
static int tolua_terminal_PlaneProp_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"PlaneProp",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GrammarObject* t1 = ((GrammarObject*)  tolua_tousertype(tolua_S,2,0));
  float _max = ((float)  tolua_tonumber(tolua_S,3,0));
  float _power = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   PlaneProp* tolua_ret = (PlaneProp*)  Mtolua_new((PlaneProp)(*t1,_max,_power));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"PlaneProp");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_terminal_PlaneProp_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  PlaneProp */
#ifndef TOLUA_DISABLE_tolua_terminal_PlaneProp_delete00
static int tolua_terminal_PlaneProp_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PlaneProp",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PlaneProp* self = (PlaneProp*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: p_scale of class  PlaneProp */
#ifndef TOLUA_DISABLE_tolua_terminal_PlaneProp_p_scale00
static int tolua_terminal_PlaneProp_p_scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PlaneProp",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PlaneProp* self = (PlaneProp*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'p_scale'", NULL);
#endif
  {
   self->p_scale(x,y,z);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'p_scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: p_translate of class  PlaneProp */
#ifndef TOLUA_DISABLE_tolua_terminal_PlaneProp_p_translate00
static int tolua_terminal_PlaneProp_p_translate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PlaneProp",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PlaneProp* self = (PlaneProp*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'p_translate'", NULL);
#endif
  {
   self->p_translate(x,y,z);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'p_translate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: p_rotate of class  PlaneProp */
#ifndef TOLUA_DISABLE_tolua_terminal_PlaneProp_p_rotate00
static int tolua_terminal_PlaneProp_p_rotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PlaneProp",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PlaneProp* self = (PlaneProp*)  tolua_tousertype(tolua_S,1,0);
  float p = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float r = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'p_rotate'", NULL);
#endif
  {
   self->p_rotate(p,y,r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'p_rotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: p_rotateDeg of class  PlaneProp */
#ifndef TOLUA_DISABLE_tolua_terminal_PlaneProp_p_rotateDeg00
static int tolua_terminal_PlaneProp_p_rotateDeg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PlaneProp",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PlaneProp* self = (PlaneProp*)  tolua_tousertype(tolua_S,1,0);
  float p = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float r = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'p_rotateDeg'", NULL);
#endif
  {
   self->p_rotateDeg(p,y,r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'p_rotateDeg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: draw */
#ifndef TOLUA_DISABLE_tolua_terminal_draw00
static int tolua_terminal_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"GrammarObject",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GrammarObject* t = ((GrammarObject*)  tolua_tousertype(tolua_S,1,0));
  {
   draw(*t);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_terminal_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"GrammarObject","GrammarObject","",tolua_collect_GrammarObject);
  #else
  tolua_cclass(tolua_S,"GrammarObject","GrammarObject","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"GrammarObject");
   tolua_function(tolua_S,"new",tolua_terminal_GrammarObject_new00);
   tolua_function(tolua_S,"new_local",tolua_terminal_GrammarObject_new00_local);
   tolua_function(tolua_S,".call",tolua_terminal_GrammarObject_new00_local);
   tolua_function(tolua_S,"delete",tolua_terminal_GrammarObject_delete00);
   tolua_function(tolua_S,"scale",tolua_terminal_GrammarObject_scale00);
   tolua_function(tolua_S,"translate",tolua_terminal_GrammarObject_translate00);
   tolua_function(tolua_S,"rotate",tolua_terminal_GrammarObject_rotate00);
   tolua_function(tolua_S,"rotateDeg",tolua_terminal_GrammarObject_rotateDeg00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Sphere","Sphere","GrammarObject",tolua_collect_Sphere);
  #else
  tolua_cclass(tolua_S,"Sphere","Sphere","GrammarObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Sphere");
   tolua_function(tolua_S,"new",tolua_terminal_Sphere_new00);
   tolua_function(tolua_S,"new_local",tolua_terminal_Sphere_new00_local);
   tolua_function(tolua_S,".call",tolua_terminal_Sphere_new00_local);
   tolua_function(tolua_S,"delete",tolua_terminal_Sphere_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Cylinder","Cylinder","GrammarObject",tolua_collect_Cylinder);
  #else
  tolua_cclass(tolua_S,"Cylinder","Cylinder","GrammarObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Cylinder");
   tolua_function(tolua_S,"new",tolua_terminal_Cylinder_new00);
   tolua_function(tolua_S,"new_local",tolua_terminal_Cylinder_new00_local);
   tolua_function(tolua_S,".call",tolua_terminal_Cylinder_new00_local);
   tolua_function(tolua_S,"delete",tolua_terminal_Cylinder_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Cube","Cube","GrammarObject",tolua_collect_Cube);
  #else
  tolua_cclass(tolua_S,"Cube","Cube","GrammarObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Cube");
   tolua_function(tolua_S,"new",tolua_terminal_Cube_new00);
   tolua_function(tolua_S,"new_local",tolua_terminal_Cube_new00_local);
   tolua_function(tolua_S,".call",tolua_terminal_Cube_new00_local);
   tolua_function(tolua_S,"delete",tolua_terminal_Cube_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Cone","Cone","GrammarObject",tolua_collect_Cone);
  #else
  tolua_cclass(tolua_S,"Cone","Cone","GrammarObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Cone");
   tolua_function(tolua_S,"new",tolua_terminal_Cone_new00);
   tolua_function(tolua_S,"new_local",tolua_terminal_Cone_new00_local);
   tolua_function(tolua_S,".call",tolua_terminal_Cone_new00_local);
   tolua_function(tolua_S,"delete",tolua_terminal_Cone_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Torus","Torus","GrammarObject",tolua_collect_Torus);
  #else
  tolua_cclass(tolua_S,"Torus","Torus","GrammarObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Torus");
   tolua_function(tolua_S,"new",tolua_terminal_Torus_new00);
   tolua_function(tolua_S,"new_local",tolua_terminal_Torus_new00_local);
   tolua_function(tolua_S,".call",tolua_terminal_Torus_new00_local);
   tolua_function(tolua_S,"new",tolua_terminal_Torus_new01);
   tolua_function(tolua_S,"new_local",tolua_terminal_Torus_new01_local);
   tolua_function(tolua_S,".call",tolua_terminal_Torus_new01_local);
   tolua_function(tolua_S,"delete",tolua_terminal_Torus_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Coscos","Coscos","GrammarObject",tolua_collect_Coscos);
  #else
  tolua_cclass(tolua_S,"Coscos","Coscos","GrammarObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Coscos");
   tolua_function(tolua_S,"new",tolua_terminal_Coscos_new00);
   tolua_function(tolua_S,"new_local",tolua_terminal_Coscos_new00_local);
   tolua_function(tolua_S,".call",tolua_terminal_Coscos_new00_local);
   tolua_function(tolua_S,"delete",tolua_terminal_Coscos_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"And","And","GrammarObject",tolua_collect_And);
  #else
  tolua_cclass(tolua_S,"And","And","GrammarObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"And");
   tolua_function(tolua_S,"new",tolua_terminal_And_new00);
   tolua_function(tolua_S,"new_local",tolua_terminal_And_new00_local);
   tolua_function(tolua_S,".call",tolua_terminal_And_new00_local);
   tolua_function(tolua_S,"new",tolua_terminal_And_new01);
   tolua_function(tolua_S,"new_local",tolua_terminal_And_new01_local);
   tolua_function(tolua_S,".call",tolua_terminal_And_new01_local);
   tolua_function(tolua_S,"new",tolua_terminal_And_new02);
   tolua_function(tolua_S,"new_local",tolua_terminal_And_new02_local);
   tolua_function(tolua_S,".call",tolua_terminal_And_new02_local);
   tolua_function(tolua_S,"new",tolua_terminal_And_new03);
   tolua_function(tolua_S,"new_local",tolua_terminal_And_new03_local);
   tolua_function(tolua_S,".call",tolua_terminal_And_new03_local);
   tolua_function(tolua_S,"delete",tolua_terminal_And_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Or","Or","GrammarObject",tolua_collect_Or);
  #else
  tolua_cclass(tolua_S,"Or","Or","GrammarObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Or");
   tolua_function(tolua_S,"new",tolua_terminal_Or_new00);
   tolua_function(tolua_S,"new_local",tolua_terminal_Or_new00_local);
   tolua_function(tolua_S,".call",tolua_terminal_Or_new00_local);
   tolua_function(tolua_S,"new",tolua_terminal_Or_new01);
   tolua_function(tolua_S,"new_local",tolua_terminal_Or_new01_local);
   tolua_function(tolua_S,".call",tolua_terminal_Or_new01_local);
   tolua_function(tolua_S,"new",tolua_terminal_Or_new02);
   tolua_function(tolua_S,"new_local",tolua_terminal_Or_new02_local);
   tolua_function(tolua_S,".call",tolua_terminal_Or_new02_local);
   tolua_function(tolua_S,"new",tolua_terminal_Or_new03);
   tolua_function(tolua_S,"new_local",tolua_terminal_Or_new03_local);
   tolua_function(tolua_S,".call",tolua_terminal_Or_new03_local);
   tolua_function(tolua_S,"delete",tolua_terminal_Or_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Diff","Diff","GrammarObject",tolua_collect_Diff);
  #else
  tolua_cclass(tolua_S,"Diff","Diff","GrammarObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Diff");
   tolua_function(tolua_S,"new",tolua_terminal_Diff_new00);
   tolua_function(tolua_S,"new_local",tolua_terminal_Diff_new00_local);
   tolua_function(tolua_S,".call",tolua_terminal_Diff_new00_local);
   tolua_function(tolua_S,"new",tolua_terminal_Diff_new01);
   tolua_function(tolua_S,"new_local",tolua_terminal_Diff_new01_local);
   tolua_function(tolua_S,".call",tolua_terminal_Diff_new01_local);
   tolua_function(tolua_S,"new",tolua_terminal_Diff_new02);
   tolua_function(tolua_S,"new_local",tolua_terminal_Diff_new02_local);
   tolua_function(tolua_S,".call",tolua_terminal_Diff_new02_local);
   tolua_function(tolua_S,"new",tolua_terminal_Diff_new03);
   tolua_function(tolua_S,"new_local",tolua_terminal_Diff_new03_local);
   tolua_function(tolua_S,".call",tolua_terminal_Diff_new03_local);
   tolua_function(tolua_S,"delete",tolua_terminal_Diff_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Xor","Xor","GrammarObject",tolua_collect_Xor);
  #else
  tolua_cclass(tolua_S,"Xor","Xor","GrammarObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Xor");
   tolua_function(tolua_S,"new",tolua_terminal_Xor_new00);
   tolua_function(tolua_S,"new_local",tolua_terminal_Xor_new00_local);
   tolua_function(tolua_S,".call",tolua_terminal_Xor_new00_local);
   tolua_function(tolua_S,"delete",tolua_terminal_Xor_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Mirror","Mirror","GrammarObject",tolua_collect_Mirror);
  #else
  tolua_cclass(tolua_S,"Mirror","Mirror","GrammarObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Mirror");
   tolua_function(tolua_S,"new",tolua_terminal_Mirror_new00);
   tolua_function(tolua_S,"new_local",tolua_terminal_Mirror_new00_local);
   tolua_function(tolua_S,".call",tolua_terminal_Mirror_new00_local);
   tolua_function(tolua_S,"delete",tolua_terminal_Mirror_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Plane","Plane","GrammarObject",tolua_collect_Plane);
  #else
  tolua_cclass(tolua_S,"Plane","Plane","GrammarObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Plane");
   tolua_function(tolua_S,"new",tolua_terminal_Plane_new00);
   tolua_function(tolua_S,"new_local",tolua_terminal_Plane_new00_local);
   tolua_function(tolua_S,".call",tolua_terminal_Plane_new00_local);
   tolua_function(tolua_S,"delete",tolua_terminal_Plane_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"PlaneProp","PlaneProp","GrammarObject",tolua_collect_PlaneProp);
  #else
  tolua_cclass(tolua_S,"PlaneProp","PlaneProp","GrammarObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"PlaneProp");
   tolua_function(tolua_S,"new",tolua_terminal_PlaneProp_new00);
   tolua_function(tolua_S,"new_local",tolua_terminal_PlaneProp_new00_local);
   tolua_function(tolua_S,".call",tolua_terminal_PlaneProp_new00_local);
   tolua_function(tolua_S,"new",tolua_terminal_PlaneProp_new01);
   tolua_function(tolua_S,"new_local",tolua_terminal_PlaneProp_new01_local);
   tolua_function(tolua_S,".call",tolua_terminal_PlaneProp_new01_local);
   tolua_function(tolua_S,"delete",tolua_terminal_PlaneProp_delete00);
   tolua_function(tolua_S,"p_scale",tolua_terminal_PlaneProp_p_scale00);
   tolua_function(tolua_S,"p_translate",tolua_terminal_PlaneProp_p_translate00);
   tolua_function(tolua_S,"p_rotate",tolua_terminal_PlaneProp_p_rotate00);
   tolua_function(tolua_S,"p_rotateDeg",tolua_terminal_PlaneProp_p_rotateDeg00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"draw",tolua_terminal_draw00);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_terminal (lua_State* tolua_S) {
 return tolua_terminal_open(tolua_S);
};
#endif

