// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseBuilding.h"
#include "SmallBuilding.generated.h"

/**
 * 
 */
UCLASS()
class TINYBUILDTEST_API ASmallBuilding : public ABaseBuilding
{
	GENERATED_BODY()
	

public:

	ASmallBuilding();

	

protected:

	virtual void BeginPlay() override;

	
	
private:
	

	UFUNCTION()
	void OnReleasedEvent(UPrimitiveComponent* TouchedComponent, FKey InputKey);

	
};
