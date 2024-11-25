// Fill out your copyright notice in the Description page of Project Settings.


#include "YSAbilityTooltipUI.h"
#include "YSSampleCode/DataTypes/YSAbilityDataTypes.h"

void UYSAbilityTooltipUI::SetTooltip(const FYSTooltipData& InData)
{
	if (!InData.IsValid()) return;
	switch (EYSAbilityType(InData.Int8Param1))
	{
	case EYSAbilityType::Skill:
		SetSkill(InData.Int32Param1, InData.Int8Param2);
		break;
	case EYSAbilityType::Buff:
		SetBuff(InData.Int32Param1, InData.Int32Param2);
		break;
	case EYSAbilityType::Mastery:
		SetMastery(InData.Int32Param1, InData.Int8Param2, InData.Int64Param1);
		break;
	default:
		break;
	}
}

void UYSAbilityTooltipUI::SetSkill(int32 InId, uint8 InSlot)
{
}

void UYSAbilityTooltipUI::SetBuff(int32 InId, int32 InSubId)
{
}

void UYSAbilityTooltipUI::SetMastery(int32 InId, uint8 InPresetIndex, int64 InCharSid)
{
}
