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

	/** Increment this value in any map, change map, and notice it persists! */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TEST")
	int32 InterLevelPersistentValue;
};
