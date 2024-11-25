// Fill out your copyright notice in the Description page of Project Settings.


#include "YSTooltipUIBase.h"
#include "Components/TextBlock.h"

void UYSTooltipUIBase::SetName(const FText& InName)
{
	if (NameTextBlock)
	{
		NameTextBlock->SetText(InName);
	}
}

void UYSTooltipUIBase::SetDesc(const FText& InDesc)
{
	if (DescTextBlock)
	{
		DescTextBlock->SetText(InDesc);
	}
}
