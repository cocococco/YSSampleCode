// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Application/IInputProcessor.h"

/**
 * 
 */
class FYSTooltipUIInputProcessor : public IInputProcessor
{
public:
	FYSTooltipUIInputProcessor() {}

	FYSTooltipUIInputProcessor(class UYSTooltipUIContainer* InContainer)
		: WidgetContainer(InContainer)
	{}

protected:
	virtual void Tick(const float DeltaTime, FSlateApplication& SlateApp, TSharedRef<ICursor> Cursor) final {}
	virtual bool HandleKeyDownEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent) final;
	virtual bool HandleMouseButtonDownEvent(FSlateApplication& SlateApp, const FPointerEvent& MouseEvent) final;

public:
	void SetKeyDataList(const TArray<struct FYSTooltipKeyData>& InKeyList);
	void ClearKeyData();

private:
	TWeakObjectPtr<class UYSTooltipUIContainer> WidgetContainer;
	TArray<struct FYSTooltipKeyData> KeyDataList;
};
