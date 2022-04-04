// Fill out your copyright notice in the Description page of Project Settings.


#include "SmallBuilding.h"
#include "TinybuildTestGameModeBase.h"
#include "Kismet/GameplayStatics.h"

ASmallBuilding::ASmallBuilding()
{
    StaticMesh->OnReleased.AddDynamic(this, &ASmallBuilding::OnReleasedEvent);
    MaxResource = 500.0f;

}

void ASmallBuilding::BeginPlay()
{
    Super::BeginPlay();
    ConstructBuilding(TimerDelay, FirstTimerDelay);
}

void ASmallBuilding::OnReleasedEvent(UPrimitiveComponent* TouchedComponent, FKey InputKey)
{

    ATinybuildTestGameModeBase* GameMode;
	if(CurrentResource == MaxResource)
	{
		GameMode = Cast<ATinybuildTestGameModeBase>(UGameplayStatics::GetGameMode(this));
		GameMode->AddFirstResourceToStorage(CurrentResource);
        
		CurrentResource -= CurrentResource;
	}
}

