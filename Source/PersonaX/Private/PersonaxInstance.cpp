#include "PersonaxInstance.h"
#include "PersonaX.h"

//#include <json.hpp>

using json = nlohmann::json;

UPersonaxInstance::UPersonaxInstance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	L = lua_open();
    luaL_openlibs(L);
    luaL_dostring(L, LUA_LOCAL_PREP);
    lua_getglobal(L, "state");
}

/**
* Used to send a valid event to the Lua state. Will return
* the value of state.update that resulted from the event.
* 
* :returns: C++ form of state.update after the event was processed
* :rtype: json
*/
json UPersonaxInstance::sendStateEvent(json event){
    lua_getfield(L, -1, "event");
    lua_pushstring(L, event.dump().c_str());
    lua_pcall(L, 1, 1, 0);
    std::string returncode = lua_tostring(L, -1);
    lua_pop(L, 1);
    return getUpdate();
}


/**
* Fetch the state.update value from the Lua stack.
* This does NOT clear the value of state.update
* 
* :returns: C++ form of state.update, for interpreting
* :rtype: json
*/
json UPersonaxInstance::getUpdate(){
	lua_getfield(L, -1, "update");
	json update = json::parse(lua_tostring(L, -1));
	lua_pop(L, 1);
	return update;
}
