// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "YSSampleCode/DataTypes/YSItemDataTypes.h"

namespace YSItemUtil
{
	const FYSWeapon& GetWeaponInfo(int32 InId, int64 InSid);
	const FYSArmor& GetArmorInfo(int32 InId, int64 InSid);
	const FYSAccessory& GetAccessoryInfo(int32 InId, int64 InSid);
	const FYSFood& GetFoodInfo(int32 InId);

	const FText& GetName(int32 InId, EYSItemType InType);
	const FText& GetDesc(int32 InId, EYSItemType InType);
}
