// Fill out your copyright notice in the Description page of Project Settings.


#include "YSItemTooltipUI.h"
#include "YSSampleCode/DataTypes/YSItemDataTypes.h"
#include "YSSampleCode/Util/YSItemUtility.h"
#include "YSTooltipUIStatPanel.h"

void UYSItemTooltipUI::SetTooltip(const FYSTooltipData& InData)
{
	if (!InData.IsValid()) return;

	switch (EYSItemType(InData.Int8Param1))
	{
	case EYSItemType::Weapon:
		SetWeaponTooltip(InData.Int32Param1, InData.Int64Param1);
		break;
	case EYSItemType::Armor:
		SetArmorTooltip(InData.Int32Param1, InData.Int64Param1);
		break;
	case EYSItemType::Accessory:
		SetAccessoryTooltip(InData.Int32Param1, InData.Int64Param1);
		break;
	case EYSItemType::Material:
		break;
	case EYSItemType::Food:
		SetFoodTooltip(InData.Int32Param1, InData.Int32Param2);
		break;
	case EYSItemType::Mod:
		break;
	default:
		break;
	}
}

void UYSItemTooltipUI::SetWeaponTooltip(int32 InId, int64 InSid)
{
	FYSWeapon WeaponInfo = YSItemUtil::GetWeaponInfo(InId, InSid);

	SetName(YSItemUtil::GetName(InId, EYSItemType::Weapon));
	SetDesc(YSItemUtil::GetDesc(InId, EYSItemType::Weapon));
	SetGrade(WeaponInfo.Grade);
	SetLevel(WeaponInfo.Level);
	SetDamageType(WeaponInfo.DamageType);
	SetBattlePower(WeaponInfo.BattlePower);

	if (MainStatPanel)
	{
		if (WeaponInfo.bIsIdentified)
		{
			MainStatPanel->UpdateOptionList(WeaponInfo.MainOptionList);
		}
		else
		{
			MainStatPanel->SetIdentify();
		}
	}

	if (SubStatPanel)
	{
		SubStatPanel->UpdateOptionList(WeaponInfo.SubOptionList);
	}
}

void UYSItemTooltipUI::SetArmorTooltip(int32 InId, int64 InSid)
{
	FYSArmor ArmorInfo = YSItemUtil::GetArmorInfo(InId, InSid);

	SetName(YSItemUtil::GetName(InId, EYSItemType::Armor));
	SetDesc(YSItemUtil::GetDesc(InId, EYSItemType::Armor));
	SetGrade(ArmorInfo.Grade);
	SetLevel(ArmorInfo.Level);
	SetBattlePower(ArmorInfo.BattlePower);

	if (MainStatPanel)
	{
		MainStatPanel->UpdateOptionList(ArmorInfo.MainOptionList);
	}

	if (SubStatPanel)
	{
		SubStatPanel->UpdateOptionList(ArmorInfo.SubOptionList);
	}
}

void UYSItemTooltipUI::SetAccessoryTooltip(int32 InId, int64 InSid)
{
	FYSAccessory AccessoryInfo = YSItemUtil::GetAccessoryInfo(InId, InSid);

	SetName(YSItemUtil::GetName(InId, EYSItemType::Accessory));
	SetDesc(YSItemUtil::GetDesc(InId, EYSItemType::Accessory));
	SetGrade(AccessoryInfo.Grade);
	SetLevel(AccessoryInfo.Level);
	SetBattlePower(AccessoryInfo.BattlePower);

	if (MainStatPanel)
	{
		MainStatPanel->UpdateOptionList(AccessoryInfo.MainOptionList);
	}

	if (SubStatPanel)
	{
		SubStatPanel->UpdateOptionList(AccessoryInfo.SetOptionList);
	}
}

void UYSItemTooltipUI::SetFoodTooltip(int32 InId, int32 InValue)
{
	FYSFood FoodInfo = YSItemUtil::GetFoodInfo(InId);

	SetName(YSItemUtil::GetName(InId, EYSItemType::Food));
	SetDesc(YSItemUtil::GetDesc(InId, EYSItemType::Food));
	SetGrade(FoodInfo.Grade);
	SetBuff(FoodInfo.BuffId);
}

void UYSItemTooltipUI::SetGrade(EYSGrade InGrade)
{
}

void UYSItemTooltipUI::SetLevel(int16 InLevel)
{
}

void UYSItemTooltipUI::SetDamageType(EYSDamageType InType)
{
}

void UYSItemTooltipUI::SetBattlePower(int32 InValue)
{
}

void UYSItemTooltipUI::SetBuff(int32 InId)
{
}
