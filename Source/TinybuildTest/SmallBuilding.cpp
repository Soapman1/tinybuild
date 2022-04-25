// Fill out your copyright notice in the Description page of Project Settings.


#include "SmallBuilding.h"
#include "TinybuildTestGameModeBase.h"
#include "Kismet/GameplayStatics.h"

ASmallBuilding::ASmallBuilding()
{
   // StaticMesh->OnReleased.AddDynamic(this, &ASmallBuilding::OnReleasedEvent);
  

}

void ASmallBuilding::BeginPlay()
{
    Super::BeginPlay();
    
}

// Event after released mouse button from geometry component
// void ASmallBuilding::OnReleasedEvent(UPrimitiveComponent* TouchedComponent, FKey InputKey)  
// {

//     ATinybuildTestGameModeBase* GameMode;
// 	if(CurrentResource == MaxResource)
// 	{
// 		GameMode = Cast<ATinybuildTestGameModeBase>(UGameplayStatics::GetGameMode(this));
// 	//	GameMode->AddFirstResourceToStorage(CurrentResource);
//         GameMode->GetResources(CurrentResource, NameOfResource);   // Add resource on storage in GM
// 		CurrentResource -= CurrentResource;
// 	}
// }

