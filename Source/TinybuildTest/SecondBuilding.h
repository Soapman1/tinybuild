// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/WidgetComponent.h"
#include "SecondBuilding.generated.h"

UCLASS()
class TINYBUILDTEST_API ASecondBuilding : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASecondBuilding();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void IncreaseResources();

	UPROPERTY()
	FTimerHandle TimerHandle;

	UFUNCTION()
	void SendResourcesToStorage(UPrimitiveComponent* TouchedComponent, FKey InputKey);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere)
	UWidgetComponent* GeometryWidget;

	UPROPERTY(BlueprintReadWrite)
	float CurrentSecondResource;

	UFUNCTION()
	void ConstructSecondBuilding();

	

};
