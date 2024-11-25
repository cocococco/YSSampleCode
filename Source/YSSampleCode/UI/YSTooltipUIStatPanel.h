// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "YSTooltipUIStatPanel.generated.h"

/**
 * 
 */
UCLASS()
class YSSAMPLECODE_API UYSTooltipUIStatPanel : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void UpdateOptionList(const TArray<struct FYSFixedOption>& InOptionList);
	void UpdateOptionList(const TArray<struct FYSRandomOption>& InOptionList);
	void UpdateOptionList(const TArray<struct FYSSetOption>& InOptionList);

	void SetIdentify();
};
