// Fill out your copyright notice in the Description page of Project Settings.


#include "OwnController.h"

void AOwnController::BeginPlay()
{
	Super::BeginPlay();

	if (HUDWidgetClass)
	{
		GameHUD = CreateWidget<UGameHUD>(this, HUDWidgetClass, TEXT("GameHUD"));
		if (GameHUD)
		{
			UE_LOG(LogTemp, Display, TEXT("own controller wtf"));
			GameHUD->AddToViewport();
		}
	}
}
