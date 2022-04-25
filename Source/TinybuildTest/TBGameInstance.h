// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/DataTable.h"
#include "BaseBuilding.h"
#include "FuncLibrary.h"
#include "TBGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TINYBUILDTEST_API UTBGameInstance : public UGameInstance
{
	GENERATED_BODY()
	

public:

	//table
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BuildSetting")
		UDataTable* BuildInfoTable = nullptr;
	UFUNCTION(BlueprintCallable)
		bool GetBuildInfoByName(FName NameBuild, FBuildInfo& OutInfo);
};
