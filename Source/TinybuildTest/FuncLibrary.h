// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/DataTable.h"
#include "FuncLibrary.generated.h"



USTRUCT(BlueprintType)
struct FBuildInfo : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category =  "Class")
	TSubclassOf<class ABaseBuilding> BaseBuildingClass = nullptr;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category =  "Timer")
	float BuildTime = 3.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timer")
	float ResourceTimerDelay = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Resource")
	float MaxResource = 500.0f;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource")
	float ResourceRate = 50.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource")
	FName NameOfResource = nullptr;


};

USTRUCT(BlueprintType)
struct FAdditionalInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Resource")
		float CurrentResource = 0.0f;


};



UCLASS()
class TINYBUILDTEST_API UFuncLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
};