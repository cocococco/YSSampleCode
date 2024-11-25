// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Classes/Engine/DataTable.h"
#include "YSSampleCode/DataTypes/YSTooltipDataTypes.h"
#include "YSTooltipTable.generated.h"

USTRUCT()
struct FYSTooltipTableRow : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	EYSTooltipType Type;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UYSTooltipUIBase> Widget;
};
