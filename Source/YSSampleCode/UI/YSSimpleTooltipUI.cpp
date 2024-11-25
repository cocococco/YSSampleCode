// Fill out your copyright notice in the Description page of Project Settings.


#include "YSSimpleTooltipUI.h"

void UYSSimpleTooltipUI::SetTooltip(const FYSTooltipData& InData)
{
	SetDesc(InData.TextParam1);
	SetName(InData.TextParam2);
}
