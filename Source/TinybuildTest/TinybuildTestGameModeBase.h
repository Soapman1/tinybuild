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

	UFUNCTION()
	void AddFirstResourceToStorage(float Value);

	UFUNCTION()
	void AddSecondResourceToStorage(float Value);

	UPROPERTY(BlueprintReadWrite)
	float FirstResourceStorage = 0.0f;

	UPROPERTY(BlueprintReadWrite)
	float SecondResourseStorage = 0.0f;

	
};
