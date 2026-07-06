// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "HTNPlanner.h"
#include "AIBoxController.generated.h"

/**
 * 
 */
UCLASS()
class UERULEBASEDAI_API AAIBoxController : public AAIController
{
	GENERATED_BODY()

	AAIBoxController();

	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* InPawn) override;

protected:
	UPROPERTY(VisibleAnywhere, Category="AI")
	TObjectPtr<UHTNPlanner> HTNPlanner;
};
