// Fill out your copyright notice in the Description page of Project Settings.

#include "TBPlayerController.h"
#include "TinybuildTestGameModeBase.h"
#include "Kismet/GameplayStatics.h"


ATBPlayerController::ATBPlayerController()
{
    bShowMouseCursor = true;
    bEnableClickEvents = true;
    bEnableMouseOverEvents = true;
    DefaultMouseCursor = EMouseCursor::Default;
}

void ATBPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    if(PreConstructFB) //Geometry follow to cursor
    {
      FirstBuildingsArray.Last(LastElem);
      FirstBuildingsArray[LastElem]->SetActorRelativeLocation(MousePosInWorld(),false);           
    }
    else if(PreConstructSB)
    {
      SecondBuildingsArray.Last(LastElem);
      SecondBuildingsArray[LastElem]->SetActorRelativeLocation(MousePosInWorld(),false);
    }
    


}

void ATBPlayerController::SetupInputComponent()
{
   Super::SetupInputComponent();
   InputComponent->BindAction(TEXT("ClickLeftMouse"), IE_Released, this, &ATBPlayerController::ClickLeftMouse);

}

FVector ATBPlayerController::MousePosInWorld() //Cursor location to world location func
{
  FVector WorldLocation, WorldDirection;
  this->DeprojectMousePositionToWorld(WorldLocation, WorldDirection);

  float DistanceAboveGround = 30.0f;
  float NotSureWhyThisValue = -1.0f;
  float WhyThisOperation = WorldLocation.Z / WorldDirection.Z + DistanceAboveGround;

  FVector IsThisNewWorldDirection = (WorldDirection * WhyThisOperation) * NotSureWhyThisValue;
  FVector ActorWorldLocation = WorldLocation + IsThisNewWorldDirection;

  return ActorWorldLocation;

}

void ATBPlayerController::PreConstructFirstBuilding()
{
  UWorld* World = GetWorld();
  
  if(World)
  {
  //Spawn actor under cursor
  FTransform GeometryTransform = FTransform(FRotator::ZeroRotator, MousePosInWorld());
  AFirstBuilding* FirstBuildingActor = World->SpawnActor<AFirstBuilding>(FirstBuildingClass, GeometryTransform);
  int32 ElemIndex = FirstBuildingsArray.Add(FirstBuildingActor);   

  if(FirstBuildingActor)
    {
      PreConstructFB = true;
    }   
  }    
}

void ATBPlayerController::PreConstructSecondBuilding()
{
  UWorld* World = GetWorld();
  ATinybuildTestGameModeBase* GameMode = Cast<ATinybuildTestGameModeBase>(UGameplayStatics::GetGameMode(this));

  if(GameMode->FirstResourceStorage >= 500)
  {
    GameMode->FirstResourceStorage -= 500;

    if(World)
    {
    //Spawn actor under cursor
    FTransform GeometryTransform = FTransform(FRotator::ZeroRotator, MousePosInWorld());
    ASecondBuilding* SecondBuildingActor = World->SpawnActor<ASecondBuilding>(SecondBuildingClass, GeometryTransform);
    int32 ElemIndex = SecondBuildingsArray.Add(SecondBuildingActor);   
    
    if(SecondBuildingActor)
      {
      PreConstructSB = true;
      }
    }
  }
}

void ATBPlayerController::ClickLeftMouse()
{
    
  if(PreConstructFB)
  {
    PreConstructFB = false;
    FirstBuildingsArray.Last(LastElem);
    if(FirstBuildingsArray[LastElem])  
    {
      FirstBuildingsArray[LastElem]->GeometryWidget->SetVisibility(true);
      FirstBuildingsArray[LastElem]->ConstructFirstBuilding();
      FirstBuildingsArray.Empty(); // clear array. NEED
    }
  }
  else if(PreConstructSB)
  {
    PreConstructSB = false;
    SecondBuildingsArray.Last(LastElem);
    if(SecondBuildingsArray[LastElem])
    {
      SecondBuildingsArray[LastElem]->GeometryWidget->SetVisibility(true);
      SecondBuildingsArray[LastElem]->ConstructSecondBuilding();
      SecondBuildingsArray.Empty();
    }

  }
  
}

//Debug message
//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Actor is NOT NULL")));