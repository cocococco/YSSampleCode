// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "YSTooltipUIAttributePanel.generated.h"

/**
 * 
 */
UCLASS()
class YSSAMPLECODE_API UYSTooltipUIAttributePanel : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetSkillPanel();
	void SetBuffPanel();
	void SetPerkPanel();

	void SetIdentify();
};
