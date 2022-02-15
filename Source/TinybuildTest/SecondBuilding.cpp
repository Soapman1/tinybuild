// Fill out your copyright notice in the Description page of Project Settings.


#include "SecondBuilding.h"
#include "TimerManager.h"
#include "TinybuildTestGameModeBase.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ASecondBuilding::ASecondBuilding()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);

	
	StaticMesh->OnReleased.AddDynamic(this, &ASecondBuilding::SendResourcesToStorage);


	GeometryWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("GeometryWidget"));
	GeometryWidget->SetupAttachment(StaticMesh);
	GeometryWidget->SetRelativeLocation(FVector(0.0f, 0.0f, 35.0f));
	GeometryWidget->SetWidgetSpace(EWidgetSpace::Screen);
	GeometryWidget->SetVisibility(false);

}

// Called when the game starts or when spawned
void ASecondBuilding::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASecondBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASecondBuilding::ConstructSecondBuilding()
{
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ASecondBuilding::IncreaseResources, 1.0f, true, 3.0f);
}

void ASecondBuilding::IncreaseResources()
{
	if(CurrentSecondResource < 500.0f)
	{
		CurrentSecondResource += 50.0f; //50 is Value of Resource
	}
}

void ASecondBuilding::SendResourcesToStorage(UPrimitiveComponent* TouchedComponent, FKey InputKey)
{
	
	ATinybuildTestGameModeBase* GameMode;
	if(CurrentSecondResource == 500.0f)
	{
		GameMode = Cast<ATinybuildTestGameModeBase>(UGameplayStatics::GetGameMode(this));
		GameMode->AddSecondResourceToStorage(CurrentSecondResource);
		CurrentSecondResource -= CurrentSecondResource;
	}

}