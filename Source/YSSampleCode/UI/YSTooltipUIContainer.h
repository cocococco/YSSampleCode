// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "YSSampleCode/DataTypes/YSTooltipDataTypes.h"
#include "YSTooltipUIBase.h"
#include "YSTooltipUIContainer.generated.h"

struct FYSPendingTooltipData
{
	TWeakObjectPtr<const UWidget> Widget;
	FYSTooltipParam Param;

	void Clear();
	bool IsValid() const;
};

/**
 * 
 */
UCLASS()
class YSSAMPLECODE_API UYSTooltipUIContainer : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UYSTooltipUIContainer(const FObjectInitializer& ObjectInitializer);

private:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

public:
	void PrepareTooltipData(const struct FYSTooltipParam& InParam, const UWidget* InWidget);

private:
	void UpdateTooltipUI(const FYSTooltipParam& InParam);
	void HideTooltipUI();

	void PrepareToUpdatePosition(const FGeometry& InTarget);
	void PrepareToFadeIn();
	void SetContextObject(const UWidget* InWidget);

	bool CanFadeInTooltip(const FVector2D& OldMainPanelPos, const FVector2D& OldComparePanelPos) const;
	void TryFadeIn(const FVector2D& OldMainPanelPos, const FVector2D& OldComparePanelPos);

	void UpdatePosition();

	void RegisterInputProcessor();
	void UnregisterInputProcessor();
	void SetInputKeyData(const TArray<struct FYSTooltipKeyData>& InKeyList);
	void ClearInputKeyData();

	UYSTooltipUIBase* GetMainTooltipWidget(EYSTooltipType InType);
	UYSTooltipUIBase* GetCompareTooltipWidget(EYSTooltipType InType);

	TSubclassOf<UYSTooltipUIBase> FindWidgetInTable(EYSTooltipType InType) const;

	template<typename YYSTooltipUIBase>
	UYSTooltipUIBase* BuildTooltipUIPanel(UNamedSlot* InSlot, TSubclassOf<UYSTooltipUIBase> InTooltipClass)
	{
		if (InSlot == nullptr || InTooltipClass == nullptr)
		{
			return nullptr;
		}

		if (auto TooltipWidget = CreateWidget<UYSTooltipUIBase>(this, InTooltipClass))
		{
			InSlot->SetContent(TooltipWidget);
			return TooltipWidget;
		}

		return nullptr;
	}

private:
	UPROPERTY()
	class UWidget* RootPanel;

	UPROPERTY()
	class UNamedSlot* MainPanel;

	UPROPERTY()
	class UNamedSlot* ComparePanel;

	UPROPERTY()
	class UCanvasPanel* PoolingCanvasPanel;

private:
	FYSPendingTooltipData PendingTooltipData;
	EYSTooltipType CurrentTooltipType = EYSTooltipType::None;

	bool bUpdatePosition = false;
	FGeometry TargetGeometry;

	bool bCheckContextObject = false;
	TWeakObjectPtr<UUserWidget> ContextObjectPtr;
	TWeakObjectPtr<const UWidget> TargetWidgetPtr;

	bool bFadeIn = false;
	float FadeOpacity = 0.f;

	TMap<EYSTooltipType, UYSTooltipUIBase*> MainTooltipCache;
	TMap<EYSTooltipType, UYSTooltipUIBase*> CompareTooltipCache;

	TSharedPtr<class FYSTooltipUIInputProcessor> InputProcessor;
};
