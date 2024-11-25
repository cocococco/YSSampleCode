// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "YSTooltipUIWithKeyGuide.h"
#include "YSAbilityTooltipUI.generated.h"

/**
 * 
 */
UCLASS()
class YSSAMPLECODE_API UYSAbilityTooltipUI : public UYSTooltipUIWithKeyGuide
{
	GENERATED_BODY()
	
public:
	virtual void SetTooltip(const FYSTooltipData& InData) override;

private:
	void SetSkill(int32 InId, uint8 InSlot);
	void SetBuff(int32 InId, int32 InSubId);
	void SetMastery(int32 InId, uint8 InPresetIndex, int64 InCharSid);
};
