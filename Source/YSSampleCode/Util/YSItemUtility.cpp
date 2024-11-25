// Copyright Epic Games, Inc. All Rights Reserved.

#include "YSItemUtility.h"
#include "YSSampleCode/DataTypes/YSTooltipDataTypes.h"
#include "YSSampleCode/UI/YSTooltipUIContainer.h"

const FYSWeapon& YSItemUtil::GetWeaponInfo(int32 InId, int64 InSid)
{
	// TODO: insert return statement here
	static FYSWeapon Weapon;
	return Weapon;
}

const FYSArmor& YSItemUtil::GetArmorInfo(int32 InId, int64 InSid)
{
	// TODO: insert return statement here
	static FYSArmor Armor;
	return Armor;
}

const FYSAccessory& YSItemUtil::GetAccessoryInfo(int32 InId, int64 InSid)
{
	// TODO: insert return statement here
	static FYSAccessory Accessory;
	return Accessory;
}

const FYSFood& YSItemUtil::GetFoodInfo(int32 InId)
{
	// TODO: insert return statement here
	static FYSFood Food;
	return Food;
}

const FText& YSItemUtil::GetName(int32 InId, EYSItemType InType)
{
	// TODO: insert return statement here
	return FText::GetEmpty();
}

const FText& YSItemUtil::GetDesc(int32 InId, EYSItemType InType)
{
	// TODO: insert return statement here
	return FText::GetEmpty();
}
