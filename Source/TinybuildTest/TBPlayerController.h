// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Math/Vector.h"
#include "FirstBuilding.h"
#include "SecondBuilding.h"
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

	UFUNCTION(BlueprintCallable)
	void PreConstructSecondBuilding();

	UPROPERTY(BlueprintReadWrite)
	bool PreConstructFB = false;
	UPROPERTY(BlueprintReadWrite)
	bool PreConstructSB = false;

	int32 LastElem;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AFirstBuilding> FirstBuildingClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ASecondBuilding> SecondBuildingClass;

	UPROPERTY()
	TArray<AFirstBuilding*> FirstBuildingsArray;

	UPROPERTY()
	TArray<ASecondBuilding*> SecondBuildingsArray;

	UFUNCTION()
	void ClickLeftMouse();

		
	
	


protected:

	
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupInputComponent() override;

	FVector MousePosInWorld();

	

	

	
};
