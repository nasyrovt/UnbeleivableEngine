//
// Created by tahan on 26/11/2023.
//

#ifndef ENGINE_LUASCRIPT_H
#define ENGINE_LUASCRIPT_H


#include <lua.h>
#include <string>
#include "../Base/ActorComponent.h"

using namespace std;

class LuaScript : public ActorComponent
{
public:

    LuaScript();

    void SetScript(const string& InAssetID);
    void Tick(float DeltaTime) override;

protected:
    lua_State* luaState;

    static void ReportErrors(lua_State* InLuaState, int status);

};


#endif //ENGINE_LUASCRIPT_H
