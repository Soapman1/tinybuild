// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TBPlayerController.h"
#include "TinybuildTestGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TINYBUILDTEST_API ATinybuildTestGameModeBase : public AGameModeBase
{
	GENERATED_BODY()


public:

	ATinybuildTestGameModeBase();

	UFUNCTION(BlueprintCallable)
	void GetResources(float Value, FName ResourceName);

	UFUNCTION(BlueprintCallable)
	void AddFirstResourceToStorage(float Value);

	UFUNCTION(BlueprintCallable)
	void AddSecondResourceToStorage(float Value);

	UPROPERTY(BlueprintReadWrite)
	float FirstResourceStorage = 0.0f;

	UPROPERTY(BlueprintReadWrite)
	float SecondResourseStorage = 0.0f;

	UPROPERTY(BlueprintReadWrite)
	TMap<FName,int32> ResourceStorage;

	UPROPERTY(BlueprintReadWrite)
	int32 MaxSizeOfStorage = 5000;

	
};
