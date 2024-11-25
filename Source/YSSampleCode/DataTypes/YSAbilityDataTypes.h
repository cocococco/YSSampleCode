// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM()
enum class EYSAbilityType : uint8
{
	Skill,
	Buff,
	Mastery,
};

UENUM()
enum class EYSOptionType : uint8
{
	Fixed,
	Random,
	Set,
	None = 255 UMETA(Hidden)
};

struct FYSOptionBase
{
	int32 Id;
	int32 Value;
	EYSOptionType Type;
	FText OptionNameText;
	FText OptionValueText;
};

struct FYSFixedOption : public FYSOptionBase
{
};

struct FYSRandomOption : public FYSOptionBase
{
};

struct FYSSetOption : public FYSOptionBase
{
	int32 SetId;
	int32 EquipCount;
};
