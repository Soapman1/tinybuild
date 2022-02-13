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
