// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "YSTooltipUIWithKeyGuide.h"
#include "YSSampleCode/DataTypes/YSCommonDataTypes.h"
#include "YSItemTooltipUI.generated.h"

/**
 * 
 */
UCLASS()
class YSSAMPLECODE_API UYSItemTooltipUI : public UYSTooltipUIWithKeyGuide
{
	GENERATED_BODY()
	
public:
	void SetTooltip(const FYSTooltipData& InData) override;

private:
	void SetWeaponTooltip(int32 InId, int64 InSid);
	void SetArmorTooltip(int32 InId, int64 InSid);
	void SetAccessoryTooltip(int32 InId, int64 InSid);
	void SetFoodTooltip(int32 InId, int32 InValue);

private:
	void SetGrade(EYSGrade InGrade);
	void SetLevel(int16 InLevel);
	void SetDamageType(EYSDamageType InType);
	void SetBattlePower(int32 InValue);
	void SetBuff(int32 InId);

private:
	UPROPERTY()
	class UTextBlock* BattlePowerTextBlock;

	UPROPERTY()
	class UTextBlock* GradeTextBlock;

	UPROPERTY()
	class UYSTooltipUIStatPanel* MainStatPanel;

	UPROPERTY()
	class UYSTooltipUIStatPanel* SubStatPanel;

	UPROPERTY()
	class UYSTooltipUIStatPanel* RandomStatPanel;

	UPROPERTY()
	class UYSTooltipUIAttributePanel* AttributePanel;

};
