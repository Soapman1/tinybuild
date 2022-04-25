// Copyright Epic Games, Inc. All Rights Reserved.


#include "TinybuildTestGameModeBase.h"

ATinybuildTestGameModeBase::ATinybuildTestGameModeBase()
{
    PlayerControllerClass = ATBPlayerController::StaticClass();

    ResourceStorage.Add(TEXT("Wood"), 0);
    ResourceStorage.Add(TEXT("Steel"), 0);

}

void ATinybuildTestGameModeBase::AddFirstResourceToStorage(float Value)
{
    FirstResourceStorage += Value;
}

void ATinybuildTestGameModeBase::AddSecondResourceToStorage(float Value)
{
    SecondResourseStorage += Value;
}

//Update resource map (storage)
void ATinybuildTestGameModeBase::GetResources(float Value, FName ResourceName)
{

    float ResourceValue = ResourceStorage[ResourceName];
    if(ResourceValue < MaxSizeOfStorage)
    {
        ResourceValue += Value;
        ResourceStorage[ResourceName] = ResourceValue;
        if(ResourceStorage[ResourceName] > MaxSizeOfStorage)
        {
            ResourceStorage[ResourceName] = MaxSizeOfStorage;
        }
    }
    
  
}