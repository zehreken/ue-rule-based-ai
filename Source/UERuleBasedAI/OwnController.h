// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameHUD.h"
#include "GameFramework/PlayerController.h"
#include "OwnController.generated.h"

/**
 * 
 */
UCLASS()
class UERULEBASEDAI_API AOwnController : public APlayerController
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, Category = "HUD")
	TSubclassOf<UGameHUD> HUDWidgetClass;

public:
	UPROPERTY()
	TObjectPtr<UGameHUD> GameHUD;
};
