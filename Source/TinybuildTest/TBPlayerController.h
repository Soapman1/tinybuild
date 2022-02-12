// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Math/Vector.h"
#include "FirstBuilding.h"
#include "TBPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TINYBUILDTEST_API ATBPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ATBPlayerController();

	UFUNCTION(BlueprintCallable)
	void PreConstructFirstBuilding();

	UPROPERTY(BlueprintReadWrite)
	bool PreConstructFB = false;
	UPROPERTY(BlueprintReadWrite)
	bool PreConstructSB = false;

	int32 LastElem;


	TSubclassOf<AFirstBuilding> FirstBuildingClass;
	//TArray<AFirstBuilding*> FirstBuildingsArray;
	
	
	


protected:

	
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupInputComponent() override;

	FVector MousePosInWorld();

	

	

	
};
