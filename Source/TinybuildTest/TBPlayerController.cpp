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

FVector ATBPlayerController::MousePosInWorld()
{
    FVector WorldLocation, WorldDirection;
  this->DeprojectMousePositionToWorld(WorldLocation, WorldDirection);

  float DistanceAboveGround = 50.0f;
  float NotSureWhyThisValue = -1.0f;
  float WhyThisOperation = WorldLocation.Z / WorldDirection.Z + DistanceAboveGround;

  FVector IsThisNewWorldDirection = (WorldDirection * WhyThisOperation) * NotSureWhyThisValue;
  FVector ActorWorldLocation = WorldLocation + IsThisNewWorldDirection;

  return ActorWorldLocation;

}

void ATBPlayerController::PreConstructFirstBuilding()
{
  
  FTransform GeometryTransform = FTransform(FRotator::ZeroRotator, MousePosInWorld());
  AFirstBuilding* FirstBuildingActor = GetWorld()->SpawnActor<AFirstBuilding>(FirstBuildingClass, GeometryTransform);
  //FirstBuildingsArray.Add(&FirstBuildingActor);  ??? STUCK HERE
 // FirstBuildingsArray.Last();
 

  

}

