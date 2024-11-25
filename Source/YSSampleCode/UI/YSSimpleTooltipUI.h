// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "YSTooltipUIBase.h"
#include "YSSimpleTooltipUI.generated.h"

/**
 * 
 */
UCLASS()
class YSSAMPLECODE_API UYSSimpleTooltipUI : public UYSTooltipUIBase
{
	GENERATED_BODY()
	
public:
	virtual void SetTooltip(const FYSTooltipData& InData) override;
};
