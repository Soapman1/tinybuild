// Fill out your copyright notice in the Description page of Project Settings.


#include "TBGameInstance.h"

bool UTBGameInstance::GetBuildInfoByName(FName NameBuild, FBuildInfo& OutInfo)
{
    bool bIsFind = false;
    FBuildInfo* BuildInfoRow;

    if(BuildInfoTable)
    {
        BuildInfoRow = BuildInfoTable->FindRow<FBuildInfo>(NameBuild, "", false);
        if(BuildInfoRow)
        {
            bIsFind = true;
            OutInfo = *BuildInfoRow;
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("UTBGameInstance::GetBuildInfoByName - BuildTable -NULL"));
    }

    return bIsFind;
}