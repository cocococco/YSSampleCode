// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "YSCommonDataTypes.h"
#include "YSAbilityDataTypes.h"

UENUM()
enum class EYSInventoryType : uint8
{
	Weapon,
	Armor,
	Accessory,
	Mod,
	Consume,
	None = 255 UMETA(Hidden)
};

UENUM()
enum class EYSItemType : uint8
{
	Weapon,
	Armor,
	Accessory,
	Material,
	Food,
	Mod,
	None = 255 UMETA(Hidden)
};

UENUM()
enum class EYSWeaponType : uint8
{
	AR,
	Shotgun,
	SMG,
	Sniper
};

UENUM()
enum class EYSArmorSlot : uint8
{
	Helmet,
	Body,
	Gloves,
	Boots
};

UENUM()
enum class EYSAccessorySlot : uint8
{
	Earing,
	Neckless,
	Ring,
	Bracelet
};

UENUM()
enum class EYSModType : uint8
{
	Normal,
	Core,
};

UENUM()
enum class EYSModTag : uint8
{
	Red,
	Green,
	Yellow,
	Blue,
};

UENUM()
enum class EYSModEquipTarget : uint8
{
	Weapon,
	Helmet,
	Body,
	Gloves,
	Boots,
};

UENUM()
enum class EYSFoodType : uint8
{
	Single,
	Multi,
};

struct FYSItem
{
	int32 Id;
	int64 Sid;
	EYSInventoryType InvenType;
	bool bIsLocked;
};

struct FYSEquipItem : public FYSItem
{
	int32 BattlePower;
	bool bIsEquipped;
};

struct FYSConsumeItem : public FYSItem
{
	int32 Count;
	EYSGrade Grade;
	int32 MaxOverlapCount;
};

struct FYSMod : public FYSEquipItem
{
	EYSModType Type;
	int64 EquippedItemSid;
	uint8 EquippedSlotIndex;
	TArray<FYSRandomOption> MainOptionList;
};

struct FYSNormalMod : public FYSMod
{
	EYSGrade Grade;
	EYSModEquipTarget EquipTarget;
};

struct FYSCoreMode : public FYSMod
{
	bool bIsIdentified;
	TArray<EYSModTag> ModTagList;
	TArray<FYSSetOption> SetOptionList;
};

struct FYSWeapon : public FYSEquipItem
{
	EYSWeaponType Type;
	int16 Level;
	EYSGrade Grade;
	EYSDamageType DamageType;
	int32 Damage;
	EYSElementType ElementType;
	int64 EquippedCharSid;
	bool bIsIdentified;
	TArray<FYSFixedOption> MainOptionList;
	TArray<FYSRandomOption> SubOptionList;
	TArray<FYSMod> EquippedModList;
};

struct FYSArmor : public FYSEquipItem
{
	EYSArmorSlot Slot;
	int16 Level;
	EYSGrade Grade;
	bool bIsIdentified;
	TArray<FYSFixedOption> MainOptionList;
	TArray<FYSRandomOption> SubOptionList;
	TArray<FYSMod> EquippedModList;
};

struct FYSAccessory : public FYSEquipItem
{
	EYSAccessorySlot Slot;
	int16 Level;
	int32 Exp;
	EYSGrade Grade;
	bool bIsIdentified;
	TArray<FYSRandomOption> MainOptionList;
	TArray<FYSSetOption> SetOptionList;
};

struct FYSMaterial : public FYSConsumeItem
{
};

struct FYSFood : public FYSConsumeItem
{
	int32 BuffId;
	EYSFoodType Type;
};
