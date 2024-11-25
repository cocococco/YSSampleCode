// Fill out your copyright notice in the Description page of Project Settings.


#include "YSTooltipUIWithKeyGuide.h"
#include "YSTooltipKeyGuidePanel.h"

void UYSTooltipUIWithKeyGuide::SetTooltipKeyGuideDataList(const TArray<FYSTooltipKeyData>& InDataList)
{
	if (KeyGuidePanel)
	{
		if (InDataList.Num() == 0)
		{
			KeyGuidePanel->SetVisibility(ESlateVisibility::Collapsed);
			return;
		}

		KeyGuidePanel->SetKeyList(InDataList);
		KeyGuidePanel->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	}
}
