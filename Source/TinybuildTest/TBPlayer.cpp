// Fill out your copyright notice in the Description page of Project Settings.


#include "TBPlayer.h"

// Sets default values
ATBPlayer::ATBPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//SpringArm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	SpringArm->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	SpringArm->TargetArmLength = 1500.0f;


	//Camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

}

// Called when the game starts or when spawned
void ATBPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATBPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


