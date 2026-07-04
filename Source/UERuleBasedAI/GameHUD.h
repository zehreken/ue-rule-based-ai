// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "GameHUD.generated.h"

/**
 * 
 */
UCLASS()
class UERULEBASEDAI_API UGameHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetStatusText(const FText& NewText);

protected:
	// Name MUST match the widget name in the UMG designer exactly
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> HealthText;
};
