// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "YSInputDataTypes.h"

UENUM(BlueprintType)
enum class EYSTooltipType : uint8
{
	Simple,
	Item,
	Currency,
	Ability,
	Quest,
	Map,
	None = 255 UMETA(Hidden)
};

struct YSSAMPLECODE_API FYSTooltipData
{
	EYSTooltipType Type = EYSTooltipType::Simple;

	uint8 Int8Param1 = 0;
	uint8 Int8Param2 = 0;
	int16 Int16Param1 = 0;
	int32 Int32Param1 = 0;
	int32 Int32Param2 = 0;
	int64 Int64Param1 = 0;

	FText TextParam1 = FText::GetEmpty();
	FText TextParam2 = FText::GetEmpty();

	void Clear();
	bool IsValid() const;
	FYSTooltipData& operator=(const FYSTooltipData& InOther);

	static FYSTooltipData CreateSimple(const FText& InDesc, const FText& InName = FText::GetEmpty());
	static FYSTooltipData CreateEquipItem(int32 InId, uint8 InItemType, int64 InSid = 0);
	static FYSTooltipData CreateStackItem(int32 InId, uint8 InItemType, int32 InValue = 0);
	static FYSTooltipData CreateSkill(int32 InId, uint8 InSkillSlot = 0);
	static FYSTooltipData CreateBuff(int32 InId, int32 InSubId = 0);
	static FYSTooltipData CreateMastery(int32 InId, uint8 InPresetIndex, int64 InCharSid);
	static FYSTooltipData CreateCurrency(uint8 InCurrencyType, int64 InValue = 0);
};

struct FYSTooltipKeyData
{
	FYSInputKey InputKey;
	FSimpleDelegate OnKeyEvent;
	FText Desc;
	bool bIsShortcut;

	FYSTooltipKeyData();
	FYSTooltipKeyData(const FKey& InKey, const FText& InDesc, bool bInShortcut = false);
	FYSTooltipKeyData(const FKey& InKey, const FKey& InModifierKey, const FText& InDesc, bool bInShortcut = false);

	void Clear();
	void SetKeyEventCallback(const FSimpleDelegate& InCallback);
};

struct FYSTooltipContext
{
	FYSTooltipData CompareData;
	TArray<FYSTooltipKeyData> KeyDataList;

	FYSTooltipContext();
	void Clear();
	bool IsValid() const;
	FYSTooltipKeyData& AddKey(const FKey& InKey, const FText& InDesc, bool bInShortcut);
	FYSTooltipKeyData& AddKey(const FKey& InKey, const FKey& InPairKey, const FText& InDesc, bool bInShortcut);
};

struct FYSTooltipParam
{
	FYSTooltipData TooltipData;
	TFunction<FYSTooltipContext()> ContextGetter;

	FYSTooltipParam();

	void Clear();
	bool IsValid() const;
	void ClearTooltip();
	void SetTooltip(const FYSTooltipData& InData);
	FYSTooltipParam& operator=(const FYSTooltipParam& InOther);
};
