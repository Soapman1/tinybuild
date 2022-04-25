// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseBuilding.h"
#include "TimerManager.h"
#include "TinybuildTestGameModeBase.h"
#include "TBGameInstance.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABaseBuilding::ABaseBuilding()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);
	StaticMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	//StaticMesh->OnReleased.AddDynamic( this, &ABaseBuilding::SendResourcesToStorage);
	GeometryWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("GeometryWidget"));
	GeometryWidget->SetupAttachment(StaticMesh);
	GeometryWidget->SetRelativeLocation(FVector(0.0f, 0.0f, 35.0f)); // Custom for each building
	GeometryWidget->SetWidgetSpace(EWidgetSpace::Screen);
	GeometryWidget->SetVisibility(false);

	StaticMesh->OnReleased.AddDynamic(this, &ABaseBuilding::SendResourcesToStorage);
}

// Called when the game starts or when spawned
void ABaseBuilding::BeginPlay()
{
	Super::BeginPlay();
	
	InitBuild(InitBuildName);
}

// Called every frame
void ABaseBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DebugTick(DeltaTime);
}

void ABaseBuilding::DebugTick(float DeltaTime)
{
	
	CreateResoursebyBuilding();
	
}

//Event to start event for mining resource
void ABaseBuilding::ConstructBuilding(float TimeDelay, float FirstTimeDelay)
{
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ABaseBuilding::CreateResoursebyBuilding, BuildSetting.ResourceTimerDelay, true, BuildSetting.BuildTime);
}

//Update CurrentResource from 0 to MAX value
void ABaseBuilding::CreateResoursebyBuilding()
{
	//UE_LOG(LogTemp, Warning, TEXT("CreateResourcebyBuilding func is WORK"));
	// if(BuildSetting.CurrentResource < BuildSetting.MaxResource)
	// {
	// 	BuildSetting.CurrentResource += BuildSetting.ResourceRate;
	//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, FString::Printf(TEXT("Current resource: %f"), BuildSetting.CurrentResource));
	// 	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("Max Resource: %f"), BuildSetting.MaxResource));
	// }
}

void ABaseBuilding::SendResourcesToStorage(UPrimitiveComponent* TouchedComponent, FKey InputKey)
{
	BuildInfo.CurrentResource  = BuildInfo.CurrentResource + 1;
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, FString::Printf(TEXT("Current resource: %f"), BuildInfo.CurrentResource));
	// ATinybuildTestGameModeBase* GameMode;
	// if(CurrentResource >= MaxResource)
	// {
	// 	GameMode = Cast<ATinybuildTestGameModeBase>(UGameplayStatics::GetGameMode(this));
    //     GameMode->GetResources(CurrentResource, NameOfResource);   // Add resource on storage in GM
	// 	CurrentResource -= CurrentResource;
	// }
}

int32 ABaseBuilding::GetCurrentResource()
{
	return BuildInfo.CurrentResource;
}

void ABaseBuilding::InitBuild(FName NameBuild)
{
	// Init build with request from table with info by name
	UTBGameInstance* myGI = Cast<UTBGameInstance>(GetGameInstance());
	FBuildInfo myBuildInfo;

	if(myGI)
	{
		myGI->GetBuildInfoByName(NameBuild, myBuildInfo);
		BuildSetting = myBuildInfo;
	}



}
