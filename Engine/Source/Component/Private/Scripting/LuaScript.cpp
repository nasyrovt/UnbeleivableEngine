//
// Created by tahan on 26/11/2023.
//

#include <iostream>
#include <lua.hpp>
#include <luabridge3/LuaBridge/LuaBridge.h>
#include "../../Public/Scripting/LuaScript.h"
#include "../../../GameFramework/Public/ResourceManager.h"

LuaScript::LuaScript()
{
    luaState = luaL_newstate();
    luaL_openlibs(luaState);
    luabridge::getGlobalNamespace(luaState);
}

void LuaScript::ReportErrors(lua_State* InLuaState, int status)
{
    if (status == 0){
        return;
    }

    std::cerr << "[LUA ERROR]" << lua_tostring(InLuaState, -1) << std::endl;

    lua_pop(InLuaState, 1);
}

void LuaScript::SetScript(const string& InAssetID)
{
    std::string path = ResourceManager::GetInstance()->GetAssetPathByID(InAssetID);

    int scriptLoadStatus = luaL_dofile(luaState, path.c_str());

    ReportErrors(luaState, scriptLoadStatus);
}

void LuaScript::Tick(float DeltaTime)
{
    ActorComponent::Tick(DeltaTime);

    luabridge::LuaRef update = luabridge::getGlobal(luaState, "update");
    luabridge::LuaResult res = update(DeltaTime);
}
