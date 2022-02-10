// Fill out your copyright notice in the Description page of Project Settings.


#include "TBPlayerController.h"

ATBPlayerController::ATBPlayerController()
{
    bShowMouseCursor = true;
    bEnableClickEvents = true;
    bEnableMouseOverEvents = true;
    DefaultMouseCursor = EMouseCursor::GrabHand;
}

void ATBPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ATBPlayerController::SetupInputComponent()
{

}


