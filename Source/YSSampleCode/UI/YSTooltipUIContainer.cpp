// Fill out your copyright notice in the Description page of Project Settings.


#include "YSTooltipUIContainer.h"
#include "Components/NamedSlot.h"
#include "YSTooltipUIWithKeyGuide.h"
#include "Components/CanvasPanel.h"
#include "YSTooltipUIInputProcessor.h"
#include "Framework/Application/SlateApplication.h"

void FYSPendingTooltipData::Clear()
{
	Widget = nullptr;
	Param.Clear();
}

bool FYSPendingTooltipData::IsValid() const
{
	return Widget.IsValid() && Param.IsValid();
}

UYSTooltipUIContainer::UYSTooltipUIContainer(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UYSTooltipUIContainer::NativeConstruct()
{
	RegisterInputProcessor();
}

void UYSTooltipUIContainer::NativeDestruct()
{
	UnregisterInputProcessor();
}

void UYSTooltipUIContainer::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	if (PendingTooltipData.IsValid())
	{
		if (!PendingTooltipData.Widget.IsValid())
		{
			PendingTooltipData.Clear();
			return;
		}

		UpdateTooltipUI(PendingTooltipData.Param);
		PrepareToUpdatePosition(PendingTooltipData.Widget->GetCachedGeometry());
		PrepareToFadeIn();
		SetContextObject(PendingTooltipData.Widget.Get());

		PendingTooltipData.Clear();
	}

	if (!bUpdatePosition) return;

	const FVector2D OldMainPanelPos = MainPanel ? MainPanel->RenderTransform.Translation : FVector2D::ZeroVector;
	const FVector2D OldComparePanelPos = ComparePanel ? ComparePanel->RenderTransform.Translation : FVector2D::ZeroVector;

	UpdatePosition();

	TryFadeIn(OldMainPanelPos, OldComparePanelPos);

	if (bCheckContextObject)
	{
		if (!IsValid(ContextObjectPtr.Get()) || !IsValid(TargetWidgetPtr.Get()))
		{
			HideTooltipUI();
		}
	}
}

void UYSTooltipUIContainer::PrepareTooltipData(const FYSTooltipParam& InParam, const UWidget* InWidget)
{
	PendingTooltipData.Clear();

	if (InWidget && InWidget->GetCachedGeometry().GetDrawSize().IsZero() == false)
	{
		PendingTooltipData.Widget = InWidget;
		PendingTooltipData.Param = InParam;
	}
}

void UYSTooltipUIContainer::UpdateTooltipUI(const FYSTooltipParam& InParam)
{
	FadeOpacity = 0.f;
	bUpdatePosition = false;
	bFadeIn = false;
	bCheckContextObject = false;
	ContextObjectPtr = nullptr;

	if (!InParam.IsValid() || !InParam.TooltipData.IsValid()) return;

	// Compare Panel
	bool bShowCompare = false;
	FYSTooltipContext ContextInfo;
	if (InParam.ContextGetter)
	{
		ContextInfo = InParam.ContextGetter();

		if (ContextInfo.CompareData.IsValid())
		{
			if (auto Widget = GetCompareTooltipWidget(ContextInfo.CompareData.Type))
			{
				bShowCompare = true;
				ComparePanel->AddChild(Widget);
				Widget->SetTooltip(ContextInfo.CompareData);
			}
		}
	}

	if (ComparePanel)
	{
		ComparePanel->SetVisibility(bShowCompare ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed);
	}

	// Main Panel
	CurrentTooltipType = InParam.TooltipData.Type;
	if (auto Widget = GetMainTooltipWidget(CurrentTooltipType))
	{
		MainPanel->AddChild(Widget);
		Widget->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
		Widget->SetTooltip(InParam.TooltipData);

		// Key Guide
		if (UYSTooltipUIWithKeyGuide* KeyGuide = Cast<UYSTooltipUIWithKeyGuide>(Widget))
		{
			SetInputKeyData(ContextInfo.KeyDataList);
			KeyGuide->SetTooltipKeyGuideDataList(ContextInfo.KeyDataList);
		}
	}
}

