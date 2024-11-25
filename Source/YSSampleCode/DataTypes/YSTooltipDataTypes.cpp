// Fill out your copyright notice in the Description page of Project Settings.


#include "YSTooltipDataTypes.h"
#include "YSAbilityDataTypes.h"
#include "YSCommonDataTypes.h"

void FYSTooltipData::Clear()
{
	Type = EYSTooltipType::None;

	Int8Param1 = 0;
	Int8Param2 = 0;
	Int16Param1 = 0;
	Int32Param1 = 0;
	Int32Param2 = 0;
	Int64Param1 = 0;

	TextParam1 = FText::GetEmpty();
	TextParam2 = FText::GetEmpty();
}

bool FYSTooltipData::IsValid() const
{
	switch (Type)
	{
	case EYSTooltipType::Simple:
		return !TextParam1.IsEmpty();
		break;
	case EYSTooltipType::Item:
	case EYSTooltipType::Ability:
	case EYSTooltipType::Quest:
	case EYSTooltipType::Map:
		return (Int32Param1 == INVALID_ID);
		break;
	case EYSTooltipType::Currency:
	default:
		break;
	}
	return true;
}

FYSTooltipData& FYSTooltipData::operator=(const FYSTooltipData& InOther)
{
	Type = InOther.Type;

	Int8Param1 = InOther.Int8Param1;
	Int8Param2 = InOther.Int8Param2;
	Int16Param1 = InOther.Int16Param1;
	Int32Param1 = InOther.Int32Param1;
	Int32Param2 = InOther.Int32Param2;
	Int64Param1 = InOther.Int64Param1;

	TextParam1 = InOther.TextParam1;
	TextParam2 = InOther.TextParam2;

	return *this;
}

FYSTooltipData FYSTooltipData::CreateSimple(const FText& InDesc, const FText& InName)
{
	FYSTooltipData Data;
	Data.Type = EYSTooltipType::Simple;
	Data.TextParam1 = InDesc;
	Data.TextParam2 = InName;
	return Data;
}

FYSTooltipData FYSTooltipData::CreateEquipItem(int32 InId, uint8 InItemType, int64 InSid)
{
	FYSTooltipData Data;
	Data.Type = EYSTooltipType::Item;
	Data.Int32Param1 = InId;
	Data.Int8Param1 = InItemType;
	Data.Int64Param1 = InSid;
	return Data;
}

FYSTooltipData FYSTooltipData::CreateStackItem(int32 InId, uint8 InItemType, int32 InValue)
{
	FYSTooltipData Data;
	Data.Type = EYSTooltipType::Item;
	Data.Int32Param1 = InId;
	Data.Int8Param1 = InItemType;
	Data.Int32Param2 = InValue;
	return Data;
}

FYSTooltipData FYSTooltipData::CreateSkill(int32 InId, uint8 InSkillSlot)
{
	FYSTooltipData Data;
	Data.Type = EYSTooltipType::Ability;
	Data.Int32Param1 = InId;
	Data.Int8Param1 = uint8(EYSAbilityType::Skill);
	Data.Int8Param2 = InSkillSlot;
	return Data;
}

FYSTooltipData FYSTooltipData::CreateBuff(int32 InId, int32 InSubId)
{
	FYSTooltipData Data;
	Data.Type = EYSTooltipType::Ability;
	Data.Int32Param1 = InId;
	Data.Int32Param2 = InSubId;
	Data.Int8Param1 = uint8(EYSAbilityType::Buff);
	return Data;
}

FYSTooltipData FYSTooltipData::CreateMastery(int32 InId, uint8 InPresetIndex, int64 InCharSid)
{
	FYSTooltipData Data;
	Data.Type = EYSTooltipType::Ability;
	Data.Int32Param1 = InId;
	Data.Int8Param1 = uint8(EYSAbilityType::Mastery);
	Data.Int8Param2 = InPresetIndex;
	Data.Int64Param1 = InCharSid;
	return Data;
}

FYSTooltipData FYSTooltipData::CreateCurrency(uint8 InCurrencyType, int64 InValue)
{
	FYSTooltipData Data;
	Data.Type = EYSTooltipType::Currency;
	Data.Int8Param1 = InCurrencyType;
	Data.Int64Param1 = InValue;
	return Data;
}

FYSTooltipKeyData::FYSTooltipKeyData()
{
	Clear();
}

FYSTooltipKeyData::FYSTooltipKeyData(const FKey& InKey, const FText& InDesc, bool bInShortcut)
{
	Clear();
	InputKey.Key = InKey;
	Desc = InDesc;
	bIsShortcut = bInShortcut;
}

FYSTooltipKeyData::FYSTooltipKeyData(const FKey& InKey, const FKey& InModifierKey, const FText& InDesc, bool bInShortcut)
{
	Clear();
	InputKey.Key = InKey;
	InputKey.SetModifierFromKey(InModifierKey);
	Desc = InDesc;
	bIsShortcut = bInShortcut;
}

void FYSTooltipKeyData::Clear()
{
	InputKey.Key = EKeys::Invalid;
	OnKeyEvent.Unbind();
	Desc = FText::GetEmpty();
	bIsShortcut = false;
}

void FYSTooltipKeyData::SetKeyEventCallback(const FSimpleDelegate& InCallback)
{
	OnKeyEvent = InCallback;
}

FYSTooltipContext::FYSTooltipContext()
{
	Clear();
}

void FYSTooltipContext::Clear()
{
	CompareData.Clear();
	KeyDataList.Empty();
}

bool FYSTooltipContext::IsValid() const
{
	return (CompareData.IsValid() || KeyDataList.Num() > 0);
}

FYSTooltipKeyData& FYSTooltipContext::AddKey(const FKey& InKey, const FText& InDesc, bool bInShortcut)
{
	return KeyDataList.Emplace_GetRef(FYSTooltipKeyData(InKey, InDesc, bInShortcut));
}

FYSTooltipKeyData& FYSTooltipContext::AddKey(const FKey& InKey, const FKey& InPairKey, const FText& InDesc, bool bInShortcut)
{
	return KeyDataList.Emplace_GetRef(FYSTooltipKeyData(InKey, InPairKey, InDesc, bInShortcut));
}

FYSTooltipParam::FYSTooltipParam()
{
	Clear();
}

void FYSTooltipParam::Clear()
{
	TooltipData.Clear();
	ContextGetter = nullptr;
}

bool FYSTooltipParam::IsValid() const
{
	return TooltipData.IsValid();
}

void FYSTooltipParam::ClearTooltip()
{
	TooltipData.Clear();
}

void FYSTooltipParam::SetTooltip(const FYSTooltipData& InData)
{
	TooltipData = InData;
}

FYSTooltipParam& FYSTooltipParam::operator=(const FYSTooltipParam& InOther)
{
	TooltipData = InOther.TooltipData;
	ContextGetter = InOther.ContextGetter;

	return *this;
}
