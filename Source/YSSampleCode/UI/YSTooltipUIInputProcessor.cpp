// Fill out your copyright notice in the Description page of Project Settings.


#include "YSTooltipUIInputProcessor.h"
#include "YSSampleCode/DataTypes/YSTooltipDataTypes.h"
#include "YSTooltipUIContainer.h"

bool FYSTooltipUIInputProcessor::HandleKeyDownEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent)
{
    if (!WidgetContainer.IsValid() || KeyDataList.Num() == 0) return false;

    const auto& EventKey = InKeyEvent.GetKey();
    for (const auto& It : KeyDataList)
    {
        //
    }

    return false;
}

bool FYSTooltipUIInputProcessor::HandleMouseButtonDownEvent(FSlateApplication& SlateApp, const FPointerEvent& MouseEvent)
{
    if (!WidgetContainer.IsValid() || KeyDataList.Num() == 0) return false;

    const auto& EventButton = MouseEvent.GetEffectingButton();
    for (const auto& It : KeyDataList)
    {
        //
    }

    return false;
}

void FYSTooltipUIInputProcessor::SetKeyDataList(const TArray<struct FYSTooltipKeyData>& InKeyList)
{
    ClearKeyData();

    for (const auto& It : InKeyList)
    {
        if (It.InputKey.Key.IsValid() && It.OnKeyEvent.IsBound())
        {
            KeyDataList.Emplace(It);
        }
    }
}

void FYSTooltipUIInputProcessor::ClearKeyData()
{
    KeyDataList.Empty();
}
