// Fill out your copyright notice in the Description page of Project Settings.


#include "SmallBuilding.h"
#include "TinybuildTestGameModeBase.h"
#include "Kismet/GameplayStatics.h"

ASmallBuilding::ASmallBuilding()
{
    StaticMesh->OnReleased.AddDynamic(this, &ASmallBuilding::OnReleasedEvent);
    MaxResource = 500.0f;
	ResourceRate = 100.0f;
	TimerDelay = 3.0f;
	FirstTimerDelay = 3.0f;
	NameOfResource = "Wood";

}

void ASmallBuilding::BeginPlay()
{
    Super::BeginPlay();
    ConstructBuilding(TimerDelay, FirstTimerDelay);
}

// Event after released mouse button from geometry component
void ASmallBuilding::OnReleasedEvent(UPrimitiveComponent* TouchedComponent, FKey InputKey)  
{

    ATinybuildTestGameModeBase* GameMode;
	if(CurrentResource == MaxResource)
	{
		GameMode = Cast<ATinybuildTestGameModeBase>(UGameplayStatics::GetGameMode(this));
	//	GameMode->AddFirstResourceToStorage(CurrentResource);
        GameMode->GetResources(CurrentResource, NameOfResource);   // Add resource on storage in GM
		CurrentResource -= CurrentResource;
	}
}

