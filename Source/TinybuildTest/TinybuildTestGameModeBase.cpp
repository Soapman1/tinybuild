// Copyright Epic Games, Inc. All Rights Reserved.


#include "TinybuildTestGameModeBase.h"

ATinybuildTestGameModeBase::ATinybuildTestGameModeBase()
{
    PlayerControllerClass = ATBPlayerController::StaticClass();

}

void ATinybuildTestGameModeBase::AddFirstResourceToStorage(float Value)
{
    FirstResourceStorage += Value;
}

void ATinybuildTestGameModeBase::AddSecondResourceToStorage(float Value)
{
    SecondResourseStorage += Value;
}

void ATinybuildTestGameModeBase::GetResources(float Value, FString ResourceName)
{
  /*  switch (ResourceName)
    {
        case "Wood":
        FirstResourceStorage +=Value;
        break;
        case "Metal":
        SecondResourseStorage+= Value;
        break;
        default:
        ;*/
}