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

    /*if(PreConstructFB)
    {
      FirstBuildingsArray.Last(LastElem);
      if(LastElem != NULL)
      {
        FirstBuildingsArray[LastElem]->SetActorRelativeLocation(MousePosInWorld(),false);
      }
      else
      {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Last elem is NULL")));
      }
     
    }*/
    


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
  UWorld* World = GetWorld();
  TArray<AFirstBuilding*> FirstBuildingsArray;
  if(World)
  {
  FTransform GeometryTransform = FTransform(FRotator::ZeroRotator, MousePosInWorld());
  AFirstBuilding* FirstBuildingActor = World->SpawnActor<AFirstBuilding>(FirstBuildingClass, GeometryTransform);
  
  int32 ElemIndex = FirstBuildingsArray.Add(FirstBuildingActor);

  GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, (TEXT("%s"),FirstBuildingsArray[ElemIndex]->GetName()));  
 
   /* if(FirstBuildingActor)
      {
       int32 ElemIndex = FirstBuildingsArray.Add(FirstBuildingActor);
        PreConstructFB = true;
      }
    else 
    {
      GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, (TEXT("%s"),FirstBuildingActor->GetName()));
    }

*/
  
  }
  
  


}

