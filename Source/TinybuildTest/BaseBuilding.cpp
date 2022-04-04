// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseBuilding.h"
#include "TimerManager.h"
#include "TinybuildTestGameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABaseBuilding::ABaseBuilding()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);

	//StaticMesh->OnReleased.AddDynamic( this, &ABaseBuilding::SendResourcesToStorage);
	GeometryWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("GeometryWidget"));
	GeometryWidget->SetupAttachment(StaticMesh);
	GeometryWidget->SetRelativeLocation(FVector(0.0f, 0.0f, 35.0f)); // Custom for each building
	GeometryWidget->SetWidgetSpace(EWidgetSpace::Screen);
	GeometryWidget->SetVisibility(false);
}

// Called when the game starts or when spawned
void ABaseBuilding::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void ABaseBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Event to start event for mining resource
void ABaseBuilding::ConstructBuilding(float TimeDelay, float FirstTimeDelay)
{
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ABaseBuilding::IncreaseResourceToStorage, TimeDelay, true, FirstTimeDelay);
}

//Update CurrentResource from 0 to MAX value
void ABaseBuilding::IncreaseResourceToStorage()
{
	if(CurrentResource < MaxResource)
	{
		CurrentResource += ResourceRate;
	}
}


