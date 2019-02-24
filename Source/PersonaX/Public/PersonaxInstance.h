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

// Fetch the path that contains the Lua source code. Undoubtably different in development and delivery: TODO
const std::string luapath = std::string(TCHAR_TO_UTF8(*FPaths::ConvertRelativePathToFull(FPaths::ProjectDir()))) + "Source/Lua/?.lua";

/*Defines runtime Lua import path, and imports the state, which instantiates the game state
and sets it as global variable. Defined for explicit runtime. Currently checks in a Lua folder
under Source.*/
const std::string LUA_LOCAL_PREP = "package.path = package.path..'" + luapath + "' require('state')";

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
	nlohmann::json sendStateEvent(nlohmann::json event);

	nlohmann::json getUpdate();
};
