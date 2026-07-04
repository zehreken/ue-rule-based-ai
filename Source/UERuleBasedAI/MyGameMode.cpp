// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"

#include "OwnController.h"

AMyGameMode::AMyGameMode()
{
	PlayerControllerClass = AOwnController::StaticClass();
}
