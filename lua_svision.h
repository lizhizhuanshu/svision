//
// Created by lizhi on 2021/3/22.
//

#ifndef SVISION_LUA_SVISION_H
#define SVISION_LUA_SVISION_H
#ifdef __cplusplus
extern "C"
{
#endif

int luaopen_svision(struct lua_State*L);
void injectMethodTo(struct lua_State*L,int tableIndex);
typedef lua_CFunction  lua_CFunction;
typedef void(*CompareColorMethodReceiver)(const char* name, lua_CFunction method, void*data);
void eachCompareColorMethod(CompareColorMethodReceiver receiver, void*data);
#ifdef __cplusplus
}
#endif

#endif //SVISION_LUA_SVISION_H
