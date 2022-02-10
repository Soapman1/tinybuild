// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "TBPlayer.generated.h"

UCLASS()
class TINYBUILDTEST_API ATBPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATBPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	USpringArmComponent* SpringArm;
	UCameraComponent* Camera;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

	
	
};