void UYSTooltipUIContainer::HideTooltipUI()
{
	if (PendingTooltipData.IsValid())
	{
		PendingTooltipData.Clear();
		return;
	}

	if (!PoolingCanvasPanel || CurrentTooltipType == EYSTooltipType::None) return;

	if (auto Widget = GetMainTooltipWidget(CurrentTooltipType))
	{
		PoolingCanvasPanel->AddChild(Widget);
		Widget->SetVisibility(ESlateVisibility::Collapsed);
		CurrentTooltipType = EYSTooltipType::None;
	}

	if (auto Widget = GetCompareTooltipWidget(CurrentTooltipType))
	{
		PoolingCanvasPanel->AddChild(Widget);
		Widget->SetVisibility(ESlateVisibility::Collapsed);
	}

	ClearInputKeyData();
}

void UYSTooltipUIContainer::PrepareToUpdatePosition(const FGeometry& InTarget)
{
	bUpdatePosition = true;
	TargetGeometry = InTarget;
}

void UYSTooltipUIContainer::PrepareToFadeIn()
{
	if (RootPanel)
	{
		RootPanel->SetVisibility(ESlateVisibility::HitTestInvisible);
		RootPanel->SetRenderOpacity(0.f);
	}
}

void UYSTooltipUIContainer::SetContextObject(const UWidget* InWidget)
{
	bCheckContextObject = false;
	ContextObjectPtr = nullptr;
	TargetWidgetPtr = nullptr;

	if (!IsValid(InWidget)) return;

	UUserWidget* ContextWidget = nullptr;
	UObject* OuterWidget = InWidget->GetOuter();

	// TODO

	if (ContextWidget)
	{
		bCheckContextObject = true;
		ContextObjectPtr = ContextWidget;
		TargetWidgetPtr = InWidget;
	}
}

bool UYSTooltipUIContainer::CanFadeInTooltip(const FVector2D& OldMainPanelPos, const FVector2D& OldComparePanelPos) const
{
	// 
	return false;
}

void UYSTooltipUIContainer::TryFadeIn(const FVector2D& OldMainPanelPos, const FVector2D& OldComparePanelPos)
{
	if (CanFadeInTooltip(OldMainPanelPos, OldComparePanelPos))
	{
		bFadeIn = true;
	}

	if (!bFadeIn) return;

	// TODO
	if (RootPanel)
	{
		RootPanel->SetRenderOpacity(FadeOpacity);
		if (FadeOpacity >= 1.f)
		{
			bFadeIn = false;
			// TODO
		}
	}
}

void UYSTooltipUIContainer::UpdatePosition()
{
}

void UYSTooltipUIContainer::RegisterInputProcessor()
{
	if (FSlateApplication::IsInitialized() && !InputProcessor.IsValid())
	{
		InputProcessor = MakeShareable(new FYSTooltipUIInputProcessor(this));
		FSlateApplication::Get().RegisterInputPreProcessor(InputProcessor);
	}
}

void UYSTooltipUIContainer::UnregisterInputProcessor()
{
	if (FSlateApplication::IsInitialized() && InputProcessor.IsValid())
	{
		FSlateApplication::Get().UnregisterInputPreProcessor(InputProcessor);
		InputProcessor.Reset();
	}
}

void UYSTooltipUIContainer::SetInputKeyData(const TArray<struct FYSTooltipKeyData>& InKeyList)
{
	if (InputProcessor.IsValid())
	{
		InputProcessor->SetKeyDataList(InKeyList);
	}
}

void UYSTooltipUIContainer::ClearInputKeyData()
{
	if (InputProcessor.IsValid())
	{
		InputProcessor->ClearKeyData();
	}
}

UYSTooltipUIBase* UYSTooltipUIContainer::GetMainTooltipWidget(EYSTooltipType InType)
{
	if (TSubclassOf<UYSTooltipUIBase> TooltipWidget = FindWidgetInTable(InType))
	{
		return MainTooltipCache.FindOrAdd(InType, BuildTooltipUIPanel<UYSTooltipUIBase>(MainPanel, TooltipWidget));
	}

	return nullptr;
}

UYSTooltipUIBase* UYSTooltipUIContainer::GetCompareTooltipWidget(EYSTooltipType InType)
{
	if (TSubclassOf<UYSTooltipUIBase> TooltipWidget = FindWidgetInTable(InType))
	{
		return CompareTooltipCache.FindOrAdd(InType, BuildTooltipUIPanel<UYSTooltipUIBase>(ComparePanel, TooltipWidget));
	}

	return nullptr;
}

TSubclassOf<UYSTooltipUIBase> UYSTooltipUIContainer::FindWidgetInTable(EYSTooltipType InType) const
{
	return nullptr;
}
