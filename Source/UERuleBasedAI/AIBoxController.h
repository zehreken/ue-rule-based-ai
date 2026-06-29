// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIBoxController.generated.h"

/**
 * 
 */
UCLASS()
class UERULEBASEDAI_API AAIBoxController : public AAIController
{
	GENERATED_BODY()


	virtual void BeginPlay() override;
	void TryMove();
};
