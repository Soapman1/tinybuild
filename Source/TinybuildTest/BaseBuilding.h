// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/WidgetComponent.h"
#include "BaseBuilding.generated.h"

UCLASS()
class TINYBUILDTEST_API ABaseBuilding : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseBuilding();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	FTimerHandle TimerHandle;

	UPROPERTY(BlueprintReadWrite, Category =  "Timer")
	float FirstTimerDelay = 0.0f;
	
	UPROPERTY(BlueprintReadWrite, Category = "Timer")
	float TimerDelay = 0.0f;

	UPROPERTY(BlueprintReadWrite)
	float TimeToBuild = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Resource")
	float MaxResource = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Resource")
	float CurrentResource = 0.0f;
	
	UPROPERTY(BlueprintReadWrite, Category = "Resource")
	float ResourceRate = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Resource")
	FString NameOfResource = "";

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere)
	UWidgetComponent* GeometryWidget;

	UFUNCTION()
	void ConstructBuilding(float TimeDelay, float FirstTimeDelay);

	//UFUNCTION()
	//void SendResourcesToStorage(UPrimitiveComponent* TouchedComponent, FKey InputKey);

	UFUNCTION()
	void IncreaseResourceToStorage();


};
