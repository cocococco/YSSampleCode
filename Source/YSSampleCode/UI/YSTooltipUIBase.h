// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "YSSampleCode/DataTypes/YSTooltipDataTypes.h"
#include "YSTooltipUIBase.generated.h"

/**
 * 
 */
UCLASS()
class YSSAMPLECODE_API UYSTooltipUIBase : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void SetTooltip(const FYSTooltipData& InData) {}

protected:
	virtual void SetDesc(const FText& InDesc);
	virtual void SetName(const FText& InName);

protected:
	UPROPERTY()
	class UTextBlock* NameTextBlock;

	UPROPERTY()
	class UTextBlock* DescTextBlock;
};
