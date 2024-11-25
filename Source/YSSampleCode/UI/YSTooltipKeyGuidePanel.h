// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "YSSampleCode/DataTypes/YSTooltipDataTypes.h"
#include "YSTooltipKeyGuidePanel.generated.h"

/**
 * 
 */
UCLASS()
class YSSAMPLECODE_API UYSTooltipKeyGuidePanel : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetKeyList(const TArray<FYSTooltipKeyData>& InData);
};
