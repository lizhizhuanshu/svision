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
#ifdef __cplusplus
}
#endif

#endif //SVISION_LUA_SVISION_H
