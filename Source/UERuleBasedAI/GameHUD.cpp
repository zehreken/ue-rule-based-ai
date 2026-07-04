// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUD.h"

void UGameHUD::SetStatusText(const FText& NewText)
{
	if (HealthText)
	{
		HealthText->SetText(NewText);
	}
}
