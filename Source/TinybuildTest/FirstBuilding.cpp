// Fill out your copyright notice in the Description page of Project Settings.

#include "FirstBuilding.h"

// Sets default values
AFirstBuilding::AFirstBuilding()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);

	GeometryWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("GeometryWidget"));
	GeometryWidget->SetupAttachment(StaticMesh);
	GeometryWidget->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));
	GeometryWidget->SetWidgetSpace(EWidgetSpace::Screen);
	GeometryWidget->SetVisibility(false);


}

// Called when the game starts or when spawned
void AFirstBuilding::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFirstBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

