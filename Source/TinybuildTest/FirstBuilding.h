// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/WidgetComponent.h"
#include "FirstBuilding.generated.h"

UCLASS()
class TINYBUILDTEST_API AFirstBuilding : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFirstBuilding();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	

	UFUNCTION()
	void IncreaseResources();

	UPROPERTY()
	FTimerHandle TimerHandle;

	



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere)
	UWidgetComponent* GeometryWidget;

	UPROPERTY(BlueprintReadWrite)
	float CurrentFirstResource;

	UFUNCTION()
	void CostructFirstBuilding();

	UFUNCTION()
	void SendResourcesToStorage();

	



};
