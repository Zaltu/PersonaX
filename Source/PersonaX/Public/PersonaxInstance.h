#pragma once

#include <json.hpp>
extern "C"{
    #include <lua.h>
    #include <lauxlib.h>
    #include <lualib.h>
}

//Essential Include
#include "Engine/GameInstance.h" 

#include "PersonaxInstance.generated.h"

using json = nlohmann::json;

/*Defines runtime Lua import path, and imports the state, which instantiates the game state
and sets it as global variable. Defined for explicit runtime. Executable MUST be one level
above model with this current const value.*/
const char * const LUA_LOCAL_PREP = "package.path = package.path..';./model/?.lua' require('state')";

/**
 * 
 */
UCLASS()
class UPersonaxInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UPersonaxInstance(const FObjectInitializer& ObjectInitializer);

	lua_State *L;

	// Send event to the GSV
	json sendStateEvent(json event);

	json getUpdate();
};
