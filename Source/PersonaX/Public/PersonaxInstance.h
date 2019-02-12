#pragma once

//Essential Include
#include "Engine/GameInstance.h" 

#include "PersonaxInstance.generated.h"

/**
 * 
 */
UCLASS()
class UPersonaxInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UPersonaxInstance(const FObjectInitializer& ObjectInitializer);

	/** Increment this value in any map, change map, and notice it persists! */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TEST")
	int32 InterLevelPersistentValue;
};
