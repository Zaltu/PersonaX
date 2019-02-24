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

/*Defines runtime Lua import paths, and imports the state, which instantiates the game state
and sets it as global variable. Defined for explicit runtime. Currently checks for the paths
in my personal clone of the lua src.*/
const char * const LUA_PERSONAX_PATH = "package.path = package.path..';K:/Git Repos/personax-lua-src/model/?.lua'";
const char * const MY_LUA_PATH = "package.path = package.path..';K:/Git Repos/personax-lua-src/extlib/lua_path/?.lua'";
const char * const MY_LUA_CPATH = "package.cpath = package.cpath..';K:/Git Repos/personax-lua-src/extlib/lua_cpath/?.dll'";
const char * const GLOBAL_DATAPATH = "_G.DATAPATH = 'K:/Git Repos/personax-lua-src/model/data/'";
const char * const REQUIRE_STATE = "require('state')";

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
private:
	void setupLuaState();
	void runPathSet(const char* command);
};
