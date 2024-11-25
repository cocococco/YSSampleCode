// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "YSTooltipUIBase.h"
#include "YSSampleCode/DataTypes/YSTooltipDataTypes.h"
#include "YSTooltipUIWithKeyGuide.generated.h"

/**
 * 
 */
UCLASS()
class YSSAMPLECODE_API UYSTooltipUIWithKeyGuide : public UYSTooltipUIBase
{
	GENERATED_BODY()
	
public:
	virtual void SetTooltipKeyGuideDataList(const TArray<FYSTooltipKeyData>& InDataList);

protected:
	UPROPERTY()
	class UYSTooltipKeyGuidePanel* KeyGuidePanel;
};
